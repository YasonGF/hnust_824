#include <stdio.h>

void reverse(int num);

int main(void) {  //
  int n;
  while(scanf("%d", &n) != EOF){
    reverse(n);
  }
  return 0;
}

void reverse(int num){
  if(num <= 9) {
    printf("%d", num);
  }else {
    printf("%d", num % 10);
    reverse(num / 10);
  }
}