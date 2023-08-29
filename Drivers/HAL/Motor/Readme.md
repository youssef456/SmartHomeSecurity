Motor Driver Module README
==========================

Author: Mosta

Table of Contents:
-------------------
1. Introduction
2. Motor Driver Configuration
3. How to Use the Motor Driver
4. Example Program

1. Introduction:
-----------------
This README provides information on how to use the motor driver module, which controls the rotation direction and speed of a motor using a motor driver chip. The module allows you to easily configure and control the motor's behavior.

2. Motor Driver Configuration:
-------------------------------
The motor driver module uses a motor driver chip to control the motor's rotation direction. It requires the following configurations:

- Two control pins (IN1 and IN2) connected to the motor driver chip.
- TIMER0 configured for Fast PWM mode to control the motor's speed.

3. How to Use the Motor Driver:
-------------------------------
To use the motor driver module, follow these steps:

3.1 Initialization:
-------------------
Call the `MOTORDRIVER_void_INIT` function to initialize the motor driver module. This function configures the control pins and sets them to their default state.

Example:
```c
MOTORDRIVER_void_INIT(PORTC, PIN0, PIN1);  // Initialize with PORTC, IN1 on PIN0, IN2 on PIN1
3.2 Control Motor Rotation:
Use the Motor_void_Control_Rotation function to control the rotation of the motor. Provide the desired rotation state (CW, CCW, or STOP) and the desired speed (0 to 100).

Example:
Motor_void_Control_Rotation(CW, 75);  // Rotate clockwise at 75% speed

Example Program:
Here's an example program that demonstrates the usage of the motor driver module:

#include "Libraries/STD_Types.h"
#include "MOTOR_Interface.h"
#include "DIO_Interface.h"

int main(void) {
    MOTORDRIVER_void_INIT(PORTC, PIN0, PIN1);  // Initialize motor driver with PORTC, IN1 on PIN0, IN2 on PIN1

    while (1) {
        Motor_void_Control_Rotation(CW, 50);  // Rotate clockwise at 50% speed
        _delay_ms(2000);  // Wait for 2 seconds

        Motor_void_Control_Rotation(CCW, 75); // Rotate counter-clockwise at 75% speed
        _delay_ms(2000);  // Wait for 2 seconds

        Motor_void_Control_Rotation(STOP, 0); // Stop the motor
        _delay_ms(2000);  // Wait for 2 seconds
    }

    return 0;
}


Note: Adjust the PORT and PIN configurations according to your hardware setup.

For more details, refer to the comments in the source code and the MOTOR_Interface.h header file.

Feel free to contact the author if you have any questions or need further assistance.


Feel free to customize the example program and README to match your hardware setup and preferences.

