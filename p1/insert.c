#include <stdio.h>
#include <stdlib.h>

int insert(int* vet, int max, int* size, int posElem,int elem){
    if(*size < max){
        for (int i = *size; i >= posElem; i--){
            vet[i+1] = vet[i];
        }
        vet[posElem] = elem;
        (*size)++;
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[]){
    int* vetor;
    int max = 3;
    int size = 0;
    vetor = malloc(sizeof(int)*max);
    if (insert(vetor, max, &size, 0, 10)){ //USANDO A FUNÇÃO INSERT
        printf("Inserido com sucesso\n");
    }else{
        printf("Falha ao inserir\n");
    }
    if (insert(vetor, max, &size, 1, 11)){
        printf("Inserido com sucesso\n");
    }else{
        printf("Falha ao inserir\n");
    }
    if (insert(vetor, max, &size, 1, 12)){
        printf("Inserido com sucesso\n");
    }else{
        printf("Falha ao inserir\n");
    }
    for(int i = 0; i < size; i++){
        printf("%d\n", vetor[i]);
    }
    return 0;
}