// perfectNumber.c 
// Repeatedly reads a non-negative value, and stops when zero is read.
// For each positive value read, it checks if the value is a perfect number.

#include <stdio.h>

int is_perfect(int);

int main(void) {
	int num, flag = 0;
	
	while(flag ==0)
	{
		printf("Enter number: ");
		scanf("%d", &num);
		if(num == 0)
			flag = 1;
		else if (is_perfect(num))
			printf("%d is a perfect number.\n",num);
		else
			printf("%d is not a perfect number.\n",num);
	}

	return 0;
}

int is_perfect(int num)
{
	int i, total;

	for(i=1;i < num;i++)
	{
		if(num%i==0)
			total +=i;
	}

	if(total == num)
		return 1;
	else 
		return 0;
}
