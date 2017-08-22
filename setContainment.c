// setContainment.c
// Program to check if a set is contained in another.
// This is an incomplete program given to students.
#include <stdio.h>

void scanArray(int [], int);
void printArray(int [], int);
int isSubset(int [], int, int [], int);

int main(void) {
	int arrayA[4], sizeA = 4, arrayB[7], sizeB = 7;

	printf("1st array:\n");
	scanArray(arrayA, sizeA);
	printf("2nd array:\n");
	scanArray(arrayB, sizeB);

	if (isSubset(arrayA, 4, arrayB, 7))
		printf("arrayA[0..3] is a subset of arrayB[0..6]\n");
	else
		printf("arrayA[0..3] is not a subset of arrayB[0..6]\n");

	if (isSubset(arrayA, 4, arrayB, 6))
		printf("arrayA[0..3] is a subset of arrayB[0..5]\n");
	else
		printf("arrayA[0..3] is not a subset of arrayB[0..5]\n");

	return 0;
}

// To read values into arr
void scanArray(int arr[], int size) {
	int i;

	printf("Enter %d values: ", size);
	for (i=0; i<size; i++) {
		scanf("%d", &arr[i]);
	}
}

// To print values of arr
void printArray(int arr[], int size) 
{
	int i;

	// To print all values on one line
	for (i=0; i<size; i++) 
		printf("%d ", arr[i]);

	printf("\n");
}

// This function is a stub. Complete it.
int isSubset(int arrA[], int sizeA, int arrB[], int sizeB) 
{
	int i, n;
	int total =0;

	for(i = 0; i < sizeA; i++)
	{
		for(n = 0; n < sizeB; n++)
		{
			if(arrA[i] == arrB[n])
			{
				total++;
				break;
			}
		}
	}

	if(total == sizeA)
		return 1;
	else return 0;
}

