#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef char ElemType;

typedef struct {
  // int *data;
  ElemType data[MaxSize];
  int front;  // 指向队头元素
  int rear;   // 指向队尾元素的下一个位置
} SQueue;

void queue_init(SQueue *q);
bool is_empty_queue(SQueue *q);
bool is_overflow_queue(SQueue *q);
bool en_queue(SQueue *q, ElemType x);
bool de_queue(SQueue *q, ElemType *x);

void queue_init(SQueue *q) {  //
  q->front = q->rear = 0;
}

bool is_empty_queue(SQueue *q) {  //
  return q->front == q->rear;
}

bool is_overflow_queue(SQueue *q) {
  return (q->rear + 1) % MaxSize == q->front;
}

bool en_queue(SQueue *q, ElemType x) {
  if (is_overflow_queue(q)) return false;
  q->data[q->rear] = x;
  q->rear = (q->rear + 1) % MaxSize;
  return true;
}

bool de_queue(SQueue *q, ElemType *x) {
  if (is_empty_queue(q)) return false;
  *x = q->data[q->front];
  q->front = (q->front + 1) % MaxSize;
  return true;
}