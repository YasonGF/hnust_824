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
void find_order_prenode(BTree T, BTNode **p, BTNode **pre, BTNode **q);
void find_post_prenode(BTree T, BTNode **p, BTNode **pre, BTNode **q);

BTNode *final = NULL;

int main(void)
{
    char *str = "abd#g##e##cf#####";
    int index = 0;
    BTree T;
    createTree(&T, str, &index);
    inOrder(T);
    printf("\n");

    // 找指定结点的中序前驱
    BTNode *p = T->rchild->lchild;
    // p = T;
    printf("%c\n", p->data);
    BTNode *pre = NULL, *q;
    find_order_prenode(T, &p, &pre, &q);

    printf("p->data=%c\n", p->data);
    printf("pre->data=%c\n", pre->data);
    printf("q->data=%c\n", q->data);
    printf("final->data=%c\n", final->data);

    // 找指定结点的中序后继
    find_post_prenode(T, &p, &pre, &q);

    printf("p->data=%c\n", p->data);
    printf("pre->data=%c\n", pre->data);
    printf("q->data=%c\n", q->data);
    printf("final->data=%c\n", final->data);
    return 0;
}

void find_post_prenode(BTree T, BTNode **p, BTNode **pre, BTNode **q)
{
    if (T)
    {
        find_order_prenode(T->lchild, p, pre, q);
        *q = T;
        if (*pre == *p)
            final = *q;
        else
            *pre = *q;
        find_order_prenode(T->rchild, p, pre, q);
    }
}

void find_order_prenode(BTree T, BTNode **p, BTNode **pre, BTNode **q)
{
    if (T)
    {
        find_order_prenode(T->lchild, p, pre, q);

        // if (*q == *p)
        //     return;
        *q = T;
        if (*q == *p)
            final = *pre;
        else
            *pre = *q;

        find_order_prenode(T->rchild, p, pre, q);
    }
}

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