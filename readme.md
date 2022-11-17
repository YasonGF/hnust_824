# 数据结构代码领背
## 一维数组静态、动态分配
 一维数组是线性表的顺序存储方式 
 静态分配方式的实现：
 ```cpp
 typedef int ElemType;

#define MaxSize 50

typedef struct {
  ElemType  data[MaxSize];
  int length;
} SqList;
 ```

动态分配方式的实现：
```CPP
#define InitSize 100
typedef int ElemType ;

typedef struct {
  ElemType *data;
  int length;
  int MaxSize;
}SqList;

SqList L;
L.data = (ElemType *) malloc(sizeof(ElemType)*InitSize);
```
## 顺序存储结构的插入与删除
在顺序表L的第i个位置上插入新元素e
```C
bool ListInsert(SqList &L, int i, ElemType e) {

    if(i < 1 || i > L.length + 1) return false; // 1. 定位置
    if(L.length >= L.MaxSize) return false;     // 2. 看空间
    int j ;
    for(j=L.length; j >= i; j--) L.data[j] = L.data[j-1];   // 3. 移位置

    L.data[i-1] = e;    
    L.length ++;    // 4. 加表长
    return true;
}
```

在顺序表L的第i个位置上删除新元素e
```CPP
bool ListDelete(SqList &L, int i, ElemType &e) {
  if (i < 1 || i > L.length) return false;
  e = L.data[i - 1];
  int j;
  for (j = i; j < L.length; j++) L.data[j - 1] = L.data[j];

  L.length--;
  return true;
}
```
## 线性表的查找(顺序存储结构)
```CPP
int LocateElem(SqList const &L, ElemType e) {  // 按值查找
  int i;
  for (i = 0; i < L.length; i++)
    if (L.data[i] == e) return i + 1;
  return 0;  // 查找失败
}
```

## 单链表
结构定义
```CPP
typedef char ElemType;
typedef struct LNode{
  struct LNode *next;
  ElemType data;
} LNode, *LinkList;
```
## 单链表的插入与建立
头插法
```CPP

```
尾插法
```CPP

```
## 单链表的查找

在单链表中按序号查找查找结点值
在单链表中按值查找结点

## 单链表L中元素的删除和插入

将值为x的结点插入到单链表的第i个位置上
将单链表的第i个位置上的结点删除

## 双链表
结构定义
```CPP
typedef char ElemType;
typedef struct DNode{
  struct DNode *prior, *next;
  ElemType data;
} DNode, *DLinkList;
```

## 双链表的插入与删除

在p之后，插入s

删除p的后继q

## 静态链表
```CPP
#define MaxSize 20
typedef char ElemType;
typedef struct {
  int next;
  ElemType data;
} SLinkList[MaxSize];
```



