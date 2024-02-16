#include<stdio.h>

int main()
{
	printf("(are you ok\?\?)\n");//??加其他符号 在早期编译器会被解析成三字母词 
	printf("%c\n",'\''); //  \' 使单引号 取消其构成两个单引号的可能,
	//使其成为一个普通的可输出  
	return 0;
}

