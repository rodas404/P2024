//
// Created by footr on 27/06/2024.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sala no, *pno;
struct sala{
 char id[10];
 int total;
 pno prox;
};
typedef struct pessoa{
 char nome[100], num[20];
 pno p;
}aluno;


pno criaSalas(int *tot) {
    int numSalas = 3;
    (*tot) = numSalas;
    pno lista = NULL;
    pno ultimo = NULL;
    char ids[3][10] = {"S1", "S2", "S3"};

    for(int i = 0; i < numSalas; i++) {
        pno novo = malloc(sizeof(no));
        if(novo == NULL) {
            printf("Erro ao alocar memoria\n");
            return NULL;
        }
        strcpy(novo->id, ids[i]);
        novo->total = 0;
        novo->prox = NULL;

        if(lista == NULL) {
            lista = novo;
            ultimo = novo;
        } else {
            ultimo->prox = novo;
            ultimo = novo;
        }
    }

    return lista;
}


aluno* criaAlunos(pno s, int *numAlunos) {
    *numAlunos = 5;
    aluno* alunos = malloc((*numAlunos) * sizeof(aluno));
    if(alunos == NULL) {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    struct pessoa tempAlunos[] = {
            {"Ana Silva", "ASDF22", NULL},
            {"Carlos Pinto", "GHY6", NULL},
            {"Iris Silva", "XFGG1", NULL},
            {"Paulo Vaz", "JKL4", NULL},
            {"Rui Alves", "LLHO334", NULL}
    };

    for(int i = 0; i < *numAlunos; i++) {
        pno salaAtual = s;
        while(salaAtual != NULL) {
            if((i == 0 && strcmp(salaAtual->id, "S3") == 0) ||
               (i == 1 && strcmp(salaAtual->id, "S2") == 0) ||
               (i == 2 && strcmp(salaAtual->id, "S3") == 0) ||
               (i == 3 && strcmp(salaAtual->id, "S3") == 0) ||
               (i == 4 && strcmp(salaAtual->id, "S1") == 0)) {
                tempAlunos[i].p = salaAtual;
                salaAtual->total++;
                break;
            }
            salaAtual = salaAtual->prox;
        }
        strcpy(alunos[i].nome, tempAlunos[i].nome);
        strcpy(alunos[i].num, tempAlunos[i].num);
        alunos[i].p = tempAlunos[i].p;
    }

    return alunos;
}


int mesmaSala(pno p, char* aluno1, char* aluno2, aluno *a, int tam){
    pno salaAluno1 = NULL;
    pno salaAluno2 = NULL;

    for(int i=0; i<tam;i++){
        if(strcmp(a[i].nome,aluno1)==0)
            salaAluno1 = a[i].p;
        else if(strcmp(a[i].nome, aluno2)==0)
            salaAluno2 = a[i].p;
    }

    if(salaAluno1 == NULL || salaAluno2 == NULL)
        return -1;

    if(salaAluno1 == salaAluno2)
        return 1;
    else
        return 0;
}

pno transfereAl(aluno *v, int tot, pno p, char *nome, char *nSala){
    pno atual = p;
    pno salaAntiga = NULL;
    pno novaSala = NULL;
    int i;

    for(i=0; i<tot; i++){
        if(strcmp(v[i].nome, nome) == 0){
            salaAntiga = v[i].p;
            break;
        }
    }
    if(salaAntiga == NULL){
        printf("Nao encontrei o aluno a transferir\n");
        return p;
    }

    while(atual != NULL) {
        if(strcmp(atual->id, nSala) == 0){
            novaSala = atual;
            break;
        }
        atual = atual->prox;
    }
    if(novaSala == NULL){
        printf("nao encontrei a sala a transferir\n");
        return p;
    }
    novaSala->total++;
    v[i].p = novaSala;
    salaAntiga->total--;

    if(salaAntiga->total == 0){
        if(p == salaAntiga) {
            p = salaAntiga->prox;
        }
        else {
            atual = p;
            while(atual->prox != salaAntiga){
                atual = atual->prox;
            }
            atual->prox = salaAntiga->prox;
        }
        free(salaAntiga);
    }
    return p;
}
void mostraInfo(aluno *a, int tot, pno s){
    for(int i=0; i<tot; i++){
        printf("%s - %s // %s\n", a[i].nome, a[i].num, a[i].p->id);
    }
    while(s != NULL){
        printf("%s ", s->id);
        s = s->prox;
    }
    printf("\n");
}
int main() {
    int totalSalas;
    pno salas = criaSalas(&totalSalas);
    int totalAlunos;
    aluno* alunos = criaAlunos(salas, &totalAlunos);
    printf("\n----Original-----\n");
    mostraInfo(alunos, totalAlunos, salas);

    printf("\nResultado: %d\n", mesmaSala(salas, "Ana Silva", "Iris Silva", alunos, totalAlunos));

    printf("\n------Pos alteracoes----\n");
    transfereAl(alunos, totalAlunos,salas, "Carlos Pinto", "S1");
    mostraInfo(alunos, totalAlunos, salas);


    free(alunos);
    pno salaAtual = salas;
    while(salaAtual != NULL) {
        pno prox = salaAtual->prox;
        free(salaAtual);
        salaAtual = prox;
    }

    return 0;
}
