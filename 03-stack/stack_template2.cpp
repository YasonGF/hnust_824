// 顺序栈的实现
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct {
  ElemType *data;
  int top;       // 栈顶指针指向栈顶元素的下一个位置
  int capacity;  // 栈的初始容量
} SqStack;

// 创、增、删、查、判空、判满
void InitStack(SqStack &s, int capacity);
void destroyStack(SqStack &s);
bool push(SqStack &s, ElemType x);
bool pop(SqStack &s, ElemType &x);
bool getTop(SqStack &s, ElemType x);
bool empty(SqStack &s);
bool overflow(SqStack &s);

void InitStack(SqStack &s, int capacity) {
  s.capacity = capacity;
  s.top = 0;
  s.data = (ElemType *)malloc(sizeof(ElemType) * capacity);
  memset(s.data, 0, sizeof(ElemType) * capacity);
}

void destroyStack(SqStack &s) {
  s.top = s.capacity = 0;
  free(s.data);
  s.data = NULL;
}

bool push(SqStack &s, ElemType x) {
  if (s.top == s.capacity) return false;
  s.data[s.top++] = x;
  return true;
}

bool pop(SqStack &s, ElemType &x) {
  if (s.top == 0) return false;
  x = s.data[--s.top];
  return true;
}

bool getTop(SqStack &s, ElemType x) {
  if (s.top == 0) return false;
  x = s.data[s.top - 1];
  return true;
}
bool empty(SqStack &s) { return s.top == 0; }
bool overflow(SqStack &s) { return s.top == s.capacity; }