#include <stdio.h>


int main(void)
{
	int sum = 0;
	char digit;
	
	printf("Enter input: ");
	digit = getchar();
	while(!isspace(digit))
	{
		if(isdigit(digit))
			sum += digit - '0';
		digit = getchar();
	}
	printf("Sum = %d\n", sum);
	return 0;
}
