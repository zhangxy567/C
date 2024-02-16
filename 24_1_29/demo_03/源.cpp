#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
using namespace std;

int main()
{
	// % 取模运算符 只能用于<整数>运算 返回结果为两整数的余数
	//例:  5%2=1
	/*int a = 7 % 2;*/
	//int b = 7.0 % 2;   //出错
	/*printf("%d\n", a);*/

	//取模的结果正负由左操作数决定
	/*printf("%d\n", 11 % -5);
	printf("%d\n",-11 %- 5);
	printf("%d\n",-11 %  5);*/

	//赋值语句从右向左运行
	//赋值语句的结果为左值
	//<连续>赋值语句从右向左运行

	/*int a = 3;
	int b = 5;
	int c = 11;
	c = b = a + 3;
	printf("%d\n", b);
	printf("%d\n", c);*/

	//<复合>赋值符
	//C语言中 如果左操作数 在右操作区间有左操作数的操作
	//则在可以使用复合操作符;

	//例子:
	//  a=a+3 ;  也可写作  a+=3  +=即是复合操作符
	//除了加减乘除模,还有<位>操作符也可以进行复合:>>= <<= ^= |= &=

	//int a = 10;
	//a =  a+5;
	//a += 5;

	//a = a - 5;
	//a -= 5;

	//a /= 5;
	//a &= 5;

	//printf("%d", a);




	return 0;
}