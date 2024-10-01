#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char char_to_upper (char c){
    return c - 32;
}

char char_to_lower (char c){
    return c + 32;
}

int main(int argc, char const *argv[]){
    printf("%d\n", 'a');
    printf("%d\n", 'A');
    printf("%d\n", 'a' - 'A');
    printf("%d\n", 'g' - 'G');

    printf(char_to_lower('h'));
    printf(char_to_upper('w'));

    char c;
    scanf("%c", c);

    if(c >= 'a' && c <= 'z'){
        printf("%c", c);
    }

}