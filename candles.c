/**
 * CS1010 AY2016/7 Semester 1 Lab2 Ex1
 * candles.c
 * Calculates the number of candles that can be burned in total, given two positive integers n and k
 * Li Liwei
 * C1B
 */

#include <stdio.h>

int count_candles(int candles, int residual);

int main(void) 
{	
	int candles, residual,totalCandles;

	printf("Enter number of candles and \n");//Gather user input
	printf("number of residuals to make a new candle: ");
	scanf("%d %d",&candles,&residual);
	
	totalCandles = count_candles(candles,residual);//Compute total candles
	
	printf("Total candles burnt = %d\n",totalCandles);

	return 0;
}

int count_candles(int candles, int residual) //Compute and retun the total candles burnt
{											 //Precondition: candles greater than or equals to residual
	int totalCandles;

	totalCandles = candles;//Candle count

	while(candles >= residual)//Checks precondition
	{
		candles = candles - residual + 1; //Adds one candle for every number of residuals collected
		totalCandles++;
	}

	return totalCandles;
}

