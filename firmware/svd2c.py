#!/usr/bin/env python3
"""
svd2c.py – CMSIS-SVD to C Header Generator
==========================================

Usage:
-------

Install dependencies:
    pip install cmsis-svd

Generate headers:
    python svd2c.py device.svd -o include/               # One header per peripheral
    python svd2c.py device.svd --style single -o include/ # Single combined header
    python svd2c.py device.svd --no-bf -o include/        # Without bitfield macros
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path
from typing import Any, List, Sequence

try:
    from cmsis_svd.parser import SVDParser
except ImportError:
    sys.exit("Missing dependency: Please install cmsis-svd via `pip install cmsis-svd`.")


def snake(name: str) -> str:
    if not any(c.islower() for c in name):
        return name.lower()
    out: List[str] = []
    for i, c in enumerate(name):
        if c.isupper() and i and name[i - 1].islower():
            out.append('_')
        out.append(c.lower())
    return ''.join(out)


def attr(o: Any, key: str, default: Any = None) -> Any:
    return getattr(o, key, o[key] if isinstance(o, dict) and key in o else default)

IND = ' ' * 4

# -----------------------------------------------------------------------------
# Bit‑field helpers ------------------------------------------------------------
# -----------------------------------------------------------------------------

def _hex_mask(width: int, lsb: int) -> str:
    if width >= 32:
        return "0xFFFFFFFFu"
    return f"0x{(((1 << width) - 1) << lsb):X}u"


def gen_field_macros(periph: str, reg: str, fields: Sequence[Any]) -> List[str]:
    """Emit macros for fields and enumerated values."""
    p, r = periph.upper(), reg.upper()
    out: List[str] = []

    for f in fields:
        fname = attr(f, 'name').upper()
        lsb = attr(f, 'bit_offset', attr(f, 'lsb', 0))
        width = attr(f, 'bit_width', attr(f, 'width', 1))

        if width == 1:
            out.append(f"#define {p}_{r}_{fname} (1u << {lsb})")
        else:
            out.append(f"#define {p}_{r}_{fname}_LSB   {lsb}")
            out.append(f"#define {p}_{r}_{fname}_WIDTH {width}")
            out.append(f"#define {p}_{r}_{fname}_MASK  ({_hex_mask(width, lsb)})")

        # Enumerated value aliases
        ev_groups = attr(f, 'enumerated_values', None) or attr(f, 'enumeratedValues', None) or []
        for g in ev_groups:
            for ev in attr(g, 'enumerated_values', None) or attr(g, 'enumeratedValues', None) or []:
                ename = attr(ev, 'name')
                if not ename:
                    continue
                value = attr(ev, 'value', None)
                if value is None:
                    continue
                out.append(f"#define {p}_{r}_{fname}_{ename.upper()} {value}u")

    return out

COMMON_BF_MACROS = """/* ---- Generic bit‑field helpers ---- */
#define BF_PREP(val, field)   (((val) << field##_LSB) & field##_MASK)
#define BF_GET(x, field)      (((x) & field##_MASK) >> field##_LSB)
#define BF_SET(x, field, v)   do { (x) = ((x) & ~(field##_MASK)) | BF_PREP((v), field); } while (0)
#define BF_CLEAR(x, field)    do { (x) &= ~(field##_MASK); } while (0)
"""

def gen_struct(periph: Any) -> str:
    regs = sorted(attr(periph, 'registers', []), key=lambda r: attr(r, 'address_offset', 0))
    cur = 0
    dup: bool = False
    lines: List[str] = ['typedef struct {']
    for reg in regs:
        dup = False
        offset = attr(reg, 'address_offset', 0)
        bits = attr(reg, 'size', 32) or 32
        bytes_ = max(bits // 8, 1)
        if offset > cur:
            lines.append(f"{IND}uint8_t _res_{cur:04X}[{offset - cur}];")
            cur = offset
        elif offset < cur:
            lines.insert(-1, f"{IND}union {{")
            dup = True
            cur -= bytes_
        lines.append(f"{IND}volatile uint{bytes_*8}_t {attr(reg,'name')}; /* 0x{offset:03X} */")
        if dup:
            lines.append(f"{IND}}};")
        cur += bytes_
    lines.append('} ' + attr(periph, 'name') + '_Type;\n')
    return '\n'.join(lines)


def gen_header(periph: Any, with_bf: bool) -> str:
    name = attr(periph, 'name')
    guard = f"{name.upper()}_H_"
    base = attr(periph, 'base_address', 0)

    out: List[str] = [f"#ifndef {guard}", f"#define {guard}", '', '#include <stdint.h>', '']
    out.append(f"#define {name.upper()}_BASE 0x{base:08X}u\n")
    out.append(gen_struct(periph))
    out.append(f"#define {name.upper()} ((volatile {name}_Type*){name.upper()}_BASE)\n")

    if with_bf:
        for reg in attr(periph, 'registers', []):
            out.extend(gen_field_macros(name, attr(reg, 'name'), attr(reg, 'fields', [])))
        out.append('')

    out.append(f"#endif /* {guard} */\n")
    return '\n'.join(out)


def gen_single(device: Any, periphs: Sequence[Any], with_bf: bool) -> str:
    guard = f"{attr(device,'name').upper()}_PERIPHERALS_H_"
    lines: List[str] = [f"#ifndef {guard}", f'#define {guard}', '', '#include <stdint.h>', '']
    if with_bf:
        lines.append(COMMON_BF_MACROS)
    for p in periphs:
        lines.append(f"/* === {attr(p,'name')} ================================= */")
        lines.append(gen_struct(p))
        base = attr(p, 'base_address', 0)
        pname = attr(p, 'name')
        lines.append(f"#define {pname.upper()}_BASE 0x{base:08X}u")
        lines.append(f"#define {pname.upper()} ((volatile {pname}_Type*){pname.upper()}_BASE)\n")
        if with_bf or True:
            for r in attr(p, 'registers', []):
                lines.extend(gen_field_macros(pname, attr(r, 'name'), attr(r, 'fields', [])))
            lines.append('')
    lines.append(f"#endif /* {guard} */\n")
    return '\n'.join(lines)


def main() -> None:
    ap = argparse.ArgumentParser(description='Generate C headers from an SVD.')
    ap.add_argument('svd', type=Path, help='Path to .svd file')
    ap.add_argument('-o', '--out', type=Path, default=Path('include'), help='Output directory')
    ap.add_argument('--style', choices=['peripheral', 'single'], default='peripheral', help='Header layout')
    ap.add_argument('--no-bf', action='store_false', dest='bf', help='Omit bit‑field macros')
    args = ap.parse_args()

    dev = SVDParser.for_xml_file(str(args.svd)).get_device()
    periphs = list(dev.peripherals)
    args.out.mkdir(parents=True, exist_ok=True)

    if args.style == 'peripheral':
        if args.bf:
            (args.out / '_bf_helpers.h').write_text(COMMON_BF_MACROS)
        for p in periphs:
            path = args.out / f"{snake(attr(p,'name'))}.h"
            path.write_text(gen_header(p, args.bf))
            print('Wrote', path)
    else:
        single = args.out / f"{snake(attr(dev,'name'))}_peripherals.h"
        single.write_text(gen_single(dev, periphs, args.bf))
        print('Wrote', single)

    print('Done.')


if __name__ == '__main__':
    main()
