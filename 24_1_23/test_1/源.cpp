#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int a=0;
	for (int a = 1; a <= 100; ++a)
	{
		if (a % 3 == 0)
			printf("%d ", a);

	}
	return 0;
} 