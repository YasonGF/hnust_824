#include <stdio.h>

void func();

int main(void) {
  void (*p)() = func;
  p();
  printf("%d\n", !4);

  return 0;
}

void func() { printf("hh"); }