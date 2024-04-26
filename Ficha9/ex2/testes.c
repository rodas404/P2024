//
// Created by footr on 18/04/2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "testes.h"

struct sala* criaSalas(int *tot){
    int numSalas = 3;
    (*tot)=numSalas;
    struct sala* s = malloc(numSalas * sizeof(struct sala));
    if(s == NULL){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    strcpy(s[0].id, "S1");
    s[0].total = 0;

    strcpy(s[1].id, "S2");
    s[1].total = 0;

    strcpy(s[2].id, "S3");
    s[2].total = 0;

    return s;
}

pno criaAlunos(struct sala* s){
    pno lista = NULL;
    pno ultimo = NULL;
    struct pessoa alunos[] = {{"Ana Silva", "ASDF22", &s[2]}, {"Carlos Pinto", "GHY6", &s[0]}, {"Iris Silva", "XFGG1", &s[2]}, {"Paulo Vaz", "JKL4", &s[2]}, {"Rui Alves", "LLHO334", &s[0]}};
    int numAlunos = 5;

    for(int i = 0; i < numAlunos; i++){
        pno novo = malloc(sizeof(no));
        if(novo == NULL){
            printf("Erro ao alocar memória\n");
            return NULL;
        }

        strcpy(novo->nome, alunos[i].nome);
        strcpy(novo->num, alunos[i].num);
        novo->p = alunos[i].p;
        novo->p->total++;
        novo->prox = NULL;

        if(lista == NULL){
            lista = novo;
            ultimo = novo;
        } else {
            ultimo->prox = novo;
            ultimo = novo;
        }

    }

    return lista;
}
void mostraInfo(pno p, struct sala* s, int tam){
    for(int i=0; i<tam; i++){
        pno atual = p;
        if(s[i].total == 0)
            printf("Sala %s sem alunos presentes\n", s[i].id);
        else
            printf("Alunos presente na Sala %s:\n", s[i].id);
        while(atual != NULL){
            if(atual->p == &s[i]){
                printf(" - %s %s\n", atual->nome, atual->num);
            }
            atual = atual->prox;
        }
    }
    printf("\n");
}

void mostraMaxSala(pno p, struct sala* s, int tam){
    int max = 0, i;
    struct sala* maxSala;
    for(i=0; i<tam; i++){
        if(max < s[i].total){
            max = s[i].total;
            maxSala = &s[i];
        }
        else if(max == s[i].total && max != 0)
            return;
    }

    printf("%d alunos farao prova na Sala %s, entre os quais:\n", max, maxSala->id);
    while(p != NULL){
        if(p->p == maxSala){
            printf(" - %s %s\n", p->nome, p->num);
        }
        p = p->prox;
    }
    printf("\n");
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
    pno atual = lista;
    struct sala* salaAntiga = NULL;
    struct sala* transf = NULL;
    int i;

    while(atual != NULL && strcmp(atual->nome, nome) != 0)
        atual = atual->prox;

    if(atual == NULL) {
        printf("Nao encontrei o aluno\n");
        return s;
    }

    for(i=0; i<(*tot); i++){
        if(strcmp(s[i].id, nSala) == 0){
            s[i].total++;
            transf = &s[i];
            break;
        }
    }

    if(transf == NULL){
        printf("Sala nao encontrada\n");
        return s;
    }

    salaAntiga = atual->p;
    atual->p = transf;
    salaAntiga->total--;

    if(salaAntiga->total == 0){
        for(i=0; i<(*tot); i++){
            if(&s[i] == salaAntiga){
                break;
            }
        }
        printf("Sala %s removida\n", s[i].id);
        for(int j=i; j<(*tot)-1; j++){
            s[j] = s[j+1];
            pno temp = lista;
            while(temp != NULL){
                if(strcmp(s[j].id,temp->p->id)==0)
                    temp->p = &s[j]; //atualizar os ponteiros da lista de alunos para nao surgir erros
                temp = temp->prox;
            }
        }

        (*tot)--;
        s = realloc(s, (*tot)*sizeof(struct sala));
    }

    printf("\n");
    return s;
}

pno adicionaAl(pno lista, struct sala *s, int tot, char *nome, char *num){
    int minAlunos = s->total;
    struct sala* minSala;

    for(int i=0; i<tot; i++){
        if(s[i].total<=minAlunos){
            minAlunos = s[i].total;
            minSala = &s[i];
        }
    }

    pno novo, aux, ant;
    novo = malloc(sizeof(no));
    if(novo == NULL)
        return lista;

    strcpy(novo->nome, nome);
    strcpy(novo->num, num);
    novo->p = minSala;
    minSala->total++;
    novo->prox = NULL;

    if(lista == NULL)
        lista = novo;
    else{
        aux = lista;
        ant = NULL;
        while(aux != NULL && strcmp(aux->nome, nome) < 0) {
            ant = aux;
            aux = aux->prox;
        }
        if(ant == NULL){
            novo->prox = lista;
            lista = novo;
        }
        else{
            novo->prox = aux;
            ant->prox = novo;
        }
    }
    printf("\n");
    return lista;
}