#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAXSIZE 1500

typedef struct {
	int i, j, e;  //三元组 
}Tripe;

typedef struct {
	Tripe data[MAXSIZE];
	int a, b, c;  //行，列和非零元个数 
}TSMatrix;

void transTSMatrix(TSMatrix T1, TSMatrix& T2)
{
	T2.a = T1.b;
	T2.b = T1.a;
	T2.c = T1.c;
	int q = 1;
	for (int col = 1; col <= T1.b; col++)
	{
		for (int p = 1; p <= T1.c; p++)
		{
			if (T1.data[p].j == col)
			{
				T2.data[q].i = T1.data[p].j;
				T2.data[q].j = T1.data[p].i;
				T2.data[q].e = T1.data[p].e;
				q++;
			}
		}
	}
}

void creatTSMatrix(TSMatrix& T1)
{
	printf("**************************\n");
	printf("请输入矩阵的行，列和非零个数:\n");
	scanf_s("%d%d%d", &T1.a, &T1.b, &T1.c);
	printf("请输入矩阵（三元组）：\n");
	for (int m = 1; m <= T1.c; m++)
	{
		cin >> T1.data[m].i >> T1.data[m].j >> T1.data[m].e;
	}
}

void printTSMatrix(TSMatrix& T)
{
	int q = 1;
	printf(":稀疏矩阵为：\n");
	for (int m = 1; m <= T.a; m++)
	{
		for (int n = 1; n <= T.b; n++)
		{
			if (T.data[q].i == m && T.data[q].j == n)
			{
				printf("%4d", T.data[q].e);
				q++;
			}
			else
				printf("%4d", 0);

		}
		printf("\n");
	}

}


void   fastTransposeSMatrix(TSMatrix M, TSMatrix& T)
{
	// 采用三元组顺序表存储表示，求稀疏矩阵M的转置矩阵T
	int col, t, p, q;
	int num[20], cpot[20];
	T.a = M.b;  T.b = M.a;  T.c = M.c;
	if (T.c) {
		for (col = 1; col <= M.b; ++col)	//对列数进行初始化
			num[col] = 0;
		for (t = 1; t <= M.c; ++t) // 求 M 中每一列所含非零元的个数
			++num[M.data[t].j];
		cpot[1] = 1;
		// 求 M 中每一列的第一个非零元在 b.data 中的序号
		for (col = 2; col <= M.b; ++col)
			cpot[col] = cpot[col - 1] + num[col - 1];
		for (p = 1; p <= M.c; ++p)
		{
			col = M.data[p].j;
			q = cpot[col];
			T.data[q].i = M.data[p].j;
			T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e;
			++cpot[col];
		}
	}
}
int main()
{
	TSMatrix T1, T2, T3;
	creatTSMatrix(T1);
	printTSMatrix(T1);
	printf("----------------------------------------------------\n");
	transTSMatrix(T1, T2);
	printf("转置矩阵(三元组)：\n");
	for (int n = 1; n <= T2.c; n++)
	{
		printf("%d %d %d\n", T2.data[n].i, T2.data[n].j, T2.data[n].e);
	}
	printTSMatrix(T2);
	printf("----------------------------------------------------\n");
	fastTransposeSMatrix(T1, T3);
	printf("快速转置矩阵(三元组)：\n");
	for (int n = 1; n <= T3.c; n++)
	{
		printf("%d %d %d\n", T3.data[n].i, T3.data[n].j, T3.data[n].e);
	}
	printTSMatrix(T3);
	return 0;
}