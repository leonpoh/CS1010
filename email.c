// CS1010 AY2015/6 Semester 1
// PE2 Ex2: email.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 51

int checkEmail(char[]);

int main(void){
	char email[MAX_LENGTH];
	int check;	
	printf("Enter email address: ");
	scanf("%s", email);
	
	check = checkEmail(email);

	if(check == 0)
		printf("This email address is not valid.\n");
	else if(check == 1)
		printf("This email address is valid but not friendly.\n");
	else if(check == 2)
		printf("This email address is valid and friendly.\n");

	return 0;
}

int checkEmail(char email[])
{
	int i=0,check = 0,count = 0, total =0,len = strlen(email);
	char local[MAX_LENGTH], domain[MAX_LENGTH];
	
	for(i = 0; i<len; i++)
	{
		if(email[i] == '@') 
		{
			check++;
			local[i] = '\0';
		}
		if(check == 0)local[i]=email[i];
		else domain[count++] = email[i];
	}
	domain[count]='\0';
	if(strlen(local)<3 || strlen(local) > 21) return 0;
	if(strcmp(domain,"@u.nus.edu")) return 0;
	if(!isalpha(local[0])) return 0;
	for(i = 0; i < strlen(local);i++)
	{
		if(local[i] != '.' &&!isalnum(local[i])) return 0;
	}
	if(local[0] == 'a' || local[0]== 'e')
	{
		for(i = 1; i< strlen(local);i++)
		{
			if(isdigit(local[i])) total++;
			else break;
		}
	}
	if(total == 7) return 1;
	else return 2;
}
