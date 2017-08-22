/**
 * rabbit.c 
 * A rabbit can jump at most 50 centimetres. It needs to cross a
 * river, with rocks positioned in a straight line in the river.
 * The program computes the minimum number of jumps for the rabbit
 * to cross to the other side of the river.
 */

#include <stdio.h>

int countJumps(int [], int);

int main(void) {
	int num_rocks, i;            // including opposite bank
	int arr[20];

	printf("Enter number of rocks: ");
	scanf("%d", &num_rocks);
	
	arr[0] = 0;
	for(i = 1; i<=num_rocks; i++)
		scanf("%d",&arr[i]);

	printf("%d\n",countJumps(arr, num_rocks));

	return 0;
}

// Counts the minimum number of jumps the rabbit needs
// to take to get to the other side of the river.
// Precond: size > 0
int countJumps(int rocks[], int size) 
{
	int i, n =0;
	int count = 0;

	for(i = 0; i<=size; i++)
	{
		if(rocks[i] - rocks[n] > 50)
		{
			if(rocks[i-1] - rocks[n] > 50)
				return -1;
			n = i-1;
			count++;
		//	printf("%d %d\n", n, count);
		}
	}
	if(rocks[i-1] - rocks[n] <= 50)
	{
		count++;
		return count;
	}
	else return -1;
}

