#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
using namespace std;
#include <limits.h>

int main()
{
	//unsigned [int] 中int可以省略
	//un/*signed a1 = 4000000000;*/


	//char 默认是signed char 还是unsigned char C语言未规定
	//取决于编译器,所以想表示 signed/unsigned 必须自己手动添加
	/*unsigned char a2=97;
	unsigned char b=253;
	printf("%c", a2);*/

	// 打印格式对应关系:
	// %d   对应 int
	// %u   对应 unsigned [int]
	// %lu  对应 unsigned long [int]
	// %llu 对应 unsigned longlong [int]


	//查看当前系统下数据类型的极限
	//两个文件
	//<limits.h>
	//<float.h>

	/*printf("%d", INT_MAX);
	return 0;*/





}