# STM32 Watch

A minimalist, bare-metal wristwatch built around an STM32L0 microcontroller.
No HAL, no RTOS, no libraries. Just registers.

This is a fully custom PCB watch powered by a CR2032 coin cell, using 12 discrete LEDs arranged like a traditional analog dial. Time is displayed using LED “hands”, with additional modes for voltage, temperature, time setting, and a physics-based pendulum simulation.

## Features

### Core

- Ultra-low-power (STM32 Cortex-M0+)
- Bare-metal firmware
- RTC-based timekeeping using LSE (32.768 kHz)
- 12 discrete LEDs forming a clock dial
- Time-division multiplexing for LED control
- Two buttons for mode switching and wake-up from sleep

### Optional with IMU

- Absolute wrist tilt (AWT) wake-up
- Double tap to change LED brightness
- Pendulum simulation

## Power Consumption

Tested on a CR2032 @ ~2.9V

| Mode | Current | Wakeup |
|:-: | :-: | :---: |
| Active (display on) | ~3mA | - |
| Stop mode (sleep) | 22uA | AWT or Buttons |
| Ultra low power (IMU off) | 5.5uA | Buttons |
| Stop mode, no IMU mounted | 2.3uA | Buttons |

## Hardware

- MCU: STM32L031
- IMU: LSM6DSM
- Timekeeping: built-in RTC with an external 32.768 kHz crystal
- Ambient light sensor (reverse-biased LED)
- Time display: 12 discrete LEDs
- Two push buttons
- Powered by a CR2032 battery

All LEDs are connected to ground through a single 100 Ω resistor, which is acceptable because only one LED is on at a time.

The RST pin has a single 100 nF capacitor, as there is an internal pull-up (~40 kΩ).

The I2C lines have external 10 kΩ pull-ups, but it would likely be possible to use weaker internal pull-ups if the frequency were reduced (not tested).

On the back side of the PCB, there are test points for SWD programming and UART debugging.

## Firmware

This project is intentionally low-level:

* Direct register access only
* No abstraction layers
* Tight control over timing and power
* Interrupt-driven architecture
* Fixed-point arithmetic (Q16.16)

### LED Driving

LEDs are updated in the IRQ handler, which runs every 100 µs. If a hand is to be shown, the LED is turned on at the beginning of its time slot and turned off when `local_step` reaches the hand’s brightness or at the end of the time slot. This approach ensures that only one LED is on at a time, limiting peak current and reducing battery voltage drop.

### Timekeeping

The STM32’s RTC runs on the low-speed external oscillator, and the time can be set by the user. Due to the high ESR of the crystal, the LSE drive strength had to be set to medium-high (`LSEDRV` in `RCC_CSR`).

### Sensors

The two interrupt pins on the LSM6DSM are used to detect double tap and absolute wrist tilt. Double tap is only available when the watch is awake, as it requires a significantly higher sampling rate.

Battery voltage is measured by reading the internal voltage reference and calculating the supply voltage. This works well, but due to the high internal resistance of the battery, the measured value is about 100 mV lower than the actual open-circuit voltage.

Temperature is measured using the IMU if it is enabled, or the internal temperature sensor of the MCU otherwise.

Ambient light sensing is not currently used, but it can be implemented by setting the pin connected to a reverse-biased LED high and then switching it to high-impedance input. The brighter it is, the faster the pin returns to a low state. Unfortunately, in very dark conditions this can take hundreds of milliseconds, which is why it is not used.


## Build System

This project uses a minimal build setup based on `build.c` and a nobuild-style workflow:
[https://github.com/tsoding/nob.h](https://github.com/tsoding/nob.h)

---

### Build

```bash
cd firmware
clang build.c -o build
./build build
```

---

### Build & Flash (ST-LINK + OpenOCD)

```bash
./build flash
```

You can also flash the firmware using STM32CubeProgrammer.

---

## Firmware Size

```
text    data     bss     dec     hex filename
10304     56    4160   14520    38b8 firmware.elf
```
