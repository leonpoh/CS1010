// CS1010 AY2014/5 Semester 1
// PE2 Ex1: ngram.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

int main(void) {
	char text[MAX_SIZE], result[3];
	int option, unigramFreq, bigramFreq;

	printf("Enter text: ");
	fgets(text, MAX_SIZE, stdin);
	if(text[strlen(text)-1] == '\n') text[strlen(text)-1] = '\0';

	printf("Enter option: ");
	scanf("%d", &option);

	if(option ==1)
	{
		unigramFreq = mostFrequentUnigram(text, result);
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
	int i,max = 0, arr[26] = {0};

	for(i =0; i < strlen(text); i++)
		if(isalpha(text[i])) arr[text[i]-97]++;
	for(i = 0;i<26; i++)
	{
		if(arr[i] > max) 
		{
			max = arr[i];
			result[0] = i+97;
		}
	}
	result[1] = '\0';
	return max;
}

int mostFrequentBigram(char text[], char result[])
{
	int i,n, count = 0, max = 0;

	for(i = 0; i < strlen(text); i++)
	{
		if(isalpha(text[i]) && isalpha(text[i+1]))
		{
			for(n = i;n<strlen(text);n++)
			{
				if(isalpha(text[n])&&isalpha(text[n+1])&&text[n] == text[i] && text[n+1] == text[i+1]) count++;
			}
			if(count > max)
			{
				max = count;
				result[0] = text[i];
				result[1] = text[i+1];
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
	result[2] = '\0';
	return max;
}
