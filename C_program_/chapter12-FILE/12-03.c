#include <stdio.h>
#include <stdlib.h>

// 将f12-2.txt文件备份保存为f12-3.txt
void test();

int main(void) {
  test();
  return 0;
}

void test() {
  FILE *fp1, *fp2;
  char ch = '\0';
  int cnt = 0;

  const char *src;
  src = "f12-2.txt";
  src = "hello.txt";
  if ((fp1 = fopen(src, "r")) == NULL) {
    printf("f12-2.txt open error!\n");
    exit(0);
  }
  const char *dest;
  dest = "f12-3.txt";
  dest = "hi.txt";
  if ((fp2 = fopen(dest, "w")) == NULL) {
    printf("f12-2.txt open error!\n");
    exit(0);
  }

  while (!feof(fp1)) {
    ch = fgetc(fp1);
    cnt++;
    if (ch != EOF) fputc(ch, fp2);
  }

  if (fclose(fp1)) {
    printf("cant close the file!\n");
    exit(0);
  }
  if (fclose(fp2)) {
    printf("cant close the file!\n");
    exit(0);
  }

  printf("cnt = %d\n", cnt);
}
