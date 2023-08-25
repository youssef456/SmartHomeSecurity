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

/* Standard Library */

#include "../../../Libraries/STD_Types.h"
#include "../../../Libraries/bit_calc.h"

/* Private libraries */
#include "../SIREN/SIREN_Interface.h"

//MCAL
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMERS/TIMERS_Config.h"
#include "../../MCAL/TIMERS/TIMERS_Interface.h"
#include "../../MCAL/TIMERS/TIMERS_Private.h"

// Static variables to store siren port and pin
static u8 sirenPort, sirenPin;



static void Siren_Timer(void){
    /*
     * The Siren_Timer function is an internal callback function used
     * as a TIMER2 overflow interrupt handler to control the siren.
     * The siren pin state is toggled approximately every 0.5 second.
     * function will only be used inside this source file
     *  do you not use it in your code!
     */
	static u16 ovfCounter =0;
	ovfCounter++;
	if(ovfCounter==1954){
		ovfCounter=0;
		TMR2_loadTCNT2(224);
		DIO_void_toggle_pin(sirenPort,sirenPin);
	}

}

void SIREN_void_INIT(u8 Copy_u8_Siren_Port, u8 Copy_u8_Siren_Pin) {
    /*
     * The SIREN_void_INIT function initializes the siren module.
     * It configures the necessary settings to enable the siren sound.
     */

    // Store the siren port and pin for internal use
    sirenPin = Copy_u8_Siren_Pin;
    sirenPort = Copy_u8_Siren_Port;

    TMR2_Init();
    TMR2_loadTCNT2(224);  // Set initial timer counter value

    DIO_void_set_pin_dir(Copy_u8_Siren_Port, Copy_u8_Siren_Pin, OUTPUT);
}



void SIREN_void_ON(void) {
    /*
     * The SIREN_void_ON function turns on the siren to generate a continuous sound.
     * It sets up a timer callback function to control the siren sound.
     */

    Timer_set_Callback_Func(TIMER2_OVF, Siren_Timer);
}


void SIREN_void_OFF(void) {
    /*
     * The SIREN_void_OFF function turns off the siren to stop generating the sound.
     * It clears the siren pin to halt the sound generation.
     */

    DIO_void_clear_pin(sirenPort, sirenPin);
}
