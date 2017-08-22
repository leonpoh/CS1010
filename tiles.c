// tiles.c

typedef struct{
	int length;
	int width;
	float price;
}tile_t;

#include <stdio.h>
#define MAX_TILES 20

int scan_tiles(tile_t []);
float difference(tile_t [], int);

int main(void) {
	tile_t tiles[MAX_TILES];
	int num_tiles;
	
	num_tiles = scan_tiles(tiles);

	printf("Largest difference = $%.2f\n",
	       difference(tiles, num_tiles));

	return 0;
}

// To read tiles' data into array tiles
// Return the number of tiles read
int scan_tiles(tile_t tiles[]) {
	int num_tiles,i;

	printf("Enter number of tiles: ");
	scanf("%d",&num_tiles);
	printf("Enter data for %d tiles:\n", num_tiles);
	for(i = 0; i < num_tiles; i++)
		scanf("%d %d %f",&tiles[i].length, &tiles[i].width, &tiles[i].price); 
	return num_tiles;
}

// Return the difference in cost between 
// the cheapest tile and the most expensive tile.
float difference(tile_t tiles[], int size) 
{
	float min, max, current;
	int i;

	min = max = tiles[0].length * tiles[0].width * tiles[0].price;

	for(i = 0; i < size; i++)
	{
		current = tiles[i].length*tiles[i].width*tiles[i].price;
		if(current > max)
			max = current;
		if(current < min) 
			min = current;
	}
	return max- min;
}

