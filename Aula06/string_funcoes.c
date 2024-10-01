#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
    char s1[32] = "Instituto Federal";
    char s2[32] = " de Sao Carlos";
    char copia[32];

    int n = strlen(s1); // tamanho da String; 
    strcat(s1, s2); // concatena Strings
    printf("%s\n", s1);

    strcpy(copia, s1); // copia uma String (s1) para outra (copia)
    strcpy(s2, " de Sao Paulo"); // também serve para mudar o valor da String

    strupr(s1); //Upper case
    strlwr(s1); //Lower case

    //comparação de Strings -> strcmp
    char s4[32] = "abacate";
    char s5[32] = "banana";
    char s6[32] = "banana";

    printf("res de strcmp(%s, %s): %d\n", s4, s5, strcmp(s4, s5));
    printf("res de strcmp(%s, %s): %d\n", s5, s6, strcmp(s5, s6));
    printf("res de strcmp(%s, %s): %d\n", s6, s4, strcmp(s6, s4));

    return 1;
}