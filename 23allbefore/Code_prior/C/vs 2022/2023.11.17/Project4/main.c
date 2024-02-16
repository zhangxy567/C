#include <stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
    char data;
    BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

void Visit(BiTree T)
{
    printf("%c", T->data);
}

void CreatBiTree(BiTree& T)
{
char ch;
ch = getchar();
getchar();
if (ch == '*')
T = NULL;
else
{
T = (BiTree)malloc(sizeof(BiTNode));
/*	if (!T)
        exit(-1);*/
T->data = ch;
CreatBiTree(T->lchild);
CreatBiTree(T->rchild);
}
}

void PreOrder(BiTree T)
{
    if (T) {
        Visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T)
{
    if (T) {
        InOrder(T->lchild);
        Visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T)
{
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        Visit(T);
    }
}

void FloorOrder(BiTree T)
{
    BiTree t[250];
    int in = 0;
    int out = 0;
    t[in++] = T;
    while (in > out)
    {
        if (t[out])
        {
            printf("%c", t[out]->data);
            t[in++] = t[out]->lchild;
            t[in++] = t[out]->rchild;
        }
        out++;
    }
}

int main()
{
    BiTree T;
    CreatBiTree(T);
    printf("先序遍历为：\n");
    PreOrder(T);
    printf("\n");
    printf("中序遍历为：\n");
    InOrder(T);
    printf("\n");
    printf("后序遍历为：\n");
    PostOrder(T);
    printf("\n");
    printf("层序遍历为：\n");
    FloorOrder(T);
    return 0;
}