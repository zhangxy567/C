#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef  struct Line
{
    struct Line* prior;
    int data;
    struct Line* next;
}line;
line* initLine();
void display(line* head);
void freeLine(line* head);
line* insertLine(line* head,int elem,int place);
line* delLine(line* head,int elem);
int selectElem(line* head,int elem);
line* amendElem(line* head,int place,int newelem);
int main()
{   line* phead=NULL;
    int elem,place,newelem;
    phead=initLine();
    display(phead);
    printf("链表中第 4 个节点的直接前驱是：%d\n",phead->next->next->next->prior->data);
    printf("请输入需要插入的数据和位置\n");
    scanf("%d %d",&elem,&place);
    phead=insertLine(phead,elem,place);
    display(phead);
    printf("请输入所要删除的元素\n");
    scanf("%d",&elem);
    phead =delLine(phead,elem);
    display(phead);

    printf("请输入查找的元素\n");
    scanf("%d",&elem);
    place=selectElem(phead,elem);
    if(place>0){ printf("所查找的元素位置是%d\n",place);}
    else printf("所查找的元素不存在\n");

    printf("请输入更改的元素和新元素\n");
    scanf("%d %d",&elem,&newelem);
    place=selectElem(phead,elem);
    if(place>0)
    {
        printf("所修改元素存在\n");
        phead= amendElem(phead,place,newelem);
        display(phead);
    }
    else printf("所修改元素不存在\n");
    freeLine(phead);
    return 0;
}
line* amendElem(line* head,int place,int newelem)
{
    line* t=head;
    for(int i=1;i<place;i++)
    {
     t=t->next;
    }
    t->data=newelem;
    return head;
}
int selectElem(line* head,int elem)
{
    line* t=head;
    int i=1;
    while (t)
    {
        if(t->data==elem) return i;
        i++;
        t=t->next;
    }
    return -1;
}
line* delLine(line* head,int elem)
{
    line* temp=head;
    while(temp)
    {
        if (temp->data == elem)
        {
            if(temp->prior!=NULL&&temp->next!=NULL)
            {
                temp->prior->next = temp->next;
                temp->next->prior = temp->prior;
                free(temp);
                return head;
            }
            else if(temp->prior==NULL)
            {
                temp->next->prior=NULL;
                head=temp->next;
                free(temp);
                return head;
            }
            else
            {
                temp->prior->next=NULL;
                free(temp);
                return head;
            }
        }
        temp=temp->next;
    }
    printf("不存在所删除节点\n");
    return  head;
}
line* insertLine(line* head,int elem,int place)
{
    line* temp=(line*) malloc(sizeof (line));
    if(temp==NULL){ printf("创建链表失败\n");exit(0);}//
    temp->data=elem;
    temp->next=NULL;
    temp->prior=NULL;
    if(place==1)
    {
        temp->next=head;
        head->prior=temp;
        head=temp;
    }
    else
    {
        line* body=head;
        for(int i=1;i<place-1;i++){body=body->next;}
        if(body->next==NULL){body->next=temp;temp->prior=body;}
        else
        {
            temp->next=body->next;
            body->next->prior=temp;
            body->next=temp;
            temp->prior=body;
        }
    }
    return head;
}
line* initLine()
{
    line* head=(line*) malloc(sizeof(line));
    if(head==NULL){printf("创建失败\n");exit(0);}
    head->next=NULL;
    head->prior=NULL;
    head->data=1;
    line * list=head;
    for(int i=2;i<=5;i++)
    {
        line* body= (line *)malloc(sizeof (line));
        if(body==NULL){printf("创建失败\n");exit(0);}
        body->data=i;
        body->prior=NULL;
        body->next=NULL;

        body->prior=list;
        list->next=body;
        list=list->next;
        body=NULL;

    }

    return head;
}
void display(line* head)
{
    line* temp=head;
    while (temp)
    {
        if(temp->next==NULL){printf("%d\n",temp->data);}
        else{printf("%d<->",temp->data);}
        temp=temp->next;
    }
}
// void freeLine(line* head)
// {
//     line* temp=head->next;
// while(head!=NULL)
// {
//     free(head);
//     head=temp;
//     if(temp!=NULL){temp=temp->next;}
//     else temp=NULL;
// }
// }
void freeLine(line* head)
{

    line* current = head;
    line* nextNode;


    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}