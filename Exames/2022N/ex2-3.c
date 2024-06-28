#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int dia, mes, ano;
    struct data *prox;} *pdata;
typedef struct pessoa aluno, *paluno;
struct pessoa{
    char nome[100]; // Nome do aluno
    int num; // Número do aluno
    int nprovas; // Provas realizadas
    int* notas; // Ponteiro para a tabela com as notas
    pdata faltas; // Ponteiro para a lista com registo de faltas
    paluno prox;
};

void ex2(paluno p){
    int soma;
    float media;
    while(p != NULL){
        soma = 0;
        for(int i=0; i<p->nprovas; i++)
            soma += p->notas[i];
        media = (float) soma / (float) p->nprovas;
        printf("%s, %d provas: %.1f\n", p->nome, p->nprovas, media);
        p = p->prox;
    }
}

paluno ex3(paluno p){
    int numFaltas, maxFaltas = 0, numMaxFaltas;
    paluno atual = p;
    paluno aRemover = NULL;
    while(atual != NULL){
        numFaltas = 0;
        pdata faltas = atual->faltas;
        while(faltas != NULL){
            numFaltas++;
            faltas = faltas->prox;
        }
        if(numFaltas > maxFaltas && numFaltas != 0){
            maxFaltas = numFaltas;
            aRemover = atual;
            numMaxFaltas = 1;
        }
        else if (numFaltas == maxFaltas && numFaltas != 0)
            numMaxFaltas++;

        atual = atual->prox;
    }
    if(numMaxFaltas > 1 || aRemover == NULL){
        printf("empate (ou erro)\n");
        return p;
    }

    if(p == aRemover)
        p = aRemover->prox;
    else{
        atual = p;
        while(atual->prox != aRemover)
            atual = atual->prox;
        atual->prox = aRemover->prox;
    }

    printf("%s removida da lista\n", aRemover->nome);
    pdata faltas = aRemover->faltas;
    while(faltas != NULL){
        pdata aux = faltas;
        faltas = faltas->prox;
        free(aux);
    }
    free(aRemover->notas);
    free(aRemover);
    return p;
}












//----powered by chatgpt-------
void criaListaDeAlunos(paluno *lista) {
    // Criação das faltas de Ana Silva
    pdata faltasAna = (pdata)malloc(sizeof(struct data));
    faltasAna->dia = 12;
    faltasAna->mes = 3;
    faltasAna->ano = 2022;
    faltasAna->prox = (pdata)malloc(sizeof(struct data));
    faltasAna->prox->dia = 3;
    faltasAna->prox->mes = 5;
    faltasAna->prox->ano = 2022;
    faltasAna->prox->prox = (pdata)malloc(sizeof(struct data));
    faltasAna->prox->prox->dia = 14;
    faltasAna->prox->prox->mes = 4;
    faltasAna->prox->prox->ano = 2022;
    faltasAna->prox->prox->prox = NULL;

    // Criação de Ana Silva
    paluno ana = (paluno)malloc(sizeof(aluno));
    strcpy(ana->nome, "Ana Silva");
    ana->num = 123456;
    ana->nprovas = 4;
    ana->notas = (int*)malloc(sizeof(int) * 4);
    ana->notas[0] = 75;
    ana->notas[1] = 23;
    ana->notas[2] = 65;
    ana->notas[3] = 86;
    ana->faltas = faltasAna;
    ana->prox = NULL;


    pdata faltasPaulo = (pdata)malloc(sizeof(struct data));
    faltasPaulo->dia = 11;
    faltasPaulo->mes = 8;
    faltasPaulo->ano = 2022;
    faltasPaulo->prox = (pdata)malloc(sizeof(struct data));
    faltasPaulo->prox->dia = 2;
    faltasPaulo->prox->mes = 4;
    faltasPaulo->prox->ano = 2022;
    faltasPaulo->prox->prox = NULL;

    // Criação de Paulo Pinto
    paluno paulo = (paluno)malloc(sizeof(aluno));
    strcpy(paulo->nome, "Paulo Pinto");
    paulo->num = 33567;
    paulo->nprovas = 3;
    paulo->notas = (int*)malloc(sizeof(int) * 3);
    paulo->notas[0] = 75;
    paulo->notas[1] = 34;
    paulo->notas[2] = 64;
    paulo->faltas = faltasPaulo;
    paulo->prox = ana;

    pdata faltasDiana = (pdata)malloc(sizeof(struct data));
    faltasDiana->dia = 14;
    faltasDiana->mes = 6;
    faltasDiana->ano = 2022;
    faltasDiana->prox = NULL;

    // Criação de Diana Alves
    paluno diana = (paluno)malloc(sizeof(aluno));
    strcpy(diana->nome, "Diana Alves");
    diana->num = 789333;
    diana->nprovas = 4;
    diana->notas = (int*)malloc(sizeof(int) * 4);
    diana->notas[0] = 55;
    diana->notas[1] = 80;
    diana->notas[2] = 90;
    diana->notas[3] = 70;
    diana->faltas = faltasDiana;
    diana->prox = paulo;

    *lista = diana;
}

// Função para imprimir a lista de alunos (para verificação)
void imprimeAlunos(paluno lista) {
    paluno atual = lista;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("Numero: %d\n", atual->num);
        printf("Numero de provas: %d\n", atual->nprovas);
        printf("Notas: ");
        for (int i = 0; i < atual->nprovas; i++) {
            printf("%d ", atual->notas[i]);
        }
        printf("\nFaltas: ");
        pdata falta = atual->faltas;
        while (falta != NULL) {
            printf("%d-%d-%d ", falta->dia, falta->mes, falta->ano);
            falta = falta->prox;
        }
        printf("\n\n");
        atual = atual->prox;
    }
}

void liberaMemoria(paluno lista) {
    paluno atual = lista;
    while (atual != NULL) {
        paluno temp = atual;
        atual = atual->prox;
        free(temp->notas);
        pdata faltaAtual = temp->faltas;
        while (faltaAtual != NULL) {
            pdata faltaTemp = faltaAtual;
            faltaAtual = faltaAtual->prox;
            free(faltaTemp);
        }
        free(temp);
    }
}

int main() {
    paluno lista = NULL;
    criaListaDeAlunos(&lista);

    ex2(lista);
    ex3(lista);

    imprimeAlunos(lista);
    liberaMemoria(lista);
    return 0;
}
