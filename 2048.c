// CS1010 AY2014/5 Semester 1
// PE2 Ex2: 2048.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 
#include <string.h>
#include <stdio.h>
#define SIZE 4
#define LENGTH 21

void readGrid(int [][SIZE]); 
void printGrid(int [][SIZE]); 
void play(int [][SIZE], char []);
int exists(int [][SIZE], int);
void moveUp(int [][SIZE]);
void moveLeft(int [][SIZE]);

int main(void) {
	int grid[SIZE][SIZE], target;
	char directions[LENGTH];

	printf("Enter grid:\n");
	readGrid(grid);
	
	printf("Enter directions: ");
	scanf("%s", directions);

	printf("Enter target: ");
	scanf("%d", &target);
	
	play(grid, directions);
	printGrid(grid);
	if(exists(grid, target))
		printf("%d is formed.\n", target);
	else
		printf("%d is not formed.\n", target);

	return 0;
}

// Read in the grid
void readGrid(int grid[][SIZE]) {
	int i,j;

	for (i=0; i<SIZE; i++)
		for (j=0; j<SIZE; j++)
			scanf("%d",&grid[i][j]);
}

// Print out the grid
void printGrid(int grid[][SIZE]) {
	int i,j;

	for (i=0; i<SIZE; i++) {
		for (j=0; j<SIZE; j++)
			printf("%d ",grid[i][j]);
		printf("\n");
	}
}

void play(int grid[][SIZE], char directions[])
{
	int i, len = strlen(directions);
	
	for(i = 0; i< len; i++)
	{
		if(directions[i] == 'U')
			moveUp(grid);
		else
			moveLeft(grid);
		//printGrid(grid);
		//printf("\n");
	}
}

void moveUp(int grid[][SIZE])
{
	int i, n, j;
	int count = 0;
	for(i = 1; i < SIZE; i++)
	{
		for(n = 0; n < SIZE; n++)
		{
			for(j = i; j > 0; j--)
			{
				if(grid[j-1][n] == 0)
				{
					grid[j-1][n] = grid[j][n];
					grid[j][n] = 0;
				}
				else if(grid[j-1][n] == grid[j][n] && count == 0)
				{	
					grid[j-1][n] += grid[j][n];
					grid[j][n] = 0;
					count ++;
				}
				else
					break;
			}
			count = 0;
		}
	}
}

void moveLeft(int grid[][SIZE])
{
	int i, n, j;
	int count = 0;	
	for(i = 1; i < SIZE; i++)
	{
		for(n = 0; n < SIZE; n++)
		{
			for(j = i; j > 0; j--)
			{
				if(grid[n][j-1] == 0)
				{
					grid[n][j-1] = grid[n][j];
					grid[n][j] = 0;
				}
				else if(grid[n][j-1] == grid[n][j] && count == 0)
				{
					grid[n][j-1] += grid[n][j];
					grid[n][j] = 0;
					count++;
				}
				else
					break;
			}
			count = 0;
		}
	}
}


int exists(int grid[][SIZE], int target)
{
	int i, n;

	for(i = 0; i < SIZE; i++)
	{
		for(n = 0; n < SIZE; n++)
		{
			if(grid[i][n] == target)
				return 1;
		}
	}

	return 0;
}

