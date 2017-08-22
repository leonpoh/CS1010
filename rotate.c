// rotate.c
#include <stdio.h>
#define MAX_SIZE 10

int scan(int [][MAX_SIZE]);
void print(int [][MAX_SIZE], int);
void rotate(int [][MAX_SIZE], int, int);
void flipH(int [][MAX_SIZE], int);
void flipD(int [][MAX_SIZE], int);

int main(void) 
{
	int degree, size;
	int image[MAX_SIZE][MAX_SIZE];

	size = scan(image);

	printf("Enter degree of rotation: ");
	scanf("%d",&degree);

	rotate(image, size, degree);

	printf("The image after rotation: \n");
	print(image, size);

	return 0;
}

void rotate(int image[][MAX_SIZE], int size, int degree) 
{
	int times = (degree % 360)/90;

	for(;times > 0; times--)
	{
		flipH(image,size);
		flipD(image,size);
	}
}

// To read in an image
int scan(int image[][MAX_SIZE]) 
{
	int size, i, n;

	printf("Enter size: ");
	scanf("%d",&size);

	printf("Enter values: \n");
	for(i = 0; i< size; i++)
	{
		for(n = 0; n<size; n++)
			scanf("%d",&image[i][n]);
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
	for(i = size-1; i >=0; i--)
	{
		for(n = 0; n<i; n++)
		{
			temp = image[i][n];
			image[i][n] = image[n][i];
			image[n][i] = temp;
		}
	}
}
