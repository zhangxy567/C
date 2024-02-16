#include <stdio.h>
#include <stdlib.h>
//������ ͷ�ڵ�Ľṹ
typedef struct Link{
    int  elem;
    struct Link *next;
}link;
//��ʼ������ĺ���
link * initLink();
//�����������ĺ���
void display(link *p);
//������ɾ�ڵ�
link* insertElem(link* p,int elem,int place);
link * delElem(link * p, int place);
int selectElem(link * p,int elem);
link *amendElem(link * p,int place,int elem);
int main() {
    int elem,place,elemplace,newelem,len;

    printf("��ʼ������Ϊ��\n");
    link *p=initLink();
    display(p);
    printf("������Ҫ��������ݺ�λ��(�ÿո񻮿�)\n");
    scanf("%d %d",&elem,&place);
    insertElem(p,elem,place);
    display(p);
    printf("������Ҫɾ����λ��\n");
    scanf("%d",&place);
    delElem(p, place);
    display(p);
    printf("������Ҫ���ҵ�Ԫ��\n");
    scanf("%d",&elem);
    elemplace=selectElem(p,elem);
    if(elemplace>0)
    {
        printf("�����ҵ�Ԫ��λ����%d\n",elemplace);
    }
    else printf("�����ҵ�Ԫ�ز�����\n") ;
    display(p);
    printf("������Ҫ���ĵ�Ԫ��λ�ú���Ԫ��ֵ\n");
    scanf("%d %d",&place,&newelem);
    len=sizeof (p);

    if((len-place)>=0)
    {
        printf("�����ĵ�Ԫ��λ����%d\n",elemplace);
        amendElem( p,elemplace,newelem);
        printf("�����������Ϊ\n");
        display(p);
    }
    else printf("�����ĵ�Ԫ�ز�����\n") ;


    return 0;
}

link * initLink(){
    link * p=(link*)malloc(sizeof(link));//����һ��ͷ���
    link * temp=p;//����һ��ָ��ָ��ͷ��㣬
    //��������
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
    link* temp=p;//��tempָ������ָ��ͷ���
    //ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
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
            printf("����λ������\n");
            return p;
        }

    }
    link* c= (link*)malloc(sizeof(link));
    if(!c)
    {
        printf("��ʼ��ʧ��\n");
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
            printf("û�����Ԫ��\n");
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