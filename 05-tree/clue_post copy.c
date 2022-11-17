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
void inOrder(ThreadTree T);

ThreadNode *pre;  // 指向当前访问结点的前驱
void createPostThreadTree(ThreadTree T);
void visit(ThreadNode *p);
void postThread(ThreadTree T);

// 在后序线索二叉树中找指定结点p的后序前驱
ThreadNode *getPre(ThreadNode *p);

// 在后序线索二叉树中找指定结点p的后序后继
ThreadNode *getNext(ThreadNode *p);

int main(void) {
  char *str = "abd#g##e##cf#####";
  int index = 0;
  ThreadTree T;
  createTree(&T, str, &index);  // 初始化一个二叉树

  postOrder(T);
  putchar('\n');

  inOrder(T);
  putchar('\n');

  createPostThreadTree(T);
  printf("okok ! ! !\n");

  return 0;
}

ThreadNode *getNext(ThreadNode *p) {
  if(p->rtag == 1) return p->rchild;
}

ThreadNode *getPre(ThreadNode *p) {
  if (p->ltag == 0 && p->rtag == 0) return p->rchild;
  return p->lchild;
}

// 后序线索化
void createPostThreadTree(ThreadTree T) {
  if (T) {
    postThread(T);
    if (pre->rchild == NULL) pre->rtag = 1;
  }
}

void visit(ThreadNode *p) {
  if (p->lchild == NULL) {
    p->ltag = 1;
    p->lchild = pre;
  }
  if (pre && pre->rchild == NULL) {
    pre->rchild = p;
    pre->rtag = 1;
  }
  pre = p;
}

void postThread(ThreadTree T) {
  if (T) {
    postThread(T->lchild);
    postThread(T->rchild);
    visit(T);
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

void postOrder(ThreadTree T) {
  if (T) {
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c", T->data);
  }
}

void inOrder(ThreadTree T) {  // 未线索化前的中序遍历
  if (T) {
    inOrder(T->lchild);
    printf("%c", T->data);
    inOrder(T->rchild);
  }
}
