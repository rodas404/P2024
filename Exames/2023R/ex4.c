//
// Created by footr on 28/06/2024.
//
#include <stdio.h>
#include <stdlib.h>

#define TAM 4
typedef struct dados no, *pno;
struct dados{
    int tab[TAM];
    pno prox;
};

void printRec(pno p, int x){
    if(p == NULL || x < 0 || x >= TAM)
        return;
    else{
        printRec(p->prox, x+p->tab[x]);
        printf("%d\t",(p->tab[x]));
    }
}

pno criaLista(){
    pno no1 = malloc(sizeof(no));
    pno no2 = malloc(sizeof(no));
    pno no3 = malloc(sizeof(no));

    if (no1 == NULL || no2 == NULL || no3 == NULL) {
        printf("erro\n");
        return NULL;
    }
    int tab1[4]= {4,0,1,3};
    int tab2[4]= {-1,-4,-2,-3};
    int tab3[4]= {9,10,11,12};

    for(int i = 0; i < TAM; i++){
        no1->tab[i] = tab1[i];
        no2->tab[i] = tab2[i];
        no3->tab[i] = tab3[i];
    }

    no1->prox = no2;
    no2->prox = no3;
    no3->prox = NULL;

    return no1;
}
int main(){
    pno lista = criaLista();
    printRec(lista, 1);
    //-4    0

    while (lista != NULL) {
        pno temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}