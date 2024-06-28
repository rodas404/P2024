
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

// Nome: Rodrigo Miguel Pessoa da Bernarda
// Número: 2021136740
void eliminaLista(pno lista){
    pno aux;

    while(lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

pno criaLista(no tab[], int tam){
    int i;
    pno lista=NULL, novo;

    for(i=tam-1; i>=0; i--){
        novo = malloc(sizeof(no));
        if(novo == NULL){
            eliminaLista(lista);
            return NULL;
        }
        *novo = tab[i];
        novo->prox = lista;
        lista = novo;
    }
    return lista;
}

void mostraLista(pno lista){
    printf("{ ");
    while(lista != NULL){
        printf("%s-%d", lista->id, lista->v);
        lista = lista->prox;
        if(lista!=NULL)
            printf(",\t");
    }
    printf("}");
}


pno desafio3(pno lista, char *velhoID, char* novoID){
    pno atual = lista;
    int i=0;

    while(atual != NULL){ //ciclo para verificar numero de elementos da lista
        i++;
        atual = atual->prox;
        if(i == 3)
            break;
    }
    if(i<3)
        return lista;

    pno anterior = NULL, auxID = NULL;
    atual = lista;
    i = 0;

    while(atual != NULL){ //ciclo principal
        i++;
        if(i % 2 == 0 || strcmp(atual->id, velhoID) == 0){ //condicao principal ativada nos 2 casos principais
            pno aux = atual;
            atual = atual->prox;

            if(anterior != NULL) //caso o no em causa nao seja o primeiro
                anterior->prox = atual;
            else
                lista = atual;

            if(strcmp(aux->id, velhoID) == 0 && i % 2 != 0) //se for o no com o velhoId e nao par desconecta da lista
                auxID = aux;
            else //se for um no par liberta da memoria
                free(aux);
        }
        else{
            anterior = atual;
            atual = atual->prox;
        }
    }

    if(auxID == NULL)
        return lista;

    strcpy(auxID->id, novoID);
    auxID->prox = NULL;
    //processo para colocar o no alterado de novo na lista
    if(lista == NULL || strcmp(lista->id, auxID->id) > 0){
        auxID->prox = lista;
        lista = auxID;
    }
    else{
        atual = lista;
        while(atual->prox != NULL && strcmp(auxID->id, atual->prox->id) > 0)
            atual = atual->prox;
        auxID->prox = atual->prox;
        atual->prox = auxID;
    }

    return lista;
}