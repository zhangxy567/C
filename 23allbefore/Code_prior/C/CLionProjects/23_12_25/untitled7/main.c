#include <stdio.h>
#include <stdlib.h>
//�����нڵ�Ľṹ
typedef struct Link{
    int  elem;
    struct Link *next;
}link;
//��ʼ������ĺ���
link * initLink();
//�����������ĺ���
void display(link *p);
link * insertElem(link * p, int elem, int add);
int main() {
    //��ʼ������1��2��3��4��
    int elem,place;
    printf("��ʼ������Ϊ��\n");
    link *p=initLink();
    display(p);
    printf("������Ҫ��������ݺ�λ��(�ÿո񻮿�)\n");
    scanf("%d %d",&elem,&place);
    insertElem(p,elem,place);
    display(p);
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
        printf("%d  ",temp->elem);
    }
    printf("\n");
}
//pΪԭ����elem��ʾ������Ԫ�أ�add��ʾ��Ԫ��Ҫ�����λ��
link * insertElem(link * p, int elem, int add) {
    link * temp = p;//������ʱ���temp
    //�����ҵ�Ҫ����λ�õ���һ�����
    for (int i = 1; i < add; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("����λ����Ч\n");
            return p;
        }
    }
    //����������c
    link * c = (link*)malloc(sizeof(link));
    c->elem = elem;
    //�������в�����
    c->next = temp->next;
    temp->next = c;
    return p;
}