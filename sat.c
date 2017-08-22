// CS1010 AY2012/3 Semester 1
// PE1 Ex1: sat.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:
#include <stdio.h>

float compute_iqscore(int, int);
int compute_percentile(int, int, int);

int main(void) {

	int verbal, math, writing ;

	printf("Enter scores: ");
	scanf("%d %d %d",&verbal, &math, &writing);

	printf("The SAT score is in the %d percentile.\n",compute_percentile(verbal,math,writing));
	printf("The IQ score is %.2f\n",compute_iqscore(verbal,math));
	if(compute_iqscore(verbal,math) > 120.0 || (verbal > 600 && math > 600 && writing > 600))
		printf("Wow, this is amazing!\n");

	return 0;

}

float compute_iqscore(int verbal, int math)
{
	return (0.095*math + 0.003*verbal +50.241);
}

int compute_percentile(int verbal, int math, int writing)
{
	int total;

	total = verbal + math + writing;

	if(total >= 2200)
		return 99;
	else if (total >= 2000)
		return 95;
	else if (total >= 1500)
		return 50;
	else
		return 10;
}
