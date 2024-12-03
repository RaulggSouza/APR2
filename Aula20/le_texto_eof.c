#include <stdio.h>

int main(int argc, char const *argv[]){
    FILE *fd;
    fd = fopen("musica.txt", "r");
    char linha[128];
    // while (fgets(linha, 128, fd) != NULL){
    //     printf("%s", linha);
    // }

    char c;
    int counter = 0;
    while ((c = fgetc(fd)) != EOF){
        counter++;
        if (c >= 'a' && c <= 'z'){
            c = c - ('a' - 'A');
        }
        printf("%c", c);
    }
    printf("%d", counter);
    fclose(fd);
    
    return 0;
}
