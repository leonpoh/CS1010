// countWords.c
#include <stdio.h>
#include <ctype.h>
#define LENGTH 50

int word_count(char []);

int main(void) {
	char sentence[LENGTH+1];

	printf("Enter a sentence with at most %d characters:\n", LENGTH);
	fgets(sentence, LENGTH+1, stdin);

	printf("Sentence = %s\n", sentence); 

	printf("Word count = %d\n", word_count(sentence));

	return 0;
}

// Count the number of words in str
int word_count(char str[]) 
{
	int i, length = 0, total = 0;
	for(i = 0; i< LENGTH+1; i++)
	{
		if(isalpha(str[i]))
			length++;
		else if(isspace(str[i]))
		{
			if(length != 0)
				total++;
			length = 0;
		}
	}
	return total;;
}

