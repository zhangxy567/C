#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char* pstr,str[] = "http://c.biancheng.net";
	int len = strlen(str);
	pstr = str;
	printf("%d\n",len);
	printf("%s\n", str);
	for (int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
	for (int i = 0; i < len; i++)
	{
		printf("%c" ,* (pstr + i));
	}
	printf("\n");
	for (int i = 0; i < len; i++)
	{
		printf("%c", *(str + i));
	}
	printf("\n");


	return 0;
}