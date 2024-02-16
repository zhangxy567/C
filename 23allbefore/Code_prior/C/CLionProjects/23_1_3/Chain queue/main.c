#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct  QNode
{
    int data;
    struct QNode *next;
} QNode;


QNode* initQueue();
QNode *enQueue(QNode* rear,int data);
QNode *deQueue(QNode* top,QNode*rear);


int main()
{
    QNode * queue,*rear,*top;
    rear=top=queue=initQueue();
    rear= enQueue(rear,1);
    rear= enQueue(rear,2);
    rear= enQueue(rear,3);
    rear= enQueue(rear,4);
    rear= deQueue(top,rear);
    rear= deQueue(top,rear);
    rear= deQueue(top,rear);
    rear= deQueue(top,rear);
    rear= deQueue(top,rear);
    return 0;
}
QNode *deQueue(QNode* top,QNode*rear)
{
    if(top->next==NULL){ printf("�����ѿ�");return rear;}
    QNode *p=top->next;
    top->next=p->next;
    printf("�ѳ���Ԫ��Ϊ%d\n",p->data);
    if(p->next==NULL){rear=top;}
    free(p);
    return rear;
}
QNode *enQueue(QNode* rear,int data)
{
    QNode * enElem=(QNode*) malloc(sizeof (QNode));
    if(!enElem){ printf("��ʼ��ʧ��\n");exit(0);}
    enElem->data=data;
    enElem->next=NULL;
    rear->next=enElem;
    rear=rear->next;
    printf("%dԪ���������\n",rear->data);
    return rear;
}

QNode *initQueue()
{
    QNode * queue=(QNode*) malloc(sizeof (QNode));
    if(!queue){ printf("��ʼ��ʧ��\n");exit(0);}
    queue->next=NULL;
    return queue;
}