// CS1010 AY2015/6 Semester 1
// PE1 Ex1: election.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>

void printSummary(double, double);

int main(void) 
{
	 double sampleCountA=0.0, sampleCountB=0.0;
	 double numVoterDivision, numStation, numVoteA, numVoteB,numVoterStation, numInvalidVote, i= 0;

	 // Use the following printf statements to print the appropriate messages.
	 printf("Enter number of voters in the division: ");
	 scanf("%lf",&numVoterDivision);

	 printf("Enter number of stations: ");
 	 scanf("%lf",&numStation);
	 
	 for(i=1;i<=numStation;i++)
	 {
 	 	printf("Enter number of voters in station %.0f: ", i); // Incomplete
	 	scanf("%lf",&numVoterStation);	 
	 	
		printf("Enter number of votes for Team A: ");
		scanf("%lf",&numVoteA);

	 	printf("Enter number of votes for Team B: ");
	 	scanf("%lf",&numVoteB);

		numInvalidVote = 100 - numVoteA - numVoteB;

		sampleCountA += ((numVoteA/(100-numInvalidVote))*(numVoterStation/numVoterDivision));
		sampleCountB += ((numVoteB/(100-numInvalidVote))*(numVoterStation/numVoterDivision));
	 }

     printf("Sample count for Team A = %.2f%%\n",(sampleCountA*100));
     printf("Sample count for Team B = %.2f%%\n",(sampleCountB*100));
	 
	 printSummary(sampleCountA*100, sampleCountB*100);

     return 0;
}

void printSummary(double sampleCountA, double sampleCountB)
{
	if(sampleCountA > sampleCountB)
	{
		if((sampleCountA - sampleCountB) < 5.0)
			printf("Team A narrowly wins this election.\n");
		else if ((sampleCountA - sampleCountB)>= 5.0 &&(sampleCountA - sampleCountB)  <=30.0)
			printf("Team A wins by a significant margin.\n");
		else 
			printf("Team A wins by a landslide.\n");
	}
	else if (sampleCountA < sampleCountB)
	{
		if((sampleCountB - sampleCountA) < 5.0)
			printf("Team B narrowly wins this election.\n");
		else if ((sampleCountB - sampleCountA)>30.0)
			printf("Team B wins by a landslide.\n");
		else
			printf("Team B wins by a significant margin.\n");
	}
	else
		printf("There is no winner in this election.\n");
}
// Remove extra comments (including this one) after you have completed the program
