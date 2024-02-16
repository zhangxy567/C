#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int enQueue(int* a,int rear,int elem);
int deQueue(int*a ,int front,int rear);
int main()
{
    int a[100]={0};
    int front=0;
    int rear=0;
    rear= enQueue(a,rear,1);
    rear= enQueue(a,rear,2);
    rear= enQueue(a,rear,3);
    rear= enQueue(a,rear,4);
    front= deQueue(a,front,rear);
    return 0;
}
int enQueue(int* a,int rear,int elem)
{
    a[rear]=elem;
    rear++;
    return rear;
}
int deQueue(int*a ,int front,int rear)
{
    if(front==rear){ printf("队列为空\n");}
    else
    {
        while (front != rear)
        {
            printf("出队列元素%d\n", a[front]);
            front++;
        }
    }
    return front;

}