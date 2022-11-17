#include <stdio.h>

int max(int a, int b, int c);  // 求a、b、c中最大的数

#define MAX2(a, b) ((a) > (b) ? (a) : (b))
#define MAX3(a, b, c) MAX2(MAX2(a, b), c)

int main(void) { 
  int a, b, c;
  while(scanf("%d%d%d", &a, &b, &c) != EOF) {
    printf("max = %d\n", max(a, b, c));
    printf("MAX3 = %d\n", MAX3(a, b, c));
  }
  return 0; }


int max(int a, int b, int c){
  int max = a;
  if(max < b) max = b;
  if(max < c) max = c;
  return max;
}
