#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include <iostream>
using namespace std;

int main()
{
	string name1 = "张三";
	string name2 = "张三";
	if (name1 == name2)
		printf("C++中string可以使用运算符\"==\"进行比较");
	return 0;
}