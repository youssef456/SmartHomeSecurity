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


/* Standard Library */

#include "../../../Libraries/STD_Types.h"
#include "../../../Libraries/bit_calc.h"



/* Private Libraries */

#include "../LAMB/LAMB_Interface.h"

/* MCAL libraries */

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Registers.h"

/*
 * Struct to store configuration information about a Lamb.
 * Contains the port and pin numbers associated with the Lamb.
 */
typedef struct {
    u8 port;  // Port number for the Lamb
    u8 pin;   // Pin number within the port for the Lamb
} lambConfig;

/*
 * Array to hold configurations for multiple Lambs.
 * This array stores the lambConfig structs for each Lamb instance.
 */
static lambConfig lambs[MAX_LAMBS];


void LAMB_u8_INIT(u8 lambIndex, u8 Copy_u8_Lamb_Port, u8 Copy_u8_Lamb_Pin) {
	/*
	 * Initialize a Lamb configuration at a specified index with port and pin information.
	 */
    if (lambIndex < MAX_LAMBS) {
        lambs[lambIndex].port = Copy_u8_Lamb_Port;
        lambs[lambIndex].pin = Copy_u8_Lamb_Pin;
        DIO_void_set_pin_dir(Copy_u8_Lamb_Port, Copy_u8_Lamb_Pin, OUTPUT);
    }
}




void LAMB_u8_Turn_ON(u8 lambIndex) {
	/*
	 *Turn on a specific Lamb indicated by its index.(Starting from 0 to MAX_LAMBS)
	 */
	DIO_void_set_pin(lambs[lambIndex].port, lambs[lambIndex].pin);
}

void LAMB_u8_Turn_OFF(u8 lambIndex) {
	/*
	 * Turn on a specific Lamb indicated by its index.(Starting from 0 to MAX_LAMBS)
	 */
	DIO_void_clear_pin(lambs[lambIndex].port, lambs[lambIndex].pin);
}


