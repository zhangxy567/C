#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
using namespace std;

int main()
{
	//ǰ��++�ͺ���++����ϵ������
	//��ϵ:
	//ǰ��++�ͺ���++��������1
	//int a = 10;
	//a++;
	//++a;
	//printf("%d", a);


	//int a = 10;
	//int b = ++a;//����++
	//printf("%d  %d \n", a,b);
	int a = 10;
	int b = a++;//ǰ��++
	printf("%d  %d \n", a, b);

	//���Ͽ�֪    ǰ��++�ͺ���++��������
	//ǰ��++: ��++��ʹ�� ,   ����++: ��ʹ����++

	//ǰ��--�ͺ���--���÷�����ǰ��++�����++�÷���ȫ��ͬ

	return 0;
}