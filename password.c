// CS1010 AY2012/3 Semester 1 PE2 Ex1
//
// password.c
// This program checks whether a new password satisfies
// corresponding rules or not.
//
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LEN 15

// function prototypes
int isValidPassword(char [], char [], char [], char []);
int complexPass(char []);

// main function complete, not to be changed!
int main(void) {
	char domain[LEN+1], userID[LEN+1], 
		 oldPasswd[LEN+1], newPasswd[LEN+1], confirmPasswd[LEN+1];

	printf("Domain: ");
	scanf("%s", domain);

	printf("UserID: ");
	scanf("%s", userID);

	printf("Old password: ");
	scanf("%s", oldPasswd);

	printf("New password: ");
	scanf("%s", newPasswd);

	printf("Confirm new password: ");
	scanf("%s", confirmPasswd);

	if ( isValidPassword(userID, oldPasswd, newPasswd, confirmPasswd) )
		printf("Password changed successfully!\n");
	else
		printf("Error: Invalid userID or password!\n");

	return 0;
}

// Check whether a new password is valid
int isValidPassword(char userID[], char oldPasswd[], char newPasswd[], char confirmPasswd[]) 
{ 
	if(strlen(newPasswd)<8)
		return 0;
	if(strstr(newPasswd,userID))
		return 0;
	if(strcmp(newPasswd, confirmPasswd))
		return 0;
	if(!strcmp(newPasswd, oldPasswd))
		return 0;
	if(!complexPass(newPasswd))
		return 0;
	return 1;
}

int complexPass(char new[])
{
	int i, len = strlen(new);
	int caps = 0, not = 0;

	for(i = 0; i < len; i++)
	{
		if(isdigit(new[i]))
			continue;
		else if(new[i] == '_')
			continue;
		else if(isalpha(new[i]))
		{
			if(isupper(new[i]))
				caps++;
			if(islower(new[i]))
				not++;
		}
		else return 0;
	}
	if(caps > 0 && not > 0)
		return 1;
	else return 0;
}
