#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode {
  struct Tnode *lchild, *rchild;
  // tag = 0 : 表示指针指向左右孩子，tag = 1：表示指针是线索
  int ltag, rtag;
  char data;
} ThreadNode, *ThreadTree;

void createTree(ThreadTree *T, char *prestr, int *index);
void inOrder(ThreadTree T);

ThreadNode *pre;  // 指向当前访问结点的前驱
void inThread(ThreadTree T);
void visit(ThreadTree T);
void createInThread(ThreadTree T);

// 1.求中序线索二叉树中中序序列下的第一个结点
ThreadNode *first_node(ThreadNode *q);

// 2.求中序线索二叉树中结点p在中序序列下的后继
ThreadNode *next_node(ThreadNode *p);

// 3.不含头结点的中序线索二叉树的中序遍历算法
void Inorder(ThreadNode *p);

// 4. 找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode *last_node(ThreadNode *q);

// 5. 在中序线索二叉树中找到结点p的前驱
ThreadNode *pre_node(ThreadNode *p);

// 6. 中序线索二叉树的逆向中序遍历
void RevInorder(ThreadNode *T);

int main(void) {
  char *str = "abd#g##e##cf#####";
  int index = 0;
  ThreadTree T;
  createTree(&T, str, &index);  // 初始化一个二叉树
  inOrder(T);
  putchar('\n');
  // 将二叉树中序线索化
  createInThread(T);
  printf("thread tree over!\n");

  // ThreadNode *p = T->lchild->rchild;
  // printf("\np->data=%c\n", p->data);
  // printf("p->lchild->data=%c\n", p->lchild->data);
  // printf("p->ltag=%d\n", p->ltag);

  // printf("p->rchild->data=%c\n", p->rchild->data);
  // printf("p->rtag=%d\n", p->rtag);

  // printf("%c\n", first_node(T)->data);
  // printf("%c\n", next_node(T)->data);
  // printf("%c\n", last_node(T)->data);
  // printf("%c\n", pre_node(T)->data);

  RevInorder(T);
  putchar('\n');

  Inorder(T);
  putchar('\n');

  return 0;
}

// 1.求中序线索二叉树中中序序列下的第一个结点
ThreadNode *first_node(ThreadNode *q) {
  while (q->ltag == 0) q = q->lchild;
  return q;
}
// 2.求中序线索二叉树中结点p在中序序列下的后继
ThreadNode *next_node(ThreadNode *p) {
  if (p->rtag == 1) return p->rchild;
  return first_node(p->rchild);
}
// 3.中序线索化二叉树的遍历
void Inorder(ThreadNode *root) {
  for (ThreadNode *q = first_node(root); q; q = next_node(q))
    printf("%c", q->data);
}
// 4. 找到以q为根的子树中，最后一个被中序遍历的结点
ThreadNode *last_node(ThreadNode *q) {
  while (q->rtag == 0) {
    q = q->rchild;
  }
  return q;
}
// 5. 在中序线索二叉树中找p的中序前驱
ThreadNode *pre_node(ThreadNode *p) {
  if (p->ltag == 1) return p->lchild;
  return last_node(p->lchild);
}

// 6. 中序线索二叉树的逆向中序遍历
void RevInorder(ThreadNode *T) {
  for (ThreadNode *p = last_node(T); p; p = pre_node(p)) printf("%c", p->data);
}

void createInThread(ThreadTree T) {
  pre = NULL;
  if (T) {
    inThread(T);
    if (pre->rchild == NULL) pre->rtag = 1;
  }
}

void visit(ThreadNode *q) {
  // 左子树为空, 建立前驱线索
  if (q->lchild == NULL) {
    q->lchild = pre;
    q->ltag = 1;
  }
  // 建立后继线索
  if (pre != NULL && pre->rchild == NULL) {
    pre->rchild = q;
    pre->rtag = 1;
  }
  pre = q;
}

void inThread(ThreadTree T)  // 一边遍历一边线索化
{
  if (T) {
    inThread(T->lchild);
    visit(T);
    inThread(T->rchild);
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

void inOrder(ThreadTree T) {
  if (T) {
    inOrder(T->lchild);
    printf("%c", T->data);
    inOrder(T->rchild);
  }
}