// box.c
// To compute the number of boxes with length, width and height
// in the range [lower,upper] whose surface area is larger than
// volume.
#include <stdio.h>

typedef struct
{
	int area, volume;
}results_t;

results_t calculate(int, int, int);

int main(void) 
{
	results_t results;
	int lower, upper;
	int i,n,total = 0;

	printf("Enter lower and upper limits: ");
	scanf("%d %d", &lower, &upper);
	
	for(;lower<=upper;lower++)
	{
		for(i=lower;i<=upper;i++)
		{
			for(n=i; n <= upper; n++)
			{
				results = calculate(lower, i, n);
				if(results.area >= results.volume)
					total++;
			}
		}
	}
	printf("Answer = %d\n",total);

	return 0;
}

results_t calculate(int x, int y, int z)
{
	results_t results;

	results.area = (2*x*y)+(2*y*z)+(2*z*x);
	results.volume = x*y*z;

	return results;
}
