#include<stdio.h>
#define max 5


int enQueue(int* a,int front,int rear,int data);
int deQueue(int* a,int front,int rear);

int main()
{
    int a[max]={0};
    int front,rear;
    front=0;rear=0;
    rear= enQueue(a,front,rear,1);
    rear= enQueue(a,front,rear,2);
    rear= enQueue(a,front,rear,3);
    rear= enQueue(a,front,rear,4);

    front=deQueue(a, front, rear);
    //�����
    rear=enQueue(a,front,rear, 5);
    //�ٳ���
    front=deQueue(a, front, rear);
    rear=enQueue(a,front,rear, 6);
    // for(int i=0;i<=4;i++) { printf("%d", a[i]) ;}
    front=deQueue(a, front, rear);
    front=deQueue(a, front, rear);
    front=deQueue(a, front, rear);
    front=deQueue(a, front, rear);
    printf("%d%d",front,rear);
}
int enQueue(int* a,int front,int rear,int data)
{
    if((rear+1)%max==front){ printf("��������\n");return rear;}
    a[rear]=data;
    printf("�����Ԫ��%d\n",a[rear]);
    return ((++rear)%max);

}
int deQueue(int* a,int front,int rear)
{
    if(front==rear) { printf("�����ѿ�,�޷�ɾ��\n"); return rear;}
    printf("�ѳ���Ԫ��%d\n",a[front]);
    front =(front+1)%max;
    return front;
}