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
            printf("Erro valor repetido\n\n");
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
        novo->prox = aux->prox;
        if(aux->prox != NULL){
            aux->prox->prev = novo;
        }
        aux->prox = novo;
        novo->prev = aux;
    }
    printf("\n");
    return p;
}

void mostra(pno p){
    while(p != NULL){
        printf("- %d\n", p->val);
        p = p->prox;
    }
    printf("\n");
}

void mostraInverso(pno p){
    while(p->prox != NULL)
        p = p->prox;

    while(p != NULL){
        printf("- %d\n", p->val);
        p = p->prev;
    }
    printf("\n");
}

pno elimina(pno p, int val){
    pno aux = NULL, atual = p;
    while(atual != NULL && atual->val != val){
        aux = atual;
        atual = atual->prox;
    }

    if(atual != NULL){
        if(aux == NULL){
            p = atual->prox;
        }
        else{
            aux->prox = atual->prox;
        }
        if(atual->prox != NULL){
            atual->prox->prev = aux;
        }
        printf("Valor %d eliminado da lista\n\n", atual->val);
        free(atual);
    }
    else
        printf("Nao encontrei o valor %d na lista\n\n", val);

    printf("\n");
    return p;
}

void media(pno p){
    int soma;
    float media;

    printf("Elementos iguais a media entre vizinhos:\n");
    while(p->prox != NULL){
        if(p->prev != NULL){
            soma = p->prev->val + p->prox->val;
            media = (float)soma/2;
            if(media == (float)p->val)
                printf("- %d\n", p->val);
        }
        p = p->prox;
    }
    printf("\n");
}