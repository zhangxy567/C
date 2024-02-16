#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char* a1=NULL;
    char* a2=NULL;
    a1=(char*) malloc(10*sizeof (char));
    strcpy(a1,"data.bian");
    a2=(char*) malloc(10*sizeof (char));
    strcpy(a2,"cheng.net");
    printf("%s\n",a1);
    printf("%s\n",a2);
    int lengthA1= strlen(a1);
    int lengthA2= strlen(a2);
    if(lengthA1+lengthA2>lengthA1)
    {
        a1=(char*) realloc(a1,(lengthA1+lengthA2+1)*sizeof (char));
        for(int i=lengthA1;i<lengthA1+lengthA2;i++)
        {
            a1[i]=a2[i-lengthA1];
        }
        a1[lengthA1+lengthA2]='\0';
        printf("%s\n",a1);
        free(a1);
        free(a2);
    }
    return 0;
}
