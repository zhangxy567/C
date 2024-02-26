#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
using namespace std;
//C语言是一门结构化语言,三种结构:顺序结构,选择结构,循环结构


//C语言的逻辑判断:     表达式,如果是 0 ,则为假,   如果是  非0, 则为真 
// 
// if语句: 三种形式 1. if(表达式) 语句 
// 
//                 2. if(表达式) 语句1 
//                    else 语句2
// 
//                 3. if(表达式1) 语句1   
//                    else if(表达式2)  语句2 
//                    else if(表达式3)  语句3 
//                    .......
//                    else if(表达式n)  语句n 
//                    else  语句n+1
// 注意: if语句的执行内容可以是单句语句,也可以是用{}构成的代码块
// 
// 悬空else问题: else总是与最近的if匹配(82-86行代码不打印)
// if else算一个语句 嵌套的时候可以算作if else的嵌套语句,可以不用语句块囊括
// 
// 
// 
// C语言用于比较的表达式,称为关系表达式,里面使用的运算符就是关系运算符
// 主要有以下六个:
// >  大于运算符
// <  小于运算符
// >= 大于等于运算符
// <= 小于等于运算符
// == 相等运算符
// != 不相等运算符
// (1)关系表达式通常返回  1 或 0 表示真假
// C语言中,  非0值表示真  , 0表示假  比如  35>12 返回 1 , 12>35 返回 0
// 关系表达式的结果通常用于判断(if , while语句)
// (2)相等运算符和赋值运算符是两个完全不同的预算符:
// 相等运算符返回值只有0 和 1 ,分别表示两个值不相等和相等;
// 赋值运算符是把右值付给左值,表达式返回的值是左值
// 为了防止常量和变量判断相等时候不出现使用错误,建议常量放在左侧,变量放在右侧(108-112)
// 
// 
// 多个关系运算符不易连用,达不到预期效果,比如i<j<k,往往达不到预期效果
// (C语言中的大部分运算符都是从左向右结合的)
// 当多个关系符的运行时从左往右的,从左向右开始按照运算符一个一个计算,计算结果(0/1)作为下一个同级运算符的左值,直至只剩结果,无运算符
// 要想表达j的范围处于i和k之间,只能使用逻辑操作符   &&   来表达, 如  (i<j)&&(j<k)
// 
// 
// 条件操作符也就是三目操作符(C语言的唯一三目操作符)  如下:  (表达式1)?(表达式2):(表达式3)
// 三目操作符是一种天然的二选一的分支表达式
// 三目操作符计算逻辑: 如果  exp1 为真 ,则计算表达式2,表达式3不计算,并将表达式2的结果作为整个表达式结果;
//                    如果  exp1 为假 ,则计算表达式3,表达式2不计算,并将表达式3的结果作为整个表达式结果;(120-127行代码)
// 120-127行同时体现前置++和后置++的区别
// 三目操作符可以替代简单的if else语句
// 
// 
// 逻辑操作符(提供逻辑判断功能): &&   ||   !
// !: 逻辑取反运算符, 把非0变为0,把0变为1;    通常用于 变量/表达式 的取反,或者 变量/表达式 为假要做什么事情的时候使用
// &&: 与运算符,两侧都为真,则是真,否则为假;
// ||: 或运算符,两侧都为假,则是假,否则为真;   C语言的或不是排除或,而是逻辑或,解释如下
//  排除或(异或/XOR)的多种表示方法   :   1.  (A||B)&&!(A&&B)    2.    (!A && B) || ( A && !B)  
// 
// 短路:  C语言的逻辑运算符特有的特性(即逻辑&& || 和 )
// 所谓的短路,就是表达式总是先对左值求值,再对右边的表达式求值,如果左边的表达式满足逻辑运算符的条件,就不再对右边的表达式求值(不计算)
// 注意:短路情况就是特指   &&逻辑与的左操作数为0   则逻辑表达式右值不再计算,逻辑表达式结果即为0
//                       ||逻辑或的左操作数为1   则逻辑表达式右值不再计算,逻辑表达式结果即为1
//
// 
// 
// switch语句:
// 除了if语句,C语言还提供Switch语句来实现分支结构,switch是一种特殊形式的if else结构,用于判断条件有多个结果的情况
// 它把多重else if改为更易用,可读性更好的形式(仅限制确定的整型数据,其他类型不可以像if语句处理,所以仅能处理整型数据)见94行注意事项
//  default   :     默认
//  value     :     数据值
// expression :     表达式
// switch语句:
//                       switch (expression)
//                       {
//                          case value1 :  statement 1
//                          case value2 :  statement 2
//                          case value3 :  statement 3
//                          .....
//                          case valuen :  statement n
//                          
//                          default :statement(n+1)
//                       }
// 
// 注意:(1)switch 后面的 expression 必须是整型表达式(即表达式计算结果必须是整型常量或者变量)
//      (2)case 后面的值 value 必须是整型常量值 或者 整型常量表达式(即表达式计算结果是整型常量值,也不能是整型变量)
//      (3)case和后面的数字中间有空格
//      (4)case 执行完后面语句,只有加上break语句才能跳出switch语句
//  
// default的作用和多重else if最后的else作用相同,用来兜底
// switch语句的原理是 表达式的值是几,就从哪个入口进入,只要没有遇见break语句,就把接下来的所有语句全部执行,然后退出switch语句
// 即 表达式的值决定入口,break或者default关键词决定出口,如果没有以上两种关键词,switch执行完全部语句也会跳出
// break用法如下:(259-268)
// switch (expression)
//                       {
//                          case value1 :  statement 1 ;  break  ;
//                          case value2 :  statement 2 ;  break  ;             //使用break语句实现真正的分支语句
//                          case value3 :  statement 3 ;  break  ;
//                          .....
//                          case valuen :  statement n
//                          
//                          default :statement(n+1)
//                       }
// 小注意:(1)字符类似'a'在C语言底层存储是ASCII码,即整型常量,所以 expression 和 case 后面的值都可以用字符替代同时表示相印的整型(272-278)
//		  (2)case后可以是空语句,制造多选一的情况.如321-323行
//		  (3)default不一定放在switch语句末尾,只有default表示兜底放在switch语句结尾可以不加break语句,但是放在其他位置则应当考虑是否为兜底操作,兜底则需要,否则不需要
//          则另行判断,比如334-374行代码  不过我们通常default语句放在最后
//		  (4)
// 
// 
// 
// 
// 
// 
// 
// while循环:
// 语句:
//                                 while(表达式)
//                                       语句;(多条语句使用代码块)
// while循环的逻辑是上来就判断表达式真假,为假则不执行while语句,为真则执行语句,执行完语句再判断表达式真假,为真则继续执行语句,为假则结束,循环可能是死循环,也可能是有限循环
//                                 
// while语句有四个部分:循环变量初始化部分,判断条件部分,循环变量调整部分 ,目的语句执行部分                               
// 注意:(1)while语句内部只含有[判断]和[调整]和[目的语句]部分,变量的[初始化]在外部
// 
// 
// 
// for循环:
// 注:for循环是为了避免while循环的关键部分太分散而产生的,所以逻辑上 for循环更紧密
// 也就是说for循环使得一个循环的初始化,循环判断和循环变量调整三个部分紧密罗列在一起,便于观察,和调整
// 语句                                 for(表达式1;表达式2;表达式3)
//                                      语句(表达式4);(多条语句使用代码块)
// 表达式1    :  用于循环变量的初始化
// 表达式2    :  用于循环结束条件的判断
// 表达式3    :  用于每次执行完for的目的语句后的循环变量的调整
// for 循环语句和 while语句一样,初始化语句(表达式1)只执行一次,剩下的是判断语句(表达式2),循环语句(表达式4),调整语句(表达式3)的一直循环
// 
// 
// 
// 
// do while循环
// 语句:
//                               do
//                               语句;          //多条语句使用语句块
//                               while(表达式);    //最后一个分号不可少
//do while 和 while 循环与 for 循环的区别在于 do while的循环语句最少被执行一次,即do while不做判断,上来就会执行循环语句,然后再做判断                               
//                               
//
// 
// 
// break和continue语句,循环执行时,遇到某种情况,需要提前终止或者跳过
// break:break语句是永久终止循环,只要break被执行,就会跳出循环,执行循环外后续代码
// continue: continue作用是跳过本次循环continue后面的代码,进入下一个循环,   在for和while循环里有差异
// 
// 
// 
// 
// 
//


/*
C语言的逻辑或和现实中的排除或有什么区别
ChatGPT  :
C语言中的逻辑或 || 和现实中的排除或（XOR，Exclusive OR）是有一些区别的。
逻辑含义：
C语言中的逻辑或 || 表示的是在多个条件中，只要有一个条件为真，整个表达式就为真。这是一种联合的逻辑操作，不排除任何条件。
现实中的排除或（XOR）表示的是在多个条件中，只有一个条件为真时，整个表达式才为真。这是一种排他的逻辑操作，排除了其他条件。
应用场景：
逻辑或 || 在编程中常用于判断条件是否满足，控制程序的流程，允许多种情况中的任意一种发生。
排除或（XOR）在现实生活中常用于选择性的操作，表示在多个选项中只能选择一个，而不能同时选择多个。例如，在某些情况下，只能选择做 A 或者 B，
不能同时做 A 和 B。
因此，虽然C语言中的逻辑或 || 和现实中的排除或有时候会有相似的应用场景，但它们的逻辑含义和运用方式是不同的。
*/

// 
// C语言变量小知识点:  局部变量未初始化,它的值是随机的;全局变量未初始化,它的值是0 //  初始化英文  : uninitialized
// 426和436行体现了如何从逻辑底层提升代码效率和质量
//




int main()
{

//判断一个数是否为奇数:
	//int a;
	//scanf("%d", &a);
	//if (a % 2)  printf("所输入的值为奇数\n");
	//else printf("所输入的值为偶数\n");
	//return 0;
	//
	//
	//输入一个数,判断是正数,0,还是负数
	//新手版
	//
	//
	//int a;
	//scanf("%d", &a);
	//
	//if (a < 0)
	//	printf("所输入的值是负数");
	//else
	//	{
	//	if (a == 0)
	//		printf("所输入的值为零");
	//	  else
	//		printf("所输入的值为正数");
	//
	//	}
	//
	//高级版
	//int a;
	//scanf("%d", &a);
	//if (a < 0) printf("所输入的值为负数");
	//else if (a == 0) printf("所输入的值为0");
	//else printf("所输入的值为正数");
	//
	//
	//int a;
	//scanf("%d", &a);
	//if (a < 18)	printf("少年");
	//else if (  a>=18  &&  a<=44  )  printf("青年");
	//else if (  a>=45  &&  a<=59  )  printf("中老年");
	//else if (  a>=60  &&  a<=89  )  printf("老年");
	//else if (  a>=90  )  printf("老寿星");
	//return 0;
	//
	//int a = 0;
	//int b = 2;
	//if (a == 1)
	//	if (b == 2) printf("hehe");
	//else printf("haha");
	//int a = 100;
	//printf("%d", a == 6);
	//
	//
	//int a = 0;
	//if (1=a)
	//	printf("hehe\n");
	//int n = 5, k = 10;
	//int m = (2 - 1 ? n++ : k++);
	//printf("%d\n", m);
	//printf("%d\n", n);
	//printf("%d\n", k);
	//
	//
	//int a=0,b=0;
	//scanf("%d", &a);
//
	//printf("b = %d", b = (a > 5 ? 3 : -3));
	//
	//int a = 0, b = 0;
	//scanf("%d", &a);
	//(a > 5 ? b = 3 : b = -3);
	//printf("b = %d", b);
	//
	//使用条件操作符找两值最大
	//
	//int max, a, b;
	//scanf("%d%*c%d", &a, &b);
	//max = (a > b ? a : b);
	//printf("max = %d", max
	//);
//
	//int flag=0;
	//if(!flag) printf("do.....");
	//
	//printf("%d", a);
	//int m;
	//scanf("%[1]d", &m);
	//if (m >= 3 && m <= 5) printf("春天\n");
//
	//int a=0;
	//scanf("%d", &a);
	//if (a == 12 || a == 1 || a == 2) printf("冬季");
	//else printf("不是冬季");
//
//
	//输入一个年份,判断是不是闰年
	//闰年判断标准:
	//能被四整除,不能被100整除
	// 或者能被400整除
	//
	//int year=0;
	//scanf("%d", &year);
	//if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	//	printf("是闰年\n");
	//else
	//	printf("不是闰年\n");
//
//
//
    //输入一个整数,整除3取余,判断结果情况
	//int a = 0,b = 0;
	//scanf("%d", &a);
	//b = a % 3;
	//if (b == 0) printf("整除了\n");
	//else if (b == 1) printf("余数是1\n");
	//else             printf("余数是2\n");
//	
	//int a = 0;
	//scanf("%d", &a);
//
	//switch (a % 3)
	//{
	//case 0:  printf("整除了\n");    break;
	//case 1:  printf("余数是1\n");   break;
	//case 2:  printf("余数是2\n");   break;
//
	//}
	//int a = 0;
	//
//
	//switch (97)
	//{
	//case 'a':  printf("整除了\n");    break;
	//case 1:  printf("余数是1\n");   break;
	//case 2:  printf("余数是2\n");   break;
//
	//}
//
//
	//输入一个整数然后输出星期几
//
//版本0
//char a = '0';
//	scanf("%[1-7]c", &a);
//	switch (a)
//	{
//	case '1':printf("星期一"); break;
//	case '2':printf("星期二"); break;
//	case '3':printf("星期三"); break;
//	case '4':printf("星期四"); break;
//	case '5':printf("星期五"); break;
//	case '6':printf("星期六"); break;
//	case '7':printf("星期日"); break;
//	}
//版本2
	//int b = 0;
	//scanf("%d", &b);
	//switch (b)
	//{
	//case 1:printf("星期一"); break;
	//case 2:printf("星期二"); break;
	//case 3:printf("星期三"); break;
	//case 4:printf("星期四"); break;
	//case 5:printf("星期五"); break;
	//case 6:printf("星期六"); break;
	//case 7:printf("星期日"); break;
	//}
//如果需求发⽣变化，变为：
//1. 输⼊1 - 5，输出的是“⼯作⽇”;
//2. 输⼊6 - 7，输出“休息⽇”
//
	//int b = 0;
	//scanf("%d", &b);
	//switch (b)
	//{
	//case 1:
	//case 2:
	//case 3:
	//case 4:
	//case 5:printf("工作日"); break;
	//case 6:
	//case 7:printf("休息日"); break;
	//}
//01	//int b = 0;
	//scanf("%d", &b);
	//switch (b)
	//{
	//case 1:
	//case 2:
	//case 3:
	//case 4:
	//case 5:printf("工作日"); break;
	//case 6:
	//case 7:printf("休息日"); break;
	//default: printf("输入错误"); break;
	//}
//02	//int b = 0;
	//scanf("%d", &b);
	//switch (b)
	//{
	//default: printf("输入错误"); break;
	//case 1:
	//case 2:
	//case 3:
	//case 4:
	//case 5:printf("工作日"); break;
	//case 6:
	//case 7:printf("休息日"); break;
	//
	//}
//03	//int b = 0;
	//scanf("%d", &b);
	//switch (b)
	//{
	//default: printf("输入错误\n");
	//case 1:
	//case 2:
	//case 3:
	//case 4:
	//case 5:printf("工作日"); break;
	//case 6:
	//case 7:printf("休息日"); break;
	//
	//}
	

//循环
//在屏幕上打印1-10的值
	//int i = 1;
	//while (i <= 10)
	//{
	//	printf("%d\n", i);
	//	i++;
	//}
//
	//输入一个正的整数,逆序打印这个整数的每一位
	//int integer = 0;
	//scanf("%d", &integer);
	//while (integer)
	//{
	//	printf("%d ", integer % 10);
	//	integer /=  10;
	//}
	//使用for循环打印1-10的数
//
 //   int a = 0;
	//for (a = 1; a <= 10; a++)
	//{
	//	printf("%d ", a);
	//}
//
//计算1-100之间三的倍数之和
//版本1
	//int sum = 0, i = 1;
//
//
	//for (i = 3; i <= 100; i += 3)
	//{
	//	sum = sum + i;
	//}
	//
	//printf("%d", sum);
//版本2 
	//int i = 0;
	//int sum = 0;
	//for (i = 1; i <= 100; i++)
	//{
	//	if (i % 3 == 0)
	//		sum += i;
	//}
//
	//printf("%d", sum);
	//

/*	int i=1;
	do
	{
		printf("%d", i);
		i++;
	} while (i <= 10);*///这个分号至关重要不可缺少  ,即 do while语句末尾即while后面不可缺少"；"
//输入一个正整数,计算这个正整数位数
	
	//int n = 0,num=0;
	//scanf("%d", &n);

	//do
	//{
	//	n /= 10;
	//	num++;
	//} while (n);
	//printf("所输入数值的位数是%d", num);



//break和continue语句代码练习
	//int i = 1;
	//	while (i <= 10)
	//	{
	//		if (i == 5) break;
	//		printf("%d\n", i);
	//		i++;
	//	}
	int i = 1;
	while (i <= 10)
	{
		if (i == 5) 
			continue;
		printf("%d\n", i);
		i++;
	}
	return 0;
}