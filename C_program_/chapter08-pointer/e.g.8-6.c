#include <stdio.h>
// 数组求和，指针求和
#define MAXN 10

int main(void) {
  int i, n, a[MAXN], *p;
  long sum = 0;

  printf("Enter n(n<=10): ");
  scanf("%d", &n);

  printf("Enter %d integers:", n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);

  for (i = 0; i < n; i++) sum = sum + *(a + i);

  printf("calculated by array, sum=%ld\n", sum);

  sum = 0;
  for (p = a; p < a + n; p++) sum = sum + *p;
  printf("calculated by pointer, sum=%ld\n", sum);

  return 0;
}
