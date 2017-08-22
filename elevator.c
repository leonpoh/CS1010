/**
 * CS1010 AY2016/7 Semester 1 Lab5 Ex2
 * elevator.c
 * Simulate elevator usage
 * Li Liwei
 * C1B
 */

#include <stdio.h>
#include <string.h>
#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

typedef struct { 
	int floor;
	int passengers;
	int usage;
} elevator_t;

void setupElevators(elevator_t [], int);
void readSequences(char [][MAX_LEN], int);
void runElevators(elevator_t [], char [][MAX_LEN], int);
void goToFloor(elevator_t *, int);
void printElevators(elevator_t [], int size);
int mostUsedElevator(elevator_t [], int);

// This function is given. You are NOT to modify it.
int main(void){
	int size;
	elevator_t elevators[MAX_ELEVATORS];
	char sequences[MAX_ELEVATORS][MAX_LEN];
	
	printf("Enter number of elevators: ");
	scanf("%d", &size);
	
	setupElevators(elevators, size);
	readSequences(sequences, size);
	
	runElevators(elevators, sequences, size);
	
	printElevators(elevators, size);
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size));
	
	return 0;
}

void setupElevators(elevator_t elevators[], int size)
{
	int i;
	for(i=0; i < size; i ++)
	{
		elevators[i].floor = 1;
		elevators[i].passengers = 0;
		elevators[i].usage = 0;
	}
}	

// Read in the sequences of floors the elevators go to.
// This function is given. You are NOT to modify it.
void readSequences(char sequences[][MAX_LEN], int size){
	int i;
	
	for (i = 0; i<size; i++){
		printf("Enter sequence for elevator %d: ", i+1);
		scanf("%s", sequences[i]);
	}
}

void runElevators(elevator_t elevators[], char sequences[][MAX_LEN], int size)
{
	for(i = 0; i < size; i++)
	{
		for(n = 0; n < strlen(sequences[i]); n++)
		{
			goToFloor(elevator[i], sequences[i]);
		}
	}
}

void goToFloor(elevator_t *elevator, int floor)
{
	if(n == 0) elevators[i].passengers += sequences[i][n];
			else if(sequences[i][n] > sequences[i][n-1])
			{
				elevators[i].passengers += sequences[i][n];
				if(elevators[i].passengers >= 15) elevators[i].passengers = 15;
			}
			else if(sequences[i][n] < sequences[i][n-1])
			{
				if(sequences[i][n] <= elevators[i].passengers)
					elevators[i].passengers -= sequences[i][n];
				else elevators[i].passengers = 0;
				elevators[i].usage += sequences[i][n];
			}
}

void printElevators(elevator_t elevators[], int size)
{
	int i;

	for(i = 0; i < size; i ++)
	{
		printf("Elevator %d:\n", i+1); 
		printf("Floor: %d\n", elevator[i].floors);
		printf("Number of passengers: %d\n", elevators[i].passengers);
		printf("Usage: %d\n", elevators[i].usage);
	}
}

int mostUsedElevator(elevator_t elevators[], int size)
{
	int max = 0, unit;

	for(i = 0; i < size; i ++)
	{
		if(elevator[i].usage > max)
			unit = i;
		else if(elevators[i].usage == max)
		{
			if(elevators[i].passengers > elevators[unit].passengers)
				unit = i;
			else if(i < unit)
				unit = i;
		}
	}
	return unit;
}

