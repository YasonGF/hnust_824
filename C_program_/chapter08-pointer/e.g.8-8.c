#include <stdio.h>
// 输入一个长度小于80的字符串，按照规则对字符串进行压缩
// 输出压缩后的字符串。

// 压缩规则：
// 如果某个字符x连续出现n（n>1）次,
// 则将这n个字符替换为“nx”的形式；否则保持不变。
#define MAXLINE 80

void zip(char *p);

int main(void) {
  char line[MAXLINE];
  printf("Input the string: ");

  fgets(line, 0, stdin);
  zip(line);
  puts(line);

  return 0;
}

void zip(char *p) {}