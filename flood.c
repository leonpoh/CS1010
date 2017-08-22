#include <stdio.h>
#define MAX_ROW 100
#define MAX_COL 100

void findEndPos(int[][MAX_COL], int, int, int, int, int*, int*);

int main(){
	int row, col, level, i, j, x, y, total= 0;
	int land[MAX_ROW][MAX_COL];

	printf("Enter dimensions of the land: ");
	scanf("%d %d",&row,&col);
	
	printf("Enter elevations: \n");
	
	for(i=0;i<row;i++) 
		for(j=0;j<col;j++) 
			scanf("%d",&land[i][j]);
	
	printf("Enter flood level: ");	
	scanf("%d",&level);
	
	for(i=0; i<row;i++)
	{
		for(j = 0;j<col;j++)
		{	
			findEndPos(land, i, j, row, col, &x, &y);
			if(land[x][y] < level)
			{
				total++;
				//printf("%d %d %d %d\n", i, j, x, y);
			}
		}
	}
	printf("Number of robots to be rescued: %d\n", total); // Incomplete
	
	return 0;
}

void findEndPos(int land[][MAX_COL], int i, int j, int row, int col, int *x, int *y)
{
	int a = 1, b = 1, c = 1, d = 1;
	int e= 0;

	while(e < a || e < b || e < c || e < d)
	{
		if( i == 0) a = 0;
		else a = land[i-1][j];
		if(i == row-1) b = 0;
		else b = land[i+1][j];
		if(j == 0) c = 0;
		else c = land[i][j-1];
		if(j == col-1) d = 0;
		else d = land[i][j+1];
		e = land[i][j];
		
		if(a > b && a > c && a > d && a > e)
			i--;
		else if(b> a && b > c && b > d && b > e)
			i++;
		else if(c > a && c > b && c > d && c > e)
			j--;
		else if(d > a && d > b && d > c && d > e)
			j++;
		

	}

	*x = i;
	*y = j;
}
