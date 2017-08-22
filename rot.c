// rot.c

#include <stdio.h>
#define MAX_LENGTH 80
#include <string.h>
#include <ctype.h>

void encrypt(char [], char []);
void decrypt(char [], char []);

int main(void) 
{
	char message[MAX_LENGTH+1];
	char result[MAX_LENGTH +1];
	int type;

	printf("Enter 1 for encryption, 2 for decryption: ");
	scanf("%d",&type);

	printf("Enter message: ");
	scanf("%s", message);

	if(type == 1)
		printf("Encrypted message: ");
	else
		printf("Decrypted message: ");

	encrypt(message, result);
	printf("%s\n", result);

	return 0;
}

// Encrypt a message based on transpose-13 algorithm
void encrypt(char message[], char result[])
{
	int i, len = strlen(message);

	for(i = 0; i<len;i++)
	{
		if(isupper(message[i]))
			result[i] = (((message[i] - 65 +13) % 26) + 65);
		else
			result[i] = (((message[i] - 97 +13) %26) +97);
	}
	result[len] = '\0';
}

// Decrypt a message based on transpose-13 algorithm
/*void decrypt(char message[], char result[])
{
	printf("Decrypted message: ");
	encrypt(message, result);	
}*/
