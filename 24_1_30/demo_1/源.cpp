#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
using namespace std;

int main()
{
	//前置++和后置++的联系与区别
	//联系:
	//前置++和后置++都是自增1
	//int a = 10;
	//a++;
	//++a;
	//printf("%d", a);


	//int a = 10;
	//int b = ++a;//后置++
	//printf("%d  %d \n", a,b);
	int a = 10;
	int b = a++;//前置++
	printf("%d  %d \n", a, b);

	//综上可知    前置++和后置++区别在于
	//前置++: 先++再使用 ,   后置++: 先使用再++

	//前置--和后置--的用法与上前置++与后置++用法完全相同

	return 0;
}