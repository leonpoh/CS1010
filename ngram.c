// CS1010 AY2014/5 Semester 1
// PE2 Ex1: ngram.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#define MAX_SIZE 101

int mostFrequentUnigram(char text[],char result[]);
int mostFrequentBigram(char text[], char result[]);

int main(void) 
{
	char text[MAX_SIZE], result[3];
	int option, unigramFreq, bigramFreq;

	printf("Enter text: ");
	fgets(text, MAX_SIZE, stdin);

	printf("Enter option: ");
	scanf("%d",&option);

	if(option == 1)
	{
		unigramFreq =mostFrequentUnigram(text,result);
		printf("Most frequent unigram: %s\n", result);
		printf("Frequency: %d\n", unigramFreq);
	}
	else
	{
		bigramFreq = mostFrequentBigram(text, result);
		printf("Most frequent bigram: %s\n", result);
		printf("Frequency: %d\n", bigramFreq);
	}

	return 0;
}

int mostFrequentUnigram(char text[], char result[])
{
	int i, n, max = 0, count = 0;;
	int len = strlen(text);

	for(i = 0; i < len; i++)
	{
		if(isalpha(text[i]))
		{
			for(n = i; n < len; n++)
				if(text[i] == text[n]) count++;
			if(count> max)
			{
				max = count;
				result[0] = text[i];
				result[1] = '\0';
			}
			else if(count == max)
			{
				if(text[i] < result[0])
					result[0] = text[i];
			}
			count = 0;
		}
	}
	return max;
}

int mostFrequentBigram(char text[], char result[])
{
	int i, n, max = 0, count = 0;
	int len = strlen(text);

	for(i = 0; i < len-1; i++)
	{
		if(isalpha(text[i]) && isalpha(text[i+1]))
		{
			for(n = i; n < len-1; n++)
				if(text[i] == text[n] && text[i+1] == text[n+1]) count++;
			if(count>max)
			{
				max = count;
				result[0] = text[i];
				result[1] = text[i+1];
				result[2] = '\0';
			}
			else if(count == max)
			{
				if(text[i] < result[0])
				{
					result[0] = text[i];
					result[1] = text[i+1];
				}
			}
			count = 0;
		}
	}
	return max;
}
