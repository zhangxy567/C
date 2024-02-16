#include <stdio.h>
#include <stdlib.h>
//链表中 头节点的结构
typedef struct Link{
    int  elem;
    struct Link *next;
}link;
//初始化链表的函数
link * initLink();
//用于输出链表的函数
void display(link *p);
//用于增删节点
link* insertElem(link* p,int elem,int place);
link * delElem(link * p, int place);
int selectElem(link * p,int elem);
link *amendElem(link * p,int place,int elem);
int main() {
    int elem,place,elemplace,newelem,len;

    printf("初始化链表为：\n");
    link *p=initLink();
    display(p);
    printf("请输入要插入的数据和位置(用空格划开)\n");
    scanf("%d %d",&elem,&place);
    insertElem(p,elem,place);
    display(p);
    printf("请输入要删除的位置\n");
    scanf("%d",&place);
    delElem(p, place);
    display(p);
    printf("请输入要查找的元素\n");
    scanf("%d",&elem);
    elemplace=selectElem(p,elem);
    if(elemplace>0)
    {
        printf("所查找的元素位置是%d\n",elemplace);
    }
    else printf("所查找的元素不存在\n") ;
    display(p);
    printf("请输入要更改的元素位置和新元素值\n");
    scanf("%d %d",&place,&newelem);
    len=sizeof (p);

    if((len-place)>=0)
    {
        printf("所更改的元素位置是%d\n",elemplace);
        amendElem( p,elemplace,newelem);
        printf("更改完的数组为\n");
        display(p);
    }
    else printf("所更改的元素不存在\n") ;


    return 0;
}

link * initLink(){
    link * p=(link*)malloc(sizeof(link));//创建一个头结点
    link * temp=p;//声明一个指针指向头结点，
    //生成链表
    for (int i=1; i<5; i++) {
        link *a=(link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
}
void display(link *p){
    link* temp=p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {
        temp=temp->next;
        printf("%d ",temp->elem);

    }
    printf("\n");
}
link* insertElem(link* p,int elem,int place)
{
    link* temp=p;
    for(int i=1;i<place;i++)
    {   temp=temp->next;
        if(temp==NULL)
        {
            printf("插入位置有误\n");
            return p;
        }

    }
    link* c= (link*)malloc(sizeof(link));
    if(!c)
    {
        printf("初始化失败\n");
        exit(0);
    }
    c->elem=elem;
    c->next=temp->next;
    temp->next=c;
    return p;

}
link * delElem(link * p, int place)
{
    link* temp=p;
    for(int i=1;i<place;i++)
    {
        temp=temp->next;
        if(temp->next==NULL)
        {
            printf("没有这个元素\n");
            return p;
        }

    }
    link * del;
    del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return p;
}
int selectElem(link * p,int elem)
{   int i=1;
    link* t=p;
    while(t->next!=NULL)
    {
        t=t->next;
        if(t->elem==elem)
        {
            return  i;
        }
        i++;
    }
    return -1;
}
link *amendElem(link * p,int place,int newelem)
{
    link* t=p->next;
    for(int i=1;i<place;i++)
    {
        t=t->next;
    }
    t->elem=newelem;
    return p;
}