#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
#include <stdio.h>
#include <string.h>
//using namespace std;
#define Size 80

char* invertstr(char str1[Size],int len)
{
	char* pstr_1;
	int i, j=0;
	pstr_1=(char*)malloc(Size * sizeof(char));
	if (!pstr_1)
	{
		printf("��ʼ���ڴ�ʧ��\n");
		exit(0);
	}
	for (i = len - 1; i >= 0; i--, j++)
	{
		pstr_1[j] = str1[i];
	}
	return pstr_1;

}

int main()
{
	char *pstr,str[80];
	int length;
	printf("������Ҫ���õ��ַ���\n");
	gets(str);
	length=strlen(str);
	printf("str�������Ч����Ϊ%d\n", length);
	printf("strԭ������ַ�Ϊ  %s\n", str);
	pstr=invertstr(str, length);
	strcpy(str, *pstr);
	printf("%s\n", str);
	return 0;
}