// reverse_array.c
// Reverse all values in an integer array.
#include <stdio.h>
#define MAX_SIZE 15

int readArray(int []);
void printArray(int [], int);
void reverseArray(int [], int);

int main(void) {
	int list[MAX_SIZE], size;

	size = readArray(list);
	reverseArray(list, size);
	
	printArray(list, size);
	
	return 0;
}

// Read values into array.
// Return number of elements read.
int readArray(int arr[]) {
	int size, i;

	printf("Enter number of integers: ");
	scanf("%d", &size);
	printf("Enter integers: ");
	for (i=0; i<size; i++)
		scanf("%d", &arr[i]);

	return size;
}

// Print values in array
void printArray(int arr[], int size) {
	int i;

	printf("Reversed array: ");
	for (i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Reverse all the values in the array arr
// Pre-cond: size >= 1
void reverseArray(int arr[], int size) 
{
	int temp;

	if(arr < &arr[size-1])
	{
		temp = arr[size-1];
		arr[size-1] = *arr;
		*arr = temp;
		reverseArray(arr+1, size - 2);
	}
}
