#define NOB_IMPLEMENTATION
#include "nob.h"

#include <stdio.h>
#include <string.h>


#if 1
#define CLANG
#warning Using Clang!!!
#endif

#ifndef CLANG

#define CROSS "arm-none-eabi-"
#define CC CROSS"gcc"
#define OBJCOPY CROSS"objcopy"
#define OBJDUMP CROSS"objdump"
#define GDB CROSS"gdb"

#define EXTRA_LDFLAGS "-nostartfiles", "-lnosys"
// #define EXTRA_LDFLAGS "-nostartfiles", "-lgcc"

#else

#ifdef _WIN32
#define CC "C:/clang/bin/clang.exe"
#define OBJCOPY "C:/clang/bin/llvm-objcopy"
#define OBJDUMP "C:/clang/bin/llvm-objdump"
#else
#define CC "clang"
#define OBJCOPY "llvm-objcopy"
#define OBJDUMP "llvm-objdump"
#endif

#define GDB "arm-none-eabi-gdb"

#define EXTRA_FLAGS "--target=arm-none-eabi", "-fno-builtin"
// #define EXTRA_LDFLAGS "-lgcc"

#endif

#define OPT "-O2"

#define BASE_FLAGS "-std=c99", "-mcpu=cortex-m0plus", "-mthumb", "-fno-strict-aliasing", "-ffreestanding", "-mfloat-abi=soft", "-fno-math-errno"

#ifdef EXTRA_FLAGS
#define FLAGS BASE_FLAGS, EXTRA_FLAGS
#else
#define FLAGS BASE_FLAGS
#endif

#define CFLAGS FLAGS, OPT, "-Iinclude", "-fno-common", "-fno-builtin", "-g", "-Wall", "-Werror", "-Wextra", "-Wno-unused-function"

#define DEFAULT_LDFLAGS "-Tlink.ld", "-nostdlib"

#ifdef EXTRA_LDFLAGS
#define LDFLAGS FLAGS, DEFAULT_LDFLAGS, EXTRA_LDFLAGS
#else
#define LDFLAGS FLAGS, DEFAULT_LDFLAGS
#endif

// openocd -f interface/stlink.cfg -c "transport select hla_swd" -f target/stm32wlx.cfg -c "reset_config srst_only connect_assert_srst"

Nob_Cmd cmd = {0};

int build(void) {
    nob_cmd_append(&cmd, CC, CFLAGS, "-c", "boot.c", "-o", "boot.o");
    if (!nob_cmd_run(&cmd)) return 1;
    nob_cmd_append(&cmd, CC, CFLAGS, "-c", "rt.c", "-o", "rt.o");
    if (!nob_cmd_run(&cmd)) return 1;
    nob_cmd_append(&cmd, CC, CFLAGS, "-c", "rt_asm.S", "-o", "rt_asm.o");
    if (!nob_cmd_run(&cmd)) return 1;
    nob_cmd_append(&cmd, CC, CFLAGS, "-c", "main.c", "-o", "main.o");
    if (!nob_cmd_run(&cmd)) return 1;
    nob_cmd_append(&cmd, CC, LDFLAGS, "boot.o", "rt.o", "rt_asm.o", "main.o", "-o", "firmware.elf");
    if (!nob_cmd_run(&cmd)) return 1;

    return 0;
}

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);



    if (argc < 2) {
        printf("build <target>\ntargets:\n\tbuild: Build the project\n");
        return 0;
    }

    if (strcmp(argv[1],"build") == 0) {
        return build();
    } else if (strcmp(argv[1],"flash") == 0) {
        if (build()) return 1;

        nob_cmd_append(&cmd, "openocd", "-f", "interface/stlink.cfg", "-c", "transport select hla_swd", "-f", "target/stm32l0.cfg", "-c", "program firmware.elf verify reset exit");
        if (!nob_cmd_run(&cmd)) return 1;
    } else if (strcmp(argv[1],"openocd") == 0) {
        nob_cmd_append(&cmd, "openocd", "-f", "interface/stlink.cfg", "-c", "transport select hla_swd", "-f", "target/stm32l0.cfg", "-c", "reset_config srst_only connect_assert_srst");
        if (!nob_cmd_run(&cmd)) return 1;
    } else if (strcmp(argv[1],"gdb") == 0) {
        nob_cmd_append(&cmd, GDB, "firmware.elf");
        nob_cmd_append(&cmd, "-ex", "target remote :3333");
        nob_cmd_append(&cmd, "-ex", "monitor reset halt");
        nob_cmd_append(&cmd, "-ex", "load");
        nob_cmd_append(&cmd, "-ex", "compare-sections");
        nob_cmd_append(&cmd, "-ex", "monitor reset run");
        if (!nob_cmd_run(&cmd)) return 1;
    } else {
        printf("Unkown target: %s\n", argv[1]);
        return -1;
    }
}