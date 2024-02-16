#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
char* exchange(char ap,int length)
{
	int len = length,j=0;
	char ac[80];
	for (int i = len - 1; i >= 0; i--, j++)

	{
		ac[j] = ac[i];
	}
	ap = ac;
	return ap;
}


int main()
{
	int length;
	char a[80],b;
	char* ap = a;
	gets(a);
	length=strlen(a);
	printf("a³¤¶ÈÎª%d", length);
	ap=exchange(ap, length);

	
	printf("%s", ap);
	
}