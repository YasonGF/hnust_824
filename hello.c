#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

// #define InitSize 100
// typedef int ElemType ;

// typedef struct {
//   ElemType *data;
//   int length;
//   int MaxSize;
// }SqList;

// bool ListInsert(SqList L, int i, ElemType e) {

//     if(i < 1 || i > L.length + 1) return false; // 1. 定位置
//     if(L.length >= L.MaxSize) return false;     // 2. 看空间
//     int j ;
//     for(j=L.length; j >= i; j--) L.data[j] = L.data[j-1];   // 3. 移位置

//     L.data[i-1] = e;    
//     L.length ++;    // 4. 加表长
//     return true;
// }

int main(void)
{
  printf("hello world！\n");

    // SqList L;
    // L.data = (ElemType *) malloc(sizeof(ElemType)*InitSize);

  return 0;
}