#include <stdio.h>
#include <string.h>
#define TAM 100

void mudaLinha(char str[]){
    int tam = strlen(str);
    for(int i=0; i<tam; i++){
        if(str[i] == ' ')
            str[i]='\n';
        printf("%c",str[i]);
    }
}

int main(){
    char str[TAM];
    printf("Introduza a frase a testar:");
    gets(str);
    mudaLinha(str);
    return 0;
}