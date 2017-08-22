// CS1010 AY2016/7 Semester 1
// PE2 Ex1: spy.c
// Name: Li Liwei
// Matriculation number: A0155991R
// plab account-id: plab1391
// Discussion group: C1B
// Description:

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
#define MAX_LENGTH 80

void createAlphabet(char [], char []);
void encrypt(char [], char[], char []);
void simplify(char []);

// Do NOT change the main function!
int main(void) {
	char keyword[MAX_LENGTH+1], alphabet[ALPHABET_SIZE+1], message[MAX_LENGTH+1], result[MAX_LENGTH+1];
	
    printf("Enter keyword: ");
    scanf("%s", keyword);
	
	printf("Enter message: ");
    scanf("%s", message);

	simplify(keyword);
	//createAlphabet(keyword, alphabet);	
	//encrypt(message, alphabet, result);
	
	printf("%s\n",keyword);
	printf("Encrypted message: %s\n", result);

	return 0;
}
//simplify the keyword
void simplify(char keyword[])
{
	int alpha[ALPHABET_SIZE+1] = {0};
	int i, n=0;

	for(i = 0; i < strlen(keyword); i++)
		alpha[toupper(keyword[i])-65]++;
	for(i = 0; i < ALPHABET_SIZE; i ++)
		if(alpha[i] != 0) keyword[n++] = i+97;
	keyword[n] = '\0';
	printf("%s\n",keyword);
}
//create encryption code
void createAlphabet(char keyword[], char alphabet[])
{
	int i, n,j, count = 0;
	int size = strlen(keyword);

	strcpy(alphabet,keyword);

	for(i = 0; i < ALPHABET_SIZE; i++)
	{
		for(n = 0; n < size;n++)
		{
			if(keyword[n] == 97+i) count++;
		}
		if(count==0) alphabet[strlen(alphabet)] = 97+i;
		count = 0;
	}
	alphabet[j] = '\0';
}
//encrypts message according to new alphabets
void encrypt(char message[], char alphabet[], char result[])
{
	int i;

	for(i = 0; i < strlen(message); i++)
	{
		if(isalpha(message[i]))
		{
			if(isupper(message[i])) result[i] = toupper(alphabet[message[i]-65]);
			else result[i] = alphabet[message[i]-97];
		}
	}	
}
