#include <stdio.h>
#define max 5//��ʾ˳�������Ŀռ��С
int enQueue(int* a, int front, int rear, int data) {
    //����ж���䣬���rear����max����ֱ�ӽ����a[0]���¿�ʼ�洢�����rear+1��front�غϣ����ʾ��������
    if ((rear + 1) % max == front) {
        printf("�ռ�����");
        return rear;
    }
    a[rear % max] = data;
    rear++;
    return rear;
}
int  deQueue(int* a, int front, int rear) {
    //���front==rear����ʾ����Ϊ��
    if (front == rear % max) {
        printf("����Ϊ��");
        return front;
    }
    printf("%d ", a[front]);
    //front����ֱ�� +1������+1��ͬmax���бȽϣ����=max����ֱ����ת�� a[0]
    front = (front + 1) % max;
    return front;
}
int main() {
    int a[max];
    int front, rear;
    //���ö�ͷָ��Ͷ�βָ�룬��������û��Ԫ��ʱ����ͷ�Ͷ�βָ��ͬһ���ַ
    front = rear = 0;
    //���
    rear = enQueue(a, front, rear, 1);
    rear = enQueue(a, front, rear, 2);
    rear = enQueue(a, front, rear, 3);
    rear = enQueue(a, front, rear, 4);
    //����
    front = deQueue(a, front, rear);
    //�����
    rear = enQueue(a, front, rear, 5);
    //�ٳ���
    front = deQueue(a, front, rear);
    //�����
    rear = enQueue(a, front, rear, 6);
    //�ٳ���
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    return 0;
}