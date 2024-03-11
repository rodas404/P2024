#include <stdio.h>
#include <string.h>

void traduz(char *tabela[][2],char mes[10], int n_linha){
    int encontrado = 0;
    for(int i=0; i<n_linha; i++){
        if(stricmp(tabela[i][0],mes) == 0){
            printf("%s",tabela[i][1]);
            encontrado = 1;
            break;
        }

    }
    if(!encontrado){
        printf("a cona da tua prima");
    }
}

int main(){
    char *tabela[4][2] = {{"janeiro","january"},{"fevereiro","february"},{"marco","march"},{"abril","april"}};
    char mes[10];
    printf("mes em tuga: ");
    gets(mes);
    traduz(tabela,mes,4);
    return 0;
}

