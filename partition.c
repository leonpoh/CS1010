// partition.c
#include <stdio.h>

void printArray(int [], int);
void partition(int [], int, int);

int main(void) {
	int i, size, pivot;
	int arr[20];

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	printf("Enter %d integers: ", size);
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);

	printf("Enter pivot: ");
	scanf("%d",&pivot);

	partition(arr,size,pivot);
	printArray(arr, size);

	return 0;
}

// Print array arr
void printArray(int arr[], int size) {
	int i;

	for (i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void partition(int arr[], int size, int pivot)
{
	int i, u, temp, n =0;
	
	for(i=0;i<size;i++)
	{
		if(arr[i] < pivot)
		{
			for(u=0; u<size; u++)
			{
				if(arr[u] > pivot)
				{
					temp = arr[u];
					arr[u] = arr[i];
					arr[i] = temp;
					break;
				}
			}
		}
	}
}
