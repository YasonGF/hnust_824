/*
假设一个序列为 HSSHHHS，运用栈的知识，编写算法将 S 全部提到 H 之前，
即为 SSSHHHH
*/

#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void t05(char *str) {
    while(*str) {
        if(*str == 'H') stack[++top] = *str; 
        if(*str == 'S') printf("%c", *str);
        str++;
    }
    while(top!=-1) {
        char x = stack[top--];
        printf("%c", x);
    }
}

int main(void) {
  char str[100];
  strcpy(str, "HSSHHHSSHHS");

  t05(str);

  return 0;
}