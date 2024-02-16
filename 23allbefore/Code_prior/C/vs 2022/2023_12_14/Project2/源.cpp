#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	static int a = 98;
	printf("%d", &a);
	return 0;
}