#include <stdio.h>

void procuraDupla(int *tab, int tam, int *prim, int *seg){
    for(int i=0; i<tam; i++){
        if(tab[i] > (*prim)) {
            (*seg) = (*prim);
            (*prim) = tab[i];
        }
        else if(tab[i] > *seg && tab[i] != *prim )
            (*seg) = tab[i];
    }
}

int main(){
    int tam;
    printf("Tamanho da tabela:");
    scanf("%d", &tam);

    int tab[tam];
    for(int i=0; i<tam; i++){
        printf("Valor %d da tabela:", i);
        scanf("%d",&tab[i]);
    }

    int prim, seg;
    procuraDupla(tab, tam, &prim, &seg);
    printf("\nMaior: %d; Segundo Maior: %d;\n", prim, seg);
    return 0;
}
