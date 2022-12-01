#include <stdio.h>

int main(void) {
  // 指向指针的指针
  int a = 10, b = 20, t;
  int *pa = &a, *pb = &b, *pt;

  int **ppa = &pa;
  int **ppb = &pb;
  int **ppt;
  // 操作1
  ppt = ppb;
  ppb = ppa;
  ppa = ppt;

  // 操作2
  pt = pb;
  pb = pa;
  pa = pt;

  // 操作3
  t = b;
  b = a;
  a = t;

  printf("*ppa = %d\n", **ppa);
  printf("*ppb = %d\n", **ppb);
  printf("*pa = %d\n", *pa);
  printf("*pb = %d\n", *pb);
  printf("a = %d\n", a);
  printf("b = %d\n", b);

  return 0;
}