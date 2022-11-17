#include <stdio.h>

double fact(int n);

int main(void) {  //

  int n;
  scanf("%d", &n);

  printf("%.3f\n", fact(n));
  return 0;
}

double fact(int n) {
  double ans ;
  if (n == 1 || n == 0)
    ans = 1;
  else
    ans = n * fact(n - 1);
  return ans;
}