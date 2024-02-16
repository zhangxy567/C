#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int n);

int main(int argc, char *argv[]){
    int i, n, result;
    if(argc <= 1){
        printf("Error: no input integer!\n");
        exit(EXIT_SUCCESS);
    }
    for(i=1; i<argc; i++){
        n = atoi(argv[i]);
        result = isPrime(n);
        if(result < 0){
            printf("%3d is error.\n", n);
        }else if(result){
            printf("%3d is prime number.\n", n);
        }else{
            printf("%3d is not prime number.\n", n);
        }
    }
    return 0;
}

//判断是否是素数
int isPrime(int n){
    int i, j;
    if(n <= 1){  //参数错误
        return -1;
    }else if(n == 2){  //2是特例，单独处理
        return 1;
    }else if(n % 2 == 0){  //偶数不是素数
        return 0;
    }else{  //判断一个奇数是否是素数
        j = (int)sqrt(n);
        for(i=3; i<=j; i+=2){
            if (n % i == 0){
                return 0;
            }
        }
        return 1;
    }
}