// 计算二叉树中所有双分支的节点个数
#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode {
  struct Tnode *lchild, *rchild;
  char data;
} BTNode, *BTree;

void createTree(BTree *T, char *prestr, int *index);
void inOrder(BTree T);

void count(BTree T, int *cnt) {
  if (T) {
    if (T->lchild && T->rchild) *cnt += 1;
    count(T->lchild, cnt);
    count(T->rchild, cnt);
  }
}

int count2(BTree T) {   // 求度为2的结点数
    if(T) {
        int l = count2(T->lchild);
        int r = count2(T->rchild);
        if(T->lchild && T->rchild) return 1 + l + r;
        if(T->lchild == NULL) return r;
        if(T->rchild == NULL) return l;
    }
}

int main(void) {
  char *str;
  // str = "abd#g##e##cf#####";
//   str = "abd##e##cf###";
//   str = "abdg##h##fw##e##c##";
str ="abd##e###";
  int index = 0;
  BTree T;
  createTree(&T, str, &index);

  inOrder(T);
  putchar('\n');

  int ans = 0;
  count(T, &ans);
  printf("ans=%d\n", ans);
  printf("ans=%d\n", count2(T));

  return 0;
}

void createTree(BTree *T, char *prestr, int *index) {
  char c = prestr[*index];
  (*index) += 1;
  if (c == '#') {
    *T = NULL;
    return;
  }
  *T = (BTNode *)malloc(sizeof(BTNode));
  (*T)->data = c;
  createTree(&(*T)->lchild, prestr, index);
  createTree(&(*T)->rchild, prestr, index);
}

void inOrder(BTree T) {
  if (T) {
    inOrder(T->lchild);
    printf("%c", T->data);
    inOrder(T->rchild);
  }
}
