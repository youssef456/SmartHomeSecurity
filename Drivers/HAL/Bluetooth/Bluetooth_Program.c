/*
 * Bluetooth_Program.c
 *
 *  Created on: Aug 28, 2023
 *      Author: karim
 */

// std libs
#include "util/delay.h"
#include "../../../Libraries/STD_types.h"
#include "../../../Libraries/bit_calc.h"

//Mcal
#include "../../../Drivers/MCAL/UART/UART_Interface.h"



void bluetoothInit(){

	/*
	 *  initialize the bluetooth module and the uart Communitcation
	 *
	 */

	UART_Init();

}


void bluetoothSendMessage(u8* copy_u8_msg){


	/*
	 *  function transmit a string through the bluetooth module (uart protocol)
	 *
	 *
	 *
	 */

	UART_Transmit_String(copy_u8_msg);

}


void bluetoothReceiveMessage(u8* arr , u8 size){


	/*
	 * function receives a message through the bluetooth module (uart protocol)
	 *
	 *	function should be given the total array size (make sure to leave space for
	 *	the null terminator \0
	 *
	 *	ex:  u8 myArray[6];
	 *
	 *		bluetoothReceiveMessage(myArray, sizeof(myArray));
	 */



	UART_Receive_String(arr, size);


}


