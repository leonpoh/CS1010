// flip.c

#include <stdio.h>
#define MAX_SIZE 10

int scan(int [][MAX_SIZE]);
void print(int [][MAX_SIZE], int);
void flipH(int [][MAX_SIZE], int);
void flipD(int [][MAX_SIZE], int);

int main(void) 
{
	int size;
	int image[MAX_SIZE][MAX_SIZE];
	char dir;
	
	size = scan(image);

	printf("Enter direction: ");
	scanf("%c %c",&dir ,&dir);
	if(dir == 'h') flipH(image, size);
	if(dir == 'd') flipD(image, size);

	printf("The image after flipping: \n");
	print(image, size);	
	return 0;
}

// To flip an image horizontally
void flipH(int image[][MAX_SIZE], int size) 
{
	int i, n, temp;

	for(i = 0; i<size/2; i++)
	{
		for(n = 0; n< size; n++)
		{
			temp = image[i][n];
			image[i][n] = image[size-i-1][n];
			image[size-i-1][n] = temp;
		}
	}
}

// To flip an image diagonally
void flipD(int image[][MAX_SIZE], int size) 
{
	int i, n, temp;

	for(i = 0; i <size; i++)
	{
		for(n = i+1; n<size; n++)
		{
			temp = image[i][n];
			image[i][n] = image[n][i];
			image[n][i] = temp;
		}
	}
}

// To read in an image
int scan(int image[][MAX_SIZE]) 
{
	int i,n,size;

	printf("Enter size: ");
	scanf("%d", &size);

	printf("Enter values: \n");
	for(i = 0; i< size; i++)
	{
		for(n = 0; n< size; n++)
		{
			scanf("%d", &image[i][n]);
		}
	}

	return size;
}

// To print an image
void print(int image[][MAX_SIZE], int size) {
	int row, col;

	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) 
			printf("%d ", image[row][col]);
		printf("\n");
	}
}

