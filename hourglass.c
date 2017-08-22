/* hourglass.c
 * This program reads the durations of 2 hourglasses and a duration to measure,
 * to find the number of times to flip the hourglasses so that the total
 * number of flips is minimum.
 */

#include <stdio.h>

// Given function prototype must not be changed
int compute_flips(int, int, int, int *, int *);

int main (void) 
{
	int hg1, hg2;        // durations of hourglasses; assume hg1 < hg2
	int time;            // duration to measure; assume hg2 < time
	int flips1, flips2;  // number of flips needed for hourglasses

	printf("Enter 3 inputs: ");
	scanf("%d %d %d", &hg1, &hg2, &time);
	
	if(compute_flips(hg1, hg2, time, &flips1, &flips2))
		printf("Possible!\n%d flip(s) for %d-minute hourglass and %d flip(s) for %d-minute hourglass.\n", flips1, hg1, flips2, hg2);
	else
		printf("Impossible!\n");
	
	return 0;
}

int compute_flips(int hg1, int hg2, int time, int *flips1, int *flips2)
{
	int i, n;

	for(i = time/hg2;i >= 0; i--)
	{
		for(n = time/hg1; n>=0; n--)
		{
			if((n*hg1 + i*hg2) == time)
			{
				*flips1 = n;
				*flips2 = i;
				return 1;
			}
			//printf("%d %d %d\n",i, n, (n*hg2 + i*hg1));
		}
	}
	return 0;
}
