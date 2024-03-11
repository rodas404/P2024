#include <stdio.h>

void calculaSoma(int tab[], int dim, int valor){
    printf("\nCombinacoes possiveis:\n");
    for (int i = 0; i < dim - 2; i++) {
        for (int j = i + 1; j < dim - 1; j++) {
            for (int k = j + 1; k < dim; k++) {
                if (tab[i] + tab[j] + tab[k] == valor) {
                    printf("\t%d %d %d\n", tab[i], tab[j], tab[k]);
                }
            }
        }
    }
}

int main(){
    int dim;
    do {
        printf("Quantos numeros tera a tabela (maior que 3)?");
        scanf("%d", &dim);
    }while(dim<3);

    int tab[dim];
    for(int i=0; i<dim; i++){
        printf("Insira o %d valor para a tabela:", i+1);
        scanf("%d", &tab[i]);
    }
    int valor;
    printf("Qual o valor da soma que queres obter?");
    scanf("%d", &valor);

    calculaSoma(tab,dim,valor);
    return 0;

}