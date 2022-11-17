#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode {
  struct Tnode *lchild, *rchild;
  char data;
} BTNode, *BTree;

void createTree(BTree *T, char *prestr, int *index);
void inOrder(BTree T);

int main(void) {
  char *str = "abd#g##e##cf#####";
  int index = 0;
  BTree T;
  createTree(&T, str, &index);

  inOrder(T);

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