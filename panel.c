// CS1010 AY2015/6 Semester 1
// PE2 Ex1: panel.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#define GRID_SIZE 5
#define MAX_LENGTH 30

void readGrid(int grid[][GRID_SIZE]);
void printGrid(int grid[][GRID_SIZE]);
int readSequence(int sequence[]);
void press(int [][GRID_SIZE], int, int[]);
void pressed(int [][GRID_SIZE], int, int);
int allOff(int [][GRID_SIZE], int *);

int main(void) {
	int grid[GRID_SIZE][GRID_SIZE], sequence[MAX_LENGTH], length, lit;
	
	readGrid(grid);

	length = readSequence(sequence);
	
	press(grid, length, sequence);

	if(allOff(grid, &lit)) printf("All panels are off.\n");
	else 
	{
		printf("Number of lighted panels: %d\n", lit);
		printGrid(grid);
	}
	
	return 0;
}

// Read the initial state of a grid
void readGrid(int grid[][GRID_SIZE]) {
	int i,j;
	
	printf("Enter grid:\n");
	
	for (i=0; i<GRID_SIZE; i++)
		for (j=0; j<GRID_SIZE; j++)
			scanf("%d", &grid[i][j]);
}

// Print the current grid
void printGrid(int grid[][GRID_SIZE]) {
	int i,j;
	
	for (i=0; i<GRID_SIZE; i++){
		for (j=0; j<GRID_SIZE; j++)
			printf("%d ", grid[i][j]);
		printf("\n");
	}
}

// Read the sequence of panels to be pressed
int readSequence(int sequence[]) {
	int i,length;
	
	printf("Enter length of sequence: ");
	scanf("%d", &length);
	
	printf("Enter sequence of panels: ");

	for (i=0; i<length; i++)
		scanf("%d", &sequence[i]);
		
	return length;
}

void press(int grid[][GRID_SIZE], int length, int sequence[])
{
	int i;

	for(i = 0; i <length; i++)
	{
		if(sequence[i] < 5) pressed(grid, 0, sequence[i]);
		else pressed(grid, sequence[i]/5, sequence[i]%5);
	}
}

void pressed(int grid[][GRID_SIZE], int i, int n)
{
	if(i != 0) grid[i-1][n] =!grid[i-1][n];
	if(i!=GRID_SIZE-1) grid[i+1][n]=!grid[i+1][n];
	if(n != 0) grid[i][n-1]=!grid[i][n-1];
	if(n!=GRID_SIZE-1) grid[i][n+1]=!grid[i][n+1];
	grid[i][n]=!grid[i][n];
}

int allOff(int grid[][GRID_SIZE], int * lit)
{
	int i, n, count = 0;
	
	for(i = 0; i < GRID_SIZE; i++)
	{
		for(n = 0; n < GRID_SIZE; n++)
			if(grid[i][n] == 1) count ++;
	}
	*lit = count;

	if(count == 0) return 1;
	else return 0;

}
