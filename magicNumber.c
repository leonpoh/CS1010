// magicNumber.c
// You must write a function get_magic().
#include <stdio.h>

int get_magic(int);

int main(void) 
{
	int value, magic;

    printf("Enter 1st value: ");
	scanf("%d",&value);
	magic = get_magic(value);
	printf("Magic number = %d\n",magic);

    printf("Enter 2nd value: ");
	scanf("%d",&value);
	magic = get_magic(value);
	printf("Magic number = %d\n",magic);

    return 0;
}

int get_magic(int value)
{
	int total;
	
	total = (value % 10 + (value/100)%10 + (value/10000));
	total = total%10;

	return total;
}
