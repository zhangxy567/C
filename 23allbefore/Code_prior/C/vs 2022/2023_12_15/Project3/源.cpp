#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Book
{
	char name[20];
	int price;
};
int main()
{
	struct Book book1 = { "C���Գ������",55 };
	struct Book* pbook1 = &book1;
	printf("������:%s\n", book1.name);
	printf("�۸�:%d\n", book1.price);
	book1.price = 15;
	printf("������ļ۸���%d\n", pbook1->price);
	strcpy(book1.name, "c++");
	printf("�޸ĺ��������:%s\n", book1.name);
	/*struct Book book1 = { "C���Գ������",55 };
	struct Book* pbook1 = &book1;
	printf("����: % s,\n�۸� : % d\n", book1.name, book1.price);
	book1.price = 15;
	printf("�޸ĺ�ļ۸���%dԪ\n", (*pbook1).price);*/

	return 0;
}