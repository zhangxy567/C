#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX(X,Y) (X>Y?X:Y)
int main()
{
	int a = 101;
	int b = 20;
	int max;
	max = MAX(a, b);
	cout << max;
	return 0;
}