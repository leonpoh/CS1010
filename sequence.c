/**
 * CS1010 AY2016/7 Semester 1 Lab4 Ex2
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * Li Liwei
 * C1B
 */

#include <stdio.h>
#define DIM 12

int scanBoard(int[][DIM]);
int search(int [][DIM], int, int *, int *);

int main(void) {
	int board[DIM][DIM] = { {0} };
	int search_digit;     
	int length;           // length of the longest sequence of search digit
	int bestRow, bestCol; // where the longest sequence of search digit starts in the board

	search_digit = scanBoard(board);
	length = search(board, search_digit, &bestRow, &bestCol);

	if (length > 0) {
		printf("Length of longest sequence = %d\n", length); 
		printf("Start at (%d,%d)\n", bestRow, bestCol);      
	}
	else
		printf("No such sequence.\n");

	return 0;
}

int scanBoard(int arr[][DIM]) //read data into the board and the search digit, and return the search digit
{
	int x, y, digit;

	for(x = 0; x<DIM; x++)
	{
		for(y = 0; y<DIM; y++)
			scanf("%d",&arr[x][y]);
	}
	scanf("%d", &digit);

	return digit;
}

int search(int arr[][DIM], int digit, int *row, int *col) //returns the length as well as the start position 
{														  //of the longest sequence of the digit in the board
	int x, y, i, max = 0;
	int hLength = 1, hX = -1, hY = -1;
	int vLength = 1, vX = -1, vY = -1;
	
	for(x = 0; x < DIM; x++)//checks vertical and horizontal sequences
	{
		for(y = 0; y < DIM; y ++)
		{
			if(arr[x][y] == digit)
			{
				if(arr[x][y+1] == digit)
				{
					if(hX < 0 && hY < 0)//if new sequence, store temporary value for starting postion
					{
						hX = x;
						hY = y;
					}
					hLength++;
				}
				else
				{
					if(hLength > max || (hLength == max && (hX < *row || (hX == *row && hY < *col))))
					{//if this sequence is the longest or if this sequence comes before other sequences of the same length
						max = hLength;
						*row = hX;
						*col = hY;
					}
					hLength = 1;
					hX = -1;
					hY = -1;
				}
			}
			if(arr[y][x] == digit) //repeat for vertical
			{
				if(arr[y+1][x] == digit)
				{
					if(vX < 0 && vY < 0)
					{
						vX = y;
						vY = x;
					}
					vLength++;
				}
				else
				{
					if(vLength > max || (vLength == max && (vX < *row || (vX == *row && vY < *col))))
					{
						max = vLength;
						*row = vX;
						*col = vY;
					}
					vLength = 1;
					vX = -1;
					vY = -1;
				}
			}
		}
	}

	hLength = 1;//resets variables for diagonal checks
	hX = -1;
	hY = -1;
	vLength = 1;
	vX = -1;
	vY = -1;

	for(x = DIM - 2; x >= 0; x--) //checks diagonal sequences from both directions; identical to previous for loop
	{
		for((y = 0) ,(i = x); y < DIM - x; y++, i++)
		{
			if(arr[i][y] == digit)
			{
				if(arr[i+1][y+1] == digit)
				{
					if(hX < 0 && hY < 0)
					{
						hX = i;
						hY = y;
					}
					hLength++;
				}
				else
				{
					if(hLength > max || (hLength == max && (hX < *row || (hX== *row && hY < *col))))
					{
						max = hLength;
						*row = hX;
						*col = hY;
					}
					hLength = 1;
					hX = -1;
					hY = -1;
				}
			}
			if(arr[y][i] == digit)
			{
				if(arr[y+1][i+1] == digit)
				{
					if(vX < 0 && vY < 0)
					{
						vX = y;
						vY = i;
					}
					vLength++;
				}
				else
				{
					if(vLength > max || (vLength == max && (vX < *row || (vX == *row && vY < *col))))
					{
						max = vLength;
						*row = vX;
						*col = vY;
					}
					vLength = 1;
					vX = -1;
					vY = -1;
				}
			}
		}
	}
	
	return max;
}