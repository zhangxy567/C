#include <stdio.h>
#include <string.h>

#define MAX(X,Y) (X>Y?X:Y)
int main() {

    int maxval=MAX(10,300);
    printf("%d",maxval);
}
