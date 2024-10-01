#include <stdio.h>
#include <stdlib.h>

void popular(int** mat, int num_linhas, int num_colunas){
    for (int i = 0; i < num_linhas; i++){
        for (int j = 0; j < num_colunas; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void print(int **mat, int num_linhas, int num_colunas){
    for (int i = 0; i < num_linhas; i++){
        for (int j = 0; j < num_colunas; j++){
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[]){
    int num_linhas = 2;
    int num_colunas = 2;
    int** mat;
    mat = (int**) malloc(sizeof(int*) * num_linhas);
    for (int i = 0; i < num_linhas; i++){
        mat[i] = (int*) malloc(sizeof(int) * num_colunas);
    }
    
    popular(mat,num_linhas,num_colunas);
    print(mat,num_linhas,num_colunas);

    for (int i = 0; i < num_linhas; i++){
        free(mat[i]);
    }
    free(mat);

    return 0;
}
