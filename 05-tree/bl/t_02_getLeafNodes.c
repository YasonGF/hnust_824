// 计算二叉树中所有叶子节点的个数
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
  struct tnode *lchild, *rchild;
  char data;
} BTNode, *BTree;

void count(BTree T, int *cnt) {
  if (T) {
    // if (!(T->lchild && T->rchild))  // 统计分支为1和分支为0的结点
    if (T->lchild == NULL && T->rchild == NULL)  // 只统计分支为0的结点
      (*cnt)++;
    count(T->lchild, cnt);
    count(T->rchild, cnt);
  }
}

int count2(BTree T) {
  if (T) {
    // if (T->lchild == NULL && T->rchild == NULL) return 1;

    int l = count2(T->lchild);
    int r = count2(T->rchild);
    if (l + r == 0) return 1;
  }
}

void createTree(BTree *T);
void destoryTree(BTree *T);
void inOrder(BTree T);

int main(void) {
  BTree T;
  // abd#g##e##cf#####
  // abd##e##c##
  createTree(&T);
  printf("中序遍历序列：");
  inOrder(T);
  printf("\n");

  int node_nums = 0;
  count(T, &node_nums);
  printf("n=%d\n", node_nums);

  printf("n2=%d\n", count2(T));
  // destoryTree(&T);
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

void inOrder(BTree T) {
  if (T) {
    inOrder(T->lchild);
    printf("%c", T->data);
    inOrder(T->rchild);
  }
}