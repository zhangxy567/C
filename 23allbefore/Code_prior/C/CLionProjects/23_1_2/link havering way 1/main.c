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
    printf("????????????\n");
    link *p=initLink();
    display(p);
    // printf("??????????¦Ë???????????\n");
    // scanf("%d",&pl);
    // crringlink(p,pl);
    printf("?????????????\n");
    Judgingringpresence(p);
    return 0;
}
bool HaveRing(link * H)
{
    long long addr[20];
    link * htemp=H;
    int length=0,i=0;
    while (htemp)
    {
        for(i=0;i<length;i++)
        {
            if(htemp==addr[i]) return True;
        }
        addr[length]=htemp;
        length++;
        htemp=htemp->next;
    }
    return False;
}
void Judgingringpresence(link *p)
{
    int m;
    m=HaveRing(p);
    if(m) printf("?§Ý?\n");
    else printf("???");
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