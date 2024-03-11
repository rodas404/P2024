#include <stdio.h>

int maisComum(int tab[], int dim) {
    int valorComum = tab[0];
    int maxComum = 1;

    for (int i = 0; i < dim; i++) {
        int comum = 1;
        for (int j = i + 1; j < dim; j++) {
            if (tab[i] == tab[j]) {
                comum++;
            }
        }
        if (comum > maxComum || (comum == maxComum && tab[i] > valorComum)) {
            maxComum = comum;
            valorComum = tab[i];
        }
    }

    return valorComum;
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

    printf("\nO valor mais comum na tabela e %d", maisComum(tab, dim));
    return 0;

}
