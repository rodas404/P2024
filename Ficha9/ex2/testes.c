//
// Created by footr on 18/04/2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "testes.h"

void mostraInfo(pno p, struct sala* s, int tam){
    for(int i=0; i<tam; i++){
        pno atual = p;
        printf("Alunos presente na Sala %s:\n", s[i].id);
        while(p != NULL){
            if(atual->p == &s[i]){
                printf(" - %s %s\n", atual->nome, atual->num);
            }
            atual = atual->prox;
        }
    }
}

void mostraMaxSala(pno p, struct sala* s, int tam){
    int max = 0, i;
    struct sala maxSala;
    for(i=0; i<tam; i++){
        if(max < s[i].total){
            max = s[i].total;
            maxSala = s[i];
        }
        else if(max == s[i].total && max != 0)
            return;
    }

    printf("%d alunos farao prova na Sala %s, entre os quais:\n", max, maxAlunos.id);
    while(p != NULL){
        if(p->p == &maxSala){
            printf(" - %s %s\n", p->nome, p->num);
        }
        p = p->prox;
    }
}

int mesmaSala(pno p, char* aluno1, char* aluno2){
    struct sala* salaAluno1 = NULL;
    struct sala* salaAluno2 = NULL;

    pno atual = p;
    while(atual != NULL){
        if(strcmp(atual->nome, aluno1) == 0){
            salaAluno1 = atual->p;
            break;
        }
        atual = atual->prox;
    }
    atual = p;
    while(atual != NULL){
        if(strcmp(atual->nome, aluno2) == 0){
            salaAluno2 = atual->p;
            break;
        }
        atual = atual->prox;
    }

    if(salaAluno1 == NULL || salaAluno2 == NULL)
        return -1;

    if(salaAluno1 == salaAluno2)
        return 1;
    else
        return 0;
}

struct sala* transfereAl(pno lista, struct sala *s, int *tot, char *nome, char *nSala){

}