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

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_



/* Enumeration for motor rotation states: Clockwise (CW), Counter Clockwise (CCW), and Stop (STOP). */
typedef enum{
	CW,
	CCW,
	STOP
}Motor_State;


/* Function Prototypes */
void MOTORDRIVER_void_INIT(u8 Copy_u8_Motor_Driver_Port, u8 Copy_u8_Motor_Driver_IN1_PIN, u8 Copy_u8_Motor_Driver_IN2_PIN);
void Motor_void_Control_Rotaion(Motor_State state,u8 speed);



#endif /* MOTOR_INTERFACE_H_ */
