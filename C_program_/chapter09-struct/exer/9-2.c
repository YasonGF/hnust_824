#include <stdio.h>
#include <stdlib.h>

struct student {
  int num;
  char name[10];
  int computer, english, math;
  double average;
  struct date birthday ;
};

// 结构的嵌套定义
struct date {  // 通信地址结构类型定义
  int year;
  int month;
  int day;
};