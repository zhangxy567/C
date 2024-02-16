#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char a[] = "adcsds";
	int b[] = { 8,5,4,6,5 };
	char* pc = a;
	int* pa = b;
	printf("%s\n", pc);
	printf("%s\n", a);
	printf("%d\n", pa);
	return 0;
}
