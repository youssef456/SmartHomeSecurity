/*
 * Bluetooth_Interface.h
 *
 *  Created on: Aug 24, 2023
 *      Author: youse
 */

#ifndef BLUETOOTH_INTERFACE_H_
#define BLUETOOTH_INTERFACE_H_

void usart_init(void);
void sendbyte(unsigned char);
void sendstr(unsigned char *);
unsigned char receivebyte(void);
void receivestr(unsigned char*);

#endif /* BLUETOOTH_INTERFACE_H_ */
