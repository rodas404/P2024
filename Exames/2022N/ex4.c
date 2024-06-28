#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct dados no, *pno;
struct dados{
    int a[TAM];
    pno prox;
};

void printRec(pno p, int x){
    if(p == NULL || x >= TAM)
        return;
    else{
        printf("%d\t", p->a[x]);
        printRec(p->prox, x+1);
        printf("%d\t", p->a[x]);
    }
}

pno criaLista(){
    pno no1 = malloc(sizeof(no));
    pno no2 = malloc(sizeof(no));
    pno no3 = malloc(sizeof(no));
    pno no4 = malloc(sizeof(no));

    if (no1 == NULL || no2 == NULL || no3 == NULL || no4 == NULL) {
        printf("erro\n");
        return NULL;
    }
    int tab1[3]= {1,2,3};
    int tab2[3]= {11,12,13};
    int tab3[3]= {21,22,23};
    int tab4[3]= {31,32,33};

    for(int i = 0; i < TAM; i++){
        no1->a[i] = tab1[i];
        no2->a[i] = tab2[i];
        no3->a[i] = tab3[i];
        no4->a[i] = tab4[i];
    }

    no1->prox = no2;
    no2->prox = no3;
    no3->prox = no4;
    no4->prox = NULL;

    return no1;
}
int main(){
    pno lista = criaLista();
    printRec(lista, 0);
    //1       12      23      23      12      1

    while (lista != NULL) {
        pno temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}