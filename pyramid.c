/**
 * pyramid.c
 * This program computes the maximum-value path
 * in a triangular matrix.
 */

#include <stdio.h>
#define MAX_ROWS 10

int maxPathValue(int[][MAX_ROWS], int);
int scanTriangularArray(int [][MAX_ROWS]);
void printTriangularArray(int [][MAX_ROWS], int);

int main(void) {
	int size; // number of rows
	int table[MAX_ROWS][MAX_ROWS];

	size = scanTriangularArray(table);
	//printTriangularArray(table, size);   // for checking

	printf("Maximum path value = %d\n", maxPathValue(table, size));

	return 0;
}

// Compute the path that gives the maximum value
int maxPathValue(int arr[][MAX_ROWS], int size) 
{
	int i, n, max = -99999;

	//sum+= arr[0][0];
	for(i = 1; i<size; i++)
	{
		for(n = 0;n <=i;n++)
		{
			if(n==0)
				arr[i][n] += arr[i-1][n];
			else if(n==i)
				arr[i][n] += arr[i-1][n-1];
			else
			{
				if(arr[i-1][n] > arr[i-1][n-1])
					arr[i][n] += arr[i-1][n];
				else
					arr[i][n]+=arr[i-1][n-1];
			}
		}
	}
	for(i = 0; i< size; i++)
		if(arr[size-1][i] > max) max = arr[size-1][i];

	return max;
}

// Read data into 2-dimensional triangular array arr,
// and return the number of rows.
int scanTriangularArray(int arr[][MAX_ROWS]) 
{
	int i, n, size;

	printf("Enter number of rows: ");
	scanf("%d",&size);
	printf("Enter values for array: \n");
	for(i = 0; i<size; i++)
	{
		for(n = 0; n<=i; n++)
			scanf("%d",&arr[i][n]);
	}

	return size;
}

// Print elements in the 2-dimensional triangular array arr.
// For checking purpose.
void printTriangularArray(int arr[][MAX_ROWS], int size) {
	int r, c;

	for (r = 0; r < size; r++) {
		for (c = 0; c <= r; c++) {
			printf("%d\t", arr[r][c]);
		}
		printf("\n");
	}
}

