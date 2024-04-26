//
// Created by footr on 26/04/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular.h"

pno insere(pno p, char* nome){
    pno novo = malloc(sizeof(circ));
    strcpy(novo->nome, nome);

    if(p == NULL){
        novo->prox = novo;
        p = novo;
    }
    else {
        pno aux = p;
        while(aux->prox != p){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = p;
    }
    printf("\n");
    return p;
}

pno sentaPrimeiro(char* nome){
    pno novo = malloc(sizeof(circ));
    strcpy(novo->nome, nome);
    novo->prox = novo;
    printf("O %s sentou-se na mesa\n\n", novo->nome);
    return novo;
}

void mostra(pno p){
    pno aux = p;
    int i = 0;
    do {
        printf("- %s\n", aux->nome);
        i++;
        aux = aux->prox;
    } while(aux != p);
    printf("Nesta mesa estao presente %d pessoas, como escrito em cima\n\n",i);
}

int nlugares(pno prim, pno seg){
    int i=0;
    while(prim->prox != seg){
        prim = prim->prox;
        i++;
    }
    printf("\n");
    return i;
}

pno sentaAoLado(pno p, char* prim, char* seg){
    pno aux=p;
    do{
        if(strcmp(aux->nome, seg) == 0)
            break;
        aux = aux->prox;
    }while(aux != p);

    if(aux == p && strcmp(aux->nome, seg) != 0){
        printf("O %s nao esta sentado na mesa\n", seg);
        return p;
    }
    pno novo = malloc(sizeof(circ));
    strcpy(novo->nome, prim);

    novo->prox = aux->prox;
    aux->prox = novo;

    printf("O %s sentou-se ao lado do %s\n\n",novo->nome,aux->nome);
    return p;
}

pno mudaLugar(pno p, char* nome, int num){
    if(p == NULL){
        printf("Nao ha ninguem sentado na mesa\n");
        return p;
    }
    pno aux = p;
    do{
        if(strcmp(aux->nome, nome) == 0)
            break;
        aux = aux->prox;
    }while(aux != p);

    if(aux == p && strcmp(aux->nome, nome) != 0){
        printf("O %s nao esta sentado na mesa\n", nome);
        return p;
    }

    pno temp;
    for(int i = 0; i < num; i++){
        temp = aux->prox;
        char tempNome[100];

        strcpy(tempNome, aux->nome);
        strcpy(aux->nome, temp->nome);
        strcpy(temp->nome, tempNome);

        aux = temp;
    }
    printf("\n");
    return p;
}
