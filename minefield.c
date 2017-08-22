// CS1010 AY2015/6 Semester 2 PE2 Ex1
//
// minefield.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#define MAX_SIZE 10

int readField(int [][MAX_SIZE]);
void printField(int [][MAX_SIZE], int);
void detonate(int [][MAX_SIZE], int[][MAX_SIZE], int, int *, int *);

int main(void) {
	int field[MAX_SIZE][MAX_SIZE], aftermath[MAX_SIZE][MAX_SIZE] = {{0}};
	int size, damage, safe;
	
	size = readField(field);
	
	detonate(field, aftermath, size, &damage, &safe);

	printf("Aftermath: \n");
	printField(aftermath, size);
	
	printf("Maximum damage: %d\n", damage); // Incomplete
	printf("Number of safe areas: %d\n", safe); // Incomplete

	return 0;
}

void detonate(int field[][MAX_SIZE], int aftermath[][MAX_SIZE], int size, int *damage, int*safe)
{
	int i, n, j, count = 0, max = 0;

	for(i = 0; i < size; i++)
	{
		for(n =0; n<size; n++)
		{
			if(field[i][n] !=0)
			{
				aftermath[i][n]++;
				for(j = field[i][n]-1; j>0; j--)
				{
					if((i-j)>=0)
						aftermath[i-j][n]++;
					if((i+j)<= (size-1))
						aftermath[i+j][n]++;
					if((n-j)>=0)
						aftermath[i][n-j]++;
					if((n+j)<=(size-1))
						aftermath[i][n+j]++;
				}
			}
		}
	}

	for(i = 0; i<size; i++)
	{
		for(n=0;n<size;n++)
		{
			if(aftermath[i][n] ==0) count++;
			if(aftermath[i][n] > max) max = aftermath[i][n];
		}
	}
	*damage = max;
	*safe = count;
}

// Read in a minefield
// Do NOT modify this function!
int readField(int field[][MAX_SIZE]) {
	int i,j, size;
	
	printf("Enter size: \n");
	scanf("%d", &size);
	
	printf("Enter minefield: \n");
	for (i=0; i<size; i++)
		for (j=0; j<size; j++)
			scanf("%d", &field[i][j]);
		
	return size;
}

// Print a minefield
// Do NOT modify this function!
void printField(int field[][MAX_SIZE], int size) {
	int i,j;
	
	for (i=0; i<size; i++){
		for (j=0; j<size; j++)
			printf("%d ", field[i][j]);
		printf("\n");
	}
}
