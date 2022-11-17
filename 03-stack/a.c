#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 50
typedef int ElemType;

typedef struct {
  ElemType data[MaxSize];
  int top;
} SqStack;