#include <stdio.h>
// 指针和数组，及其存储单元

int main(void) {
  double a[2];
  double *p, *q;

  p = &a[0];
  q = p + 1;

  printf("%d\n", q - p);
  // printf("%d\n", (int)q - (int)p);

  return 0;
}
