#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	extern int global;
	printf("g=%d\n", global);
	return 0;
}