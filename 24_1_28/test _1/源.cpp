#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
using namespace std;

int main()
{

	int a1;        //标准的整型类型


	// 以下写在方括号 [] 表示可以省略,但是仍表示原来意思
	short a2;      //short [int]短整型
				   // [signed] short [int]
	               // unsigned short [int]


	long a3;       // long [int]
	               // [signed] long [int]
	               // unsigned long [int]

	//以下标准是C99引入
	long long a4;  // long long [int]
	               // [signed] long long [int]
	               // unsigned long long [int]

	float b1;      //单精度浮点型
	
	double b2;     //双精度浮点型
	
	long double b3;


	//布尔类型名字起源于一个科学家;
	//使用布尔类型必须包含一个头文件 <stdbool.h>
	bool c3;

	return 0;
}