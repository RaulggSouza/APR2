#include <stdio.h>

//Vetor VLA -> Variable Length Array

int main(int argc, char const *argv[])
{
    int n = 0;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];
    
    for(int i = 0; i < n; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}
