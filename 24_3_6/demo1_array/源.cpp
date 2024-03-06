#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


#include <iostream>
using namespace std;
//array 数组 就是一组数据的意思
// 数组概念:数组是一组相同类型元素的集合
// 一维数组:
//一维数组创建的语法形式:
// type arr_name[常量值]
// 存放在数组里面的值被称为数组的元素,数组在创建的时候可以指定数组的大小和元素类型
// type:指数组里面存放数据的类型,可以是char short int float等,也可以是**自定义类型**
// arr_name指的是数组的名字,这个名字根据实际情况,取得有意义就行
// []中的常量值用来指定数组大小,但是注意只能放常量值,不能放变量
// 
// 数组的初始化,初始化一般使用大括号,将数据放在大括号中;
// 1完全初始化
// 2不完全初始化    按照次序初始化,剩下没有初始化的默认全部放0
// 3初始化的项数不能比常量值大
// 
// 数组的类型:
// 数组的类型不是数组元素的类型而是整个集合的类型:
// 比如 int array[10]的数组类型   不是int 而是 int[10]  //和变量一样,去掉名字就是数组类型
// 
// 一维数组的使用:
// 1数组下标
// 
// 
//
int main()
{
	//int score[5]={ 1,2,3,4,5 };
	int score[100]={ 1,2,3,4,5 };
	return 0;
}