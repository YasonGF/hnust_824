#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
3 3
1 2 3
4 5 6
7 8 9

*/
int main(void) {
  int m, n;
  scanf("%d %d", &m, &n);

  // 动态申请一个m行n列的二维数组， int arr[m][n]
  int **arr = (int **)malloc(sizeof(int *) * m);

  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(sizeof(int) * n);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  printf("------------------------------------\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  // 释放
  for(int i = 0; i < m; i++) {
    free(arr[i]);
    arr[i] = NULL;
  }
  arr = NULL;

  return 0;
}