#include <stdio.h>

void meteZeros(int *tab, int tam){
    int i;
    float media, soma=0;
    for(i=0; i<tam; i++){
        soma += tab[i];
    }

    media = soma/tam;
    printf("\nmedia = %.2f\n", media);

    for(i=0; i<tam; i++){
        if(tab[i]<media)
            tab[i]=0;
    }
}

int main(){
    int tam;
    printf("Tamanho da tabela:");
    scanf("%d", &tam);

    int tab[tam], i;
    for(i=0; i<tam; i++){
        printf("Valor %d da tabela:", i);
        scanf("%d",&tab[i]);
    }

    meteZeros(tab, tam);
    printf("\nTabela apos alteracoes:\n");
    for(i=0; i<tam; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
    return 0;
}
