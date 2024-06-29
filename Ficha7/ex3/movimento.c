//
// Created by footr on 15/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movimento.h"

mov info(){
    mov m;
    printf("Data do movimento:\n");
    printf(" - Dia:");
    scanf("%d", &m.dMov.d);
    printf(" - Mes:");
    scanf("%d", &m.dMov.m);
    printf(" - Ano:");
    scanf("%d", &m.dMov.a);
    printf("Numero da conta:");
    scanf(" %[^\n]", m.nconta);
    printf("Valor do movimento:");
    scanf("%d", &m.val);
    return m;
}
mov* addMov(mov *tab, int *total){
    if((*total) == 0) {
        tab = malloc(sizeof(mov));
        if(tab == NULL) {
            printf("Erro na alocacao de memoria\n");
            return NULL;
        }
        tab[*total] = info();
        (*total)++;
        printf("\n");
        return tab;
    }
    else{
        tab = realloc(tab, ((*total)+1)*sizeof(mov));
        if(tab == NULL) {
            printf("Erro na alocacao de memoria\n");
            return NULL;
        }
        tab[*total] = info();
        (*total)++;
        printf("\n");
        return tab;
    }
}

void mostraMovs(mov *tab, int total){
    printf("Estao registados %d movimentos:\n", total);
    for(int i=0; i<total; i++)
        if(tab[i].val > 0)
            printf(" - Conta %s depositou %d euros em %d/%d/%d\n", tab[i].nconta, tab[i].val, tab[i].dMov.d, tab[i].dMov.m, tab[i].dMov.a);
        else
            printf(" - Conta %s levantou %d euros em %d/%d/%d\n", tab[i].nconta, abs(tab[i].val), tab[i].dMov.d, tab[i].dMov.m, tab[i].dMov.a);
    printf("\n");
}

void listaMovs(mov *tab, int total, data d1, data d2){
    printf("Movimentos entre %d/%d/%d e %d/%d/%d:\n", d1.d, d1.m, d1.a, d2.d, d2.m, d2.a);
    for(int i=0; i<total; i++) {
        if ((tab[i].dMov.a > d1.a && tab[i].dMov.a < d2.a) || //comparacao entre anos
            (tab[i].dMov.a == d1.a && tab[i].dMov.m > d1.m) || //comparacao entre o mes 1
            (tab[i].dMov.a == d2.a && tab[i].dMov.m < d2.m) || //comparacao entre mes 2
            (tab[i].dMov.a == d1.a && tab[i].dMov.m == d1.m && tab[i].dMov.d > d1.d) || //comparecao entre o dia 1
            (tab[i].dMov.a == d2.a && tab[i].dMov.m == d2.m && tab[i].dMov.d < d2.d))  { //comparecao entre o dia 2
            if (tab[i].val > 0)
                printf(" - Conta %s depositou %d euros em %d/%d/%d\n", tab[i].nconta, tab[i].val, tab[i].dMov.d,
                       tab[i].dMov.m, tab[i].dMov.a);
            else
                printf(" - Conta %s levantou %d euros em %d/%d/%d\n", tab[i].nconta, abs(tab[i].val), tab[i].dMov.d,
                       tab[i].dMov.m, tab[i].dMov.a);
        }
    }
    printf("\n");
}

void mostraMovsConta(mov *tab, int total, char *nconta){
    int nLevs = 0, nDeps = 0, totalMovs = 0, saldo = 0;
    for(int i=0; i<total; i++)
        if(strcmp(tab[i].nconta, nconta) == 0) {
            if (tab[i].val > 0) {
                saldo += tab[i].val;
                nDeps++;
                totalMovs++;
            } else {
                nLevs++;
                totalMovs++;
                saldo += tab[i].val;
            }
        }
    printf("Conta %s regista um total de %d movimentos entre os quais:\n", nconta, totalMovs);
    printf(" - %d depositos\n", nDeps);
    printf(" - %d levantamentos\n", nLevs);
    printf("Saldo atual: %d\n\n", saldo);
}

mov *eliminaMovs(mov *tab, int *total, data d){
    int i, j;
    for(i=0; i<(*total); i++){
        if(tab[i].dMov.a == d.a && tab[i].dMov.m == d.m && tab[i].dMov.d == d.d) {
            for(j=i; j<(*total)-1; j++)
                tab[j] = tab[j+1];
            (*total)--;
            tab = realloc(tab, (*total)*sizeof(mov));
            if(tab == NULL) {
                printf("Erro na alocacao de memoria\n");
                return NULL;
            }
            i--;
        }
    }
    return tab;
}
