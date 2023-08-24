
# User Manager

This module provides user management functionalities for the ATmega32 microcontroller using the internal EEPROM (HAL LAYER)

## Features

- Create a new user with a username, password, and user ID.
- Retrieve user information based on the user ID.
- Delete a user by marking their data as inactive and erasing it from EEPROM.\

All Data are Written in the internal Eeprom and managed accordingly. 

## Usage

- You can create users by Creating an object of the userData Struct

````c
typedef struct {

	u8 userName[USER_LENGTH];
	u8 passWord[PASS_LENGTH];
	u8 userId;
	bool isActive;

}userData;
````
 - USER_LENGTH & PASS_LENGTH Are predefind Macros with the Username and Password Length
 - userID is variable used to track the number of users and also used for memory Mapping. (available values from 0 to (MAXUSERS-1)
 
- isActive is a bool used to check the status of the user make it true when creating a new user.

for example
````c
userData newUser = {{"jack"},{"1234"},0,true};
````
## Functions 

- `status_t createUser(userData* newUser);` 
- `status_t fetchUser( userData* user);`
- `status_t deleteUser(userData* user);`
- `void retrieveUsers();`
 
 ### How to use the functions?
 
 After creating a user `useradata newUser ={{"jack"},{"1234"},0,true;`
 
 - Call the createUser Function `status_t createUser(&newUser);`
 - `void retrieveUsers();` should be called to read the data in the eeprom and store it in the global array `userData allUsers[MAXUSERS]`
 
 
 YOU CAN CONCLUDE THAT AFTER CALLING ANY FUNCTION (CREATE, DELETE) YOU SHOULD CALL `void retrieveUsers();` TO SAVE CHANGES.
 
 ## Status & Error Mechanism
 
 ### Enum created for this purpose with the name `status_t`
 
 ````c
 typedef enum{

	deleteSuccess,
	userFound,
	userNotFound,
	userCreated,
	userLimitExceeded

}status_t;
````

# License
This User Manager module is intended to be used as part of the smart security home project and is not designed as a standalone project. It facilitates easy management of user information using the ATmega32 microcontroller's internal EEPROM memory.

For further details on implementation and integration into your specific project, refer to the module's source code and documentation.