#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if (n == 1 || n == 2){
        return 1;
    }else{
        return fib(n-2) + fib(n-1);
    }
}

int main(int argc, char const *argv[]){
    int n = 5;
    printf("%d", fib(n));
}
