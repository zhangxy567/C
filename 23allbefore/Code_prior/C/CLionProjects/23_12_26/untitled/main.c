#include <stdio.h>
#include <stdlib.h>
//链表中节点的结构
typedef struct Link{
    int  elem;
    struct Link *next;
}link;
//自定义的 bool 类型
typedef enum bool
{
    False = 0,
    True = 1
}bool;
//L1 和 L2 为 2 个单链表，函数返回 True 表示链表相交，返回 False 表示不相交
bool LinkIntersect(link * L1, link * L2) {
    link * p1 = L1;
    link * p2 = L2;
    //逐个遍历 L1 链表中的各个节点
    while (p1)
    {
        //遍历 L2 链表，针对每个 p1，依次和 p2 所指节点做比较
        while (p2) {
            //p1、p2 中记录的就是各个节点的存储地址，直接比较即可
            if (p1 == p2) {
                return True;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return False;
}


//初始化链表的函数
link * initLink();
//用于输出链表的函数
void display(link *p);

int main() {
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    link *p=initLink();
    display(p);
    return 0;
}

link * initLink(){
    link * p=NULL;//创建头指针
    link * temp = (link*)malloc(sizeof(link));//创建首元节点
    //首元节点先初始化
    temp->elem = 1;
    temp->next = NULL;
    p = temp;//头指针指向首元节点
    for (int i=2; i<5; i++) {
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
    while (temp) {
        printf("%d ",temp->elem);
        temp=temp->next;
    }
    printf("\n");
}