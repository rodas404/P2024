#include <stdio.h>

int vetoresIguais(int *tab1, int tam1, int *tab2, int tam2){
    if(tam1!=tam2)
        return 0;
    for(int i=0; i<tam1; i++){
        if(tab1[i] != tab2[i])
            return 0;
    }
    return 1;
}

int main(){
    int tam1, tam2;
    printf("Tamanho da tabela 1:");
    scanf("%d", &tam1);
    printf("Tamanho da tabela 2:");
    scanf("%d", &tam2);
    printf("\n");

    int tab1[tam1], tab2[tam2], i;
    for(i=0; i<tam1; i++){
        printf("Valor %d da tabela 1:", i);
        scanf("%d",&tab1[i]);
    }
    printf("\n");
    for(i=0; i<tam2; i++){
        printf("Valor %d da tabela 2:", i);
        scanf("%d",&tab2[i]);
    }

    printf("\nResultado: %d\n", vetoresIguais(tab1,tam1,tab2,tam2));
    return 0;
}
