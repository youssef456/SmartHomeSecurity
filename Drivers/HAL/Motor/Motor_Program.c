/*
  Motor Driver Control using Atmega32 - Header
  Author: Youssef nagi
  Date: August 24, 2023
*/

# include "Motor_Interface.h"
# include "DIO_Interface.h"

//hbridge
int main(){


	return 0;
}

void motorInit(){
	DIO_void_set_pin_dir(PORTD,PIN0,OUTPUT);
	DIO_void_set_pin_dir(PORTD,PIN1,OUTPUT);

}

void motorTurnRight(){
	DIO_void_set_pin(PORTD,0);
	DIO_void_set_pin(PORTD,1);

}

void motorTurnLeft(){
	DIO_void_set_pin(PORTD,1);
	DIO_void_set_pin(PORTD,0);

}
void StopMotor(){
	DIO_void_set_pin(PORTD,0);
	DIO_void_set_pin(PORTD,0);
}
void BreakMotor(){
	DIO_void_set_pin(PORTD,1);
	DIO_void_set_pin(PORTD,1);
}
