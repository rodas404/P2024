#include <stdio.h>
#include <string.h>
#define TAM 100

int contaPalavras(char str[]){
    int tam = strlen(str);
    int palavras = 0;

    for(int i=0; i<tam; i++){
        if((i==0 || str[i-1]==' ') && str[i]!=' ')
            palavras++;
    }
    return palavras;
}

int main(){
    char str[TAM];
    printf("Frase a testar:");
    gets(str);
    printf("Numero de palavras da frase em questao: %d\n", contaPalavras(str));
    return 0;
}