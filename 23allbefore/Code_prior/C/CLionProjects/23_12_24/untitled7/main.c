#include <stdio.h>
#include <string.h>

int main()
{



    typedef char ARRAY20[20];
    typedef struct stu STU;
    typedef  int ARRAY34[3][4];
    ARRAY34 a={1,2,3,4,5,6,7,8,9,10,11,12};
    typedef int (*p)[4];
    p b=a;
    printf("%d,%d",*(*(b+1)+3),*(*(b+2)+0));

}
