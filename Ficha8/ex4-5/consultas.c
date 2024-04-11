//
// Created by footr on 11/04/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consultas.h"

pno addPaciente(pno lista){
    pno novo, aux;
    int grau;
    novo = malloc(sizeof(pc));
    if(novo == NULL){
        printf("Erro na alocacao de memoria\n");
        return lista;
    }

    printf("Nome do Paciente:");
    scanf(" %[^\n]", novo->nome);
    do {
        printf("Grau de Urgencia:");
        scanf("%d", &grau);
        if(grau>3 || grau<=0)
            printf("Grau de Urgencia invalido\n");
    } while(grau>3 || grau<=0);
    novo->grau = grau;
    novo->prox = NULL;

    if(lista == NULL || novo->grau < lista->grau) {
        novo->prox = lista;
        lista = novo;
    }
    else{
        aux = lista;
        while(aux->prox != NULL && novo->grau >= aux->prox->grau)
            aux = aux->prox;
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    printf("\n");
    return lista;
}

pno atendePaciente(pno lista){
    pno atual;
    atual = lista;

    if(atual == NULL){
        printf("Sem pacientes por atender\n\n");
        return lista;
    }
    printf("%s chamado a rececao!\n\n", atual->nome);
    lista = atual->prox;

    free(atual);
    return lista;
}

pno removerPaciente(pno lista, char paciente[100]){
    pno atual, anterior = NULL;
    atual = lista;

    while(atual != NULL && strcmp(atual->nome, paciente) != 0){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL){
        printf("Paciente %s nao consta na lista\n", paciente);
        return lista;
    }
    if(anterior == NULL)
        lista = atual->prox;
    else
        anterior->prox = atual->prox;

    printf("Paciente %s removido da lista de espera com sucesso\n\n", atual->nome);
    free(atual);
    return lista;
}

void mostraLista(pno lista){
    int i = 1;
    printf("Temos na lista de espera:\n");
    while(lista != NULL){
        printf("%d - %s (%d)\n", i, lista->nome, lista->grau);
        i++;
        lista = lista->prox;
    }
    printf("\n");
}

void freeLista(pno lista){
    pno temp;
    while(lista != NULL){
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}