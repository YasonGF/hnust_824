#include <stdio.h>
#include <string.h>

#define MaxSize 50
// 使用文件包含连接各程序文件模块
#include "computing.c"
#include "input_output.c"
#include "search.c"
#include "update.c"

typedef struct student {
    int num;
    char name[10];
    int computer, english, math;
    double average;
} student;

int COUNT = 0;  // 记录当前学生总数

int main(void) {  //


    student stus[MaxSize];
    new_student(stus);  
    output_student(stus);

  return 0;
}