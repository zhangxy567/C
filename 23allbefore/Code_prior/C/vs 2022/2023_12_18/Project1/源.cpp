#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char str1[] = "http://c.biancheng.net";
	char str2[] = "http://www.baidu.com";
	int result = strcmp(str1, str2);
	printf("str1-str2=%d\n", result);

	return 0;
}