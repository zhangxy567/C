#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int max(int* intArr, int len)
{
	int i, maxvalue = intArr[0];
	for (i = 1; i < len; i++)
	{
		if (maxvalue < intArr[i])
		{
			maxvalue = intArr[i];
		}
	}
	return maxvalue;
}

int main()
{
	int nums[6], i;
	int len = sizeof(nums) / sizeof(int);
	for (i = 0; i < len; i++)
	{
		scanf("%d", nums+i);
	}

	for (i = 0; i < len; i++)
	{
		printf("nums[%d]=%d	 ",i,nums[i]);
	}
	printf("\n");
	
	printf("最大的值为%d", max(nums, len));
}