// CS1010 AY2014/5 Semester 1
// PE1 Ex2: happy.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 
#include <stdio.h>

int computeHappyNumbers(int, int);

int main(void){
	int lower1, upper1, lower2, upper2, number1, number2;

	printf("Enter first range: ");
	scanf("%d %d",&lower1, &upper1);

	printf("Enter second range: ");
	scanf("%d %d",&lower2, &upper2);
	
	number1 = computeHappyNumbers(lower1, upper1);
	number2 = computeHappyNumbers(lower2, upper2);

	printf("The numbers of happy numbers in the two ranges are: %d %d\n", number1, number2);
	if(number1>number2)
		printf("There are more happy numbers in the first range.\n");
	else if (number2>number1)
		printf("There are more happy numbers in the second range.\n");
	else
		printf("The numbers of happy numbers in both ranges are the same.\n");

	return 0;
}

int computeHappyNumbers(int lower, int upper)
{
	int new=0,total=0, flag=0, old;

	for(old = lower;old<=upper;old++)
	{
		lower = old;
		//printf("%d\n",lower);
		while(flag==0)
		{
			new=0;
			while(lower)
			{
				new += (lower%10)*(lower%10);
				lower /= 10;
			}
			if(new==0 || new == 1 || new == 4 || new == 16 || new == 20 || new == 37 || new == 42 || new == 58 || new == 89 || new == 145)
			{	
				if(new==1)
					total++;
				flag = 1;
			}
			else
				lower = new;
		}
		flag = 0;
	}

	return total;
}
