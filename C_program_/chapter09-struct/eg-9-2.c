// 学生成绩排序

#include <stdio.h>
#include <stdlib.h>

struct student {
  int num;
  char name[10];
  int computer, english, math;
  double average;
};

int main(void) {
  int i, index, j, n;
  struct student students[50], temp;

  printf("Input n:");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Input the info of No.%d:", 1 + i);

    printf("number: ");
    scanf("%d", &students[i].num);

    printf("name: ");
    scanf("%s", students[i].name);

    printf("math score:");
    scanf("%d", &students[i].math);

    printf("english score:");
    scanf("%d", &students[i].english);

    printf("computer score:");
    scanf("%d", &students[i].computer);

    students[i].average =
        (students[i].computer + students[i].math + students[i].english) / 3.0;
  }

  // 选择排序
  // for()

  return 0;
}