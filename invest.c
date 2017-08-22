/**
 * CS1010 AY2016/7 Semester 1 Lab1 Ex1
 * invest.c
 * This program calculates the final amount given principal amount,
 * interest rate, and number of years, based on compound interest.
 * Li Liwei
 * C1B
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	int principal, rate, numYears;
	float amt;

	printf("Enter principal amount: ");
	scanf("%d",&principal);
	printf("Enter interest rate   : ");
	scanf("%d",&rate);
	printf("Enter number of years : ");
	scanf("%d",&numYears);

	amt= (principal*(1.0-pow((rate/100.0),(numYears+1.0))))/(1.0-rate/100.0);  //Calculates final amount

	printf("Amount = $%.2f\n",amt);

	return 0;
}

