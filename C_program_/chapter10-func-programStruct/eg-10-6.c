#include <stdio.h>

int max(int a[], int m, int n);  // 分治法求a[m]到a[n]中最大值的递归函数
int min(int a[], int m, int n);

void insert_sort(int a[], int n);
void print_arr(int a[], int n);

int main(void) {  //

  int a[] = {
      // 32, 51, 64, 36, 75, 13, 6, 87, 3, 2, 97, 67, 61, 28, 79, 83,
      2, 4, 5, 6, 1, 7, 
  };
  int len = sizeof a / sizeof a[0];
  printf("%d\n", max(a, 0, len - 1));
  printf("%d\n", min(a, 0, len - 1));

  insert_sort(a, len);
  print_arr(a, len);

  return 0;
}

void print_arr(int a[], int n){
  for(int i = 0; i < n; i ++) {
    if(i == 0) printf("%d", a[i]);
    else printf(" %d", a[i]);
  }

}

void insert_sort(int a[], int n){
  for(int i = 1; i < n ; i ++) {
    if(a[i-1] > a[i]) {
      int temp = a[i];
      int j;
      for (j = i - 1; j >= 0 && a[j] > temp; j--) a[j + 1] = a[j];
      a[j + 1] = temp;
    } 
  }
}

int min(int a[], int m, int n) {
  int k, u, v;
  if (m == n) return a[m];
  k = (m + n) / 2;
  u = min(a, m, k);
  v = min(a, k + 1, n);
  return u > v ? v : u;
}

int max(int a[], int m, int n) {
  int k, u, v;
  if (m == n) return a[m];
  k = (m + n) / 2;
  u = max(a, m, k);
  v = max(a, k + 1, n);

  return u > v ? u : v;
}
