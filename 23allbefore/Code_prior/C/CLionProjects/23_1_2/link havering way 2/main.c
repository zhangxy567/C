#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
    int  elem;
    struct Link *next;
}link;
typedef enum
{
    False=0,
    True=1
}bool;
link * initLink();

void display(link *p);
void crringlink(link *p,int pl);
void Judgingringpresence(link *p);
bool HaveRing(link * H);

int main() {

    int pl;
    printf("初始化链表为\n");
    link *p=initLink();
    display(p);
    printf("请输入循环链表接入位置\n");
    scanf("%d",&pl);
    // crringlink(p,pl);
    printf("循环接入单链表失败\n");
    Judgingringpresence(p);
    return 0;
}
bool HaveRing(link * H)//************************VERY IMPORTANT!!!!!!!
{
    link* H1=H->next;
    link *H2=H;
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
void Judgingringpresence(link *p)
{
    int m;
    m=HaveRing(p);
    if(m) printf("有环\n");
    else printf("无环");
}
void crringlink(link* p,int pl)
{
    link *tail=p;
    link *ringhead=p;
    while (tail->next!=NULL)
    {
        tail=tail->next;
    }
    for(int i=1;i<pl;i++)
    {
        ringhead=ringhead->next;
    }
    tail->next=ringhead;

}
link * initLink(){
    link * p=NULL;
    link * temp = (link*)malloc(sizeof(link));

    temp->elem = 1;
    temp->next = NULL;
    p = temp;
    for (int i=2; i<10; i++) {
        link *a=(link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
}
void display(link *p){
    link* temp=p;

    while (temp) {
        printf("%d ",temp->elem);
        temp=temp->next;
    }
    printf("\n");
}