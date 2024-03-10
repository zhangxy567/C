#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <windows.h>


#include <iostream>
using namespace std;
#include "head1.h"
int main()
{
	int a = 30;
	int b = 30;
	int c = Add(a, b);
	printf("%d", c);
	return 0;
}