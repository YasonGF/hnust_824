// 1. 计算二叉树中结点总数
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
void inOrder(BTree T);


void count(BTree T, int *cnt) {  // 操作型（void）
  if (T) {
    *cnt += 1;
    count(T->lchild, cnt);
    count(T->rchild, cnt);
  }
}
int count2(BTree T) {
  if (T) {
    int l = count2(T->lchild);
    int r = count2(T->rchild);
    return l + r + 1;
  }
}

int main(void) {
  BTree T;
  int idx = 0;
  char *str;
  //   str = "abd##e##cf###";
  str = "abd##e###";
  createTreeByPre(&T, str, &idx);
  inOrder(T);
  putchar('\n');
  // 1. 计算二叉树中结点总数
  int ans = 0;
  count(T, &ans);
  printf("ans = %d\n", ans);
  printf("ans2 = %d\n", count2(T));

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
  //   (*pTree) = realloc(sizeof(BTNode), 1);
  (*pTree) = (BTNode *)malloc(sizeof(BTNode) * 1);
  (*pTree)->data = c;
  createTreeByPre(&(*pTree)->lchild, preStr, index);
  createTreeByPre(&(*pTree)->rchild, preStr, index);
}
