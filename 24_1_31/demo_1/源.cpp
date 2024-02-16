#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
using namespace std;

int main()
{
	//单目操作符正负号:+/-
	//  正号+对单目操作数没有影响,可以省略,主要起强调作用
	//  负号可以改变数字的正负号

	//int a = - 1;
	//printf("%d\n", a);
	//printf("%d\n", +a);
	int a = -1;
	int b = 2;
	printf("%d\n", -a);
	printf("%d\n", -b);



	//括号里面放个类型  类似:  (int) 可以把强转标识符后面的类容转为目标类型
	//在数据结构动态数组篇章比较常用

	 
	return 0;
}