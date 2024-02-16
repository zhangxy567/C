#include <stdio.h>
#include <stdlib.h>
//链表中节点的结构
typedef struct Link{
    int  elem;
    struct Link *next;
}link;
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