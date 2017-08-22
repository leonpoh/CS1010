/**
 * CS1010 AY2016/7 Semester 1 Lab3 Ex2
 * subsequence.c
 * This program reads in a list of integers and find the
 * k-interval subsequence with the largest sum.
 * Li Liwei
 * C1B
 */

#include <stdio.h>

int scan_list(int []);
void sum_subsequence(int [], int, int []);

int main(void) 
{
	int list[10], size; // array and actual number of elements entered
	int answers[3];     // stores the required answers

	size = scan_list(list); 

	sum_subsequence(list, size, answers);

	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
			answers[0], answers[1], answers[2]);

	return 0;
}

// Read in elements for the array arr and returns the 
// number of elements read.
// Postcond: i > 0
int scan_list(int arr[]) 
{
	int num, i;

	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num>1)?"s":"");
	for (i=0; i<num; i++) 
	{
		scanf("%d", &arr[i]);
	}

	return num;
}

void sum_subsequence(int list[], int size, int answers[])//Calculates the maximum of a subsequence and returns the sum, subsequence and starting position
{
	int k, i, u, sum = 0;

	answers[0] = 0;

	for(k=1;k<=size;k++)
	{
		for(u = 0; u < k; u++)
		{
			for(i = u; i<size; i+=k)
			{
				sum += list[i];
			}
			if(sum > answers[0])
			{
				answers[0] = sum;
				answers[1] = k;
				answers[2] = u;
			}
			sum = 0;
		}
	}
}
// Write a description for this function below
// ...
// ...
//   ans[0] = maximum sum of solution subsequence
//   ans[1] = interval k of the solution subsequence
//   ans[2] = start position of the solution subsequence
