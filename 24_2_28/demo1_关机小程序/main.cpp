#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//#include <iostream>
//using namespace std;

//shutdown -s -t 60   // cmd命令行  -s是设置关机 -t是设置时间关机 60是时间,单位是秒
//shutdown -a         // cmd命令行  -a是取消关机 

//system是一个库函数,使用它可以执行cmd命令行(即系统命令),!!!!      使用需要包含头文件<stdlib.h>    !!!!
//使用方法  :system("系统命令");     例子:system("system -s -t 60"); 
//          注意分号不可少,因为是C语言语句,形式上同时语法使用貌似printf都是("")这样类似的结构
// 
// C语言字符数组比较不能用运算符"=="比较;而是使用 strcmp(全称 string compare 即字符串比较)这个库函数,使用这个库函数就要包含<string.h>这个库
// 注:在C++中,引入了 string类,它是动态分配内存空间的 ,可以进行比较(?  希望考古时可以验证这个开机小程序的正确性 ,验证成功,见demo2_test )
// strcmp函数使用方法:
//				strcmp(  字符数组1 (字符串1)  ,   字符数组2 (字符串2)   ) 其中可以比较的 可以字符串和字符串,也可以时字符串和字符数组
// 结果: 如果两个  字符串/数组  内容相同,则返回0 !!!
// 
//                                             怎么样发布程序:
//1. 点击放上的debug,改为release
//2. 点击生成,再点击生成可执行方案(或者之间快捷键Ctrl+Shift+B)
// 
// 
//


//版本1
//int main()
//{
//	char nameget[20] = { 0 };
//	system("shutdown -s -t 60");
//inputerror:
//	printf("你的程序将在60秒后关机,请输入我是猪来取消关机\n");
//	scanf("%s", nameget);
//	if (strcmp(nameget, "我是猪") == 0)
//	{
//		printf("恭喜你输入成功,成功取消关机");
//		system("shutdown -a");
//	}
//	else 
//	{
//		goto inputerror;
//	}
//
//	return 0;
//}
//版本2
int main()
{
	char nameget[20] = { 0 };
	system("shutdown -s -t 60");
	while (1)
	{
		printf("你的电脑将在一分钟内关机,请输入我是猪取消关机\n");
		scanf("%s", nameget);
		if (strcmp(nameget, "我是猪") == 0)
		{
			system("shutdown -a");
			printf("!!!输入成功,已取消关机!!!");
			break;
		}
		else
		{
			printf("!!!输入错误,");
		}

	}
	return 0;
}