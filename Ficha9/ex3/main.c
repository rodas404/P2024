//
// Created by footr on 19/04/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include "dados.h"
#include <string.h>

int main(){
    pno lista = NULL;
    int op, val;
    do{
        printf("1. Inserir no\n");
        printf("2. Ver nos\n");
        printf("3. Ver nos invertidamente\n");
        printf("4. Eliminar no\n");
        printf("5. Elementos iguais a media\n");
        printf("6. Sair\n");
        printf("Opcao:");
        scanf("%d", &op);
        printf("\n");
        switch(op){
            case 1:
                printf("Valor a inserir:");
                scanf("%d", &val);
                lista = insere(lista,val);
                break;
            case 2:
                mostra(lista);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while(op != 6);

    return 0;
}