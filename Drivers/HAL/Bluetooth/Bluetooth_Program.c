/*
 * Bluetooth_Program.c
 *
 *  Created on: Aug 24, 2023
 *      Author: youse
 */
#include "UART_Interface.h"
#include "Bluetooth_Interface.h"
#include "STD_Types.h"

u8 rxdata;
u8 loggedin = 0;

int main(){
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
				u8 username = UART_Receive_char();
				UART_Transmit_String("Enter User Password\n");
				u8 password = rxdata = UART_Receive_char();

			}
			else if(rxdata =='B')
			{
				UART_Transmit_String("Enter User Name\n");
				u8 username = UART_Receive_char();
				UART_Transmit_String("Enter User Password\n");
				u8 password = rxdata = UART_Receive_char();
			}
			else if(rxdata =='C')
			{
				UART_Transmit_String("Enter User Name\n");
				u8 username = UART_Receive_char();
				UART_Transmit_String("Enter User Password\n");
				u8 password = rxdata = UART_Receive_char();
			}
		}else{
			UART_Transmit_String("Choose an action\n");
			UART_Transmit_String("A- open Door\n");
			UART_Transmit_String("B- Close Door\n");
			UART_Transmit_String("C- Turn Siren On\n");
			UART_Transmit_String("D- Turn Siren ff\n");
			if(rxdata == 'A')
			{
				//opendoor
			}
			else if(rxdata =='B')
			{
				//closedoor
			}
			else if(rxdata =='C')
			{
				//turnondiren
			}
			else if(rxdata =='D')
			{
				//turnoffsiren

		}
	}

}
   return 0;
}
