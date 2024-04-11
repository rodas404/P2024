//
// Created by footr on 11/04/2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct local no, *pno;
struct local{
    char nome[50];
    pno prox;
};

//adiciona no inicio da lista
pno addNo_1(pno lista, char *st){
    pno novo;
    novo = malloc(sizeof(no));
    if(novo == NULL) return lista;
    strcpy(novo->nome, st);
    novo->prox = lista;
    return novo;
}

//adiciona no fim da lista
pno addNo_2(pno lista, char *st){
    pno novo, aux=lista;

    novo = malloc(sizeof(no));
    if(novo == NULL) return lista;
    strcpy(novo->nome, st);
    novo->prox = NULL;
    if(lista == NULL)
        lista = novo;
    else{
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return lista;
}

//adiciona na segunda posicao da lista
pno addNo_3(pno lista, char *st){
    pno novo;

    novo = malloc(sizeof(no));
    if(novo == NULL) return lista;
    strcpy(novo->nome, st);
    if(lista == NULL) {
        novo->prox = lista;
        lista = novo;
    }
    else {
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    return lista;
}

void mostraLista(pno lista){
    int i = 1;
    while(lista != NULL){
        printf("%d- %s\n",i, lista->nome);
        i++;
        lista = lista->prox;
    }
}
void freeLista(pno lista){
    pno temp;
    while(lista != NULL){
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}
int main() {
    pno lista = NULL;

    lista = addNo_3(lista, "AAA");
    lista = addNo_1(lista, "BBB");
    lista = addNo_1(lista, "CCC");
    lista = addNo_2(lista, "DDD");
    lista = addNo_3(lista, "EEE");

    mostraLista(lista);
    freeLista(lista);
    return 0;

}