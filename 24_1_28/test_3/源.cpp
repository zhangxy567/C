#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
using namespace std;

int main()
{
	int b=0;
	//sizeof ר���������� sizeof������<����>�ĳ���
	//sizeof �Ĳ����������� ���� ,���� ,���ʽ
	//���ؽ����λ���ֽ�;


	//sizeof �Ĳ��������������������,���Ǳ����ͱ��ʽ,����ʡ��Բ����
	int a1 = sizeof(int);//���ֿ���
	//int a2 = sizeof int;//�������лᱨ��


	//sizeof����ı��ʽ������������ ,���Ǹ��ݱ��ʽ���͵ó�����/����<����>���
	int a3 = sizeof(b++);
	int a4 = sizeof b;
	printf("%d\n", a3);
	printf("%d\n", a4);
	printf("%d\n", b);//b ֵδ�ı�

	//�����ͳ���
	/*printf("%zd\n", sizeof(int));
	printf("%zd\n", sizeof(short));
	printf("%zd\n", sizeof(long));
	printf("%zd\n", sizeof(long long));

	printf("%zd\n", sizeof(char));

	printf("%zd\n", sizeof(float));
	printf("%zd\n", sizeof(double));
	printf("%zd\n", sizeof( long double));
	printf("%zd\n", sizeof( bool));*/



	//******************
	//sizeof ��������size_t���� ,C����ֻ�涨���޷�������
	// Ҳ���ǿ���Ϊ unsigned int,unsigned long,unsigned long long,
	// ����δ�涨,������ֱ��Ӧ  %u ,%lu ,%llu
	// Ϊ�˽���������,C���Թ涨��Ϊsize_t����,��������������֮һ
	// ���Դ�ӡ��ʹ�� %zdΪ�޷���������ӡ




	
	return 0;
}