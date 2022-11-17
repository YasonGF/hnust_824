#include <stdio.h>

// for test
#define PI 3.1415926
#define TRUE 1
#define FALSE 0

#define LONG_STRING \
  "It represents a long string that \
is used as an example."

#define R 1
#define S PI* R* R

#define F for (i = 0; i < n; i++)

#define MAX(a, b) a > b ? a : b
#define SQR(x) x* x

#define LOWCASE(c) (((c) >= 'a' && (c) <= 'z'))
#define CTOD(c) (((c) >= '0') && ((c) <= '9') ? c - '0' : -1)

int main(void) {  //
  int i;
  int n = 5;
  F { printf("hello %d\n", i + 1); }

  printf("%.7f\n", S);

  printf("%d\n", LOWCASE('s'));
  printf("%d\n", CTOD('4'));


  return 0;
}