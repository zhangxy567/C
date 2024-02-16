#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//#include <string.h>
//#include <iostream>
//using namespace std;

//打印1~100 3的整数倍
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
////从屏幕输入三数,比较大小
//int main()
//{
//	int a=0, b=0, c=0,max,min;
//	scanf("%d%d%d", &a,&b, &c);
//	min=max = a;
//	//找最大
//	if (a < b) 
//		max = b;
//	if (max < c) max = c;
//
//	//找最小
//	if (a > b)
//		min = b;
//	if (min > c)
//		min = c;
//	
//	//按照从大到小打印
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

//1~100中,整数出现数字9的个数

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
	printf("含多少个9: %d", num);
	return 0;

}
