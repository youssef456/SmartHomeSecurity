/*
 * Bluetooth_Program.c
 *
 *  Created on: Aug 24, 2023
 *      Author: youse
 */
#include "../../MCAL/UART/UART_Interface.h"
#include "../USER_MANAGER/USER_MANAGER_Interface.h"
#include "../SIREN/SIREN_Interface.h"
#include "../Motor/Motor_Interface.h"
#include "../../../Libraries/STD_Types.h"

#include "Bluetooth_Interface.h"

u8 rxdata;
u8 loggedin = 0;
u8 username[USER_LENGTH];
u8 password[PASS_LENGTH];

void BluetoothConnection(){
	UART_Init();

	while(1)
	{
		rxdata  = UART_Receive_char();
		if (loggedin == 0){
			UART_Transmit_String("Choose an action\n");
			UART_Transmit_String("A- Create user\n");
			UART_Transmit_String("B- Login\n");
			UART_Transmit_String("C-Delete user\n");
			if(rxdata == 'A')
			{
				UART_Transmit_String("Enter User Name\n");
				UART_Receive_String(&username);
				UART_Transmit_String("Enter User Password\n");
				UART_Receive_String(&password);

			}
			else if(rxdata =='B')
			{
				UART_Transmit_String("Enter User Name\n");
				UART_Receive_String(&username);
				UART_Transmit_String("Enter User Password\n");
				UART_Receive_String(&password);
			}
			else if(rxdata =='C')
			{
				UART_Transmit_String("Enter User Name\n");
				UART_Receive_String(&username);
				UART_Transmit_String("Enter User Password\n");
				UART_Receive_String(&password);
			}
		}else{
			UART_Transmit_String("Choose an action\n");
			UART_Transmit_String("A- open Door\n");
			UART_Transmit_String("B- Close Door\n");
			UART_Transmit_String("C- Turn Siren On\n");
			UART_Transmit_String("D- Turn Siren ff\n");
			if(rxdata == 'A')
			{
				motorTurnRight();
			}
			else if(rxdata =='B')
			{
				motorTurnLeft();
			}
			else if(rxdata =='C')
			{
				SIREN_void_ON();
			}
			else if(rxdata =='D')
			{
				SIREN_void_OFF();

		}
	}

}
}

void userManager(u8 username[USER_LENGTH], u8 password[PASS_LENGTH], u8 action){
	userData user;
	user.userName[USER_LENGTH] = username[USER_LENGTH];
	user.passWord[PASS_LENGTH] = password[PASS_LENGTH];
	user.isActive = 1;
	switch(action){
	case 1:
		createUser(&user);
		break;
	case 2:
		fetchUser(&user);
		break;
	case 3:
		deleteUser(&user);
		break;
	default:
		break;
	}

}
