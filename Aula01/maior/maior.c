#include <stdio.h>

int maior_dois_numeros(int x, int y){
    if (x > y){
        return x;
    }
    return y;
}

int maior_tres_numeros(int x, int y, int z){
    if (x > y && x> z){
        return x;
    } else if (y > z){
        return y;
    }
    return z;
}

int ordenar_tres_numeros(int x, int y, int z){
    
}

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 5;
    int c = 20;
    int res =  maior_dois_numeros(10,5);
    printf("%d\n", res);

    return 0;
}
