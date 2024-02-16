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
link* recursive_reverse(link* head);

int main() {
    //��ʼ������1��2��3��4��
    printf("��ʼ������Ϊ��\n");
    link *p=initLink();
    display(p);
    p=recursive_reverse(p);
    printf("�ݹ鷴ת��ĺ�����\n");
    display(p);
    return 0;
}
link* recursive_reverse(link* head)
{
    if(head==NULL||head->next==NULL) return head;
    else
    {
        link* new_head=recursive_reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return new_head;
    }

}

link * initLink(){
    link * p=NULL;//����ͷָ��
    link * temp = (link*)malloc(sizeof(link));//������Ԫ�ڵ�
    //��Ԫ�ڵ��ȳ�ʼ��
    temp->elem = 1;
    temp->next = NULL;
    p = temp;//ͷָ��ָ����Ԫ�ڵ�
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
    link* temp=p;//��tempָ������ָ��ͷ���
    //ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
    while (temp) {
        printf("%d ",temp->elem);
        temp=temp->next;
    }
    printf("\n");
}