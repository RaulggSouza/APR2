#include <stdio.h>

void troca(int* x, int* y){
    int aux;
    aux = *x;
    *x = *y; // Tem o ponteiro e quer o conteúdo, coloca o * antes da variável
    *y = aux;
}

int main(int argc, char const *argv[]){
    int a = 10;
    int b = 5;
    int c = 20;

    if(a > b && a > c){
        troca(&a, &c); // Tem o conteúdo e quer o ponteiro, coloca o & antes da variável
    } else if (b > c){
        troca(&b, &c);
    }
    if (a > b){
        troca(&a, &b);
    }

    printf("%d %d %d\n", a,b,c);

    return 1;
}
