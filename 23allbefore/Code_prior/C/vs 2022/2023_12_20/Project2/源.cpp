#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
#include <stdio.h>
#include <string.h>
//using namespace std;

int main()
{
	char* str;
	str = "http://c.biancheng.net";
	int len = strlen(str), i;
	printf("%s\n", str);
	for (i = 0; i < len; i++)
	{
		printf("%c", *(str + i));
	}
	printf("\n");
	for (i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}
	return 0;
}