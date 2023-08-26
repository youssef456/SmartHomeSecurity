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

void userManager(u8 username[USER_LENGTH], u8 password[PASS_LENGTH], u8 action);
void BluetoothConnection();
#endif /* BLUETOOTH_INTERFACE_H_ */
