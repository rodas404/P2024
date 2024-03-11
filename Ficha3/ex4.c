#include <stdio.h>

void conta(int *t, int tam, int *np, int *ni, int *maior, int *pos){
    for(int i=0; i<tam; i++){
        if(t[i] % 2 == 1)
            (*ni)++;
        else
            (*np)++;

        if(t[i] > (*maior)) {
            (*maior) = t[i];
            (*pos) = i;
        }
    }
}

int main(){
    int tam;
    printf("Tamanho da tabela:");
    scanf("%d", &tam);

    int tab[tam];
    for(int i=0; i<tam; i++){
        printf("Valor %d da tabela:", i);
        scanf("%d",&tab[i]);
    }

    int np=0, ni=0, maior, pos;
    conta(tab, tam, &np, &ni, &maior, &pos);
    printf("\nNumeros pares: %d; Numeros impares: %d; Maior: %d; Posicao: %d;\n", np, ni, maior, pos);
    return 0;
}