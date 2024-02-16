#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//*********无头节点版本
//结构体构造
typedef struct Link
{
    int elem;
    struct Link* next;
}link;
//函数声明
link * initLink();
//用于输出链表的函数
void display(link *p);

link* initLink()
{
    link* p=(link*) malloc(sizeof (link));
    if(!p)
    {
        printf("初始化失败\n");
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
    printf("初始化结果如下:\n");
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