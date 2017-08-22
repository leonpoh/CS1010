/**
 * CS1010 AY2016/7 Semester 1 Lab4 Ex1
 * square.c
 * Author: Jin
 * Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.
 * Li Liwei
 * C1B
 */

#include <stdio.h>
#define MAXSIZE 9

int scanSquare(int [][MAXSIZE]);
int isSemiMagic(int [][MAXSIZE], int);

int main(void) 
{
	int size, arr[MAXSIZE][MAXSIZE] = {{0}};

	size = scanSquare(arr);
	if(isSemiMagic(arr,size))
		printf("It is a semi-magic square.\n");  
	else
		printf("It is not a semi-magic square.\n");

	return 0;
}

int scanSquare(int arr[][MAXSIZE])//Reads data into the array and returns size of array 
{ 
	int size, i, n;

	printf("Enter size of square: ");
	scanf("%d",&size);
	printf("Enter values in the square: \n");
	for(i=0;i<size;i++)
	{
		for(n=0;n<size;n++)
		{
			scanf("%d",&arr[i][n]);
		}
	}
	return size;
}

int isSemiMagic(int arr[][MAXSIZE], int size)//Checks whether the square is a magic square; returns 1 if yes, 0 if no
{
	int fixedSum = 0,vertSum = 0, horSum = 0;
	int check[MAXSIZE] = {0};
	int i, n, k, count = 0;

	for(i=0;i<size;i++)
		fixedSum += arr[0][i];
	for(i=0;i<size;i++)
	{
		for(n=0;n<size;n++)
		{
			horSum += arr[i][n];
			vertSum += arr[n][i];
			check[count] = arr[i][n];
			for(k=0;k<count;k++)
				if(arr[i][n] == check[k]) return 0;
			count ++;
		} 
		if(horSum!=fixedSum || vertSum!=fixedSum)
			return 0;
		horSum = 0;
		vertSum= 0;
	}

	return 1;
}
