#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

#define InitSize 50
typedef int ElemType;

typedef struct List {
  ElemType *data;
  int length;
  int MaxSize;
} SqList;

bool ListInsert(SqList &L, int i, ElemType e);
bool ListDelete(SqList &L, int i, ElemType &e);

bool ListInit(SqList &L);
void ListPrint(SqList const &L);
bool ListDestroy(SqList &L);
bool ListEmpty(SqList const &L);
int ListLength(SqList const &L);

int LocateElem(SqList const &L, ElemType e);  // 按值查找
// ElemType GetElem(SqList const &L, int i);
bool GetElem(SqList const &L, int i, ElemType &e);  // 按位查找

int main(void) {
  SqList L;
  // 线性表的初始化
  ListInit(L);

  // 插入元素
  for (int i = 1; i <= 10; i++) {
    ListInsert(L, i, i * 2 + 1);
  }

  // 遍历线性表中元素
  ListPrint(L);

  // 删除元素
  ElemType e;
  ListDelete(L, 3, e);
  ListPrint(L);
  printf("e=%d\n", e);
  ListDestroy(L);
  return 0;
}

bool ListInit(SqList &L) {
  L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
  if (L.data == NULL) return false;
  memset(L.data, -1, InitSize);
  L.length = 0;
  L.MaxSize = 100;
  return true;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
  if (i < 1 || i > L.length) return false;
  e = L.data[i - 1];
  int j;
  for (j = i; j < L.length; j++) L.data[j - 1] = L.data[j];

  L.length--;
  return true;
}

int LocateElem(SqList const &L, ElemType e) {  // 按值查找
  int i;
  for (i = 0; i < L.length; i++)
    if (L.data[i] == e) return i + 1;
  return 0;  // 查找失败
}

bool GetElem(SqList const &L, int i, ElemType &e) {  // 按位查找
  if (i < 1 || i > L.length) return false;
  e = L.data[i - 1];
  return true;
}

bool ListInsert(SqList &L, int i, ElemType e) {
  if (i < 1 || i > L.length + 1) return false;  // 1. 定位置
  if (L.length >= L.MaxSize) return false;      // 2. 看空间
  int j;
  for (j = L.length; j >= i; j--) L.data[j] = L.data[j - 1];  // 3. 移位置

  L.data[i - 1] = e;
  L.length++;  // 4. 加表长
  return true;
}

void ListPrint(SqList const &L) {  //
  // L.length = 0;
  for (int i = 0; i < L.length; i++) printf("%d\t", L.data[i]);
  printf("\n");
}

bool ListDestroy(SqList &L) {
  L.length = 0;
  L.MaxSize = 0;
  free(L.data);
  L.data = nullptr;
  return true;
}

bool ListEmpty(SqList const &L) { return L.length == 0; }

int ListLength(SqList const &L) { return L.length; }