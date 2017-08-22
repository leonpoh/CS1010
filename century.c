// CS1010 AY2011/2 Semester 1 
// PE1 Ex1: century.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:
#include <stdio.h>

int printCentury(int);
void printOrdinal(int, int);

int main(void)
{
	int year; // user's input

	printf("Enter year: ");
	scanf("%d",&year);

	printOrdinal(year, printCentury(year));

	return 0;
}

int printCentury(int year)
{
	return (year/100 + 1);
}

void printOrdinal(int year, int century)
{
	if((century/10)%10!=1 || century < 10)
	{
		switch(century%10)
		{
			case 1: printf("The year %d falls in the %dst century.\n",year,century);break;
			case 2: printf("The year %d falls in the %dnd century.\n",year,century);break;
			case 3: printf("The year %d falls in the %drd century.\n",year,century);break;
			default: printf("The year %d falls in the %dth century.\n",year,century);break;
		}
	}
	else
		printf("The year %d falls in the %dth century.\n",year,century);
}
