#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

typedef int ElemType;

typedef struct node {
  ElemType data;
  struct node *next;
} Lnode, *LinkList;

bool InitList(LinkList &L) {
  L = (LinkList)malloc(sizeof(Lnode));
  if (L == NULL) return false;
  L->data = 0X3F;
  L->next = NULL;
  return true;
}

void ClearList(LinkList L) {
  Lnode *p = L->next, *s;
  while (p) {
    s = p;
    p = p->next;
    free(s);
    s = NULL;
  }
}

void DestroyList(LinkList &L) {
  ClearList(L);
  L->next = NULL;
  free(L);
  L = NULL;
}

void PrintList(LinkList L) {
  Lnode *p = L->next;  // p指向第一个结点
  while (p) {
    printf("%-3d\t", p->data);
    p = p->next;
  }
  putchar('\n');
}

bool Empty(LinkList L) { return L->next == NULL; }

//前插的传统方式处理，传入一个头指针
bool InsertPriorNode(LinkList L, Lnode *p, ElemType ele) {
  Lnode *q = L, *s = NULL;
  while (q->next != p) q = q->next;

  s = (Lnode *)malloc(sizeof(Lnode));
  s->data = ele;
  q->next = s;
  s->next = p;
  return true;
}

//前插：在 p结点前插入元素ele
bool InsertPriorNode(Lnode *p, ElemType ele) {
  if (p == NULL) return false;
  Lnode *s = (Lnode *)malloc(sizeof(Lnode));
  if (s == NULL) return false;

  ElemType e = p->data;
  p->data = ele;
  s->data = e;

  s->next = p->next;
  p->next = s;
  return true;
}

//后插：在 p结点后插入元素ele
bool InsertNextNode(Lnode *p, ElemType ele) {
  if (p == NULL) return false;
  Lnode *s = (Lnode *)malloc(sizeof(Lnode));
  if (s == NULL) return false;

  s->data = ele;
  s->next = p->next;
  p->next = s;
  return true;
}

bool ListInsert(LinkList &L, int i, ElemType ele) {
  if (i < 1) return false;
  Lnode *p;   // p指向当前扫描到的结点
  int j = 0;  // p指向的是第几个结点
  p = L;      // p当前指向头结点，j=0
  while (p != NULL && j < i - 1) {
    p = p->next;
    j++;
  }

  if (p == NULL)  // i值非法，位序i大于当前表长length+1
    return false;

  // 找到p指向要插入的位置i前一个位置
  Lnode *s = (Lnode *)malloc(sizeof(Lnode));
  s->data = ele;
  s->next = p->next;
  p->next = s;
  return true;
}

//	删除结点p，且需修改其前驱结点的next指向
bool DeleteNode(Lnode *p) {
  if (p == NULL) return false;

  Lnode *q = p->next;
  if (q == NULL)   // 要删除的结点是最后一个
    return false;  // 只能从表头开始，依次寻找p的前驱

  p->data = q->data;
  p->next = q->next;

  free(q);
  q = NULL;
  return true;
}

bool ListDelete(LinkList &L, int i, ElemType &e) {
  if (i < 1) return false;
  Lnode *p;
  int j = 0;
  p = L;
  while (p && j < i - 1) {
    p = p->next;
    j++;
  }
  if (!p) return false;               // i is illegal
  if (p->next == NULL) return false;  // 第i-1个结点 后没有其他结点

  Lnode *q = p->next;
  e = q->data;
  p->next = q->next;
  free(q);
  q = NULL;
  return true;
}

// 按值查找
Lnode *LocateElem(LinkList L, ElemType ele) {
  Lnode *p = L->next;
  while (p && p->data != ele) p = p->next;
  return p;
}

// 按位查找
Lnode *GetElem(LinkList L, int i) {
  int j = 1;
  Lnode *p = L->next;

  if (i == 0) return L;

  if (i < 1) return NULL;

  while (p && j < i) {
    p = p->next;
    j++;
  }
  return p;
  //	if(i < 0)	return NULL;
  //	Lnode *p;
  //	int j = 0;
  //	p = L;
  //	while(p && j < i){
  //		p=p->next;j++;
  //	}
  //	return p;
}

// 求表长
int Length(LinkList L) {
  int len = 0;
  Lnode *p = L;
  while (p->next) {
    p = p->next;
    len++;
  }
  return len;
}

bool insert(LinkList &L, int i, ElemType ele) {
  Lnode *p = GetElem(L, i - 1);
  return InsertNextNode(p, ele);
}

// 头结点的单链表-头插法
LinkList List_headInsert(LinkList &L) {
  int x;
  Lnode *p;
  L = (LinkList)malloc(sizeof(Lnode));
  L->next = NULL;
  while (x != -1) {
    p = (Lnode *)malloc(sizeof(Lnode));
    p->data = x;
    p->next = L->next;
    L->next = p;
    scanf("%d", &x);
  }
  return L;
}

// 头结点的单链表-尾插法
LinkList List_tailInsert(LinkList &L) {
  int x;
  L = (LinkList)malloc(sizeof(Lnode));
  Lnode *s, *r = L;  
  scanf("%d", &x);
  while (x != -1) {
    s = (Lnode *)malloc(sizeof(Lnode));
    s->data = x;
    r->next = s;
    r = s;  
    scanf("%d", &x);
  }
  r->next = NULL; 
  return L;
}

// 带头结点的单链表的原地逆置
// bool reverseList(LinkList &L) {}

int main(void) {
  LinkList L;
  InitList(L);
 

  List_tailInsert(L);

//   reverseList(L);

  PrintList(L);
  DestroyList(L);
  PrintList(L);

  return 0;
}