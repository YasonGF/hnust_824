#include <stdio.h>
#include <string.h>
#define N 80
// 找最小的字符串，输入n个字符串，输出其中最小的字符串

int main(void) {
  int i, n;
  char sx[N], smin[N];
  scanf("%d", &n);
  scanf("%s", sx);
  strcpy(smin, sx);

  for (i = 1; i < n; i++) {
    scanf("%s", sx);
    if (strcmp(sx, smin) < 0) {
      strcpy(smin, sx);
    }
  }
  printf("min is %s\n", smin);
  return 0;
}
