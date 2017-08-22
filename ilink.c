// ilink.c
#include <stdio.h>
#define MAXSIZE 10

void printArr(int [][MAXSIZE], int);
void readFriends(int [][MAXSIZE], int);
void iSolitude(int [][MAXSIZE], int);
void uFriend(int [][MAXSIZE], int);

int main() {
	int friendArr[MAXSIZE][MAXSIZE] = { {0} };
	int size, pairsNum;
	int i, j, k;

	printf("Read in the number of users: ");
	scanf("%d", &size);

	printf("There are %d users, indexed from 0 to %d.\n", size, size-1);
	printf("Enter the number of pairs of direct friends: ");
	scanf("%d", &pairsNum);

	printf("Enter actual pairs of direct friends:\n");

	for (k = 0; k < pairsNum; k++) {
		scanf("%d %d", &i, &j);
		friendArr[i][j] = 1;
	}

	printArr(friendArr,size);

	for (i = 0; i < size; i++) {
		friendArr[i][i] = 1;
		for (j = i+1; j < size; j++) {
			if (friendArr[i][j] != friendArr[j][i]) {
				friendArr[i][j] = 1; 
				friendArr[j][i] = 1;
			}
		}
	}

	printf("The friendship matrix is:\n");
	printArr(friendArr, size);

	iSolitude(friendArr, size);

	uFriend(friendArr, size);

	return 0;
}

void iSolitude(int arr[][MAXSIZE], int size)
{
	int i, n, min = MAXSIZE, sum = 0;
	int num[MAXSIZE] = {0};

	for(i =0; i< size; i++)
	{
		for(n = 0; n< size; n++)
			sum+= arr[i][n];
		num[i] = sum;
		if(sum < min) min = sum;
		sum = 0;
	}
	printf("The least number of friends found is %d\n", min);
	for(i = 0; i< size; i++)
	{
		if(num[i]== min)
			printf("User %d has least number of friends\n", i);
	}
}

void uFriend(int arr[][MAXSIZE], int size)
{
	int i, n, k;
	
	for(i = 0; i < size-1; i++)
	{
		for(n = i+1; n<size; n++)
		{
			for(k = 0; k<size; k++)
			{
				if(arr[i][k] == 1 && arr[n][k] == 1 && arr[i][n] == 0 && i!= k && n!=k)
				{
					printf("(%d,%d) has a friend-of-friend relation.\n", i, n);
					break;
				}
			}
		}
	}
}
void printArr(int arr[][MAXSIZE], int size) 
{
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			printf("%3d", arr[i][j]);
		printf("\n");
	}
}

