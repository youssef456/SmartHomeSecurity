/*
 * USER_MANAGER_Program.c
 *
 *  Created on: Aug 23, 2023
 *      Author: karim
 */

#include "../../../Libraries/STD_Types.h"
#include "../../../Libraries/bit_calc.h"

#include "../../MCAL/INTERNAL_EEPROM/Eeprom_Interface.h"
#include "../../HAL/USER_MANAGER/USER_MANAGER_Interface.h"


status_t deleteUser(userData* user){

	/*
	 *  Function Deletes the user based on their user index
	 *  with userId bounds from 0 ~ 9 (10 USERS)
	 *
	 */
	status_t deleteStatus;

	if(user->userId < MAXUSERS){

		//create a blank user to erease the original user data from the eeprom
		userData blankUser = {{0},{0},0,false};
		eepromWriteBytes(user->userId*sizeof(userData),(u8*)&blankUser, sizeof(userData));
		deleteStatus = deleteSuccess;

	}else{

		// User not found
		deleteStatus = userNotFound;

	}

	return deleteStatus;
}

void retrieveUsers(){

	//reset the num of users to 0
	numOfUsers = 0;

	for(u8 i = 0; i< MAXUSERS; i++){
		userData user;
		user.userId = i;
		fetchUser(&user);
		if(user.userId != NOT_CREATED && user.isActive == true){

			//store current user in the global array
			allUsers[numOfUsers] = user;
			numOfUsers++;

		}


	}



}


status_t createUser(userData* newUser){

	// index is used to map the positions of the 10 users accross the eeprom

	/*
	 *  size of userdata is 11 bytes if index = 0 , address will be 0x00
	 *  if user created then the next index is 1 hence the address will be
	 *  1 x 11 = 0x0b and like this until the 10 users are mapped.
	 *
	 */
		status_t creationStatus;

	if(newUser->userId < MAXUSERS){

		eepromWriteBytes((newUser->userId * sizeof(userData)),(u8*)newUser, sizeof(userData));
		// user created successfuly
		creationStatus = userCreated;
	}else{

		creationStatus = userLimitExceeded;
	}

	return creationStatus;
}


status_t fetchUser(userData* user){

	/*
	 *  Same logic as CreateUser Function but here we perfom a reading operation
	 *  on the desired user
	 *
	 */

	status_t fetchStatus;

	if(user->userId < MAXUSERS){

		eepromReadBytes((user->userId * sizeof(userData)),(u8*)user, sizeof(userData));
		// user found
		fetchStatus = userFound;

	}else{

		// user limit exceeded (user not found)

		fetchStatus = userNotFound;

	}
}
