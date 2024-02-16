#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct OLNode
{
    int i, j, e;
    struct OLNode* down, * right;
}OLNode, * OLink;


typedef struct
{
    int mu, nu, tu;
    OLink* rhead, * chead;

}CrossList;



CrossList  CreateMatrix_OL(CrossList M);
void display(CrossList M);


int main()
{
    CrossList M;
    M.chead = NULL;
    M.rhead = NULL;
    M = CreateMatrix_OL(M);
    printf("输出矩阵的元素为\n");
    display(M);
    return 0;
}
CrossList CreateMatrix_OL(CrossList M)
{
    int m, n, t;
    int i, j, e;
    OLNode *p, *q;

    printf("请输入矩阵的行数列数和非零元素个数\n");
    scanf("%d%d%d", &m, &n, &t);
    M.mu = m;
    M.nu = n;
    M.tu = t;

    if (!(M.rhead = (OLink*)malloc((m + 1) * sizeof(OLink))) || !(M.chead = (OLink*)malloc((n + 1) * sizeof(OLink))))
    {
        printf("初始化失败\n"); exit(0);

    }
    for (i = 1; i <= m; i++)
    {
        M.rhead[i] = NULL;
    }
    for (j = 1; j<= n; j++)
    {
        M.chead[j] = NULL;
    }

    printf("请依次输入元素行 列 元素\n");

    for (scanf("%d%d%d", &i, &j, &e); 0 != i; scanf("%d%d%d", &i, &j, &e))

    {
        if (!(p = (OLink)malloc(sizeof(OLNode)))) { printf("初始化失败\n"); exit(0); }



        p->i = i;
        p->j = j;
        p->e = e;
        //行链接
        if (M.rhead[i] == NULL || M.rhead[i]->j > j)
        {
            p->right = M.rhead[i];
            M.rhead[i] = p;
        }
        else
        {
            for (q = M.rhead[i]; q->right && q->right->j < j; q = q->right);
            p->right = q->right;
            q->right = p;
        }
        //列链接
        if (NULL==M.chead[j] || M.chead[j]->i > i)
        {
            p->down = M.chead[j];
            M.chead[j] = p;
        }
        else
        {
            for (q = M.chead[j]; q->down && q->down->i < i; q = q->down);
            p->down = q->down;
            q->down = p;
        }
    }
    return M;
}
void display(CrossList M)
{
    for (int i = 1; i <= M.nu; i++)
    {
        if (NULL != M.chead[i])
        {
            OLink p = M.chead[i];
            while (NULL != p)
            {
                printf("%d\t%d\t%d\n", p->i, p->j, p->e);
                p = p->down;
            }
        }
    }

}