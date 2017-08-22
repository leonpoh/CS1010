/**
 * CS1010 AY2016/7 Semester 1 Lab3 Ex3
 * frogs.c
 * Simulation for frogs crossing a bridge
 * Li Liwei
 * C1B
 */
#include <stdio.h>

int jump(int, int, int[]);
void printBridge(int, int[]);
int checkGameState(int, int[]);

int main(void) {

	int bridge[1000];
	int i;
	int lengthOfBridge;
	int position;

	int numMoves = 0;
	//int gameState;

	printf("Please enter the length of the bridge: ");
	scanf("%d", &lengthOfBridge);

 	for (i=0; i<lengthOfBridge; i++) {
		int frogType;

		printf("Please insert frogs at position %d: ", i);
		scanf("%d", &frogType);

		bridge[i] = frogType;
	}

	printf("Input completed\n");
	printBridge(lengthOfBridge, bridge);

	printf("Please start moving the frogs\n");

	/** Insert your code below **/
	while(checkGameState(lengthOfBridge, bridge) == 0)
	{
		printf("Move the frog at position: ");
		scanf("%d",&position);
		if(jump(position,lengthOfBridge,bridge))
		{
			printBridge(lengthOfBridge,bridge);
			numMoves++;
		}
		else
			printf("Invalid move!\n");
	}
	if(checkGameState(lengthOfBridge, bridge) == 1)
		printf("Congratulations! The frogs took %d jumps to cross the bridge!\n",numMoves);
	else
		printf("Oh no! It seems like the two clans of frogs are stuck!\n");

	return 0;
}

//This function is provided for you
/**
 * Prints out the current state on the bridge
 * @param size (int) represents the size of bridge
 * @param bridge[] contains the current state of the bridge
 **/
void printBridge(int size, int bridge[]) {

	int i;
	printf("Position: ");
	for (i=0; i<size; i++) {
		printf("%2d ", i);
	}
	printf("\n");

	printf("Bridge:   ");
	for (i=0; i<size; i++) {
		printf("%2d ", bridge[i]);
	}
	printf("\n");
}
int jump(int position, int size, int bridge[])//checks and assigns the frog into the empty position if its valid
{
	if(bridge[position]==1 && bridge[position + 1] == 0)
	{
		bridge[position] = 0;
		bridge[position + 1] = 1;
		return 1;
	}
	else if(bridge[position] == 1 && bridge[position +2] == 0)
	{
		bridge[position] = 0;
		bridge[position + 2] = 1;
		return 1;
	}
	else if(bridge[position]==-1 && bridge[position -1] == 0)
	{
		bridge[position] = 0;
		bridge[position-1]=-1;
		return 1;
	}
	else if(bridge[position]==-1 && bridge[position-2] == 0)
	{
		bridge[position] = 0;
		bridge[position-2]=-1;
		return 1;
	}
	else
		return 0;
}
int checkGameState(int size, int bridge[])//checks the game state; if the game can continue, return 1; if the game is lost, return -1; if the game is won, return 1;
{
	int i, emptyPos, left = 0, right = 0;

	for(i=0;i<size;i++)//find empty position
	{
		if(bridge[i]==0)
		{
			emptyPos = i;
			break;
		}
	}
	for(i = size-1;i>emptyPos;i--)
	{
		right += bridge[i];
	}
	for(i = 0;i<emptyPos;i++)
	{
		left += bridge[i];
	}
	if(left == (emptyPos*-1) && right == (size-emptyPos-1))
		return 1; //win game
	else if(bridge[emptyPos-2] == 1 || bridge[emptyPos-1] == 1 || bridge[emptyPos +1] == -1 || bridge[emptyPos +2] == -1)
		return 0; //continue game
	else
		return -1; //lost game
}
