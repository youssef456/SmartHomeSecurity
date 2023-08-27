/*
 * Bluetooth_Interface.h
 *
 *  Created on: Aug 24, 2023
 *      Author: youse
 */

#include "../USER_MANAGER/USER_MANAGER_Interface.h"
#include "../../../Libraries/STD_Types.h"

#ifndef BLUETOOTH_INTERFACE_H_
#define BLUETOOTH_INTERFACE_H_

typedef enum{
	transmitionSuccess,
	transmitionFailed

}transmitionstatus;


#define null ((void *) 0)
void BluetoothConnection();
void Bluetoothsend();
void BluetoothInit();


#endif /* BLUETOOTH_INTERFACE_H_ */
