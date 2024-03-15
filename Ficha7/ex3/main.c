//
// Created by footr on 15/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movimento.h"

int main(){
    mov *tab = NULL;
    int total=0, i;
    char conta[100];
    data d1 = {10,12,2020}, d2 = {10,12,2021}, d3;

    for(i=0; i<2; i++)
        tab = addMov(tab, &total);

    mostraMovs(tab, total);

    listaMovs(tab, total, d1, d2);

    printf("Conta a procurar:");
    scanf(" %[^\n]", conta);
    mostraMovsConta(tab, total, conta);

    printf("Data a eliminar:\n");
    printf(" - Dia:");
    scanf("%d", &d3.d);
    printf(" - Mes:");
    scanf("%d", &d3.m);
    printf(" - Ano:");
    scanf("%d", &d3.a);
    eliminaMovs(tab, &total, d3);
    mostraMovs(tab, total);

    free(tab);

}
