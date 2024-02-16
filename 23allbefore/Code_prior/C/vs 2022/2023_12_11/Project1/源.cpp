#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;
#define MONTHS 12
#define PI 3.14159
int main()
{	const int days = 7;
	cout << "一个星期有" << days << "天\n";
	double t_PI=PI* PI* PI;
	cout << "一年有:" << MONTHS << "个月" << endl;
	cout << "圆周率是:" << PI << endl;
	cout << "圆周率的三次方:" << t_PI << endl;
	
	

	return 0;
}