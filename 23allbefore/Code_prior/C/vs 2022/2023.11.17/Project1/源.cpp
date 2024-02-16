#include<stdio.h>
#include<stdlib.h>
#define MAXSIDE 100
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#include<iostream>
using namespace std;
typedef int Status;
typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
void DLRCreateBiTree(BiTree& T)//先序创建二叉链表
{
    char ch;
    cin >> ch;
    if (ch == '#') T = NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;
        DLRCreateBiTree(T->lchild);
        DLRCreateBiTree(T->rchild);
    }
}
void Copy(BiTree T, BiTree& NewT)//复制二叉树
{
    if (T == NULL)
    {
        NewT = NULL;
        return;
    }
    else
    {
        NewT = new BiTNode;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild, NewT->rchild);
    }
}
int Depth(BiTree T)//计算深度
{
    int m, n;
    if (T == NULL) return 0;
    else
    {
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        if (m > n) return (m + 1);
        else return (n + 1);
    }
}
int NodeCount(BiTree T)//计算结点个数
{
    if (T == NULL) return 0;
    else
    {
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    }
}

void DLRTravelTree(BiTree T)//先序遍历二叉树
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        printf("%c", T->data);
        DLRTravelTree(T->lchild);
        DLRTravelTree(T->rchild);
    }
}
void LDRTravelTree(BiTree T)//中序遍历二叉树
{
    if (T == NULL)
    {
        return;
    }
    else
    {

        LDRTravelTree(T->lchild);
        printf("%c", T->data);
        LDRTravelTree(T->rchild);
    }
}
void LRDTravelTree(BiTree T)//后序遍历二叉树
{
    if (T == NULL)
    {
        return;
    }
    else
    {

        LRDTravelTree(T->lchild);
        LRDTravelTree(T->rchild);
        printf("%c", T->data);
    }
}
int main()
{
    BiTree T;
    int d, n;
    printf("================================\n");
    printf("请先序输入二叉树，#代表空树\n");
    DLRCreateBiTree(T);
    d = Depth(T);
    n = NodeCount(T);
    printf("该树的深度：%d\n该树结点的个数：%d\n\n", d, n);
    printf("先序遍历二叉树\n");
    DLRTravelTree(T);//先序遍历二叉树
    printf("\n\n");
    printf("后序遍历二叉树\n");
    LRDTravelTree(T);
    printf("\n\n");
    printf("中序遍历二叉树\n");
    LDRTravelTree(T);//中序遍历二叉树
}
