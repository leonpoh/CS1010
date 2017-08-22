/**
 * CS1010 AY2016/7 Semester 1 Lab3 Ex1
 * estimatePi.c
 * This program reads in a list of n distinct integers and
 * computes the estimate value for pi.
 * This program uses an external GCD function (provided in gcd.o).
 * LI Liwei
 * C1B
 */
#include <stdio.h>
#include "gcd.h"
#include <math.h>

double pi(int [], int); //define function prototype

int main(void) 
{
	int i,size, arr[50] = {0} ;
	double p;
	scanf("%d",&size); //read in the size of the array
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]); //read the numbers into the array
	}

	printf("Estimated pi = %.4f\n",pi(arr,size));
	
	return 0;
}

// Calculates the estimate value of pi after reading in a list of integers
double pi(int arr[], int size) 
{
	int i, n, common=0,total =0;
	for(i=0;i<size;i++)
	{
		for(n=i+1;n<size;n++)
		{
			if(gcd(arr[i],arr[n])==1)
				common++;
			total++;
		}
	}
	return sqrt(6.0*(double)total/(double)common);
}
