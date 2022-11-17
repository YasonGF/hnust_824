#include <stdio.h>

void hanoi(int n, char a, char b, char c);

int main(void) {  //
  int n;

  do {
    printf("input the number of disk:");
    scanf("%d", &n);
    if(n <= 0) break;
    printf("the steps for %d disk are:\n", n);

    hanoi(n, 'a', 'b', 'c');

  } while (1);
  return 0;
}

void hanoi(int n, char a, char b, char c) {
  if (n == 1)
    printf("%c --> %c\n", a, b);
  else {
    hanoi(n - 1, a, c, b);
    printf("%c --> %c\n", a, b);
    hanoi(n - 1, c, b, a);
  }
}