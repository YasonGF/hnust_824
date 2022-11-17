#include <stdio.h>

void InsertSort(int a[], int n);

int main(void) {
  int a[] = {
      // 3, 1, 7, 2, 5,
      0, 49, 38, 65, 97, 76, 13, 27, 49,
  };
  int len = sizeof a / sizeof a[0];
  InsertSort(a, len);
  //   print_arr(a, len);
  return 0;
}

void InsertSort(int a[], int n) {
  int i, j;
  for (i = 2; i < n; i++) {
    if (a[i] < a[i - 1]) {
      a[0] = a[i];
      for (j = i - 1; a[j] > a[0]; j--) a[j + 1] = a[j];
      a[j + 1] = a[0];
    }
  }
  a[0] = -0x003f003f;    // 哨兵
}

void print_arr(int a[], int n) {
  for (int i = 0; i < n; i++) printf("%d\n", a[i]);
}