/**
 * CS1010 AY2016/7 Semester 1 Lab4 Ex3
 * Game of Life
 * Li Liwei
 * C1B
 */

#include <stdio.h>

#define DIM_ROW 20
#define DIM_COL 20
#define DEAD    '-'
#define LIFE    'O'
#define MAX_GEN 5

int genesis(char[][DIM_COL+2]); 
void display(int, char[][DIM_COL+2]);
int next_generation(char[][DIM_COL+2], char[][DIM_COL+2]);
int checkDOA(char[][DIM_COL+2], int, int);
int numberAlive(char[][DIM_COL+2]);
int checkSame(char[][DIM_COL+2],char[][DIM_COL+2]);

int main(void) {
	char board[DIM_ROW+2][DIM_COL+2]; // the community
	int  lives;                       // how many lives in community
	int  generation = 0;              // generation
	char newCommunity[DIM_ROW+2][DIM_COL+2];
	int diff = 1, r, c;

	lives = genesis(board);
//	display(generation, board); // for checking

	while(lives && diff && generation < MAX_GEN)
	{
		lives = next_generation(board, newCommunity);
		diff = checkSame(board, newCommunity);
		generation++;
		for(r = 1; r<=DIM_ROW; r++)
		{
			for(c = 1; c<=DIM_COL; c++)
			{
				board[r][c] = newCommunity[r][c];
			}
		}
	}
	// Display the final generation
	display(generation, board); 

	return 0;
}

// To initialise the community with generation 0 from user's input, and
// return the number of life cells read.
// Sentinels are used here. Dead cells are padded around the actual
// community area.
int genesis(char community[][DIM_COL+2]) {
	int population = 0;
	int r, c; 

	// Fill left-most and right-most columns with dead cells.
	for (r=0; r < DIM_ROW + 2; r++)
		community[r][0] = community[r][DIM_COL + 1] = DEAD;

	// Fill top and bottom rows with dead cells.
	for (c=1; c < DIM_COL + 1; c++)
		community[0][c] = community[DIM_ROW + 1][c] = DEAD;

	// Fill the middle 20x20 area with input data
	for (r=1; r<=DIM_ROW; r++) {
		for (c=1; c<=DIM_COL; c++) {
			community[r][c] = fgetc(stdin);
			if (community[r][c] == LIFE)
				population++;
		}
		fgetc(stdin);  // to read the newline character
	}

	return population;
}

// To display the community
void display(int generation, char community[][DIM_COL+2]) {
	int r, c;

	printf("Generation %d:\n", generation);
	for (r=1; r <= DIM_ROW; r++) {
		for (c=1; c <= DIM_COL; c++) {
			printf("%c", community[r][c]);
		}
		printf("\n");
	}
}

// To generate next generation and
// return number of live cells in next generation.
// next_generation()
int next_generation(char community[][DIM_COL+2], char newCommunity[][DIM_COL+2])
{
	int r, c, alive;

	for(r=1;r<=DIM_ROW;r++)
	{
		for(c=1;c<=DIM_COL;c++)
		{
			if(community[r][c] == LIFE)
			{
				alive = checkDOA(community, r, c);
				if(alive == 2 || alive == 3)
					newCommunity[r][c] = LIFE;
				else
					newCommunity[r][c] = DEAD;
				//printf("%d, %c\n", alive, newCommunity[r][c]);
			}
			else
			{
				alive = checkDOA(community, r, c);
				if(alive == 3)
					newCommunity[r][c] = LIFE;
				else
					newCommunity[r][c] = DEAD;
			}
		}
	}
	return numberAlive(newCommunity);
}

int checkDOA(char community[][DIM_COL+2], int r, int c)//checks if the cell should be dead or alive
{
	int count = 0;

	if(community[r][c-1] == LIFE)
		count++;
	if(community[r][c+1] == LIFE)
		count++;
	if(community[r-1][c] == LIFE)
		count++;
	if(community[r+1][c] == LIFE)
		count++;
	if(community[r-1][c-1]==LIFE)
		count++;
	if(community[r-1][c+1]==LIFE)
		count++;
	if(community[r+1][c-1]==LIFE)
		count++;
	if(community[r+1][c+1]==LIFE)
		count++;

	return count;
}

int numberAlive(char newCommunity[][DIM_COL+2])
{//checks the number of cells that are alive
	int r, c, alive = 0;

	for(r = 1; r <= DIM_ROW; r++)
	{
		for(c = 1; c <= DIM_COL; c++)
		{
			if(newCommunity[r][c] == LIFE)
				alive++;
		}
	}

	return alive;
}

int checkSame(char community[][DIM_COL+2], char newCommunity[][DIM_COL+2])
{//checks if the new community is similar to the old one
	int r, c;

	for(r = 1; r <= DIM_ROW; r++)
	{
		for(c = 1; c <= DIM_COL; c++)
		{
			if(community[r][c] != newCommunity[r][c])
				return 1; //not same
		}
	}
	return 0;
}
