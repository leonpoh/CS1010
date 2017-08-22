// CS1010 AY2012/3 Semester 1
// PE2 Ex2: poker.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:

#include <stdio.h>
#define NUMBER_OF_CARDS 5

void read_hand(int []);
void type_and_keycard_ranks(int[], int *, int*);
int who_wins(int, int, int, int);

int main(void) {
	int hand1[NUMBER_OF_CARDS], hand2[NUMBER_OF_CARDS]; 
	int type1, type2, rank1, rank2, winner;
	// Read in the hand of the first player
	printf("Enter the hand of player 1:\n");
	read_hand(hand1);

	// Read in the hand of the second player
	printf("Enter the hand of player 2:\n");
	read_hand(hand2);
	
	type_and_keycard_ranks(hand1, &type1, &rank1);
	printf("Player 1 has a hand of type rank %d and key card rank %d.\n", type1, rank1);
	type_and_keycard_ranks(hand2, &type2, &rank2);
	printf("Player 2 has a hand of type rank %d and key card rank %d.\n", type2, rank2);
	winner = who_wins(type1, rank1, type2, rank2);
	if(winner == 0)
		printf("There is a draw.\n");
	else if(winner == 1)
		printf("Player 1 wins.\n");
	else
		printf("Player 2 wins.\n");

	return 0;
}

// Reads an array of integers representing a hand
void read_hand(int hand[]) {
	int i;
	
	for (i = 0; i < NUMBER_OF_CARDS; i++) {
		scanf("%d", &hand[i]);
	}
}

void type_and_keycard_ranks(int hand[], int *type, int *rank)
{
	int i, max = 0, temp, len = 5;
	int arr[13] = {0};
	
	for(i = 0; i < len; i++)
	{
		switch(hand[i])
		{
			case 1: arr[12]++;break;
			case 2: arr[0]++; break;
			case 3: arr[1]++; break;
			case 4: arr[2]++; break;
			case 5: arr[3]++; break;
			case 6: arr[4]++; break;
			case 7: arr[5]++; break;
			case 8: arr[6]++; break;
			case 9: arr[7]++; break;
			case 10:arr[8]++; break;
			case 11:arr[9]++; break;
			case 12:arr[10]++; break;
			case 13:arr[11]++;break;
		}
	}
	for(i = 0; i< 13; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
			temp = i+1;
		}
		else if(arr[i] == max)
		{
			if(i+1 > temp)
			{
				temp = i+1;
			}
		}
	}
	*type = max;
	*rank = temp;
}

int who_wins(int type1, int rank1, int type2, int rank2)
{
	if(type1 > type2)
		return 1;
	if(type2 > type1)
		return 2;
	if(type1 == type2)
	{
		if(rank1 > rank2)
			return 1;
		else if(rank2> rank1)
			return 2;
		else
			return 0;
	}
}
