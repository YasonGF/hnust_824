#include <stdio.h>
// 冒泡排序
#define MAXN 10

void swap(int *px, int *py);
void bubble(int a[], int n);

int main(void) {
  int n, a[MAXN];
  int i;

  printf("Enter n(n <= 10): ");
  scanf("%d", &n);
  printf("Enter %d integers: ", n);

  for (i = 0; i < n; i++) scanf("%d", &a[i]);

  bubble(a, n);
  printf("After sorted: ");
  for (i = 0; i < n; i++) printf("%3d", a[i]);

  return 0;
}
void bubble(int a[], int n) {
  int i, j;
  for (i = 1; i < n; i++) {
    for (j = 0; j < n-i; j++) {
      if (a[j] > a[j + 1]) swap(&a[j], &a[j + 1]);
    }
  }
}
void swap(int *px, int *py) {
  int t = *px;
  *px = *py;
  *py = t;
}