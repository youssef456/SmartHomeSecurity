/**********************************************************************/
/*                      Created on: Aug 23, 2023                      */
/*                      Created By: Mostafa Gamal                     */
/*                Lamb driver for Atmega32  Version 1.0               */
/**********************************************************************/
/* NOTE: all the data in this file is based on the atmega32 datasheet */
/*       editing anything in these files will affect the MCU behavior */
/*       i dont recommend editing anything unless you know            */
/*          what you're doing and the expected behavior               */
/**********************************************************************/


#ifndef LAMB_INTERFACE_H_
#define LAMB_INTERFACE_H_

#define MAX_LAMBS 3 // Adjust this based on the number of Lambs you want to support


/* Function declaration */
void LAMB_u8_INIT(u8 LambIndex, u8 Copy_u8_Lamb_Port, u8 Copy_u8_Lamb_Pin);
void LAMB_u8_Turn_ON(u8 LambIndex);
void LAMB_u8_Turn_OFF(u8 LambIndex);


#endif /* LAMB_INTERFACE_H_ */
