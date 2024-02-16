#include <stdio.h>
#include <string.h>

int main() {
    int a[3][4]={{0,1,2,3},{4,5,6,7},{8,9,10,11}};
    int i,j ;
    int (*p)[4]=a;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d  ",*(*(p+i)+j));
        }
        printf("\n");
    }
    // printf("%d\n",sizeof(  *(p+1) ));
    // printf("%d\n",sizeof(  *(p+1)+1) );
    // printf("%d\n",sizeof(  *(*(p+1)+1) ) );
    // printf("%d\n",sizeof(  p[1][1]  ));
    // printf("%d\n",sizeof(  a ) );
    // printf("%d\n",*(*(p+1)+1));

    return 0;
}
