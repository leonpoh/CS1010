// magic_square.c
// To generate a magic square for nxn matrix (n is odd integer)

#include <stdio.h>
#define MAX_SIZE 15

void printMagic(int [][MAX_SIZE], int);
void generateMagic(int [][MAX_SIZE], int);

int main(void) {
	int magic[MAX_SIZE][MAX_SIZE] = { {0} }; 
	int size; 

	printf("Enter size of matrix: ");
	scanf("%d", &size);
	printf("%d\n", size);
	generateMagic(magic, size);
	printMagic(magic, size);

	return 0;
}

// To generate the magic square
void generateMagic(int arr[][MAX_SIZE], int size) 
{
	int i = 0, n = (size/2), num = 1;

	while(num <= size*size)
	{	
		if(arr[i][n%size] == 0) 
		{
			arr[i][n%size] = num;
			num++;
		}
		else
		{
			if(i == 0) i = size;
			
			if(arr[i-1][(n+1)%size] == 0) 
			{
				i = i-1;
				n = n+1;
			}
			else 
			{	
				if(i ==size)
					i = 1;
				else
					i++;
			}
		}
	}
}

// To print the magic square
void printMagic(int arr[][MAX_SIZE], int size) {
	int row, col;

	for (row=0; row<size; row++) {
		for (col=0; col<size; col++) 
			printf("%5d", arr[row][col]);
		printf("\n");
	}
}

