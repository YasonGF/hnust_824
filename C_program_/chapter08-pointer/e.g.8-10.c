#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, sum, i, *p;
  printf("Enter n:");
  scanf("%d", &n);
  p = (int *)calloc(n, sizeof(int));
  
  if (p == NULL) {
    printf("Not able to allocate memory.\n");
    exit(1);
  }
  printf("Enter %d integers:", n);
  for (i = 0; i < n; i++) scanf("%d", p + i);

  sum = 0;
  for (i = 0; i < n; i++) sum = sum + *(p + i);
  printf("the sum is %d\n", sum);
  free(p);

  return 0;
}