#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int a = 100;
	int* p1 = &a;
	int** p2 = &p1;
	int*** p3 = &p2;
	printf("%d, %d, %d, %d\n", a, *p1, **p2, ***p3);
	printf("%#X,%#X\n", &p2, p3);
	printf("p1=%#X, p2=%#X, *p3=%#X\n", &p1, p2, *p3);
	printf("&a=%#X,p1=%#X,*p2=%#X,**p3=%#X\n", &a, p1, *p2, **p3);
	printf("%d", sizeof(p1));
	return 0;
}