#include <stdio.h>
#include <string.h>
#define TAM 100

void eliminaEspacosSuperfluos(char str[]){
    int tam = strlen(str);
    int j = 0;
    int verificaEspaco = 0;

    for(int i=0; i<tam; i++){
        if(str[i]!=' '){
            str[j++]=str[i]; //copia caracteres que nao sao espaços
            verificaEspaco = 0;
        }
        else{
            if(!verificaEspaco)
                str[j++]=str[i]; //primeiro espaco contara como um caracter qualquer, espaços posteriores serao contados como espaços e portanto nao serao copiados

            verificaEspaco = 1;
        }
    }
    str[j]='\0';
}

int main(){
    char str[TAM];
    printf("Conteudo da frase a testar:");
    gets(str);

    eliminaEspacosSuperfluos(str);
    printf("Resultado: %s\n", str);
    return 0;
}
