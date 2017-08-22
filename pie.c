#include <stdio.h>
#define MAX_SLICES 20

int maxCherries(int [], int, int);

int main()
{
	int i, slices, pie[20] , max, total = 0;

	printf("Enter number of slices: ");
	scanf("%d",&slices);

	printf("Enter numbers of cherries: ");
	for(i=0;i<slices;i++)
	{
		scanf("%d",&pie[i]);
		total += pie[i];
	}
	max = maxCherries(pie, slices, total);

	printf("The maximum number of cherries Alice can get is %d.\n", max); // Incomplete

	return 0;
}

int maxCherries(int arr[], int slices, int total)
{
	int i, n, min= 0;
	int max = 0;

	for(i = 0; i<slices; i++)
	{
		for(n = i; n<slices; n++)
		{
			min += arr[n];
			if(total - min > min)
			{
				if(min > max)
					max = min;
			}
			else
			{
				if(total - min > max)
					max = (total - min);
			}
		}
		min = 0;
	}
	return max;
}
