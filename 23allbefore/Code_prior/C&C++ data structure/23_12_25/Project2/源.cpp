#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


//链表中 节点的结构
typedef struct Link {
    int  elem;
    struct Link* next;
}link;
//初始化链表的函数
link* initLink();
//用于输出链表的函数
void display(link* p);
//用于增删节点
link* insertElem(link* p, int elem, int place);
int main() {
    int elem, place;

    printf("初始化链表为：\n");
    link* p = initLink();
    display(p);
    printf("请输入要插入的数据和位置(用空格划开)\n");
    scanf("%d %d", &elem, &place);
    insertElem(p, elem, place);
    display(p);
    return 0;
}

link* initLink() {
    link* p = (link*)malloc(sizeof(link));//创建一个头结点
    link* temp = p;//声明一个指针指向头结点，
    //生成链表
    for (int i = 1; i < 5; i++) {
        link* a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}
void display(link* p) {
    link* temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {
        temp = temp->next;
        printf("%d ", temp->elem);

    }
    printf("\n");
}
link* insertElem(link* p, int elem, int place)
{
    link* temp = p;
    for (int i = 1; i < place; i++)
    {
        if (temp == NULL)
        {
            printf("插入位置有误\n");
            return p;
        }
        temp = temp->next;
    }
    link* c = (link*)malloc(sizeof(link));
    if (!c)
    {
        printf("初始化失败\n");
        exit(0);
    }
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;

}