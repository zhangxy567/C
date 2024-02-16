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
link * insertElem(link * p, int elem, int add);
int main() {
    //初始化链表（1，2，3，4）
    int elem,place;
    printf("初始化链表为：\n");
    link *p=initLink();
    display(p);
    printf("请输入要插入的数据和位置(用空格划开)\n");
    scanf("%d %d",&elem,&place);
    insertElem(p,elem,place);
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
        printf("%d  ",temp->elem);
    }
    printf("\n");
}
//p为原链表，elem表示新数据元素，add表示新元素要插入的位置
link * insertElem(link * p, int elem, int add) {
    link * temp = p;//创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("插入位置无效\n");
            return p;
        }
    }
    //创建插入结点c
    link * c = (link*)malloc(sizeof(link));
    c->elem = elem;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return p;
}