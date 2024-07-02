#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 4
typedef struct dados no, *pno;
struct dados{
char txt[TAM];
pno prox;
};

void printRec(pno p, int x){
    if(p == NULL ||  strlen(p->txt)<=x)
        return;
    else{
        printf("%s\t",(p->txt)+x);
        printf("%c\t", p->txt[x]);
        printRec(p->prox, x+1);
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
    strcpy(no1->txt, "ABC");
    strcpy(no2->txt, "DEF");
    strcpy(no3->txt, "GHI");
    strcpy(no4->txt, "XYZ");

    no1->prox = no2;
    no2->prox = no3;
    no3->prox = no4;
    no4->prox = NULL;

    return no1;
}

int main(){
    pno lista = criaLista();
    printRec(lista, 0);
    //ABC     A       EF      E       I       I
    return 0;
}