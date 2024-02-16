#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

// ����������ṹ
typedef struct Node
{
    int data;
    struct Node* next;
} LinkNode;

// �������� n ����������
LinkNode* Create(LinkNode* L, int n)
{
    int i;
    LinkNode* p;

    // Ϊ����ͷ�������ڴ�
    L = (LinkNode*)malloc(sizeof(LinkNode));
    L->next = NULL;

    LinkNode* tail = L;

    // ѭ������ n ����㣬��������ӵ�������
    for (i = 0; i < n; i++)
    {
        p = (LinkNode*)malloc(sizeof(LinkNode));
        p->data = i;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }

    return L;
}

// ��ת����
LinkNode* back(LinkNode* L)
{
    // �������Ϊ�ջ�ֻ��һ����㣬�����跴ת
    if (L == NULL || L->next == NULL)
    {
        return L;
    }

    LinkNode* pre = NULL;
    LinkNode* p = L->next;
    LinkNode* q = L->next->next;

    // ����������תָ�뷽��
    while (q != NULL)
    {
        p->next = pre;
        pre = p;
        p = q;
        q = q->next;
    }

    p->next = pre;
    L->next = p;

    return L;
}

int main()
{
    LinkNode* p;
    LinkNode* L = NULL;

    // �������� 6 ����������
    L = Create(L, 6);

    printf("��ʼ����: ");

    // ��ӡ��ʼ�����Ԫ��
    p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    // ��ת����
    L = back(L);

    printf("���ú������: ");

    // ��ӡ���ú������Ԫ��
    p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}
