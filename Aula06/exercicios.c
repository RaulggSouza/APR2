#include <stdio.h>
#include <stdlib.h>

//retorna o tamanho da string
int my_strlen(char str[]){
    int len = 0;
    while (str[len] != '\0'){
        len++;
    }
    return len;
}

//imprime string
int my_printf_str(char str[]){
    // int i;
    for (int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
    }
    printf("\n");
}

//retorna quantidade de letras minusculas
int count_lower_char(char str[]) {
    int number_of_lowers = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            number_of_lowers++;
        }
    }
    return number_of_lowers;
}

// retorna o indice do caractere c
int index_of_str(char str[], char c) {
    for (int i = 0; str[i] != '\0'; i++){
        if(str[i] == c){
            return i;
        }
    }
}

// insere caractere c no indice i
//   sem apagar o caractere existente
int insert_at_index_str(char str[], char c, int i) {
    int len = my_strlen(str);
    for (int j = len; j > 0; j--){
        str[j+1] = str[j];
        if(j == i){
            str[i] = c;
            break;
        }
    }
}

// remove o caractere do indice i
//   deve retornar o caractere removido
int remove_at_index_str(char str[], int i) {
    int comecarTroca = 0;
    for (int j = 0; str[j] != '\0'; j++){
        if (j == i){
            comecarTroca = 1;
        }
        if (comecarTroca == 1){
            str[j] = str[j+1];
        }
    }
}


int main(int argc, char const *argv[]){
    char palavra[] = "ifsp IFSP";
    // printf("%d\n", my_strlen(palavra));
    
    // my_printf_str(palavra);
    // printf("%d\n", count_lower_char(palavra));

    // printf("%d\n", index_of_str(palavra, 'p'));

    insert_at_index_str(palavra,'k',2);
    printf("%s\n", palavra);
    remove_at_index_str(palavra,2);
    printf("%s\n", palavra);


    return 1;
}