#include <stdio.h>

void unicos(int v[], int tam){
    int unico[tam];
    int i;
    int qtdUnicos = 0;

    for(i=0; i<tam; i++){
        int aparece = 0;
        for(int j=0; j<i; j++){
            if(v[i] == v[j]) {
                aparece = 1;
                break;
            }
        }
        for(int j=i+1; j<tam; j++){
            if(v[i] == v[j]) {
                aparece = 1;
                break;
            }
        }
        if(!aparece) {
            unico[qtdUnicos] = v[i];
            qtdUnicos++;
        }
    }

    printf("Tabela de valores unicos:\n");
    for(i=0; i<qtdUnicos; i++){
        printf("%d ", unico[i]);
    }
}

int main(){
    int dim;
    printf("Quantos numeros tera a tabela?");
    scanf("%d", &dim);

    int tab[dim];
    for(int i=0; i<dim; i++){
        printf("Insira o %d valor para a tabela:", i+1);
        scanf("%d", &tab[i]);
    }

    unicos(tab,dim);
    return 0;

}