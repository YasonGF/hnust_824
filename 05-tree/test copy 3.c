#include <stdio.h>
#include <stdlib.h>
// 土方法找指定结点p的中序前驱和后继
typedef struct Tnode
{
    struct Tnode *lchild, *rchild;
    char data;
} BTNode, *BTree;

void createTree(BTree *T, char *prestr, int *index);
void inOrder(BTree T);

void visit2(BTNode *q); // 找指定结点p的中序后继
void visit(BTNode *q);
void findPre(BTree T);
void findPost(BTree T); // 土方法寻找指定结点的中序后继

BTNode *p;
BTNode *pre = NULL;   // 指向当前访问结点的前驱
BTNode *final = NULL; // 用于记录最终结果

int main(void)
{
    char *str = "abd#g##e##cf#####";
    int index = 0;
    BTree T;
    createTree(&T, str, &index);
    inOrder(T);
    printf("\n");

    p = T->rchild->lchild;
    // 找指定结点的中序前驱
    findPre(T);
    printf("%c\n", final->data);

    // 找指定结点的中序后驱
    pre = final = NULL;
    findPost(T);
    printf("%c\n", final->data);

    return 0;
}

void visit2(BTNode *q) // 找指定结点p的中序后继
{
    if (pre == p)
        final = q;
    else
        pre = q;
}
void visit(BTNode *q) // 找指定结点p的中序前驱
{
    if (q == p)
        final = pre;
    else
        pre = q;
}

void findPre(BTree T) // 土方法寻找指定结点的中序前驱
{
    if (T)
    {
        findPre(T->lchild);
        visit(T);
        findPre(T->rchild);
    }
}

void findPost(BTree T) // 土方法寻找指定结点的中序后继
{
    if (T)
    {
        findPost(T->lchild);
        visit2(T);
        findPost(T->rchild);
    }
}

// --------------------------------------------------------------------
void createTree(BTree *T, char *prestr, int *index)
{
    char c = prestr[*index];
    (*index) += 1;
    if (c == '#')
    {
        *T = NULL;
        return;
    }
    *T = (BTNode *)malloc(sizeof(BTNode));
    (*T)->data = c;
    createTree(&(*T)->lchild, prestr, index);
    createTree(&(*T)->rchild, prestr, index);
}

void inOrder(BTree T)
{
    if (T)
    {
        inOrder(T->lchild);
        printf("%c", T->data);
        inOrder(T->rchild);
    }
}