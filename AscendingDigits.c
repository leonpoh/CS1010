// AscendingDigits.c
// This program reads 3 positive integers and outputs "Yes" if
// the hundreds digits are in ascending order, or "No" otherwise.
#include <stdio.h>

int isAscending(int, int, int);

int main(void) 
{    
	int num1, num2, num3, counter;
	
	printf("Enter 3 positive integers: ");
	scanf("%d %d %d",&num1,&num2,&num3);
	printf("The integers are %d, %d and %d\n",num1,num2,num3);
	
	if(isAscending(num1,num2,num3)) printf("Yes\n");
	else printf("No\n");
	return 0;
}

int isAscending(int num1, int num2, int num3)
{
	if(((num1/100)%10 < (num2/100)%10) && ((num2/100)%10 < (num3/100)%10)) return 1;
	else return 0;
}
// This function returns 1 if the digits at the hundredth position
// of the 3 parameters are in ascending order, or 0 otherwise.

