// echo.c

#include <stdio.h>
#define MAX_SIZE 100

int scan(int []);
void print(int [], int);
int echo(int [], int [], int, int, int);

int main(void) 
{
	int size, copies, decay;
	int sound[MAX_SIZE], result[MAX_SIZE*MAX_SIZE];

	size = scan(sound);

	printf("Enter number of echoes and decay percentage: ");
	scanf("%d %d",&copies, &decay);
	
	size = echo(sound, result, size, copies, decay);

	printf("The sound wave with echoes added: \n");
	print(result, size);

	return 0;
}

// To add echo effects to a sound wave and return the size 
// of the resulting sound wave.
// Precond: 
int echo(int sound[], int result[], int size, int copies, int decay) 
{
	int i;
	
	decay = (100-decay);

	for(i = 0; i < size; i++)
		result[i] = sound[i];

	for(;i < (size * (copies+1)); i++)
	{
		sound[i%size] = sound[i%size] * decay/100;
		result[i] = sound[i%size];
	}

	return i;
}

// To read in a sound wave
int scan(int sound[]) 
{
	int i, size;
	
	printf("Enter size: ");
	scanf("%d", &size);

	printf("Enter values: \n");
	for(i = 0; i < size; i++)
		scanf("%d",&sound[i]);
	
	return size;
}

// To print a sound wave
void print(int sound[], int size) 
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", sound[i]);
	printf("\n");
}

