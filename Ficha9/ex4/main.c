//
// Created by footr on 26/04/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include "circular.h"
#include <string.h>

int main(){
    pno lista = NULL, aux, prim,seg;
    char nome[20], nome2[20];
    int op, num;
    do{
        printf("1. Sentar primeira pessoa\n");
        printf("2. Ver pessoas sentadas\n");
        printf("3. Numero de lugares entre 2 pessoas\n");
        printf("4. Sentar ao lado de alguem\n");
        printf("5. Inserir normalmente\n");
        printf("6. Muda de lugar\n");
        printf("7. Sair\n");
        printf("Opcao:");
        scanf("%d", &op);
        printf("\n");
        switch(op){
            case 1:
                if(lista == NULL) {
                    printf("Nome a inserir:");
                    scanf(" %[^\n]", nome);
                    lista = sentaPrimeiro(nome);
                }
                else{
                    printf("Ja ha pessoas sentadas sentadas na mesa\n\n");
                }
                break;
            case 2:
                mostra(lista);
                break;
            case 3:
                for(int i=1; i<=2; i++){
                    aux = lista;
                    if(aux == NULL){
                        printf("Nao ha ninguem sentado na mesa\n\n");
                        break;
                    }
                    printf("Nome da %d pessoa:", i);
                    scanf(" %[^\n]", nome);
                    do {
                        if(strcmp(aux->nome, nome) == 0){
                            break;
                        }
                        aux = aux->prox;
                    } while(aux != lista);
                    if(strcmp(aux->nome, nome) != 0) {
                        printf("O %s nao esta sentado na mesa\n\n", nome);
                        break;
                    }
                    if(i==1)
                        prim = aux;
                    if(i==2) {
                        seg = aux;
                        printf("Entre o %s e %s estao %d pessoas\n\n", prim->nome, seg->nome, nlugares(prim, seg));
                    }
                }
                break;
            case 4:
                printf("Nome da pessoa a sentar:");
                scanf(" %[^\n]", nome);
                printf("Nome da pessoa ja sentada:");
                scanf(" %[^\n]", nome2);
                sentaAoLado(lista, nome, nome2);
                break;
            case 5:
                printf("Nome a inserir:");
                scanf(" %[^\n]", nome);
                lista = insere(lista,nome);
                break;
            case 6:
                printf("Nome da pessoa a mudar de lugar:");
                scanf(" %[^\n]", nome);
                printf("Lugares a deslocar:");
                scanf("%d", &num);
                lista = mudaLugar(lista, nome, num);
                break;
            case 7:
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while(op != 7);

    return 0;
}