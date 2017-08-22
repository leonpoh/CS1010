/**
 * CS1010 AY2016/7 Semester 1 Lab5 Ex1
 * prerequisites.c
 * Displays prerequisites of a module
 * Li Liwei
 * C1B
 */

// Add the preprocessor include statements below
#include <stdio.h>
#include <string.h>

#define MAX_MOD  10
#define MAX_LEN  7

int scanModules(char [][MAX_LEN]);
int computePrereq(char [][MAX_LEN], int, char [], char [][MAX_LEN]);
void printPrereq(char [][MAX_LEN], int, char []);

// Note: the main() function is given below. You are NOT to modify it.
int main(void) {
	int numModules, numPrereq;
	char codes[MAX_MOD][MAX_LEN],         // the list of modules codes
	     target[MAX_LEN],                 // the target module
	     prerequisites[MAX_MOD][MAX_LEN]; // prerequisites of the target module

	numModules = scanModules(codes);

	printf("Choose a module: ");
	scanf("%s", target);

	numPrereq = computePrereq(codes, numModules, target, prerequisites);

	printPrereq(prerequisites, numPrereq, target);

	return 0;
}

// Print the prerequisites
// This function is given. You are NOT to modify it.
void printPrereq(char prerequisites[][MAX_LEN], int numPrereq, char target[]) {
	int i;

	if (numPrereq == -1) {
		printf("No such module %s\n", target);
	}
	else if (numPrereq == 0) {
		printf("No prerequisites for %s\n", target);
	}
	else {
		printf("Prerequisites for %s:", target);
		for (i = 0; i < numPrereq; i++){
			printf(" %s", prerequisites[i]);
		}
		printf("\n");
	}
}

int scanModules(char codes[][MAX_LEN])
{
	int i, num;

	printf("Enter number of modules: ");
	scanf("%d",&num);

	printf("Enter %d modules:\n", num);
	for(i = 0; i < num; i++)
		scanf("%s",codes[i]);
	return num;
}

int computePrereq(char codes[][MAX_LEN], int numModules, char target[MAX_LEN], char prerequisites[][MAX_LEN])
{
	int i, n, yes = 0, count = 0;
	
	for(i = 0; i < numModules; i++)
	{
		for(n = 0; n < 6; n++)
		{
			if(!strcmp(codes[i], target)) yes = 1;
			if(n == 0 || n == 1)
			{
				if(codes[i][n] != target[n])
					break;
			}
			else if(n == 2)
			{
				if(codes[i][n] >= target[n])
					break;
			}
			else 
			{
				if(codes[i][n] > target[n])
					break;
			}
		}
		if(n == 6) strcpy(prerequisites[count++],codes[i]);
	}
	if(yes)
		return count;
	return -1;
}
