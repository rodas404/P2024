#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia, mes, ano;
} data;

typedef struct dadosSala {
    char refSala[100];  // Nome da sala
    int capacidade;     // Capacidade de sala
    struct dadosSala *prox;
} sala, *pSala;

typedef struct dadosUc {
    char refUc[100];    // Nome da Unidade Curricular
    data dataEx;        // Data do exame
    pSala lista;        // Ponteiro para a lista de salas
} uc, *pUc;




void ex2(pUc uc, int tam, char *sala){
    printf("A sala '%s' recebe os exames de:\n",sala);
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

//----------nao terminei, mas da para pegar umas ideias daqui-------
pUc elimina(pUc v, int *nUcs, data d){
    int flag;
    for(int i=0; i<(*nUcs); i++){
        flag = 0;

        if (d.ano < v[i].dataEx.ano) {
            flag = 1;
        } else if (d.ano == v[i].dataEx.ano) {
            if (d.mes < v[i].dataEx.mes) {
                flag = 1;
            } else if (d.mes == v[i].dataEx.mes) {
                if (d.dia < v[i].dataEx.dia) {
                    flag = 1;
                }
            }
        }

        if(flag){
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
            if(v == NULL){
                printf("Erro na realocacao de memoria\n");
                return NULL;
            }
        }
    }
}



