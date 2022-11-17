#include <stdio.h>

int gcd(int m, int n);

int main(void) {  //
  int a, b;
  while(scanf("%d %d", &a, &b) != EOF){
    printf("%d\n", gcd(a, b));
  }
  return 0;
}

int gcd(int m, int n) {
  if (m % n == 0) return n;
  return gcd(n, m % n);
}