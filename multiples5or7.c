// multiples5or7.c 
// Reads a positive integer num and count the number
// of multiples of 5 or 7 in the range [1, num].

#include <stdio.h>

int count_multiples(int);

int main(void) {
	int num;

	printf("Enter positive integer: ");
	scanf("%d", &num);
	
	switch(count_multiples(num))
	{
		case 0: printf("There are no multiples of 5 or 7 in [1,%d].\n",num);break;
		case 1: printf("There is 1 multiple of 5 or 7 in [1,%d].\n",num);break;
		default:printf("There are %d multiples of 5 or 7 in [1,%d].\n",count_multiples(num),num);break;
	}
	return 0;
}

// Precond: value > 0
int count_multiples(int value) 
{
	int total=0, i;

	for (i=1;i<=value;i++)
	{
		if(i%5==0 || i%7==0)
			total++;
	}

	return total;
}

