/**
 * CS1010 AY2016/7 Semester 1 Lab4 Ex2
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>
#define DIM 12

// Fill in the function prototypes below
int scanboard(int [][DIM]);
int search(int [][DIM], int, int*, int*);

int main(void) {
	int board[DIM][DIM] = { {0} };
	int search_digit;     
	int length;           // length of the longest sequence of search digit
	int bestRow, bestCol; // where the longest sequence of search digit starts in the board

	// call scanBoard() 
	search_digit = scanBoard(board);
	// call search()
	length = search(board, search_digit, &bestRow, &bestCol);

	if (length > 0) {
		printf("Length of longest sequence = %d\n", length); 
		printf("Start at (%d,%d)\n", bestRow, bestCol);      
	}
	else
		printf("No such sequence.\n");

	return 0;
}

// Fill in the description of the function.
int scanBoard(int arr[][DIM]) 
{
	int i, n;
    int digit;
	
	for(i = 0; i<DIM; i++)
    {
        for(n = 0; n<DIM; n++)
        scanf("%d",&arr[i][n]);
    }

    scanf("%d", &digit);
 
    return digit;
}


// Fill in the description of the function.
int search(int arr[][DIM], int digit, int *bestRow, int *bestCol) 
{
	int i, n, k;
	int hLength = 1, vLength = 1, max = 0;
	int startHN = -1, startHI = -1, startVN = -1, start VI = -1;
	int startN, startI;
	
	for(i=0;i<DIM-1;i++)
	{
		for(n=0;n<DIM-1;n++)
		{
			if(arr[i][n] == digit)
			{
				if(arr[i][n+1] == digit)
				{
					hLength++;
					if(startHN < 0 && startHI < 0)
					{
						startHN = n;
						startHI = i;
					}
				}
				else
				{
					if(hLength > max)
					{
						max = hLength;
						startN = startHN;
						startI = startHI;
					}
					hLength = 1;
					startHN = -1;
					startHI = -1;
				}
			}
			if(arr[n][i] == digit)
			{
				if(arr[n+1][i] == digit)
				{
					vLength++;
					if(startVN < 0 && startVI < 0)
					{
						startVN = n;
						startVI = i;
					}
				}
				else
				{
					if(hLength > max)
					{
						max = vLength;
						startN = startVN;
						startI = startVI;
					}
					vLength = 1;
					startVN = -1;
					startVI = -1;
				}
			}
		}
		hLength = 1;
		startHN = -1;
		startHI = -1;
		vLength = 1;
		startVN = -1;
		startVI = -1;
	}
	for(i = DIM-1; i > 0 ; i--)
	{
		for(n = 0 && k = i; n < DIM-1; n++ && k++)
		{
			if(arr[k][n] == digit)
			{
				if(arr[k+1][n+1] == digit)
				{
					hLength++;
					if(startHN < 0 && startHI < 0)
					{
						startHN = n;
						startHI = i;
					}
				}
				else
				{
					if(hLength > max)
					{
						max = hLength;
						startN = startHN;
						startI = startHI;
					}
					hLength = 1;
					startHN = -1;
					startHI = -1;
				}
			}
			if(arr[n][k] == digit)
			{
				if(arr[n+1][k+1] == digit)
				{
					vLength++;
					if(startVN < 0 && startVI < 0)
					{
						startVN = n;
						startVI = i;
					}
				}
				else
				{
					if(vLength > max)
					{
						max = vLength;
						startN = startVN;
						startI = startVI;
					}
					vLength = 1;
					startVN = -1;
					startVI = -1;
				}
			}
		}
		hLength = 1;
		startHN = -1;
		startHI = -1;
		vLength = 1;
		startVN = -1;
		startVI = -1;
	}
	*bestRow = startI;
	*bestCol = startN;
	return max;
}

