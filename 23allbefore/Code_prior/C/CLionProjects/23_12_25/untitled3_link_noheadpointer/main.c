#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//*********��ͷ�ڵ�汾
//�ṹ�幹��
typedef struct Link
{
    int elem;
    struct Link* next;
}link;
//��������
link * initLink();
//�����������ĺ���
void display(link *p);

link* initLink()
{
    link* p=(link*) malloc(sizeof (link));
    if(!p)
    {
        printf("��ʼ��ʧ��\n");
        exit(0);
    }
    link* temp=p;
    temp->elem=1;
    temp->next=NULL;
    for(int i=2;i<5;i++)
    {
        link* a=(link*) malloc(sizeof (link));
        a->elem=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
}
int main() {
    link *phead=initLink();
    printf("��ʼ���������:\n");
    display(phead);
    return 0;
}
void display(link *p)
{link* temp=p;

    while (temp)
    {
        printf("%d  ",temp->elem);
        temp=temp->next;

    }
    printf("\n");
}