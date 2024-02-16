#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 12500
#define MARXRC 100
#define ElemType int
typedef struct
{
    int i,j;
    ElemType e;
}Triple;

typedef struct
{
    Triple data[MAXSIZE+1];
    int rpos[MARXRC+1];
    int mu,nu,tu;//行,列,总个数
}RLSMatrix;

void display(RLSMatrix M);
int main()
{
    RLSMatrix M;
    M.mu=3;
    M.nu=4;
    M.tu=4;

    M.rpos[1]=1;
    M.rpos[2]=3;
    M.rpos[3]=4;

    M.data[1].e=3;
    M.data[1].i=1;
    M.data[1].j=2;

    M.data[2].e = 5;
    M.data[2].i = 1;
    M.data[2].j = 4;

    M.data[3].e = 1;
    M.data[3].i = 2;
    M.data[3].j = 3;

    M.data[4].e = 2;
    M.data[4].i = 3;
    M.data[4].j = 1;
    display(M);
    return 0;
}
void display(RLSMatrix M)
{
    for(int i=1;i<=M.mu;i++)
    {
        for(int j=1;j<=M.nu;j++)
        {
            int value=0;
            if(i+1<=M.mu)
            {
                for(int k=M.rpos[i];k<M.rpos[i+1];k++)
                {
                    if(i==M.data[k].i&&j==M.data[k].j)
                    {
                        printf("%d ",M.data[k].e);
                        value=1;
                        break;
                    }
                }
                if(value==0)printf("0 ");
            }
            else
            {
                for (int k=M.rpos[i];k<=M.tu;k++)
                {
                    if(i==M.data[k].i&&j==M.data[k].j)
                    {
                        printf("%d ",M.data[k].e);
                        value=1;
                        break;
                    }
                }
                if(value==0)printf("0 ");
            }

        }
        printf("\n");
    }
}