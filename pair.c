// pair.c
#include <stdio.h>

int findPair(int [], int, int, int *, int *);

int main() {
	int size, i, sum, num1, num2;
	int arr[10];
	printf("Please enter the number of elements: ");
	scanf("%d",&size);

	//input the elements into array
	printf("Please enter %d integers: ", size);
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);

	printf("Please enter the target sum: ");
	scanf("%d",&sum);

	if(findPair(arr, size, sum, &num1, &num2))
		printf("The pair of values are %d and %d.\n", num1, num2);
	else
		printf("No solution!\n");

	return 0;
}

int findPair(int arr[], int size, int sum, int *num1, int *num2)
{
	int i, n;

	for(i = 0; i< size; i++)
	{
		for(n= i; n<size; n++)
		{
			if(arr[i] + arr[n] == sum)
			{
				*num1 = arr[i];
				*num2 = arr[n];
				return 1;
			}
		}
	}

	return 0;
}
