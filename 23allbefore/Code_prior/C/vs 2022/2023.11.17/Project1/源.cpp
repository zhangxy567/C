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
void DLRCreateBiTree(BiTree& T)//���򴴽���������
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
void Copy(BiTree T, BiTree& NewT)//���ƶ�����
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
int Depth(BiTree T)//�������
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
int NodeCount(BiTree T)//���������
{
    if (T == NULL) return 0;
    else
    {
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
    }
}

void DLRTravelTree(BiTree T)//�������������
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
void LDRTravelTree(BiTree T)//�������������
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
void LRDTravelTree(BiTree T)//�������������
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
    printf("�����������������#�������\n");
    DLRCreateBiTree(T);
    d = Depth(T);
    n = NodeCount(T);
    printf("��������ȣ�%d\n�������ĸ�����%d\n\n", d, n);
    printf("�������������\n");
    DLRTravelTree(T);//�������������
    printf("\n\n");
    printf("�������������\n");
    LRDTravelTree(T);
    printf("\n\n");
    printf("�������������\n");
    LDRTravelTree(T);//�������������
}
