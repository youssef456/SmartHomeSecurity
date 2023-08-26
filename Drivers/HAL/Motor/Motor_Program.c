/*
  Motor Driver Control using Atmega32 - Header
  Author: Youssef nagi
  Date: August 24, 2023
*/

#include "Motor_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMERS/TIMERS_Interface.h"

void motorInit(){
	DIO_void_set_pin_dir(PORTD,PIN0,OUTPUT);
	DIO_void_set_pin_dir(PORTD,PIN1,OUTPUT);

}

void motorTurnRight(){
	DIO_void_set_pin(PORTD,0);
	DIO_void_clear_pin(PORTD,1);

}

void motorTurnLeft(){
	DIO_void_clear_pin(PORTD,0);
	DIO_void_set_pin(PORTD,1);

}
void StopMotor(){
	DIO_void_clear_pin(PORTD,0);
	DIO_void_clear_pin(PORTD,1);
}
void BreakMotor(){
	DIO_void_set_pin(PORTD,0);
	DIO_void_set_pin(PORTD,1);
}
