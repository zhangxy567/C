#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;

//���� a �� b ��λ�õĺ���
void swap(int* a, int* b);
int main()
{
    int array[8] = { 49,38,65,97,76,13,27,49 };
    int i, j;
    int key;
    //�ж��ټ�¼������Ҫ���ٴ�ð�ݣ����ȽϹ��̣����м�¼��������������ʱ���������
    for (i = 0; i < 8; i++) {
        key = 0;//ÿ�ο�ʼð��ǰ����ʼ�� key ֵΪ 0
        //ÿ�����ݴ��±�Ϊ 0 ��ʼ���� 8-i ����
        for (j = 0; j + 1 < 8 - i; j++) {
            if (array[j] > array[j + 1]) {
                key = 1;
                swap(&array[j], &array[j + 1]);
            }
        }
        //��� key ֵΪ 0���������м�¼�������
        if (key == 0) {
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}