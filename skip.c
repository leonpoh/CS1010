// CS1010 AY2015/6 Semester 2 PE1 Ex2
//
// skip.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>

int skipCount(int, int, int);
int countOddDigits(int);

int main(void)
{
	int startPos, endPos, lower, upper;
	
	// Insert appropriate statements for reading the inputs.
	printf("Enter starting position: ");
	scanf("%d",&startPos);
	printf("Enter lower bound and upper bound: ");
	scanf("%d %d", &lower, &upper);

	endPos = skipCount(startPos, lower, upper);
	
	printf("The ending position is %d.\n", endPos);
	
	return 0;
}

int skipCount(int startPos, int lower, int upper)
{
	int i, odd;
	for(i = lower;i<=upper; i++)
	{
		odd= countOddDigits(i);
		startPos = startPos +1 + odd;
	}
	if(startPos%5 == 0)
		return 5;
	else 
		return (startPos %5);
}

int countOddDigits(int num)
{
	int odd=0;
	while(num>0)
	{
		if((num%10)%2 >0)
			odd++;
		num /=10;
	}

	return odd;
}
