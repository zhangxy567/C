#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	/*
	printf("(are you ok\?\?)\n");//??加其他符号 在早期编译器会被解析成三字母词 
	printf("%c\n", '\''); //  \' 使单引号 取消其构成两个单引号的可能,
						  //使其成为一个普通的可输出  
	printf("%s\n", "\"");//同理 \"

	printf("c:\\test\\test.c");//防止 \构成转义字符,使其变成普通\字符
	*/

	//printf("\a");//触发电脑蜂鸣

	//printf("abcdef\n");// \b------- backspace 回退一格,不删除
	//printf("abc\b\n");//但是如果继续打印,则覆盖
	//printf("abc\bdef\n");
	

	//printf("abcdef\n");// \n换行符


	//printf("a\r");// \r回车符 移到同一行开头并且删除字符
	//printf("a\rdef");

	//printf("a\tbc\tdef\tqwer");//制表符,光标移到下一个制表位,通常是4/8
	//注意:不是固定的移动八个空位,而是连上前面的位置一共有八个
	//比如a后面有7个空格,bc后面有6个空格,def后面有5个空格






	//字符的八进制和十六进制表示形式
	// \ddd  ddd表示1~3个8进制数      表示用八进制表示的字符
	// \xdd  xdd表示1~2个十六进制数   表示用十六进制表示的字符
	//以上两种写法,都表示的是字符,所以必须用单引号括起来
	//各种情况可以是1位,也可以是最多两位或三位
	printf("%c\n", '\130');
	printf("ab%cc", '\x9');


	return 0;
}
