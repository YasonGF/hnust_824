// 先序线索二叉树找指定结点p的先序序列后继next

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct TNode {
  struct TNode *lchild;
  struct TNode *rchild;
  int ltag;
  int rtag;
  ElemType data;
} ThreadNode, *ThreadTree;

// 以先序序列先建立一棵二叉树
void createBTree(ThreadTree *pTree, char *preStr, int *index);
// 未线索化前的中序遍历
void inOrder(ThreadTree T);

// 先序线索化
void createThreadTree(ThreadTree T);
void visit(ThreadNode *p, ThreadNode **pre);
void preThread(ThreadTree p, ThreadNode **pre);

// 先序线索二叉树的基本操作
// 1.先序线索二叉树找指定结点p的先序序列后继next
ThreadNode *getNextNode(ThreadNode *p);

// 2.先序线索二叉树找指定结点p的先序序列前驱pre
ThreadNode *getPreNode(ThreadNode *p);

int main(void) {
  ThreadTree T;
  char *str = "abd#g##e##cf###";
  int idx = 0;
  createBTree(&T, str, &idx);
  inOrder(T);
  putchar('\n');

  createThreadTree(T);
  printf("okok\n");

  // 先序线索二叉树的遍历
  ThreadNode *p;
  for (p = T; p; p = getNextNode(p)) printf("%c", p->data);

  return 0;
}

ThreadNode *getPreNode(ThreadNode *p) {
  if(p->ltag == 1) return p->lchild;
  // else
  // p肯定有左孩子，p的左右子树结点都不可能是p的先序前驱。
  // 因此找不到先序前驱，除非从头开始再遍历一遍
  // 或者改为三叉链表，增加一个父节点域
}

ThreadNode *getNextNode(ThreadNode *p) {
  // if (p->rtag == 1 || p->lchild) return p->rchild;
  if (p->ltag == 0) return p->lchild;
  return p->rchild;
}

// 先序线索化
void createThreadTree(ThreadTree T) {
  ThreadTree pre = NULL;
  if (T) {
    preThread(T, &pre);
    if (pre->rchild == NULL) pre->rtag = 1;
  }
}
void visit(ThreadNode *p, ThreadNode **pre) {
  if (p->lchild == NULL) {
    p->ltag = 1;
    p->lchild = *pre;
  }
  if (*pre && (*pre)->rchild == NULL) {
    (*pre)->rtag = 1;
    (*pre)->rchild = p;
  }
  *pre = p;
}
void preThread(ThreadTree p, ThreadNode **pre) {
  if (p) {
    visit(p, pre);
    if (p->ltag == 0) preThread(p->lchild, pre);
    if (p->rtag == 0) preThread(p->rchild, pre);
  }
}

void createBTree(ThreadTree *pTree, char *preStr, int *index) {
  // 先建立一棵二叉树
  char c = *(preStr + *index);
  *index += 1;
  if (c == '#') {
    (*pTree) = NULL;
    return;
  }
  (*pTree) = (ThreadNode *)malloc(sizeof(ThreadNode));
  (*pTree)->data = c;
  (*pTree)->ltag = (*pTree)->rtag = 0;
  createBTree(&(*pTree)->lchild, preStr, index);
  createBTree(&(*pTree)->rchild, preStr, index);
}

void inOrder(ThreadTree T) {  // 未线索化前的中序遍历
  if (T) {
    inOrder(T->lchild);
    printf("%c", T->data);
    inOrder(T->rchild);
  }
}
