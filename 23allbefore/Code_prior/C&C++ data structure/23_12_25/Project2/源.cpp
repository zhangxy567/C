#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


//������ �ڵ�Ľṹ
typedef struct Link {
    int  elem;
    struct Link* next;
}link;
//��ʼ������ĺ���
link* initLink();
//�����������ĺ���
void display(link* p);
//������ɾ�ڵ�
link* insertElem(link* p, int elem, int place);
int main() {
    int elem, place;

    printf("��ʼ������Ϊ��\n");
    link* p = initLink();
    display(p);
    printf("������Ҫ��������ݺ�λ��(�ÿո񻮿�)\n");
    scanf("%d %d", &elem, &place);
    insertElem(p, elem, place);
    display(p);
    return 0;
}

link* initLink() {
    link* p = (link*)malloc(sizeof(link));//����һ��ͷ���
    link* temp = p;//����һ��ָ��ָ��ͷ��㣬
    //��������
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
    link* temp = p;//��tempָ������ָ��ͷ���
    //ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
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
            printf("����λ������\n");
            return p;
        }
        temp = temp->next;
    }
    link* c = (link*)malloc(sizeof(link));
    if (!c)
    {
        printf("��ʼ��ʧ��\n");
        exit(0);
    }
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;

}