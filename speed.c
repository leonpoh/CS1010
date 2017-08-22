// speed.c

#include <stdio.h>
#define MAX_SIZE 100

int scan(int []);
void print(int [], int);
int slowdown(int [], int [], int, int);
int speedup(int [], int [], int, int);

int main(void) 
{
	int size, change;
	int sound[MAX_SIZE], result[MAX_SIZE*8];

	size = scan(sound);

	printf("Enter speed change: ");
	scanf("%d", &change);
	
	if(change < 0)
		size = slowdown(sound, result, size, change);
	else
		size = speedup(sound, result, size, change);
	
	printf("The sound wave after speed change: \n");
	print(result, size);

	return 0;
}

// To slow down a sound wave and return the size of the 
// resulting sound wave.
// Precond: 
int slowdown(int sound[], int result[], int size, int change) 
{
	int i, n, j = 0;

	for(n = 0; n < size; n++)
	{
		for(i = 0; i > change; i--, j++)
			result[j] = sound[n];
	}

	return j;
}

// To speedup a sound wave and return the size of the 
// resulting sound wave.
// Precond: 
int speedup(int sound[], int result[], int size, int change) 
{
	int i, n , j = 0;
	int average = 0;

	for(n = 0; n < size/change; n++, j++)
	{
		for(i = 0; i < change; i++)
			average += sound[n*change+i];		
		average /= change;
		result[j] = average;
		average = 0;
	}

	return j;
}

// To read in a sound wave
int scan(int sound[]) 
{
	int size, i;

	printf("Enter size: ");
	scanf("%d", &size);

	printf("Enter values: \n");
	for(i = 0; i <size; i++)
		scanf("%d", &sound[i]);

	return size;
}

// To print a sound wave
void print(int sound[], int size) {
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", sound[i]);
	printf("\n");
}

