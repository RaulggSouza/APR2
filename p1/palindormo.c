#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char* str, int begin, int end){
    while (begin < end){
        if (str[begin] != str[end]){
            return 0;
        }
        begin++;
        end--;
    }
    return 1;
}

int count_palindromes(char* str){
    int begin = 0, end = 0;
    int count = 0;
    while (begin < strlen(str)){
        while (str[end] != ' ' && str[end] != '\0'){
            end++;
        }
        count += is_palindrome(str, begin, end-1);
        begin = end + 1;
        end = begin;
    }
    return count;
}

int main(int argc, char const *argv[]){
    char str[] = "aba cad a";
    printf("%d\n", count_palindromes(str));
    return 0;
}
