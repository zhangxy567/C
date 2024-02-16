#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
using namespace std;

int a=100;

int main()
{	
	//int a = 10;     //全局变量范围>局部变量
	//printf("%d", a);//全局变量和局部变量<名>相同,局部变量优先
	//				全局变量在内存静态区
	//				局部变量在栈区


	//float fa = 3.14;
	//double dfa = 3.14;
	//printf("%f\n", fa);//单精度浮点型用%f打印
	//printf("%lf\n", dfa);//双精度浮点型用%lf打印

	//C语言除法和现实中的区别:
	//printf("%d\n", 6 / 4);//如果除数两端为整数,则执行整数除法,
	//                      //只取商,不留余数,结果整数
	//printf("%.1lf\n", 6.0 / 4);//如果要计算出小数的效果,除号两端
	//printf("%.2lf\n", 6.0 / 4);   //至少要一个小数,全是小数也可以

	// %f 和 %lf 打印小数默认打印六位小数
	//通过在占位符的%后面添加内容修改打印形式
	//如:
	//% .1 f 这样的书写使得结果只有一位小数
	//还有其他各种形式,在 printf和scanf篇会细讲


	//编译器上写的小数默认是double类型,需要标注,
	//形式如右: 3.14f
	

	return 0;
}