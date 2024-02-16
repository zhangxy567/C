#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct line
{
    struct line * prior;
    int data;
    struct line * next;
}line;
typedef enum
{
    False=0,
    True=1
}bool;


line* initLine(line * head,int n);
void Judgingringpresence(line *p);
bool HaveRing(line * H);



int main()
{
    printf("请输入链表的长度 \n");
    int n;
    scanf("%d",&n);
    line* phead=initLine(phead,n);
    Judgingringpresence(phead);
    line * cyclic=phead;
    printf("这个循环链表是\n");
    for(int i=1;i<=10;i++)
    {
        printf("%d  ",cyclic->data);
        cyclic=cyclic->next;
    }

    return 0;
}
line* initLine(line * head,int n)
{
    head=(line*)malloc(sizeof (line));
    if(!head){ printf("初始化失败\n");exit(0);}
    head->next=NULL;
    head->prior=NULL;
    head->data=1;
    line * cyclic=head;

    for(int i=2;i<=n;i++)
    {
        line * body=(line*) malloc(sizeof (line));
        if(!body){ printf("初始化失败\n");exit(0);}
        body->prior=NULL;
        body->next=NULL;
        body->data=i;

        cyclic->next=body;
        body->prior=cyclic;
        cyclic=cyclic->next;
    }
    cyclic->next=head;
    head->prior=cyclic;


}
bool HaveRing(line * H)//************************VERY IMPORTANT!!!!!!!
{
    line* H1=H->next;
    line *H2=H;
    while (H1)
    {
        if(H1==H2){return True;}
        else
        {
            H1=H1->next;
            if(!H1){return False;}
            else {H1=H1->next;H2=H2->next;}
        }
    }
    return False;
}
void Judgingringpresence(line *p) {
    int m;
    m = HaveRing(p);
    if (m) printf("有环\n");
    else printf("无环");
}