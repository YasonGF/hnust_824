// 计算二叉树的深度
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;  //  数据域类型定义

typedef struct TNode {  //  二叉树结点定义
  struct TNode *lchild;
  struct TNode *rchild;
  ElemType data;
} BTNode, *BTree;

// 操作实现
// 1. 以先序遍历序列建立二叉树
void createTreeByPre(BTree *pTree, char *preStr, int *index);
// 2. 中序遍历
void inOrder(BTree T);

int getDepth(BTree T) {  // 计算二叉树的深度
  if (T) {
    int l = getDepth(T->lchild);
    int r = getDepth(T->rchild);
    int max = l > r ? l : r;
    return max + 1;
  }
  return 0;
}

void getDepth2(BTree T, int *cnt, int *max) {
  if (T) {
    *cnt += 1;
    if (*max < *cnt) *max = *cnt;
    getDepth2(T->lchild, cnt, max);
    getDepth2(T->rchild, cnt, max);
    *cnt -= 1;
  }
}

int main(void) {
  BTree T;
  int idx = 0;
  char *str;
  // str = "abd##e##cf###";
  str = "13##57###";
  createTreeByPre(&T, str, &idx);
  inOrder(T);
  putchar('\n');

  printf("depth=%d\n", getDepth(T));

  // int cnt, max;
  // cnt = max = 0;
  // getDepth2(T, &cnt, &max);
  // printf("depth=%d\n", max);
  return 0;
}
void inOrder(BTree T) {
  if (T) {
    inOrder(T->lchild);
    printf("%c", T->data);
    inOrder(T->rchild);
  }
}
void createTreeByPre(BTree *pTree, char *preStr, int *index) {
  char c = *(preStr + *index);
  *index += 1;
  if (c == '#') {
    (*pTree) = NULL;
    return;
  }
  (*pTree) = calloc(1, sizeof(BTNode));
  // (*pTree) = (BTNode *)malloc(sizeof(BTNode) * 1);
  (*pTree)->data = c;
  createTreeByPre(&(*pTree)->lchild, preStr, index);
  createTreeByPre(&(*pTree)->rchild, preStr, index);
}
