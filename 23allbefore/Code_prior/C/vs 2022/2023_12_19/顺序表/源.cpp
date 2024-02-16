#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define Size 5

typedef struct Table
{
	int* head;
	int length;
	int size;

}table;
int selectTable(table t, int elem);
table amendTable(table t, int elem, int newelem)
{
	int place=selectTable(t, elem);
	
	if (place > 0)
	{
		t.head[place - 1] = newelem;
	}
	else printf("���޸�Ԫ�ز�����");
	return t;


}
int selectTable(table t, int elem)
{
	for (int i = 0; i < t.length; i++)
	{
		if (t.head[i] == elem) return (i + 1);
		
	}
	return -1;
}
table delTable(table t, int place)
{
	if (place<1 || place>t.length)
	{
		printf("���λ������\n");
		return t;
	}
	for (int i = place; i < t.length;i++)
	{
		t.head[i - 1] = t.head[i];
	}
	t.length--;
	return t;
}
table addTable(table t,int elem,int place)
{
	if (place<1 || place>t.length + 1)
	{
		printf("����λ��������\n" );
		return t;
	}
	if (t.length == t.size)
	{
		  t.head = (int*)realloc(t.head, (t.size + 1) * sizeof(int));
		  if(!t.head)
		  {
			  printf("���·����ڴ�ʧ��\n");
			  exit(0);
			  return t;

		  }
		  t.size += 1;
	}
	for (int i = t.length - 1; i >= place - 1; i--)
	{
		t.head[i + 1] = t.head[i];
	}
	t.head[place - 1] = elem;
	t.length += 1;
	return t;
}
table initTable()
{
	table t;
	t.head = (int*)malloc(Size * sizeof(int));
	if(!t.head)
	{
		printf("��ʼ��ʧ��\n");
		exit(0);
	}
	t.length = 0;
	t.size = Size;
	return t;
}
void displayTable(table t)
{
	for (int i = 0; i < t.length; i++)
	{
		printf("t.head[%d]=%d	", i,t.head[i]);
	}
	printf("\n");
	printf("����%d\n", t.length);

}
int main()
{
	int elem, place, newelem;
	table t=initTable();
	for (int i = 1; i <= Size; i++)
	{
		t.head[i - 1] = i;
		t.length++;

	}
	printf(" ˳����д洢��Ԫ�طֱ���\n");
	displayTable(t);
	printf("������Ҫ��������ݺ�λ��\n");
	scanf("%d %d", &elem, &place);
		t=addTable(t, elem,place);
		displayTable(t);
		printf("������ɾ����λ��\n");
		scanf("%d", &place);
		t = delTable(t, place);
		displayTable(t);
		printf("˳���ĳ���%d\n", t.length);
		printf("������Ҫ���ҵ�Ԫ��\n");
		scanf("%d", &elem);
		place = selectTable(t, elem);
		if (place > 0)
		{
			printf("Ҫ���ҵ�Ԫ��λ����%d\n", place);
		}
		else printf("������Ԫ�ز�����\n");
		printf("������Ҫ���ĵ�Ԫ�غ�Ŀ��Ԫ��ֵ\n");
		scanf("%d %d", &elem, &newelem);
		t=amendTable(t, elem, newelem);
		displayTable(t);


	
	return 0;
}