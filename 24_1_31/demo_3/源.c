#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//#include <iostream>
//using namespace std;



int main() 
{
    int charCount;
    printf("Hello, %nWorld!\n", &charCount);

    printf("Number of characters printed: %d\n", charCount);

    return 0;
}
