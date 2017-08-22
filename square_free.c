/**
 * CS1010 AY2016/7 Semester 1 Lab2 Ex2
 * square_free.c
 * Li Liwei
 * C1B
 * To read 4 positive integers in the following sequence: lower1, upper1, lower2, upper2,
 * compute the number of square-free integers in two ranges [lower1, upper1] (both inclusive) and [lower2, upper2] (both inclusive)
 * compare and report which range has more square free numbers
 */

#include <stdio.h>
#include <math.h>

int squareFree(int lower, int upper);

int main(void) 
{
	int lower1, upper1, lower2, upper2, numbers1, numbers2;

	printf("Enter four positive integers: ");   //Gather user input
	scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);
	
	numbers1 = squareFree(lower1, upper1);      //Compute no. of square free numbers in each range
	numbers2 = squareFree(lower2, upper2);

	if (numbers1 > numbers2)                    //Compare and return the range with more square free numbers
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower1, upper1, numbers1);
	else if (numbers2 > numbers1)
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower2, upper2, numbers2);
	else
		printf("Both ranges have the same number of square-free numbers: %d\n", numbers1);

	return 0;
}

int squareFree(int lower, int upper) //Reads two positive integers, computes and returns the number of square-free numbers within the range
{
	int numbers, max, min;
	
	max = sqrt(upper);                          //Max square root that we are required to check
	numbers = upper - lower + 1;                //Number of integers in the range

	for (lower = lower; lower <= upper; lower++)//Check within the range given
	{
		for (min = 2; min <= max; min ++)       //Range of roots that we are required to check
		{	
			if ((lower % (int)pow(min,2)) == 0) //Check if the integer is divisible by the square of the root
			{
				numbers--;                      //If true minus one integer from range
				break;
			}
		}	
	}

	return numbers;
}
