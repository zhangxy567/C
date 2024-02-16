#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int* func()
{
	int n = 100;
	return &n;
}

int main()
{
	int* p = func();
	printf("c.biancheng.net\n");
	int n = *p;
	printf("n=%d", n);
	return 0;
}