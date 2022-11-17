#include <stdio.h>

// 1.
#define MIN(a, b) (a) > (b) ? (b) : (a)

// 2.
#define ISLOWER(c) ((c) >= 'a' && (c) <= 'z')

// 3.
#define ISLEAP(y) ((y) % 4 == 0 && (y) % 100 != 0) || (y) % 400 == 0

// 4.
#define CIRFER(r) 2 * PI* r
#define PI 3.14

int main(void) {
  int a = 3, b = 7;
  printf("%d\n", MIN(a + 2, b));
  printf("%d\n", ISLOWER('a'));
  printf("%d\n", ISLOWER('A'));
  printf("%d\n", ISLEAP(2001));
  printf("%d\n", ISLEAP(2000));
  printf("%.3f\n", CIRFER(2));
  printf("%.3f\n", CIRFER(1));
  return 0;
}