#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;
int Add(int x, int y)
{
	int z = x + y;
	return z;
}
int main()
{
	int i ,n;
	/*int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("%d\n", arr[4]);*/
	/*/*for (i = 0; i <= 9; i++) arr[i] = i;*/
	/*for (i = 0; i <= 9; i++) cout << &arr[i] <<' ';*/
	int sum,num1 = 25; int num2 = 39;
	int a = 16; int b = 359;
	sum = Add(num1, num2);
	cout << sum << endl;
	sum = Add(a, b);
	cout << sum << endl;
	sum = Add(3, 6);
	cout << sum << endl;
	return 0;
}