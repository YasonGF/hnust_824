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

int main(void) {
  BTree T;
  int idx = 0;
  char *str = "abd##e##cf###";
  createTreeByPre(&T, str, &idx);
  inOrder(T);
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
