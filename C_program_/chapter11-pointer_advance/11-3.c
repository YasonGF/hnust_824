#include <stdio.h>
// 使用二级指针改写11-1
int main(void) {
  int i, flag = 0;
  char ch;
  const char *color[5] = {
      "red", "blue", "yellow", "green", "black",
  };

  const char **p = color;
  printf("Input a letter:");
  ch = getchar();
  for (i = 0; i < 5; i++) {
    if(p[i][0] == ch){
      flag = 1;
      puts(p[i]);
    }
  }
  if (flag == 0) {
    printf("not found\n");
  }
  return 0;
}