#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
char exchange(char str[], int length)
{
	int len = length, j = 0;
	char a[80];
	for (int i = len - 1; i >= 0; i--, j++)

	{
		a[j] = str[i];
	}
	
	return a;
}


int main()
{
	int length;
	char str[80];
	gets(str);
	length = strlen(str);
	printf("a长度为%d\n", length);
	printf("a的内容为%s\n", str);
	strcpy(str, exchange(str, length));
	printf("%s\n", str);

}