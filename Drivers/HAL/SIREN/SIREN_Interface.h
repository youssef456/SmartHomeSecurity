/**********************************************************************/
/*                      Created on: Jul 16, 2023                      */
/*                      Created By: Mostafa Gamal                     */
/*       		 SIREN driver for Atmega32  Version 1.0               */
/**********************************************************************/
/* NOTE: all the data in this file is based on the atmega32 datasheet */
/*       editing anything in these files will affect the MCU behavior */
/*       i dont recommend editing anything unless you know            */
/*          what you're doing and the expected behavior               */
/**********************************************************************/

#ifndef SIREN_INTERFACE_H_
#define SIREN_INTERFACE_H_

/* Functions Prototypes */

void SIREN_void_INIT(u8 Copy_u8_Siren_Port, u8 Copy_u8_Siren_Pin);
void SIREN_void_ON(void);
void SIREN_void_OFF(void);

#endif /* SIREN_INTERFACE_H_ */
