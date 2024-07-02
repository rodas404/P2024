//
// Created by footr on 27/06/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct sala{
    char id[10];
    int total;
};
typedef struct pessoa no, *pno;
struct pessoa{
    char nome[100], num[20]; // Nome e número do aluno
    struct sala* p; // Ptr. para a sala onde o aluno fará o teste
    pno prox;
};

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

void mostraMaxSala(pno p, struct sala* s, int tam){
    int max = 0, i, empate;
    struct sala* maxSala;
    for(i=0; i<tam; i++){
        if(max < s[i].total){
            max = s[i].total;
            maxSala = &s[i];
            empate = 0;
        }
        else if(max == s[i].total)
            empate = 1;
    }
    if(empate)
        return;
    
    printf("%d alunos farao prova na Sala %s, entre os quais:\n", max, maxSala->id);
    while(p != NULL){
        if(p->p == maxSala){
            printf(" - %s %s\n", p->nome, p->num);
        }
        p = p->prox;
    }
    printf("\n");
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
    printf("Adicionei '%s' a sala '%s'\n", novo->nome, novo->p->id);
    return lista;
}

int main(){
    int tot = 0;
    struct sala *s = criaSalas(&tot);
    pno lista = criaAlunos(s);
    mostraMaxSala(lista, s, tot);
    lista = adicionaAl(lista, s, tot, "maninho", "1234");

    while(lista != NULL) {
        pno temp = lista;
        lista = lista->prox;
        free(temp);
    }
    free(s);

    return 0;
}