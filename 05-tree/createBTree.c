// 给定一个先序遍历序列，建立二叉树，以中序和后序遍历输出
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
  struct tnode *lchild, *rchild;
  char data;
} BTNode, *BTree;

void createTree(BTree *T);
void destoryTree(BTree *T);

void preOrder(BTree T);
void inOrder(BTree T);
void postOrder(BTree T);

int main(void) {
  BTree T;
  // abd#g##e##cf#####
  createTree(&T);
  printf("中序遍历序列：");
  inOrder(T);
  printf("\n");

  printf("先序遍历序列：");
  preOrder(T);
  printf("\n");

  printf("后序遍历序列：");
  postOrder(T);
  printf("\n");

  return 0;
}

void createTree(BTree *T) {
  char c;
  scanf("%c", &c);
  if (c != '#') {
    *T = (BTree)malloc(sizeof(BTNode));
    (*T)->data = c;
    createTree(&(*T)->lchild);
    createTree(&(*T)->rchild);
  } else {
    *T = NULL;
  }
}

void preOrder(BTree T) {
  if (T) {
    printf("%c", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
  }
}

void inOrder(BTree T) {
  if (T) {
    inOrder(T->lchild);
    printf("%c", T->data);
    inOrder(T->rchild);
  }
}

void postOrder(BTree T) {
  if (T) {
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c", T->data);
  }
}
