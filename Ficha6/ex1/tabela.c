#include <stdio.h>
#include "tabela.h"

void printV(ret a[], int total){
    int i;

    printf("Existem %d retangulos na tabela\n", total);
    for(i=0; i<total; i++) {
        printf("R. %d\n", i);
        printRet(a[i]);
    }
}

int addRet(ret a[], int *total){
    if((*total)<10){
        printf("Adicionar R. %d:\n",(*total));
        printf("Ponto x:");
        scanf("%d", &(a[(*total)].canto.x));
        printf("Ponto y:");
        scanf("%d",&(a[(*total)].canto.y));
        printf("Altura:");
        scanf("%d",&(a[(*total)].alt));
        printf("Largura:");
        scanf("%d",&(a[(*total)].larg));
        (*total)++;
        return 1;
    }
    else{
        printf("Numero maximo de retangulos permitido atingido\n");
        return 0;
    }
}

void duplicaAltLarg(ret a[], int total){
    int area = 0;
    for(int i=0; i<total;i++){
        area = areaR(a[i]);
        if(area%2 == 0){
            a[i].larg *= 2;
            a[i].alt *= 2;
        }
    }
}


int quadrante1(ret a[], int total){
    int quad, cont=0;
    for(int i=0; i<total; i++){
        quad = quadrante(a[i].canto);
        if(quad == 1)
            cont++;
    }
    return cont;
}

void eliminaMenor(ret a[], int *total){
    int area, minArea=1000000000, index=-1, i;
    for(i=0; i<(*total); i++){
        area= areaR(a[i]);
        if(area<minArea){
            minArea=area;
            index = i;
        }
    }
    for(i=index; i<(*total)-1;i++){
        a[i] = a[i+1];
    }
    printf("Foi eliminado o R. %d (area = %d)\n", index, minArea);
    (*total)--;
}

void eliminaVarios(ret a[], int *total, int lim){
    int area, eliminado=0;
    for(int i=(*total)-1; i>=0; i--){
        area= areaR(a[i]);
        if(area<lim){
            for(int j=i; j<(*total)-1; j++){
                a[j]=a[j+1];
            }
            (*total)--;
            eliminado++;
        }
    }
    printf("Foram eliminados %d retangulos\n",eliminado);
}

void inverteOrdem(ret a[], int total){
    int inicio=0, fim=total-1;
    while (inicio<fim){
        ret temp = a[inicio];
        a[inicio] = a[fim];
        a[fim] = temp;
        inicio++;
        fim--;
    }
    printf("Ordem invertida\n");
}