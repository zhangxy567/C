#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//#include <iostream>
//using namespace std;

int main()
{
	char* str = (char*)malloc(sizeof(char) * 30);
	gets(str);
	printf("str  =  %s", str); 
		free(str);
	return 0;
}
