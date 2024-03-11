#include <stdio.h>
#include <string.h>
#define TAM 100

void inverteFrase(char str[]){
    int tam = strlen(str);
    printf("\n");
    for(int i = tam-1; i>=0; i--){
        printf("%c",str[i]);
    }
}

int main(){
    char str[TAM];
    printf("Introduza a frase a inverter:");
    gets(str);
    inverteFrase(str);
    return 0;
}

