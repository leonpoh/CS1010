// minesweeper.c

#include <stdio.h>
#define MINE '*'       // a mine-filled square
#define L1_ROWS 8      // number of rows for level-1 grid
#define L1_COLS 8      // number of columns for level-1 grid
#define L2_ROWS 12     // number of rows for level-2 grid
#define L2_COLS 16     // number of columns for level-2 grid
#define L3_ROWS 16     // number of rows for level-3 grid
#define L3_COLS 30     // number of columns for level-3 grid

void scan_mines(char [][L3_COLS+1], int);
void print(char [][L3_COLS+1], int, int);

int main(void) {
	int level, rows, cols;
	char grid[L3_ROWS+1][L3_COLS+1];
	int rows_limit[3] = {L1_ROWS, L2_ROWS, L3_ROWS};
	int cols_limit[3] = {L1_COLS, L2_COLS, L3_COLS};

	scanf("%d\n", &level);
	
	rows = rows_limit[level-1];
	cols = cols_limit[level-1];
	
	scan_mines(grid, rows);
	print(grid, rows, cols);

    return 0;
}

// Read the grid for minefield
void scan_mines(char grid[][L3_COLS+1], int rows) {
	int r;

	for (r=0; r<rows; r++) {
		scanf("%s", grid[r]); // Alternatively: gets(grid[r])
	}
}

void print(char grid[][L3_COLS+1], int rows, int cols)
{
	int i, n, count = 0;

	for(i = 0; i< rows; i++)
	{
		for(n = 0; n< cols; n++)
		{
			if(grid[i][n] == MINE)
				printf(" 9");
			else
			{
				if(grid[i+1][n-1]==MINE) count++;
				if(grid[i+1][n] == MINE) count++;
				if(grid[i+1][n+1]==MINE) count++;
				if(grid[i][n+1] == MINE) count++;
				if(grid[i][n-1] == MINE) count++;
				if(grid[i-1][n-1]==MINE) count++;
				if(grid[i-1][n] == MINE) count++;
				if(grid[i-1][n+1]==MINE) count++;
				printf(" %d",count);
				count = 0;
			}
		}
		printf("\n");
	}
}
