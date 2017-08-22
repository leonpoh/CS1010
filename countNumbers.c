// countNumbers.c
// To count the number of integers in the range [limit1, limit2]
// which are not divisible by divisor1 and divisor2
#include <stdio.h>

int count_numbers(int, int, int, int);

int main(void) {    
	int divisor1, divisor2, limit1, limit2, flag=1;
	
	while(flag == 1)
	{
		printf("Enter 2 divisors: ");
		scanf("%d %d",&divisor1,&divisor2);
		if(divisor1==divisor2 || divisor1 <= 0 || divisor2 <= 0)
			flag = 1;
		else
			flag = 0;
	}

	while(flag == 0)
	{
		printf("Enter lower and upper limits: ");
		scanf("%d %d", &limit1, &limit2);
		if(limit1 >= limit2 || limit1 <= 0 || limit2 <= 0)
			flag = 0;
		else
			flag = 1;
	}
	
	flag = count_numbers(divisor1, divisor2, limit1, limit2);

	printf("Answer = %d\n",flag);

	return 0;
}

int count_numbers(int divisor1, int divisor2, int limit1, int limit2)
{
	int total = limit2 - limit1 + 1;
	
	for(;limit1<=limit2;limit1++)
	{
		if(limit1%divisor1 == 0 || limit1%divisor2 == 0)
			total--;
	}

	return total;
}
