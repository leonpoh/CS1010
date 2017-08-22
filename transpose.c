// transpose.c

#include <stdio.h>
#define MAX_ROWS 10      // maximum number of rows
#define MAX_COLS 10     // maximum number of columns 
#define MAX_LENGTH 100   // maximum number of characters in the message & result

int encrypt(int, int, char [], char []);
int decrypt(int, int, char [], char []);

int main(void) 
{
	char message[MAX_LENGTH+1];
	char result[MAX_LENGTH+1];
	int rows, cols, type;

	printf("Enter 1 for encryption, 2 for decryption: ");
	scanf("%d",&type);

	printf("Enter dimensions of a 2D array: ");
	scanf("%d %d", &rows, &cols);
	
	printf("Enter message: ");
	scanf("%s",message);
	
	if(type==1)
	{
		if(encrypt(rows, cols, message, result))
			printf("Encrypted message: %s\n", result);
		else
			printf("Encryption failed.\n");
	}
	else
	{
		if(decrypt(rows, cols, message, result))
			printf("Decrypted message: %s\n", result);
		else
			printf("Decryption failed.\n");
	}
	return 0;
}

// Encrypt a message based on transposition algorithm
int encrypt(int rows, int cols, char message[], char result[])
{
	char temp[rows][cols];
	int i, n, count = 0;
	if(strlen(message)>(rows*cols))
		return 0;
	for(i = 0; i< rows; i++)
	{
		for(n = 0; n<cols; n++)
		{
			if(count <strlen(message))
				temp[i][n] = message[count++];
			else
				temp[i][n] = '@';
		}
	}
	count = 0;
	for(i = 0; i<cols; i++)
	{
		for(n = 0; n< rows; n++)
		{
			result[count++] = temp[n][i];
		}
	}
	result[rows*cols] = '\0';

	return 1;
}

// Decrypt a message based on transposition algorithm
int decrypt(int rows, int cols, char message[], char result[])
{
	char temp[rows][cols];
	int i, n, count =0;
	
	if(strlen(message) <(rows*cols) || strlen(message) > (rows*cols))
		return 0;
	for(i = 0; i< cols; i++)
	{
		for(n = 0; n< rows; n++)
		{
			temp[n][i] = message[count++];
		}
	}
	count = 0;
	for(i=0;i<rows; i++)
	{
		for(n = 0; n< cols; n++)
		{
			if(isalpha(temp[i][n]))
				result[count++] = temp[i][n];
		}
	}
	result[count] = '\0';
	return 1;
}

