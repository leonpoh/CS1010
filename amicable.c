// CS1010 AY2015/6 Semester 1
// PE1 Ex2: amicable.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>

void countPairs(int lower, int upper, int results[]);
int sumFactors(int number);

// Do NOT change the main function at all!
int main(void){
	int lower, upper, results[2] = {0};
	
	printf("Enter range: ");
	scanf("%d %d", &lower, &upper);

	countPairs(lower, upper, results);
	
	printf("Number of full pairs: %d\n", results[0]);
	printf("Number of half pairs: %d\n", results[1]);

	return 0;
}

void countPairs(int lower, int upper, int results[])
{
	int u,i,full=0,half=0;
	
	for(u=lower;u<=upper;u++)
	{
		i = sumFactors(u);
		if(u == sumFactors(i) && u!= i)
		{	
			//printf("in, %d, %d\n",u,i);
			if(i < lower || i > upper)
				half++;
			else
				full++;
		}
	}
//	printf("%d\n",full);
	results[0] = full/2;
	results[1] = half;
	// Remember to assign the calculated number of full pairs to results[0],
	// and the calculated number of half pairs to results[1]
}
int sumFactors(int number)
{
	int i,sum=1;
	for(i=2;i<number;i++)
	{
		if(number%i==0)
		{
			sum+=i;
		}
	}
	//printf("Sum = %d\n",sum);
	return sum;
}

// Remove extra comments (including this one) after you have completed the program
