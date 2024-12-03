#include <stdio.h>

int main(int argc, char const *argv[]){
    char texto1[32];
    int ano_tri;
    char texto2[32];
    char num_rei;
    char texto3[32];
    int teste;
    FILE *fd;
    fd = fopen(argv[1], "r");

    fread(texto1, sizeof(char), 32, fd);
    fread(&ano_tri, sizeof(int), 1, fd);
    fread(texto2, sizeof(char), 32, fd);
    fread(&num_rei, sizeof(int), 1, fd);
    fread(texto3, sizeof(char), 32, fd);
    fread(&teste, sizeof(int), 1, fd);

    printf("%s - %d\n", texto1, ano_tri);
    printf("%s - %d\n", texto2, num_rei);
    printf("%s - %d\n", texto3, teste);

    fclose(fd);
    return 0;
}
