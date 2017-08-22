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

// Fill in the function prototypes below
int scanBoard(int [][DIM]);
int search(int [][DIM], int, int *, int *);

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

// Reads data into the array and returns the search digit
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
	int i, n, vLength = 1, hLength= 1, dLength = 1;
	int longest = 0, vLongest = 0, hLongest = 0, dLongest = 0;
	int startHN = 0, startHI = 0, newHN = -1, newHI = -1;
	int startVN = 0, startVI = 0, newVN = -1, newVI = -1;
	int startDN = 0, startDI = 0, newDN = -1, newDI = -1;
	
	for(i=0;i<DIM;i++)
	{
		for(n=0;n<DIM;n++)
		{
			if(arr[i][n] == digit)
			{
				if(arr[i][n+1] == digit)
				{
					if(newHN <= 0 && newHI <= 0)
					{
						newHN = n;
						newHI = i;
					}
					hLength++;
				}
				else
				{
					if(hLength > hLongest)
					{
						startHN = newHN;
						startHI = newHI;
						hLongest = hLength;
					}
					else if(hLength == hLongest)
					{
						startHN = startHN;
						startHI = startHI;
					}
					newHN = -1;
					newHI = -1;
					hLength = 1;
				}
				if(arr[i+1][n] == digit)
				{
					if(newVN <= 0 && newVI <= 0)
					{
						newVN = n;
						newVI = i;
					}
					vLength++;
				}
				else
				{
					if(vLength > vLongest)
					{
						startVN = newVN;
						startVI = newVI;
						vLongest = vLength;
					}
					else if(vLength == vLongest)
					{
						startVN = startVN;
						startVI = startVN;
					}
					newVN = -1;
					newVI = -1;
					vLength = 1;
				}
				if(arr[i+1][n+1] == digit)
				{
					if(newDN <= 0 && newDI <= 0)
					{
						newDN = n;
						newDI = i;
					}
					dLength++;
				}
				else
				{
					if(dLength > dLongest)
					{
						startDN = newDN;
						startDI = newDI;
						dLongest = dLength;
					}
					else if(dLength == dLongest)
					{
						startDN = startDN;
						startDI = startDI;
					}
					newDN = -1;
					newDI = -1;
					dLength = 1;
				}
			}
		}
	}
	if(hLongest > vLongest && hLongest > dLongest)
	{
		*bestRow = startHN;
		*bestCol = startHI;
		return hLongest;
	}
	else if(vLongest > hLongest && vLongest > dLongest)
	{
		*bestRow = startVN;
		*bestCol = startVI;
		return vLongest;
	}
	else if(dLongest > hLongest && dLongest > vLongest)
	{
		*bestRow = startDN;
		*bestCol = startDI;
		return dLongest;
	}
	else
	{
		*bestRow = startHN;
		*bestCol = startHI;
		return hLongest;
	}
}
