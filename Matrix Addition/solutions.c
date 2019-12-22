#include <stdlib.h>
#include <stddef.h>

// Have to return a single pointer instead of a pointer to pointers
int* matrix_addition(size_t n, int matrix_a[n][n], int matrix_b[n][n]) { 
    int *matrixSum = malloc(n*n*sizeof(int*));

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){          
            *(matrixSum + row*n + col) = matrix_a[row][col] + matrix_b[row][col];
        }
    }
    return matrixSum;
}

// Best Solutions

//Single Loop Solution
/*
#include <stdlib.h>

int* matrix_addition(size_t n, int * a, int * b) {
  int * ans = malloc(sizeof(int)*n*n);
  for (int i = 0; i <n*n; i++)
      ans[i] = a[i] + b[i];
  return ans;
}
*/

/*
#include <stdlib.h>
#include <stddef.h>

int* matrix_addition(size_t n, int matrix_a[n][n], int matrix_b[n][n]) {

  int i,j;
  int *ans;
  ans = malloc(sizeof(int)*n*n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      matrix_a[i][j] += matrix_b[i][j];
    }
  }
  memcpy(ans, matrix_a, sizeof(int)*n*n); // avoid dealing with a real multidim array
  return ans;
}
*/