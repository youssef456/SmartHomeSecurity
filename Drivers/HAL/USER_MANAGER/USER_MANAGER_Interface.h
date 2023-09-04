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
#define PASS_LENGTH 5
#define USER_LENGTH 7
#define USER_DATA_LENGTH (PASS_LENGTH + USER_LENGTH)
#define EEPROM_ADDRESS 0x00

// to store number of current users
// check this variable only after calling the retrieveUsers function
volatile u8 numOfUsers;

typedef enum{

	deleteSuccess,
	userFound,
	userNotFound,
	userCreated,
	userLimitExceeded

}status_t;

typedef enum{
	false,
	true


}bool;

typedef struct {

	u8 userName[USER_LENGTH];
	u8 passWord[PASS_LENGTH];
	u8 userId;
	bool isActive;

}userData;

// aray of users to store all active users
userData allUsers[MAXUSERS];


void retrieveUsers();
status_t createUser(userData* newUser);
status_t fetchUser( userData* user);
status_t deleteUser(userData* user);
#endif /* USER_MANAGER_INTERFACE_H_ */
