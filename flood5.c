#include <stdio.h>
#include <stdbool.h>

#define r 10
#define c 10

void scanFlood(int n, int max[r][c], int i, int j);
void floodTest(int n, int max[r][c], int i, int j); 
void printFlood(int n, int max[r][c], int i, int j);
void peri(int n, int max[r][c], int i, int j);

int main(void) {
   int n, count;
   int max[r][c], i, j;

   scanf("%d", &n);
   scanFlood(n, max, i, j);
   floodTest(n, max, i, j);
   printFlood(n, max, i, j);

   return 0;
}

void scanFlood(int n, int max[r][c], int i, int j) {

   for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
         scanf("%d", &max[i][j]);
      }
   }
   return;
}

void floodTest(int n, int max[r][c], int i, int j) {
   int k;
   int count;

   for (i = 0; i < 10; i++) {
      for (j = 0; j < 10 ; j++) {
         if ((i == 0 || j == 0 || i == 9 || j == 9) && (max[i][j] <= n)) {
            max[i][j] =  -1;
         }
      }
   }

   for (k = 0; k < 10; k++) {
      for (i = 0; i < 10; i++) {
         for (j = 0; j < 10 ; j++) {
            if ((max[i-1][j] == -1 || max[i][j-1] == -1 || max[i+1][j] == -1 || max[i][j+1] == -1) && max[i][j] <= n) {
               max[i][j] = -1;
            }
         }
      }
   }
   return;
}

void printFlood(int n, int max[r][c], int i, int j) {
   int count=0, area=0;

   for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
         if(max[i][j] == -1) {
            printf("*");
         }
         else {
            printf("%d", max[i][j]);
         }
      } 
      printf("\n");
   }
   for (i = 0; i < 10; i++) {
      for (j = 0; j < 10; j++) {
         if(max[i][j] == -1) {
            count++;
         }
      }
   }
   area = (i * j) - count;

   printf("area = %d square units; ", area);

   return;
}

void peri(int n, int max[r][c], int i, int j) {
   int peri=0;

   for (i = 0; i < 10; i++) {
      for (j = 0; j <= 10; j++) {
         if (max[i][j] != -1) {
            if (i == r - 1 || max[i][j] == -1) {
               peri++;
            }
            if (i == 0 || max[i-1][j] == -1) {
               peri++;
            }
            if (j == c - 1 || max[i][j+1] == -1) {
               peri++;
            }
            if (j == 0 || max[i][j-1] == -1) {
               peri++;
            }
         }
      }
   }
   printf("perimeter = %d units\n", peri);

   return;
}
