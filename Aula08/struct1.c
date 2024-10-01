#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char titulo[128];
    char genero[32];
    int anoDeLancamento;
} T_FILME;

int atualiza_ano(T_FILME* filme, int novoAno){
    printf("DENTRO DA FUNCAO: %p\n",&filme);
    //(*filme).anoDeLancamento = novoAno;
    filme->anoDeLancamento = novoAno;
}

int imprime_filme(T_FILME* filme){
    printf("Titulo: %s\n", filme->titulo);
    printf("Genero: %s\n", filme->genero);
    printf("Ano Lancamento: %d\n", filme->anoDeLancamento);
}

T_FILME* criar_filme(char* titulo, char* genero, int ano){
    T_FILME* filme;
    filme = malloc(sizeof(T_FILME));
    strcpy(filme->titulo, titulo);
    strcpy(filme->genero, genero);
    filme->anoDeLancamento, ano;
    return filme;
}

int main(int argc, char const *argv[]){
    //T_FILME filme1;
    T_FILME* filme1;

    filme1 = criar_filme("titanic", "drama", 1997);

    imprime_filme(filme1);

    printf("%p\n",&filme1);

    atualiza_ano(filme1, 2001);

    imprime_filme(filme1);

    free(filme1);

    T_FILME* catalogo;

    catalogo = (T_FILME *) malloc(sizeof(T_FILME)*100);

    return 0;
}