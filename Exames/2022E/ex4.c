#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 4
typedef struct dados no, *pno;
struct dados{
    char txt[TAM];
    pno prox;
};

void printRec(pno p, int x, int y){
    if(p == NULL ||  p->prox == NULL)
        return;
    else if(p->txt[x] != p->prox->txt[y]){
        printf("%c\t", p->txt[x]);
        printRec(p->prox, x+1, y-1);
    }
    else
        printRec(p->prox, x, y);
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
    strcpy(no1->txt, "ABC");
    strcpy(no2->txt, "BCA");
    strcpy(no3->txt, "CBA");
    strcpy(no4->txt, "BAC");

    no1->prox = no2;
    no2->prox = no3;
    no3->prox = no4;
    no4->prox = NULL;

    return no1;
}
int main(){
    pno lista = criaLista();
    printRec(lista, 0, TAM-2);
    //B       B
    return 0;
}