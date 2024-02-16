#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxSize 6
typedef struct staticlinklist
{
    int data;
    int cur;
}component;
//���ṹ�����������з������ӵ�����������
void reserveArr(component *array);
//��ʼ����̬����
int initArr(component *array);
//�������
void displayArr(component * array,int body);
//�ӱ���������ժ�¿��нڵ�ĺ���
int mallocArr(component * array);
//��������
void insertArr(component* array,int body, int place,int a);
//ɾ������
void deletArr(component * array,int body,int a);
void freeArr(component* array,int del);
int selectElem(component* array,int body,int a);
void amendElem(component* array,int body,int oldelem,int newelem);
int main() {
    int place,a,placeindex,oldelem,newelem;
    component array[maxSize];
    int body =initArr(array);
    displayArr(array,body);
    printf("����������λ�ú�����\n");
    scanf("%d %d",&place,&a);
    printf("Place and elem is %d and %d\n",place,a);
    insertArr(array,body, place, a);
    displayArr(array,body);
    printf(" �����Ҫɾ����Ԫ��\n");
    scanf("%d",&a);
    deletArr(array,body,a);
    displayArr(array,body);
    printf("��������Ҫ���ҵ�Ԫ��\n");
    scanf("%d",&a);
    placeindex= selectElem(array,body,a);
    if(placeindex==-1){ printf("������Ԫ�ز�����\n");}
    else {
        printf("������Ԫ��%d�������е������±�Ϊ%d\n", array[placeindex].data, placeindex);

    }
    printf("��������Ҫ�޸ĵ�Ԫ��,��Ŀ��ֵ\n");
    scanf("%d %d",&oldelem,&newelem);
    amendElem(array,body,oldelem,newelem);
    printf("�޸ĺ�ľ�̬����Ϊ\n");
    displayArr(array,body);
    return 0;
}
void amendElem(component* array,int body,int oldelem,int newelem)
{
    int placeindex= selectElem(array,body,oldelem);
    if(placeindex==-1){ printf("������Ԫ�ز�����\n");return;}
    array[placeindex].data=newelem;

}
//����1/2����ѡ��һ��ʹ֮��Ч�ſ�ִ��
//����body��Ϊͷ���������в���������Ϊelem�Ľ���������е�λ��
int selectElem(component * array,int body,int elem)//����1
{
    int tempBody=body;
    //���α�ֵΪ0ʱ����ʾ�������
    while (array[tempBody].cur!=0)
    {
        tempBody=array[tempBody].cur;
        if (array[tempBody].data==elem)
        {
            return tempBody;
        }
    }
    return -1;//����-1����ʾ��������û���ҵ���Ԫ��
}
// int selectElem(component* array,int body,int a)//���ֹ�����2
// {
//     int tempbody=body;
//     while(array[tempbody].data!=a)
//     {
//         if(array[tempbody].cur==0) return -1;
//         tempbody=array[tempbody].cur;
//     }
//     return tempbody;
// }
void freeArr(component* array,int del)
{
    array[del].cur=array[0].cur;
    array[0].cur=del;
}
void deletArr(component * array,int body,int a)
{
    int tempbody=body;
    while (array[tempbody].data!=a)
    {
        if(array[tempbody].cur==0) return;
        tempbody=array[tempbody].cur;
    }
    int del=tempbody;
    tempbody=body;
    while (array[tempbody].cur!=del)
    {
        tempbody=array[tempbody].cur;
    }
    array[tempbody].cur=array[del].cur;
    freeArr(array,del);
}
void insertArr(component *array,int body,int place,int a)
{
    int insert=mallocArr(array);
    int tempbody=body;
    for(int i=1;i<place;i++)
{
        tempbody=array[tempbody].cur;
}
    array[insert].data=a;
    array[insert].cur=array[tempbody].cur;
    array[tempbody].cur=insert;
}
int mallocArr(component *array)
{
    int i=array[0].cur;
    if(i)
    {
        array[0].cur=array[i].cur;
    }
    return i;
}
void reserveArr(component *array)
{
    for(int i=0;i<maxSize;i++)
    {
        array[i].cur=i+1;
        array[i].data=-1;
    }
    array[maxSize-1].cur=0;
}
int initArr(component *array)
{
    reserveArr(array);
    int body=mallocArr(array);
    int tempbody=body;
    for(int i=1;i<4;i++)
    {
      int j= mallocArr(array);
      array[tempbody].cur=j;
      array[j].data=i;
      tempbody=j;
    }
    array[tempbody].cur=0;
    return body;

}
void displayArr(component* array,int body)
{   int tempbody=body;
    while(array[tempbody].cur)
    {
        printf("%d,%d     ",array[tempbody].data,array[tempbody].cur);
        tempbody=array[tempbody].cur;
    }
    printf("%d, %d  \n",array[tempbody].data,array[tempbody].cur);
}