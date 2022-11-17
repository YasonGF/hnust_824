// 4、判断一个表达式中括号是否配对(假设只包含圆括号)
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
char stack[50];
int top = -1;

/*
扫描字符序列，左括号入栈，遇到右括号，
1）弹出栈顶元素，与之比较，不相符返回false
2）此时栈空，返回false
否则继续扫描到'\0'结束

若栈非空，则说明有多余的左括号，返回false

*/
bool t04(char *str) {
  while (*str) {
    if (*str == '(') stack[++top] = *str;
    if (*str == ')') {
      if (top == -1) return false;

      char x = stack[top--];
      if (x != '(') return false;
    }
    str++;
  }
  if (top != -1) return false;
  return true;
}

int main(void) {
  char str[100];
  strcpy(str, "(3+4)*5/(7-3)+1");

  if (t04(str)) {
    printf("okok\n");
  } else {
    printf("not today!\n");
  }

  return 0;
}
