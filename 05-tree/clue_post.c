#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode {
  struct Tnode *lchild, *rchild;
  // tag = 0 : 表示指针指向左右孩子，tag = 1：表示指针是线索
  int ltag, rtag;
  char data;
} ThreadNode, *ThreadTree;

void createTree(ThreadTree *T, char *prestr, int *index);
void postOrder(ThreadTree T);

ThreadNode *pre;  // 指向当前访问结点的前驱

int main(void) {
  char *str = "abd#g##e##cf#####";
  int index = 0;
  ThreadTree T;
  createTree(&T, str, &index);  // 初始化一个二叉树
  postOrder(T);

  return 0;
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

void postOrder(ThreadTree T) {
  if (T) {
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c", T->data);
  }
}