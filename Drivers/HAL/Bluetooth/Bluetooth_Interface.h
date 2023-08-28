/*
 * Bluetooth_Interface.h
 *
 *  Created on: Aug 24, 2023
 *      Author: youse
 */



#ifndef BLUETOOTH_INTERFACE_H_
#define BLUETOOTH_INTERFACE_H_


void bluetoothInit();
void bluetoothSendMessage(u8* copy_u8_msg);
void bluetoothReceiveMessage(u8* arr , u8 size);

#endif /* BLUETOOTH_INTERFACE_H_ */
