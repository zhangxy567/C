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
	struct Book book1 = { "C语言程序设计",55 };
	struct Book* pbook1 = &book1;
	printf("书名是:%s\n", book1.name);
	printf("价格:%d\n", book1.price);
	book1.price = 15;
	printf("促销后的价格是%d\n", pbook1->price);
	strcpy(book1.name, "c++");
	printf("修改后的书名是:%s\n", book1.name);
	/*struct Book book1 = { "C语言程序设计",55 };
	struct Book* pbook1 = &book1;
	printf("书名: % s,\n价格 : % d\n", book1.name, book1.price);
	book1.price = 15;
	printf("修改后的价格是%d元\n", (*pbook1).price);*/

	return 0;
}