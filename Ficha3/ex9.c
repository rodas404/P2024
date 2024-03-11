#include <stdio.h>

void desloca(int *v, int tam, int shift){
    int j,i;
    int temp[shift];

    if(shift>=tam) {
        printf("Valor de deslocacao invalido\n");
        return;
    }
    for(i=tam-shift, j=0; i<tam; i++, j++){ //primeiro ciclo para armazenar os valores do fim do vetor, num vetor temporario
        temp[j]=v[i];
    }
    for(i=tam-1; i>=shift; i--){ //segundo ciclo para mover os elementos como planeado
        v[i] = v[i-shift];
    }
    for(i=0; i<shift; i++){ //terceiro ciclo para colocar no inicio do vetor os valores armazenados no vetor temporario
        v[i]=temp[i];
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

    int shift;
    printf("Quantas posicoes quer mover o vetor?");
    scanf("%d",&shift);

    desloca(tab,tam,shift);
    printf("Resultado:\n");
    for(i=0; i<tam; i++){
        printf("%d ", tab[i]);
    }

    return 0;
}
