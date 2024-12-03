#include <stdio.h>
#include <stdlib.h>

long fib_rec(int n){
    if (n == 1 || n == 2){
        return 1;
    }
    return fib_rec(n-2) + fib_rec(n-1);
}

long fib_pd(int n, long cache[]){
    if (cache[n] == -1){
        if (n == 1 || n == 2){
            cache[n] = 1;
        }
        cache[n] = fib_pd(n-2, cache) + fib_pd(n-1, cache);   
    }
    return cache[n];
}

int main(int argc, char const *argv[]){
    int n = atoi(argv[1]);

    long* cache = malloc(sizeof(long) * (n+1));
    for (long i = 0; i < n + 1; i++){
        cache[i] = -1;
    }
    long r = fib_pd(n, cache);

    printf("%ld\n", r);
    return 0;
}
