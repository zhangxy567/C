
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node
{
    int number;
    struct node* next;
}person;


person* initLink(int n);
void freeLink(person* head);
person * FindAndKillk(person* head,int k,int m);

int main()
{
    printf("输入圆桌上的人数\n");
    int n;
    scanf("%d",&n);
    person* phead=initLink(n);
    printf("从第k人开始报数(k>1且k<%d)：\n",n);
    int k;
    scanf("%d",&k);
    printf("输出到第m个人出列\n");
    int m;
    scanf("%d",&m);
    FindAndKillk(phead,k,m);

    // freeLink(phead);
    return 0;
}
person * FindAndKillk(person* head,int k,int m)
{
    person * tail=head;
    while(tail->next!=head)
    {
        tail=tail->next;
    }
    person * p=head;

    while (p->number!=k)
    {
        tail=p;
        p=p->next;
    }

    while (p->next!=p)
    {
        for(int i=1;i<m;i++)
        {
            tail=p;
            p=p->next;
        }
        tail->next=p->next;
        printf("输出的元素为%d\n",p->number);
        free(p);
        p=tail->next;
    }
    printf("最后出列的元素为%d\n",p->number);
    free(p);
}
person* initLink(int n)
{
    person* head=(person*) malloc(sizeof (person));
    if(!head)
    { printf("初始化失败\n");exit(0);}
    head->number=1;
    head->next=NULL;
    person * cyclic=head;
    for(int i=2;i<=n;i++)
    {
        person * body=(person*) malloc(sizeof (person));
        body->number=i;
        body->next=NULL;
        cyclic->next=body;
        cyclic=cyclic->next;
    }
    cyclic->next=head;
    return head;
}
void freeLink(person* head)
{
    person* temp=head;
    int count=-1,num=0;
    while (1)
    {
        if(temp==head){count++;}
        if(count==1) break;
        temp=temp->next;
        num++;
    }
    printf("顺换链表元素个数为%d\n",num);
    person * willfreenum=temp->next;
    for(int i=1;i<=num;i++)
    {
        free(temp);
        temp=willfreenum;
        if(i==num){willfreenum=NULL;break;}
        willfreenum=willfreenum->next;
    }
    printf("释放内存完毕\n");

}