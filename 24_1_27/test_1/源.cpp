#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{

	////验证 \0
	//printf("%s", "a\0bc\0def");
	//return 0;
	/* 这是一个注释 */

	/* 
	这是一个分行注释
	*/
	printf("%s", /* 这种注释可以加在代码中间 */"abcdef");
	// 但是这种注释不支持嵌套

	// "//"这种注释是C99风格,或者叫C++风格
	//printf("%s", "//abc/*双引号里面的注释符号失效*/def");
	int/*注释会被替换成空格*/a;
	//inta;

}