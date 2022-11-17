#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef char ElemType;

typedef struct {
  ElemType data[MaxSize];
  int top;  // 指向栈顶元素
} Seqstack;

bool stack_overflow(Seqstack *s);
bool stack_empty(Seqstack *s);
void stack_init(Seqstack *s);
bool push(Seqstack *s, ElemType x);
bool pop(Seqstack *s, ElemType *x);
bool top(Seqstack *s, ElemType *x);

/*-____------________--___---________-__________----____-----____----*/
bool stack_overflow(Seqstack *s) { return s->top == MaxSize - 1; }

bool stack_empty(Seqstack *s) { return s->top == -1; }

void stack_init(Seqstack *s) { s->top = -1; }

// -----------------------------------------------------------------

bool push(Seqstack *s, ElemType x) {
  if (stack_overflow(s)) return false;
  s->data[++s->top] = x;
  return true;
}

bool pop(Seqstack *s, ElemType *x) {
  if (stack_empty(s)) return false;
  *x = s->data[s->top--];
  return false;
}

bool top(Seqstack *s, ElemType *x) {
  if (stack_empty(s)) return false;
  *x = s->data[s->top];
  return false;
}