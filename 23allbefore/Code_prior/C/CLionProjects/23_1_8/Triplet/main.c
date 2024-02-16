#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define number 20
typedef struct
{
    int i,j;
    int data;
}triple;

typedef struct
{
    triple data[number];
    int n,m,num;
}TSMatrix;

void display(TSMatrix M);

int main()
{
    TSMatrix M;
    M.num=3;
    M.m=3;
    M.n=3;

    M.data[0].i=1;
    M.data[0].j=1;
    M.data[0].data=1;

    M.data[1].i=2;
    M.data[1].j=3;
    M.data[1].data=5;

    M.data[2].i=3;
    M.data[2].j=1;
    M.data[2].data=3;
    display(M);
    return 0;
}
void display(TSMatrix M)
{
    for(int i=1;i<=M.m;i++)
    {
        for(int j=1;j<=M.n;j++)
        {
            int value =0;
            for(int k=0;k<M.num;k++)
            {
                if(M.data[k].i==i&&M.data[k].j==j)
                {
                    printf("%d ",M. data[k].data);
                    value=1;
                    break;
                }
            }
            if (value==0)printf("0 ");
        }
        printf("\n");
    }
}