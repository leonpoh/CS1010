// MatrixOps.c
// To compute the matrix sum and matrix product of two matrices.

#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 10

void scanMatrix(float [][MAX_COL], int, int);
void printMatrix(float [][MAX_COL], int, int);
void sumMatrix(float [][MAX_COL], float [][MAX_COL], float [][MAX_COL], int, int);
void prodMatrix(float [][MAX_COL], float [][MAX_COL], float [][MAX_COL], int, int, int);

int main(void) {
	float matrixA[MAX_ROW][MAX_COL]; // input matrix
	float matrixB[MAX_ROW][MAX_COL]; // input matrix
	float matrixC[MAX_ROW][MAX_COL]; // sum matrix
	int matrixArows, matrixAcols; // number of rows and columns for matrix A
	int matrixBrows, matrixBcols; // number of rows and columns for matrix B

	printf("Matrix A:\n");
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &matrixArows, &matrixAcols);
	scanMatrix(matrixA, matrixArows, matrixAcols);

	printf("Matrix B:\n");
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &matrixBrows, &matrixBcols);
	scanMatrix(matrixB, matrixBrows, matrixBcols);

	if ((matrixArows == matrixBrows) &&
			(matrixAcols == matrixBcols)) {
		sumMatrix(matrixA, matrixB, matrixC, matrixArows, matrixAcols);
		printf("Sum matrix:\n");
		printMatrix(matrixC, matrixArows, matrixAcols);
	}
	else
		printf("Unmatched dimensions; cannot be added.\n");

	if (matrixAcols == matrixBrows) {
		prodMatrix(matrixA, matrixB, matrixC, matrixArows, matrixAcols, matrixBcols);
		printf("Product matrix:\n");
		printMatrix(matrixC, matrixArows, matrixBcols);
	}
	else
		printf("Unmatched dimensions; cannot be multiplied.\n");

	return 0;
}

// To sum mtxA and mtxB to obtain mtxC
void sumMatrix(float mtxA[][MAX_COL], float mtxB[][MAX_COL], 
		float mtxC[][MAX_COL], int row_size, int col_size) {
	int row, col;

	for (row=0; row<row_size; row++)
		for (col=0; col<col_size; col++) 
			mtxC[row][col] = mtxA[row][col] + mtxB[row][col];
}

// To multiply mtxA and mtxB to obtain mtxC
void prodMatrix(float mtxA[][MAX_COL], float mtxB[][MAX_COL], float mtxC[][MAX_COL], int mtxA_row_size, int mtxA_col_size, int mtxB_col_size) 
{
	int i, n, j;
	float sum = 0.0;
	for(i = 0; i < mtxA_row_size; i++)
	{
		for(n = 0; n < mtxB_col_size; n++)
		{
			for(j = 0; j < mtxA_col_size; j++)
			{
				sum += (mtxA[i][j] * mtxB[j][n]);
			}
			mtxC[i][n] = sum;
			sum = 0;
		}
	}
}

// To read values into mtx
void scanMatrix(float mtx[][MAX_COL], int row_size, int col_size) {
	int row, col;

	printf("Enter values for matrix:\n");
	for (row=0; row<row_size; row++)
		for (col=0; col<col_size; col++) 
			scanf("%f", &mtx[row][col]);
}

// To print values of mtx
void printMatrix(float mtx[][MAX_COL], int row_size, int col_size) {
	int row, col;

	for (row=0; row<row_size; row++) {
		for (col=0; col<col_size; col++) 
			printf("%.2f\t", mtx[row][col]);
		printf("\n");
	}
}

