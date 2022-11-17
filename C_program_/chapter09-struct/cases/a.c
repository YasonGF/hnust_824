#include <stdio.h>
#include <stdlib.h>

// 结构的嵌套定义
struct address {  // 通信地址结构类型定义

  char city[10];    // 城市
  char street[20];  // 街道
  int code;         // 门牌号
  int zip;          // 邮编
};

struct student {
  int num;
  char name[10];
  int computer, english, math;
  double average;
};

struct nest_student {
  struct student stu;
  struct address addr;
};

int main(void) {
  printf("%d\n", sizeof(struct student));  // 4 + 10 + 12 + 8
  printf("%d\n", sizeof(struct address));  // 10 + 20 + 4 + 4
  printf("%d\n", sizeof(struct nest_student));
  return 0;
}
