# STM32 Watch
<img width="550" height="510" alt="image" src="https://github.com/user-attachments/assets/adb3dd84-9512-466d-9a0b-b8bb77398ba6" />

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

## Modes

### Time display

- Hour hand: Static LED
- Minute hand: Slow fade in and out
- Subminutes (full rotation every 5min) hand: Quick fade in and out

### Statistics (Battery voltage, IMU/MCU temperature)

Battery voltage = Hour / 10 + 2V

(If hour hand is at 9 the battery voltage is 0.9V + 2V = 2.9V)

IMU/MCU temperature = Hour * 5°C + Minute * 0.1°C

(If hour hand is at 4 and minute hand is at 35 the temperature is 4*5°C + 35*0.1°C = 23.5°C)


### Time setting

Hour hand running in a circle indicated you are in the time setting mode.
Press Upper button to go into hour setting then press lower button to move the hour hand form 12 to 1, 2, 3 up to the current time. Confirm with the Upper button. Reapeat for minutes. After confirming minutes the watch will go back to Time display mode.

### Pendulum simulation

If the LEDs at 3 and 9 blink the IMU is disabled. You can enable it by pressing both buttons at once. This will enable the IMU and change mode to Time display.

IF the IMU is enbaled ther hour hand will behave like a pendulum with very low friction. I reacts to the acceleration vector in the XY plane so either tilting or moving the watch arround can cause the hour hand to move.

By double tapping the watch you can add 5 rotations a seconds to the pendulum in the current rotation direction.

If you wanna disalbe the IMU just press both buttons at once. The watch will disable the IMU and go back to the Time display mode.

## Mode changing

| *Current Mode* | *Action* | *Effect* |
|:-: | :-: | :- |
| Time display | Upper button | Change brightness |
| Time display | Double tap | Change brightness (if IMU enabled) |
| Time display | Lower button | Change mode to Stats (battery voltage) |
| Statistics | Upper button | Cycle stats (voltage/temperature) |
| Statistics | Lower button | Change mode to Time setting |
| Time setting | Upper button | Set hour/minute or confirm and change mode to Time display |
| Time setting | Lower button | Change mode to Pendulum simulation or increment hour/minute hand |
| Pendulum simulation | Upper button | Change brightness |
| Pendulum simulation | Double tap | Add +/- 5 rotations/second to the pendulum speed |
| Pendulum simulation | Upper & Lower buttons | Enable/Disable IMU (All the IMU features won't work if the IMU is disabled) |
| Pendulum simulation | Lower button | Change mode to Time display |

## Power Consumption

Tested on a CR2032 @ ~2.9V

| *Mode* | *Current* | *Wakeup* |
|:-: | :-: | :-: |
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

<img width="500" height="549" alt="image" src="https://github.com/user-attachments/assets/834a7873-24d1-477f-8f74-5b5cd947f12e" />
<img width="500" height="549" alt="IMG_4101" src="https://github.com/user-attachments/assets/f59391d3-52ff-4921-98b7-3f072621f65f" />

<img width="332" height="444" alt="IMG_4097" src="https://github.com/user-attachments/assets/fd066a6f-1798-40fe-af9e-7129ccd4bbab" />
<img width="332" height="444" alt="IMG_4099" src="https://github.com/user-attachments/assets/74d63b61-c85f-460e-bb64-6c354a5a50cd" />
<img width="332" height="444" alt="IMG_4100" src="https://github.com/user-attachments/assets/b4dea928-5fc9-495e-9a0b-eb06f8b9351d" />


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
