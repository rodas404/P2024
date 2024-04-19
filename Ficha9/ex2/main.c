//
// Created by footr on 18/04/2024.
//
#include <stdio.h>
#include "testes.h"
#include <stdlib.h>
#include <string.h>


int main(){
    int tot = 0;
    struct sala *s = criaSalas(&tot);
    pno lista = criaAlunos(s);
    char nome[50], num[50], nSala[50];
    int opcao;

    do {
        printf("1. Adicionar aluno\n");
        printf("2. Transferir aluno\n");
        printf("3. Verificar se dois alunos estao na mesma sala\n");
        printf("4. Mostrar salas\n");
        printf("5. Mostrar sala com mais alunos\n");
        printf("6. Sair\n");
        printf("Opcao:");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao) {
            case 1:
                printf("Nome do aluno:");
                scanf(" %[^\n]", nome);
                printf("Numero do aluno:");
                scanf(" %[^\n]", num);
                lista = adicionaAl(lista, s, tot, nome, num);
                break;
            case 2:
                printf("Nome do aluno a ser transferido:");
                scanf(" %[^\n]", nome);
                printf("ID da nova sala:");
                scanf("%s", nSala);
                s = transfereAl(lista, s, &tot, nome, nSala);
                break;
            case 3:
                printf("Nome do primeiro aluno:");
                scanf(" %[^\n]", nome);
                printf("Nome do segundo aluno:");
                scanf(" %[^\n]", num);
                printf("Resultado: %d\n\n", mesmaSala(lista,nome, num));
                break;
            case 4:
                mostraInfo(lista,s,tot);
                break;
            case 5:
                mostraMaxSala(lista, s, tot);
                break;
            case 6:
                break;
            default:
                printf("Opção invalida\n");
        }
    } while(opcao != 6);

    while(lista != NULL) {
        pno temp = lista;
        lista = lista->prox;
        free(temp);
    }
    free(s);

    return 0;
}
