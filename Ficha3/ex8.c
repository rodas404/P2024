#include <stdio.h>

int comuns(int *tabA, int tamA, int *tabB, int tamB){
    int comum=0;

    for(int i=0; i<tamA; i++){
        for(int j=0; j<tamB; j++){
            if(tabA[i]==tabB[j])
                comum++;
        }
    }
    return comum;
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

    printf("\nNumero de elementos comuns: %d\n", comuns(tab1,tam1,tab2,tam2));
    return 0;
}
