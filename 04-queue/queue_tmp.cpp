// 循环队列
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 10
typedef int ElemType;

typedef struct {
  ElemType *base;
  int front;  // 队头指针指向队头元素
  int rear;   // 队尾指针指向
} SqQueue;

void init_queue(SqQueue &queue);

void en_queue(SqQueue &q, ElemType x);   // 入队
void de_queue(SqQueue &q, ElemType &x);  // 出队

void init_queue(SqQueue &queue) {
  queue.base = (ElemType *)malloc(sizeof(ElemType) * MaxSize);
  queue.front = 0;
}

void en_queue(SqQueue &q, ElemType x);
