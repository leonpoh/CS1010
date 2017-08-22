// palindrome.c
#include <stdio.h>
#define MAXLEN 20

int isPalindrome(char []);

int main(void) {
	char word[MAXLEN+1];

	printf("Enter word: ");
	fgets(word, MAXLEN+1, stdin);

	if (isPalindrome(word))
		printf(" is a palindrome.\n");
	else
		printf(" is not a palindrome.\n");

	return 0;
}

// Return 1 if str is a palindrome, otherwise return 0.
int isPalindrome(char str[]) {
	int len = strlen(str);
	int i;
	printf("\"");
	for(i = 0; i<len-1;i++)
		printf("%c",str[i]);
	printf("\"");
	for(i = 0; i< len-1; i++)
	{
		if(toupper(str[i]) != toupper(str[len-i-2]))
			return 0;
	}
	
	return 1;
}

