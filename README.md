# STM32 Watch:
This project is about maing a PCB watch that is based around an STM32, runs on a CR2032 battery, and displays time with 12 leds aranged in a circle. (Kinda like mechanical watches do)

The goal is to learn more about PCB desing, STM32 enviorment and low-power features.

## Rev: A

### Features
* Powered by a CR2032
* STM32 MCU with SWD & UART communication
* The watch has two buttons
* Time is displayed through 12 leds arranged on a circle
* Ambiend light sensing
* IMU can be set into low-power and acceleratin can be read
* Wrist up interrupt detection
* Gesture control

### Buttons funcions
* Wake up from standby
* Time can be set
* Battery voltage can be checked
* Brightnes can be changed (1 - 2 - 3 - auto)
* Particle sim with a single LED showing a particle that reacts to watch acceleration
* MCU and IMU tmeperature can be checked


### UI
* BTN Upper - Brightness control / Confirm / Next
* BTN Lower - Change Mode
* Wake up - Wrist up / Tap / Double Tap / Button press

#### Time Display
* Hour - Solid, Minute - Slow Breathing, Second - Fast Breathing
* BTN Upper -> Change brightness (1, 2, 3, auto)
* BTN Lower -> Next mode (Stats)

#### Stats
* Battery voltage: VBAT[V] = 2 + LED_index / 10 (2V->3.2V)
* Temperature: T[°C] = 5 * LED_index (0°C->60°C)
* BTN Upper -> Next statistic
* BTN Lower -> Next mode (Time Setting)

#### Time Setting
* H/M/S: Current H/M/S shown with a single LED. Can changed with the buttons
* BTN Upper -> Enter time setting / Confirm time & Switch to the next variable. If seconds confirmed => Time Display
* BTN Lower -> Next mode (Particle Sim) / Increament current variable (hold for fast increment)

#### Particle Sim (For fun)
* Single LED reactive to watch accleration imitating physical particle
* BTN Upper -> Change brightness (1, 2, 3, auto)
* BTN Lower -> Next mode (Time Display)