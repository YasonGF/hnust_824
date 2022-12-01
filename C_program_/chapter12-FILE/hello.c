#include <stdio.h>
#include <stdlib.h>

void test() {
  printf("test hehe\n");
  // exit(0);
  return;
}

int main(void) {
  //
  FILE *fp = NULL;
  fp = fopen("hello.txt", "w");
  if (fp == NULL) {
    printf("%s", "cant find hello.txt");
    exit(1);
  }
  fprintf(fp, "%s", "hello world!\\n");

  if (fclose(fp)) {
    printf("cant close the file!\n");
    exit(0);
  }

  test();
  puts("over");
  return 0;
}