#include <stdio.h>
// 取地址运算和间接访问运算
int main(void) {
  int a = 3, *p;
  p = &a;
  printf("a=%d, *p=%d\n", a, *p);

  *p = 10;
  printf("a=%d, *p=%d\n", a, *p);

  printf("Enter a:");
  scanf("%d", &a);

  printf("a=%d, *p=%d\n", a, *p);
  (*p)++;
  printf("a=%d, *p=%d\n", a, *p);

  return 0;
}
