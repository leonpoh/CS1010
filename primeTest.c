// primeTest.c
// To check if a number is prime.
#include <stdio.h>

int is_prime(int);

int main(void) {    
	int value;

	printf("Enter a positive integer: ");
	scanf("%d", &value);

	if (is_prime(value)) 
		printf("%d is a prime.\n", value);
	else
		printf("%d is not a prime.\n", value);

	return 0;
}

// Write a description for this function,
// and fill in the precondition below.
// Precond: 
int is_prime(int n) 
{
	int i;

	if(n==1)
	{
		return 0;
	}
	for (i=2;i<n; i++)
	{
		if(n%i ==0)
		{
			return 0;
			break;
		}
	}
}

