#include <stdio.h>

int maiorNumero(int tab[], int dim){
    int maior = tab[0];

    for(int i=0; i<dim; i++){
        if(maior < tab[i])
            maior = tab[i];
    }
    return maior;
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

    printf("\nO maior valor inserido na tabela e %d", maiorNumero(tab, dim));
    return 0;

}
