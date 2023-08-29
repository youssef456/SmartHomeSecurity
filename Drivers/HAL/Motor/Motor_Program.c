/**********************************************************************/
/*                      Created on: AUG 28, 2023                      */
/*                      Created By: Youssef Nagy                      */
/*       		 SIREN driver for Atmega32  Version 1.0               */
/**********************************************************************/
/* NOTE: all the data in this file is based on the atmega32 datasheet */
/*       editing anything in these files will affect the MCU behavior */
/*       i dont recommend editing anything unless you know            */
/*          what you're doing and the expected behavior               */
/**********************************************************************/

// standard libs
#include "Libraries/STD_Types.h"
#include "Libraries/bit_calc.h"

//private
#include "MOTOR_Interface.h"

//MCAL
#include "DIO_Interface.h"
#include "DIO_Registers.h"
#include "TIMERS_Config.h"
#include "TIMERS_Interface.h"
#include "TIMERS_Private.h"

// Static variables to store motor driver port and pins
static u8 motorPort, motorIN1, motorIN2;

// Internal function to start PWM using TIMER0
static void PWM_TMR0_START(u8 Duty_Cycle) {
    /*
     * The PWM_TMR0_START function initializes TIMER0 in Fast PWM mode,CLK/8,and OCR0 clear
     * to control the speed of the motor driver based on the given duty cycle.
     * This function will only be used inside this source file.
     * Dont use it in your main code!
     */

    TMR0_Init();
    DIO_void_set_pin_dir(PORTB,PIN3,OUTPUT);
    TMR0_loadTCNT0(0);
    TMR0_loadOCR0(((u16)(((u32)Duty_Cycle * 255) / 100)));
}


void MOTORDRIVER_void_INIT(u8 Copy_u8_Motor_Driver_Port, u8 Copy_u8_Motor_Driver_IN1_PIN, u8 Copy_u8_Motor_Driver_IN2_PIN){
    /*
     * The MOTOR_void_INIT function initializes the motor driver module.
     * It configures the necessary settings for controlling the motor.
     *
     * This function sets up the specified port and pins for controlling the motor's
     * direction and initializes them as output pins. It also ensures that the motor
     * is initially stopped by setting both direction control pins to low.
     */
	motorPort = Copy_u8_Motor_Driver_Port;
	motorIN1 = Copy_u8_Motor_Driver_IN1_PIN;
	motorIN2 = Copy_u8_Motor_Driver_IN2_PIN;

	DIO_void_set_pin_dir(motorPort,motorIN1,OUTPUT);
	DIO_void_set_pin_dir(motorPort,motorIN2,OUTPUT);

	DIO_void_clear_pin(motorPort,motorIN1);
	DIO_void_clear_pin(motorPort,motorIN2);
}



void Motor_void_Control_Rotaion(Motor_State state,u8 speed){
	/*
	 *  * This function controls the rotation of the motor based on the specified
	 * direction and speed. It configures the necessary pins to control the motor's
	 * direction and starts a PWM signal to adjust the motor's speed.
	 *
	 * state: The desired motor rotation state (CW, CCW, STOP).
	 * speed: The speed of the motor rotation (0 to 100).
	 */
	switch(state){
	case CW:
		DIO_void_set_pin(motorPort,motorIN1);
		DIO_void_clear_pin(motorPort,motorIN2);
		break;
	case CCW:
		DIO_void_clear_pin(motorPort,motorIN1);
		DIO_void_set_pin(motorPort,motorIN2);
		break;
	case STOP:
		DIO_void_clear_pin(motorPort,motorIN1);
		DIO_void_clear_pin(motorPort,motorIN2);
		break;
	default:
		DIO_void_clear_pin(motorPort,motorIN1);
		DIO_void_clear_pin(motorPort,motorIN2);
		break;
	}
	  if (0 <= speed && speed <= 100){
		  PWM_TMR0_START(speed);
	  }
}


