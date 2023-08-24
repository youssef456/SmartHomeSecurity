/*
 * USER_MANAGER_Program.c
 *
 *  Created on: Aug 23, 2023
 *      Author: karim
 */

#include "../../../Libraries/bit_calc.h"
#include "../../../Libraries/STD_Types.h"

#include "../../../Drivers/MCAL/INTERNAL_EEPROM/Eeprom_Interface.h"
#include "USER_MANAGER_Interface.h"


void deleteUser(userData* user){

	/*
	 *  Function Deletes the user based on their user index
	 *  with userId bounds from 0 ~ 9 (10 USERS)
	 *
	 */

	if(user->userId < MAXUSERS){

		//create a blank user to erease the original user data from the eeprom
		userData blankUser = {{0},{0},0,false};
		eepromWriteBytes(user->userId*sizeof(userData),(u8*)&blankUser, sizeof(userData));

	}


}

void retreiveUsers(){

	//reset the num of users to 0
	numOfUsers = 0;

	for(u8 i = 0; i< MAXUSERS; i++){
		userData user;
		fetchUser(i, &user);
		if(user.userId != NOT_CREATED && user.isActive == true){

			//store current user in the global array
			allUsers[numOfUsers] = user;
			numOfUsers++;

		}


	}



}


void createUser(userData* newUser){

	// index is used to map the positions of the 10 users accross the eeprom

	/*
	 *  size of userdata is 11 bytes if index = 0 , address will be 0x00
	 *  if user created then the next index is 1 hence the address will be
	 *  1 x 11 = 0x0b and like this until the 10 users are mapped.
	 *
	 */
	eepromWriteBytes((newUser->userId * sizeof(userData)),(u8*)newUser, sizeof(userData));


}


void fetchUser(userData* user){

	/*
	 *  Same logic as CreateUser Function but here we perfom a reading operation
	 *  on the desired user
	 *
	 */
	eepromReadBytes((user->userId * sizeof(userData)),(u8*)user, sizeof(userData));

}
