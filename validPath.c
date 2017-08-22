// validPath.c
#include <stdio.h>
#include <string.h>

#define SIZE 6     // size (number of rows and columns) of maze
#define WALL 0
#define CELL 1
#define MAX_PATHLEN 10

void readMaze(int [][SIZE], int);
int isValid(int [][SIZE], char []);

int main(void) {
	int maze[SIZE][SIZE];
	char path[MAX_PATHLEN+1];

	readMaze(maze, SIZE); 

	printf("Enter path: ");
	scanf("%s", path);

	if (isValid(maze, path))
		printf("Path is valid.\n");
	else
		printf("Path is not valid.\n");

	return 0;
}

// Create the maze
void readMaze(int maze[][SIZE], int size) {
	int	r, c;

	printf("Enter maze:\n");
	for (r=0; r<size; r++)
		for (c=0; c<size; c++)
			scanf("%d", &maze[r][c]);
}

// Determine whether input path is valid in input maze
int isValid(int maze[][SIZE], char path[]) {
	int pathlen, i;
	int x=0, y=0;

	pathlen = strlen(path);
	
	for(i = 0; i < pathlen; i ++)
	{
		switch(path[i])
		{
			case 'W':
				if(y == 0 || maze[x][y-1] == 0) return 0;
				else y -= 1;
				//printf("N");
				break;
			case 'E':
				if(y == SIZE || maze[x][y+1] == 0) return 0;
				else y+=1;
				//printf("S");
				break;
			case 'N':
				if(x == 0 || maze[x-1][y] == 0) return 0;
				else x-=1;
				//printf("W");
				break;
			case 'S':
				if(x == SIZE || maze[x+1][y] == 0) return 0;
				else x+=1;
				//printf("E");
				break;
		}
	}

	return 1; // this is a stub
}

