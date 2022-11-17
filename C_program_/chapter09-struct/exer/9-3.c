// 计算三门课程的课程平均分

#include <stdio.h>
#include <stdlib.h>

struct student {
  int num;
  char name[10];
  int computer, english, math;
  double average;
};

int main(void) {
  int i, n;
  struct student  stu;

  double c, e, m;

  printf("Input n:");
  scanf("%d", &n);
  printf("Input the student's number, name, and course scores\n");
  for (i = 1; i <= n; i++) {
    printf("No.%d:", i);
    scanf("%d%s%d%d%d", &stu.num, &stu.name, &stu.math, &stu.english,
          &stu.computer);

    c += stu.computer;
    e += stu.english;
    m += stu.math;

    
  }
  printf("computer=%.2f\n", c/3);
  printf("english=%.2f\n", e/3);
  printf("math=%.2f\n", m/3);
  return 0;
}