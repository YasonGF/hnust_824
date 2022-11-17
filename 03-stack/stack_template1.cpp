// 顺序栈的实现
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
typedef int ElemType;

typedef struct {
  ElemType data[MaxSize];
  int top;  // 栈顶指针指向栈顶元素
} SqStack;

// 创、增、删、查、判空、判满
void InitStack(SqStack &s);
bool push(SqStack &s, ElemType x);
bool pop(SqStack &s, ElemType &x);
bool getTop(SqStack &s, ElemType x);
bool empty(SqStack &s);
bool overflow(SqStack &s);


bool push(SqStack &s, ElemType x) {
  if (s.top == MaxSize - 1) return false;

  s.data[++s.top] = x;
  return true;
}

bool pop(SqStack &s, ElemType &x) {
  if (empty(s)) return false;
  x = s.data[s.top--];
  return true;
}

bool getTop(SqStack &s, ElemType x) {
  if (empty(s)) return false;
  x = s.data[s.top];
  return true;
}

void InitStack(SqStack &s) { s.top = -1; }
bool empty(SqStack &s) { return s.top == -1; }
bool overflow(SqStack &s) { return s.top == MaxSize - 1; }