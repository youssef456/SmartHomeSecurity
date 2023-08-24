SIREN Driver for Atmega32 - Version 1.0
Created on: Jul 16, 2023
Created By: Mostafa Gamal

---

Description:

The SIREN driver is designed to control a siren module connected to an Atmega32 microcontroller. It provides functions to initialize the siren, turn it on to generate a continuous sound, and turn it off to stop the sound generation. This driver is intended for use with the Atmega32 microcontroller and is based on the Atmega32 datasheet.

---

Important Notes:

- All data and settings in this driver are based on the Atmega32 datasheet.
- Modifying anything in these files may affect the behavior of the microcontroller.
- It is recommended not to edit anything unless you fully understand the expected behavior.

---

Usage:

1. Include the necessary header files:

#include "SIREN_Interface.h"

2. Initialize the siren using the SIREN_void_INIT function:

SIREN_void_INIT(SIREN_PORT, SIREN_PIN);

Replace SIREN_PORT and SIREN_PIN with the appropriate port and pin values.

3. To turn on the siren and generate a continuous sound, use the SIREN_void_ON function:

SIREN_void_ON();

4. To turn off the siren and stop the sound generation, use the SIREN_void_OFF function:

SIREN_void_OFF();

---

File Structure:

- SIREN_Interface.h: Header file containing function prototypes 
- SIREN_Interface.c: Source file containing the implementation of the driver functions.
---

Dependencies:

This driver relies on the following libraries and modules:

- STD_Types.h: Standard types and definitions.
- bit_calc.h: Bit manipulation macros.
- DIO_Interface.h: DIO (Digital Input/Output) module for controlling pins.
- TIMERS_Config.h and TIMERS_Interface.h: Timer modules for managing time-based operations.

---
