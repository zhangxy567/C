#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAXSIZE 12500
#define MAXRC 100
#define ElemType int
typedef struct
{
    int i, j;//行，列
    ElemType e;//元素值
}Triple;

typedef struct
{
    Triple  data[MAXSIZE + 1];
    int rpos[MAXRC + 1];//每行第一个非零元素在data数组中的位置
    int mu, nu, tu;//行数，列数，元素个数
}RLSMatrix;
//矩阵的输出函数





void display(RLSMatrix M) {
    for (int i = 1; i <= M.mu; i++) //行循环
    {
        for (int j = 1; j <= M.nu; j++)//列循环
        {
            int value = 0;//用于判断输出0还是非零数据
            if (i + 1 <= M.mu) //除去最后一行
            {
                for (int k = M.rpos[i]; k < M.rpos[i + 1]; k++) //rpos使用来用来修饰一维线性数组data的
                {
                    if (i == M.data[k].i && j == M.data[k].j)
                    {
                        printf("%d ", M.data[k].e);
                        value = 1;
                        break;
                    }
                }
                if (value == 0) 
                {
                    printf("0 ");
                }
            }
            else //最后一行
            {
                for (int k = M.rpos[i]; k <= M.tu; k++) 
                {
                    if (i == M.data[k].i && j == M.data[k].j) 
                    {
                        printf("%d ", M.data[k].e);
                        value = 1;
                        break;
                    }

                }
                if (value == 0) {
                    printf("0 ");
                }
            }

        }
        printf("\n");
    }
}





int main(int argc, char* argv[])
{
    RLSMatrix M;

    M.tu = 4;
    M.mu = 3;
    M.nu = 4;

    M.rpos[1] = 1;
    M.rpos[2] = 3;
    M.rpos[3] = 4;

    M.data[1].e = 3;
    M.data[1].i = 1;
    M.data[1].j = 2;

    M.data[2].e = 5;
    M.data[2].i = 1;
    M.data[2].j = 4;

    M.data[3].e = 1;
    M.data[3].i = 2;
    M.data[3].j = 3;

    M.data[4].e = 2;
    M.data[4].i = 3;
    M.data[4].j = 1;
    //输出矩阵
    display(M);
    return 0;
}