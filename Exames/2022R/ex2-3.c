#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prova teste, *pteste;
typedef struct pessoa aluno, *paluno;

struct prova {
    int *alineas;  // Ponteiro para o vetor com as notas obtidas no teste
    int totA;  // Número de alíneas do teste
    float nota;  // Nota obtida no teste
    pteste prox;
};

struct pessoa {
    char nome[100]; // Nome do aluno
    int num;  // Número do aluno
    pteste lista;  // Ponteiro para a lista de testes
    paluno prox;
};

int ex2(paluno a){
    int numTestes = 0, soma;
    float notaTeste;
    while(a != NULL){
        pteste testes = a->lista;
        while(testes != NULL){
            soma = 0;
            for(int i=0; i<testes->totA; i++)
                soma += testes->alineas[i];
            notaTeste = (float) soma / (float) testes->totA;
            testes->nota = notaTeste;
            numTestes++;
            testes = testes->prox;
        }
       a = a->prox;
    }
    return numTestes;
}

paluno adicionaTeste(paluno p, char *nome, int num, int al, int notas[]){
    paluno atual = p;
    int flag = 0;
    while(atual != NULL){
        if(strcmp(atual->nome, nome) == 0){
            flag = 1;
            pteste testes = atual->lista;
            pteste anteriorTeste = NULL;
            while(testes != NULL){
                anteriorTeste = testes;
                testes= testes->prox;
            }

            pteste novoTeste = malloc(sizeof(teste));
            if(novoTeste == NULL){
                printf("erro\n");
                return p;
            }
            int soma = 0;
            float notaTeste;
            novoTeste->alineas = notas;

            for(int i =0; i<al; i++)
                soma += notas[i];
            notaTeste = (float) soma / (float) al;

            novoTeste->prox = NULL;
            novoTeste->totA = al;
            novoTeste->nota = notaTeste;
            if(anteriorTeste == NULL)
                atual->lista = novoTeste;
            else{
                anteriorTeste->prox = novoTeste;
            }
            break;
        }
        atual = atual->prox;
    }

    if(!flag){
        paluno novoAluno = malloc(sizeof(aluno));
        if(novoAluno == NULL){
            printf("erro\n");
            return p;
        }
        strcpy(novoAluno->nome, nome);
        novoAluno->num = num;
        novoAluno->prox = NULL;

        pteste novoTeste = malloc(sizeof(teste));
        if(novoTeste == NULL){
            printf("erro\n");
            free(novoAluno);
            return p;
        }
        int soma = 0;
        float notaTeste;
        novoTeste->alineas = notas;

        for(int i =0; i<al; i++)
            soma += notas[i];
        notaTeste = (float) soma / (float) al;

        novoTeste->prox = NULL;
        novoTeste->totA = al;
        novoTeste->nota = notaTeste;

        novoAluno->lista = novoTeste;

        if(p == NULL)
            p = novoAluno;
        else{
            paluno temp = p;
            while(temp->prox != NULL)
                temp = temp->prox;
            temp->prox = novoAluno;
        }
    }

    return p;
}











//----powered by chatgpt-----
paluno criaEstruturaExemplo() {
    // Notas dos testes
    int notas1[] = {70};
    int notas2[] = {25, 100, 80, 75};
    int notas3[] = {70, 60, 88, 35};
    int notas4[] = {90, 85};
    int notas5[] = {77, 66, 55};
    int notas6[] = {60, 70, 80};
    int notas7[] = {80, 90};
    int notas8[] = {75, 85, 95};


    // Criando os testes para Ana Silva
    pteste teste1 = (pteste)malloc(sizeof(teste));
    teste1->totA = 1;
    teste1->alineas = (int*)malloc(1 * sizeof(int));
    teste1->alineas[0] = notas1[0];
    teste1->nota = 0.0;
    teste1->prox = NULL;

    pteste teste2 = (pteste)malloc(sizeof(teste));
    teste2->totA = 4;
    teste2->alineas = (int*)malloc(4 * sizeof(int));
    for (int i = 0; i < 4; i++) {
        teste2->alineas[i] = notas2[i];
    }
    teste2->nota = 0.0;
    teste2->prox = NULL;

    pteste teste3 = (pteste)malloc(sizeof(teste));
    teste3->totA = 4;
    teste3->alineas = (int*)malloc(4 * sizeof(int));
    for (int i = 0; i < 4; i++) {
        teste3->alineas[i] = notas3[i];
    }
    teste3->nota = 0.0;
    teste3->prox = NULL;

    // Ligando os testes de Ana Silva
    teste1->prox = teste2;
    teste2->prox = teste3;

    // Criando os alunos
    paluno aluno1 = (paluno)malloc(sizeof(aluno));
    strcpy(aluno1->nome, "Ana Silva");
    aluno1->num = 1234;
    aluno1->lista = teste1;
    aluno1->prox = NULL;

    // Criando os testes para Paulo Pinto
    pteste teste4 = (pteste)malloc(sizeof(teste));
    teste4->totA = 2;
    teste4->alineas = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < 2; i++) {
        teste4->alineas[i] = notas4[i];
    }
    teste4->nota = 0.0;
    teste4->prox = NULL;

    pteste teste5 = (pteste)malloc(sizeof(teste));
    teste5->totA = 3;
    teste5->alineas = (int*)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        teste5->alineas[i] = notas5[i];
    }
    teste5->nota = 0.0;
    teste5->prox = NULL;

    pteste teste6 = (pteste)malloc(sizeof(teste));
    teste6->totA = 3;
    teste6->alineas = (int*)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        teste6->alineas[i] = notas6[i];
    }
    teste6->nota = 0.0;
    teste6->prox = NULL;

    // Ligando os testes de Paulo Pinto
    teste4->prox = teste5;
    teste5->prox = teste6;

    paluno aluno2 = (paluno)malloc(sizeof(aluno));
    strcpy(aluno2->nome, "Paulo Pinto");
    aluno2->num = 5567;
    aluno2->lista = teste4;
    aluno2->prox = NULL;

    // Criando os testes para Diana Alves
    pteste teste7 = (pteste)malloc(sizeof(teste));
    teste7->totA = 2;
    teste7->alineas = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < 2; i++) {
        teste7->alineas[i] = notas7[i];
    }
    teste7->nota = 0.0;
    teste7->prox = NULL;

    pteste teste8 = (pteste)malloc(sizeof(teste));
    teste8->totA = 3;
    teste8->alineas = (int*)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        teste8->alineas[i] = notas8[i];
    }
    teste8->nota = 0.0;
    teste8->prox = NULL;

    // Ligando os testes de Diana Alves
    teste7->prox = teste8;

    paluno aluno3 = (paluno)malloc(sizeof(aluno));
    strcpy(aluno3->nome, "Diana Alves");
    aluno3->num = 58997;
    aluno3->lista = teste7;
    aluno3->prox = NULL;

    // Ligando os alunos
    aluno1->prox = aluno2;
    aluno2->prox = aluno3;

    return aluno1;
}

// Função para imprimir a estrutura (para verificação)
void imprimeEstrutura(paluno inicio) {
    paluno atualAluno = inicio;
    while (atualAluno != NULL) {
        printf("Aluno: %s, Num: %d\n", atualAluno->nome, atualAluno->num);
        pteste atualTeste = atualAluno->lista;
        while (atualTeste != NULL) {
            printf("  Teste - totA: %d, nota: %.2f, notas: ", atualTeste->totA, atualTeste->nota);
            for (int i = 0; i < atualTeste->totA; i++) {
                printf("%d ", atualTeste->alineas[i]);
            }
            printf("\n");
            atualTeste = atualTeste->prox;
        }
        atualAluno = atualAluno->prox;
    }
}

// Função para liberar a memória alocada
void liberaMemoria(paluno inicio) {
    while (inicio != NULL) {
        paluno alunoTemp = inicio;
        pteste testeAtual = inicio->lista;
        while (testeAtual != NULL) {
            pteste testeTemp = testeAtual;
            free(testeTemp->alineas);
            testeAtual = testeAtual->prox;
            free(testeTemp);
        }
        inicio = inicio->prox;
        free(alunoTemp);
    }
}

int main() {
    paluno alunos = criaEstruturaExemplo();
    int notas[2] = {50, 60};
    adicionaTeste(alunos, "Diana Alves", 1234, 2, notas);
    printf("num testes: %d\n", ex2(alunos));
    imprimeEstrutura(alunos);

    liberaMemoria(alunos);
    return 0;
}
