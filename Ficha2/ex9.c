#include <stdio.h>
#include <string.h>
#define TAM 100

void comparaStrings(char str1[], char str2[], char str3[]){

    int tam1 = strlen(str1);
    int i, j=0;
    for(i=0; i<tam1; i++){
        if(str1[i] != ' ' ) {
            str1[j++] = str1[i]; //o intuito é ir refazendo a str1 apenas com caracteres que nao sejam espaço
        }
    }
    str1[j] = '\0';
    tam1 = j;

    int tam2 = strlen(str2);
    j = 0;
    for(i=0; i<tam2; i++){
        if(str2[i] != ' ' ) {
            str2[j++] = str2[i];
        }
    }
    str2[j] = '\0';
    tam2 = j;

    if(strcmp(str1, str2) == 0){
        strcpy(str3, "Conteudo Igual!");
    }
    else if(tam1 == tam2){
        strcpy(str3, "Tamanho Igual!");
    }
    else{
        if(strcmp(str1, str2) < 0){
            strcat(str1, " ");
            strcat(str1, str2);
            strcpy(str3, str1);
        }
        else{
            strcat(str2, " ");
            strcat(str2, str1);
            strcpy(str3, str2);
        }
    }
}

int main(){
    char str1[TAM], str2[TAM], str3[TAM];
    printf("Conteudo da string 1:");
    gets(str1);
    printf("Conteudo da string 2:");
    gets(str2);

    comparaStrings(str1, str2, str3);
    printf("Resultado: %s\n", str3);
    return 0;
}
