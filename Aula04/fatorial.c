#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int n = atoi(argv[1]);
    int fat = 1;

    for (int i = 2; i <= n; i++){
        fat = fat * i;
    }
    printf("%d\n", fat);
    
    return 0;
}
