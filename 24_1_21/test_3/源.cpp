#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//#include <string.h>
//#include <iostream>
//using namespace std;

//��ӡ1~100 3��������
//int main()
//{
//	int i = 1;
//	while (i < 101)
//	{
//		if (i % 3 == 0) printf("%d ", i);
//		i++;
//	}
//	return 0;
//
//}
//
////����Ļ��������,�Ƚϴ�С
//int main()
//{
//	int a=0, b=0, c=0,max,min;
//	scanf("%d%d%d", &a,&b, &c);
//	min=max = a;
//	//�����
//	if (a < b) 
//		max = b;
//	if (max < c) max = c;
//
//	//����С
//	if (a > b)
//		min = b;
//	if (min > c)
//		min = c;
//	
//	//���մӴ�С��ӡ
//	printf("%d", max);
//
//	if (a != max && a != min)
//		printf("%d", a);
//	else if (b != max && b != min)
//		printf("%d", b);
//	else printf("%d", c);
//
//	printf("%d", min);
//
//
//}

//1~100��,������������9�ĸ���

int main()
{
	int num = 0;
	for (int i = 1; i <= 100; i++)
	{
		int k = i;
		while (k)
		{
			if ((k % 10)-9 == 0)
			{
				num++;
			}
			k /= 10;
		}
	}
	printf("�����ٸ�9: %d", num);
	return 0;

}
