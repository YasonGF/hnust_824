#include <stdio.h>

void insert_sort(int a[], int n);  // 自定义实现的版本
void print_arr(int a[], int n);

int main(void) {
  int a[] = {
      // 3, 1, 7, 2, 5,
      49, 38, 65, 97, 76, 13, 27, 49,
  };
  int len = sizeof a / sizeof a[0];
  insert_sort(a, len);
  //   print_arr(a, len);
  return 0;
}

void insert_sort(int a[], int n) {  // 无哨兵
  int i, j, tmp;
  for (i = 1; i < n; i++) {
    tmp = a[i];
    for (j = i - 1; j >= 0 && a[j] > tmp; j--) {
      a[j + 1] = a[j];
    }
    a[j + 1] = tmp;
  }
}

void InsertSort(int a[], int n) {
  int i, j, tmp;
  for (i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      tmp = a[i];
      for (j = i - 1; j >= 0 && a[j] > tmp; j--) a[j + 1] = a[j];
      a[j + 1] = tmp;
    }
  }
}

void print_arr(int a[], int n) {
  for (int i = 0; i < n; i++) printf("%d\n", a[i]);
}