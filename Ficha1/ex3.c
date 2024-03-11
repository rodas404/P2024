#include <stdio.h>

int maiorVezes(int tab[], int dim){
    int maior = tab[0];
    int vezes = 1;

    for(int i=0; i<dim; i++){
        if(maior < tab[i]) {
            maior = tab[i];
            vezes = 1;
        }
        else if(maior == tab[i])
            vezes++;
    }
    return vezes;
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

    printf("\nO maior valor inserido na tabela aparece %d vezes", maiorVezes(tab, dim));
    return 0;

}

