#include <stdio.h>

int maiorPosicao(int tab[], int dim){
    int maior = tab[0];
    int pos = 0;

    for(int i=0; i<dim; i++){
        if(maior < tab[i]) {
            pos = i;
            maior = tab[i];
        }
    }
    return pos+1;
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

    printf("\nA posicao da tabela com o maior numero e %d", maiorPosicao(tab, dim));
    return 0;

}
