//
// Created by footr on 11/04/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "consultas.h"

int main(){
    pno lista = NULL;
    int op;
    char paciente[100];
    do{
        printf("1. Adicionar Paciente\n");
        printf("2. Mostrar Lista de Espera\n");
        printf("3. Atender Paciente\n");
        printf("4. Remover Paciente da Lista de Espera\n");
        printf("5. Terminar\n");
        printf("Opcao:");
        scanf("%d", &op);
        printf("\n");
        switch(op){
            case 1:
                lista = addPaciente(lista);
                break;
            case 2:
                mostraLista(lista);
                break;
            case 3:
                lista = atendePaciente(lista);
                break;
            case 4:
                printf("Nome do paciente a remover:");
                scanf(" %[^\n]", paciente);
                lista = removerPaciente(lista, paciente);
                break;
            case 5:
                break;
            default: printf("Opcao invalida\n");
        }
    } while(op != 5);

    freeLista(lista);
    return 0;
}