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
	//sizeof 专门用来计算 sizeof操作数<类型>的长度
	//sizeof 的操作数可以是 类型 ,变量 ,表达式
	//返回结果单位是字节;


	//sizeof 的操作数如果不是数据类型,而是变量和表达式,可以省略圆括号
	int a1 = sizeof(int);//这种可以
	//int a2 = sizeof int;//这种运行会报错


	//sizeof后面的表达式不参与真运算 ,而是根据表达式类型得出变量/类型<长度>结果
	int a3 = sizeof(b++);
	int a4 = sizeof b;
	printf("%d\n", a3);
	printf("%d\n", a4);
	printf("%d\n", b);//b 值未改变

	//各类型长度
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
	//sizeof 计算结果是size_t类型 ,C语言只规定是无符号整数
	// 也就是可能为 unsigned int,unsigned long,unsigned long long,
	// 具体未规定,且上面分别对应  %u ,%lu ,%llu
	// 为了解决这个问题,C语言规定其为size_t类型,可能是上面三种之一
	// 所以打印是使用 %zd为无符号整数打印




	
	return 0;
}