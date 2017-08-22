// CS1010 AY2011/2 Semester 1 
// PE1 Ex2: winners.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description: 
#include <stdio.h>

int lottery(int, int, int);

int main(void)
{
	int factor, must, participants;       

	printf ("Enter factor-digit: ");
	scanf("%d",&factor);

	printf("Enter must-have-digit: ");
	scanf("%d",&must);

	printf("Enter number of participants: ");
	scanf("%d",&participants);
	
	printf("Number of winners: %d\n",lottery(factor, must, participants));

	return 0;
}

int lottery(int factor, int must, int participants)
{
	int i, total = 0, n= participants;

	for (i = 0; i <= participants; i++)
	{
		n=i;
		if(i%factor ==0)
		{
			while(i)
			{
				if(i%10 == must)
				{
					total++;
					break;
				}
				//printf("%d %d %d\n",i,participants, total);
				i = i/10;
			}
			i = n;
		}
	}
	return total;
}
