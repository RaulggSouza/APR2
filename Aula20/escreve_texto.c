#include <stdio.h>

int main(int argc, char const *argv[]){
    FILE *fd; //File Descriptor

    fd = fopen(argv[1], "w");
    if (fd == NULL){
        printf("Erro ao abrir arquivo");
        return 1;
    }
    fprintf(fd, "16 08 1914\n");
    fprintf(fd, "Ola, BES\n");
    fprintf(fd, "Ola, IFSP\n");

    fclose(fd);
    
    return 0;
}
