#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode {
  struct Tnode *lchild, *rchild;
  // tag = 0 : 表示指针指向左右孩子，tag = 1：表示指针是线索
  int ltag, rtag;
  char data;
} ThreadNode, *ThreadTree;

void createTree(ThreadTree *T, char *prestr, int *index);
void preOrder(ThreadTree T);

void preThread(ThreadTree T);
void visit(ThreadNode *q);
void createPreThread(ThreadTree T);

ThreadNode *get_next(ThreadNode *q);

ThreadNode *pre;  // 指向当前访问结点的前驱

int main(void) {
  char *str;
  str = "abd#g##e##cf#####";
  // str = "abd##e##c##";
  int index = 0;
  ThreadTree T;
  createTree(&T, str, &index);  // 初始化一个二叉树
  preOrder(T);
  printf("\nokok!\n");

  createPreThread(T);  // 先序线索化

  // 遍历先序线索二叉树
  ThreadNode *p;
  for (p = T; p; p = get_next(p)) {
    printf("%c", p->data);
  }

  return 0;
}

ThreadNode *get_next(ThreadNode *q) {
  if (q->ltag == 0) return q->lchild;
  return q->rchild;
}

void preThread(ThreadTree T) {
  if (T) {
    visit(T);
    if (T->ltag == 0) preThread(T->lchild);
    if (T->rtag == 0) preThread(T->rchild);
  }
}

void visit(ThreadNode *q) {
  if (q->lchild == NULL) {
    q->ltag = 1;
    q->lchild = pre;
  }
  if (pre && pre->rchild == NULL) {
    pre->rtag = 1;
    pre->rchild = q;
  }
  pre = q;
}

void createPreThread(ThreadTree T) {
  pre = NULL;
  if (T) {
    preThread(T);
    if (pre->rchild == NULL) pre->rtag = 1;
  }
}

// ---------------------------------------------------------------
void createTree(ThreadTree *T, char *prestr, int *index) {
  char c = prestr[*index];
  (*index) += 1;
  if (c == '#') {
    *T = NULL;
    return;
  }
  *T = (ThreadTree)malloc(sizeof(ThreadNode));
  (*T)->data = c;
  // tag 初始时全置为0，表示是指向左右孩子的指针
  (*T)->ltag = (*T)->rtag = 0;

  createTree(&(*T)->lchild, prestr, index);
  createTree(&(*T)->rchild, prestr, index);
}

void preOrder(ThreadTree T) {
  if (T) {
    printf("%c", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
  }
}