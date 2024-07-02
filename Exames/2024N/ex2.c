#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dadosUc uc, *pUc;
typedef struct dadosSala sala, *pSala;
typedef struct {int dia, mes, ano;} data;
struct dadosUc{
    char refUc[100]; // Nome da Unidade Curricular
    data dataEx; // Data do exame
    pSala lista; // Ponteiro para a lista de salas
};
struct dadosSala{
    char refSala[100]; // Nome da sala
    int capacidade; // Capacidade de sala
    pSala prox;
};




void ex2(pUc uc, int tam, char *sala){
    printf("A %s recebe os exames de:\n",sala);
    for(int i=0; i<tam; i++){
        pSala salas = uc[i].lista;
        while(salas != NULL){
            if(strcmp(salas->refSala, sala) ==0){
                printf(" - %s\n", uc[i].refUc);
            }
            salas = salas->prox;
        }
    }
}

//----------em principio e isto, mas pode conter erros-------
pUc elimina(pUc v, int *nUcs, data d){
    for(int i=0; i<(*nUcs); i++){
        if ((v[i].dataEx.ano < d.ano) ||
            (v[i].dataEx.ano == d.ano && v[i].dataEx.mes < d.mes) ||
            (v[i].dataEx.ano == d.ano && v[i].dataEx.mes == d.mes && v[i].dataEx.dia < d.dia)) {

            printf("vou remover a %s\n", v[i].refUc);
            pSala salas = v[i].lista;
            while(salas != NULL){
                pSala temp = salas;
                salas = salas->prox;
                free(temp);
            }

            for(int j = i; j<(*nUcs)-1; j++)
                v[j] = v[j+1];

            (*nUcs)--;
            v = realloc(v, (*nUcs)*sizeof(uc));
            if(v== NULL){
                printf("merda\n");
                return NULL;
            }
            i--;
        }
    }
    return v;
}

