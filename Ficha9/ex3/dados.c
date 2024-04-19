//
// Created by footr on 19/04/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

pno insere(pno p, int val){
    pno aux = p;
    while(aux != NULL){
        if(aux->val == val){
            printf("Erro valor repetido\n");
            return aux;
        }
        aux = aux->prox;
    }

    pno novo = malloc(sizeof(no));
    novo->val = val;
    novo->prev = NULL;
    novo->prox = NULL;

    if(p == NULL)
        p = novo;
    else if(p->val > val){
        novo->prox = p;
        p->prev = novo;
        p = novo;
    }
    else{
        aux = p;
        while(aux->prox != NULL && aux->prox->val < val)
            aux = aux->prox;
        if(aux->prox != NULL)
            aux->prox->prev = novo;
        aux->prox = novo;
        novo->prev = aux;
    }
    return p;
}

void mostra(pno p){
    while(p != NULL){
        printf("- %d\n", p->val);
        p = p->prox;
    }
}