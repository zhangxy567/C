#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

void cleanup() {
    printf("Performing cleanup before exit...\n");
}

int main() {
    int value;

    // Register cleanup function
    atexit(cleanup);

    printf("Enter a positive integer: ");
    scanf("%d", &value);

    if (value <= 0) {
        fprintf(stderr, "Invalid input. Exiting with error code 1.\n");
        exit(1);
    }

    printf("You entered: %d\n", value);

    // Normal termination
    exit(0);
}