#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int n,i;
	printf("请输入要生成的数组大小\n");
	scanf("%d", &n);

	int* arr;
	arr = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		arr[i]=i+1
	}
	for (i = 0; i < n; i++)
	{
		printf("a[%d]=%d",i,a[i])
	}
	return 0;
}