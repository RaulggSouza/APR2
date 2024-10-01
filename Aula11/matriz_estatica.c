#include <stdio.h>
#include <stdlib.h>

#define NUM_LINHAS 2
#define NUM_COLUNAS 2

void print(int mat[][NUM_COLUNAS]){
    /*
    matriz[i][j] <-> (i * NUM_CLONUAS) + j
    Exige que passe a coluna pois usa um calculo (i*c+j) onde i = linha procurada, c = numero de colunas e j = coluna procurada
    */
    for (int i = 0; i < NUM_LINHAS; i++){
        for (int j = 0; j < NUM_COLUNAS; j++){
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[]){
    int vet1[10];
    int matriz[NUM_LINHAS][NUM_COLUNAS]; // 3 linhas e 4 colunas
    int* vet2;

    for (int i = 0; i < NUM_LINHAS; i++){
        for (int j = 0; j < NUM_COLUNAS; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    print(matriz);
    

    vet2 = (int*) malloc(sizeof(int)*10); //malloc retorna um ponteiro void, o cast serve para retornar um ponteiro int, porém o C já faz isso automaticamente
    return 0;
}
