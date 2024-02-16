#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxSize 6
typedef struct staticlinklist
{
    int data;
    int cur;
}component;
//将结构体数组中所有分量链接到备用链表中
void reserveArr(component *array);
//初始化静态链表
int initArr(component *array);
//输出函数
void displayArr(component * array,int body);
//从备用链表上摘下空闲节点的函数
int mallocArr(component * array);
//插入数组
void insertArr(component* array,int body, int place,int a);
//删除数据
void deletArr(component * array,int body,int a);
void freeArr(component* array,int del);
int selectElem(component* array,int body,int a);
void amendElem(component* array,int body,int oldelem,int newelem);
int main() {
    int place,a,placeindex,oldelem,newelem;
    component array[maxSize];
    int body =initArr(array);
    displayArr(array,body);
    printf("请输入插入的位置和数据\n");
    scanf("%d %d",&place,&a);
    printf("Place and elem is %d and %d\n",place,a);
    insertArr(array,body, place, a);
    displayArr(array,body);
    printf(" 请输出要删除的元素\n");
    scanf("%d",&a);
    deletArr(array,body,a);
    displayArr(array,body);
    printf("请输入需要查找的元素\n");
    scanf("%d",&a);
    placeindex= selectElem(array,body,a);
    if(placeindex==-1){ printf("所查找元素不存在\n");}
    else {
        printf("所查找元素%d在数组中的索引下标为%d\n", array[placeindex].data, placeindex);

    }
    printf("请输入需要修改的元素,和目标值\n");
    scanf("%d %d",&oldelem,&newelem);
    amendElem(array,body,oldelem,newelem);
    printf("修改后的静态链表为\n");
    displayArr(array,body);
    return 0;
}
void amendElem(component* array,int body,int oldelem,int newelem)
{
    int placeindex= selectElem(array,body,oldelem);
    if(placeindex==-1){ printf("所查找元素不存在\n");return;}
    array[placeindex].data=newelem;

}
//方案1/2必须选择一个使之有效才可执行
//在以body作为头结点的链表中查找数据域为elem的结点在数组中的位置
int selectElem(component * array,int body,int elem)//方案1
{
    int tempBody=body;
    //当游标值为0时，表示链表结束
    while (array[tempBody].cur!=0)
    {
        tempBody=array[tempBody].cur;
        if (array[tempBody].data==elem)
        {
            return tempBody;
        }
    }
    return -1;//返回-1，表示在链表中没有找到该元素
}
// int selectElem(component* array,int body,int a)//纯手工方案2
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