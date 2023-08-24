/*
 * USER_MANAGER_Interface.h
 *
 *  Created on: Aug 23, 2023
 *      Author: karim
 */

#ifndef USER_MANAGER_INTERFACE_H_
#define USER_MANAGER_INTERFACE_H_

#define NOT_CREATED 255
#define MAXUSERS 10
#define PASS_LENGTH 4
#define USER_LENGTH 6
#define USER_DATA_LENGTH (PASS_LENGTH + USER_LENGTH)
#define EEPROM_ADDRESS 0x00
//global vars

u8 numOfUsers;

typedef enum{
	true,
	false
}bool;

typedef struct {

	u8 userName[2];
	u8 passWord[2];
	u8 userId;
	bool isActive;

}userData;

// aray of users to store all active users
userData allUsers[MAXUSERS];


void retreiveUsers();
void createUser(u8 index ,userData* newUser);
void fetchUser(u8 index, userData* user);
void deleteUser(u8 index);
#endif /* USER_MANAGER_INTERFACE_H_ */
