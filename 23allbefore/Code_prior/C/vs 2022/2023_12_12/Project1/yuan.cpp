#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int a = 0; int b = 1; int c = 100;
	cout<<a? ++b :c*100;
	return 0;
}