#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int prime(int n);
// 什么是文件缓冲区？
/*
  文件缓冲区是内存中用于数据存储的数据块，在文件处理过程中，程序需要访问该缓冲区
  实现数据的存取。
*/


// 在c语言中，文件类型指针主要的功能是什么？

/*
  c语言中的FILE文件结构，其成员指针指向文件缓冲区，通过移动指针实现对文件的操作
  
*/

int main(void) {
  //
  int n = 2;
  int cnt = 0;

  FILE *fp;

  if ((fp = fopen("prime.txt", "w")) == NULL) {
    printf("File open error!\n");
    exit(0);
  }

  while (cnt < 500) {
    if (prime(n) != 0) {
      cnt++;
      fprintf(fp, "%d\n", n);
    }
    n++;
  }

  if (fclose(fp)) {
    printf("Can not close the file!\n");
    exit(0);
  }
  return 0;
}

int prime(int n) {
  if (n < 2) return 0;
  if (n != 2 && n % 2 == 0) return 0;

  for (int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) return 0;
  }
  return 1;
}
