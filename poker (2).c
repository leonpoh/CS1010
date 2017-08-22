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
	int winner, type1, type2, rank1, rank2;

	// Read in the hand of the first player
	printf("Enter the hand of player 1:\n");
	read_hand(hand1);

	// Read in the hand of the second player
	printf("Enter the hand of player 2:\n");
	read_hand(hand2);

	type_and_keycard_ranks(hand1, &type1, &rank1);
	type_and_keycard_ranks(hand2, &type2, &rank2);

	printf("Player 1 has a hand of type rank %d and key card rank %d.\n",type1, rank1);
	printf("Player 2 has a hand of type rank %d and key card rank %d.\n",type2, rank2);

	winner = who_wins(type1, rank1, type2, rank2);

	if(winner == 0) printf("There is a draw.\n");
	else printf("Player %d wins.\n", winner);

	return 0;
}

// Reads an array of integers representing a hand
void read_hand(int hand[]) {
	int i;

	for (i = 0; i < NUMBER_OF_CARDS; i++) {
		scanf("%d", &hand[i]);
	}
}

void type_and_keycard_ranks(int hand[], int*type, int*rank)
{
	int i,n, count = 0, max = 0;

	for(i=0; i< 5; i++)
	{
		for(n = i; n <5; n++)
		{
			if(hand [n]== hand[i]) count ++;
			if(count > max)
			{
				max = count;
				if(hand[i] == 1) *rank = 13;
				else *rank = hand[i]-1;
			}
			else if(count == max)
			{
				if(hand[i] == 1) *rank = 13;
				else if(hand[i] > *rank) *rank = hand[i]-1;
			}
		}
		count = 0;
	}
	*type = max;
}

int who_wins(int type1, int rank1, int type2, int rank2)
{
	if(type1>type2) return 1;
	else if(type2>type1) return 2;
	else if(type1 == type2 && rank1 > rank2) return 1;
	else if(type1 == type2 && rank2 > rank1) return 2;
	else if(type1 == type2 && rank1 == rank2)return 0;
}
