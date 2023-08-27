/*
 * Bluetooth_Program.c
 *
 *  Created on: Aug 24, 2023
 *      Author: youse
 */
#include "../../MCAL/UART/UART_Interface.h"
#include "../USER_MANAGER/USER_MANAGER_Interface.h"
#include "../SIREN/SIREN_Interface.h"
#include "../LAMB/LAMB_Interface.h"
#include "../Motor/Motor_Interface.h"
#include "../../../Libraries/STD_Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Bluetooth_Interface.h"

void BluetoothInit(){
	UART_Init();
}

transmitionstatus Bluetoothsend(u8* copy_string){
	if (copy_string == null){
		return transmitionSuccess;
	}
	else{
		UART_Transmit_String(copy_string);
		return transmitionFailed;
	}
}

transmitionstatus BluetootRecieve(u8* arr){
	UART_Receive_String(arr);
	if (arr == null){
		return transmitionSuccess;
	}else{
		return transmitionFailed;

	}
}
