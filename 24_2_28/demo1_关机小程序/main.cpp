#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//#include <iostream>
//using namespace std;

//shutdown -s -t 60   // cmd������  -s�����ùػ� -t������ʱ��ػ� 60��ʱ��,��λ����
//shutdown -a         // cmd������  -a��ȡ���ػ� 

//system��һ���⺯��,ʹ��������ִ��cmd������(��ϵͳ����),!!!!      ʹ����Ҫ����ͷ�ļ�<stdlib.h>    !!!!
//ʹ�÷���  :system("ϵͳ����");     ����:system("system -s -t 60"); 
//          ע��ֺŲ�����,��Ϊ��C�������,��ʽ��ͬʱ�﷨ʹ��ò��printf����("")�������ƵĽṹ
// 
// C�����ַ�����Ƚϲ����������"=="�Ƚ�;����ʹ�� strcmp(ȫ�� string compare ���ַ����Ƚ�)����⺯��,ʹ������⺯����Ҫ����<string.h>�����
// ע:��C++��,������ string��,���Ƕ�̬�����ڴ�ռ�� ,���Խ��бȽ�(?  ϣ������ʱ������֤�������С�������ȷ�� ,��֤�ɹ�,��demo2_test )
// strcmp����ʹ�÷���:
//				strcmp(  �ַ�����1 (�ַ���1)  ,   �ַ�����2 (�ַ���2)   ) ���п��ԱȽϵ� �����ַ������ַ���,Ҳ����ʱ�ַ������ַ�����
// ���: �������  �ַ���/����  ������ͬ,�򷵻�0 !!!
// 
//                                             ��ô����������:
//1. ������ϵ�debug,��Ϊrelease
//2. �������,�ٵ�����ɿ�ִ�з���(����֮���ݼ�Ctrl+Shift+B)
// 
// 
//


//�汾1
//int main()
//{
//	char nameget[20] = { 0 };
//	system("shutdown -s -t 60");
//inputerror:
//	printf("��ĳ�����60���ػ�,��������������ȡ���ػ�\n");
//	scanf("%s", nameget);
//	if (strcmp(nameget, "������") == 0)
//	{
//		printf("��ϲ������ɹ�,�ɹ�ȡ���ػ�");
//		system("shutdown -a");
//	}
//	else 
//	{
//		goto inputerror;
//	}
//
//	return 0;
//}
//�汾2
int main()
{
	char nameget[20] = { 0 };
	system("shutdown -s -t 60");
	while (1)
	{
		printf("��ĵ��Խ���һ�����ڹػ�,������������ȡ���ػ�\n");
		scanf("%s", nameget);
		if (strcmp(nameget, "������") == 0)
		{
			system("shutdown -a");
			printf("!!!����ɹ�,��ȡ���ػ�!!!");
			break;
		}
		else
		{
			printf("!!!�������,");
		}

	}
	return 0;
}