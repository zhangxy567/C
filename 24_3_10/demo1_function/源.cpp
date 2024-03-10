#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#include <iostream>
using namespace std;
//一 函数
// 定义:C语言的函数就是为了完成某项特定任务的一小段代码
// 1 库函数
// 库函数文档的一般格式:
// (1)函数原型                                 (即语法格式)
// (2)函数功能介绍
// (3)参数和返回类型介绍
// (4)代码举例
// (5)代码输出
// (6)相关知识链接
// 
// 
// 2自定义函数
// (1)语法: ret_type  fun_name(形式参数) 
//          {
// 
//          }
// 理解:(1)函数的作用就如同一个工厂,给它数据,就如同给工厂原材料,通过加工,工厂会得到产品,而函数则会得到处理后的数据
//      (2)函数的返回类型可以是内置的,也可以是自定义的; 但是有时候可以是void
//         函数的名字定义与组成和标识符同理;
//      (3)函数的参数:
//             调用函数时,传递给函数的参数就是实际参数,简称实参
//             函数定义中,函数名后面括号里的就是形式参数,简称形参
//             实参和形参需要用圆括号()括起来,
//             形参必须要定义类型,实参直接上传,
//             多个参数用逗号分开;有时候形参可以为空或者填上void,实参可以为空
//             形参和实参名称可以相同
//             形参和实参在第一次赋值时是一一对应的,但是复制之后在内存上是相互独立的,对形参的修改不会影响实参
//         函数的调用是  fun_name();圆括号里的实参根据形参个数填入
// 
// return语句:
// (1) return语句后可以是一个值,也可以是一个表达式,如果是表达式,则先执行表达式,再返回表达式的结果
// (2) return后面也可以什么都没有,直接写  return;  这种写法适合需要提前返回,但是函数返回类型是void的情况
// (3) return返回的值与函数返回的类型不一致,系统将自动把返回的值转换成函数的返回类型(类似于强制转换,可能会有值的丢失)
// (4) return语句执行后,函数就彻底返回,后面代码不再执行
// (5) 如果函数中出现if等分支语句,则要保证每种情况下都有return返回,否则会出现编译警告/警告
// (6) 数组传参传的是数组的指针,所以是直接在实参原值上的修改
// 
// 
// 
// 数组传参的重要知识点:
// (1)数组的形参个数要和数组的实参个数匹配
// (2)函数的实参是数组,那么函数的形参可以写成数组形式也可以写成指针的形式
// (3)当形参写成数组形式,形参如果是一维数组,数组大小可以不写
// (4)当形参写成数组形式,形参如果是二维数组,数组行可以不写,列必须写
// (5)数组传参,传的是地址,不会创建新的数组,操作的是同一个数组
// 
// 
// 嵌套调用和链式访问:
// 嵌套调用就是函数之间的互相调用
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// vs2022 F10是逐过程运行,F11进入函数
// 
//

//这里是函数的定义--实现
//int Add(int a, int b)
//{
//	return (a + b);
//}
//int main()
//{
//	//double res = sqrt(16.0);
//	//printf("%2.1lf", res);
//	int c = Add(3, 5);//函数的使用
//	printf("%d",c);
//
//	return 0;
//}
//int is_odd(int n)
//{
//	return n % 2;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int r = is_odd(n);
//	if (r == 1) printf("是奇数");
//	else        printf("是偶数");
//	return 0;
//}
//void print_arr(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return;
//}
//void set_arr(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		arr[i] = -1;
//	}
//	return;
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	set_arr(arr,sz);
//	print_arr(arr, sz);
//
//	return 0;
//}

//计算某年某月有多少天
int is_leep_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

int get_day_num(int year,int month) 
{
	int key=0;
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int days_res = days[month];
	
	key = is_leep_year(year);
	if (key&& month==2)
	{
		days_res += 1;
	}
	
	return days_res;
}

int main()
{
	int year = 0;
	int month = 0;
	int daynum = 0;
	cout << "请输出年和月份->";
	scanf("%d %d", &year, &month);

	daynum = get_day_num(year,month);

	printf("%d年%d月的天数为:  %d", year, month,daynum);

}