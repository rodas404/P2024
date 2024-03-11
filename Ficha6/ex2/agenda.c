//
// Created by footr on 08/03/2024.
//
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "agenda.h"

void imprime_voos(voo v[], int total){
    for(int i=0; i<total; i++){
        printf("Informacoes do Voo n. %d:\n",v[i].n_voo);
        printf(" - companhia: %s\n", v[i].nome);
        printf(" - cidade destino: %s\n", v[i].cidade);
        printf(" - hora de partida: %d:%d\n\n", v[i].agenda.horas, v[i].agenda.minutos);
    }
}

void addVoo(voo v[], int *total){
    int num;
    printf("Quantos voos a adicionar?");
    scanf("%d",&num);
    for(int i=0; i<num; i++) {
        printf("\n%d voo\n", i+1);
        printf("Numero de voo:");
        scanf("%d", &(v[(*total)].n_voo));
        printf("Nome da companhia:");
        scanf(" %99[^\n]", v[(*total)].nome);
        printf("Cidade de destino:");
        scanf(" %99[^\n]", v[(*total)].cidade);
        printf("Hora:");
        scanf("%d", &(v[(*total)].agenda.horas));
        printf("Minutos:");
        scanf("%d", &(v[(*total)].agenda.minutos));
        printf("\n");
        (*total)++;
    }
}

void mudaAgenda(voo* v){
    int hora, minutos;
    printf("Nova hora:");
    scanf("%d",&hora);
    printf("Novos minutos:");
    scanf("%d",&minutos);
    v->agenda.horas=hora;
    v->agenda.minutos=minutos;
}

int partiu(voo v, tempo t){
    int hora_voo = v.agenda.horas * 60 + v.agenda.minutos;
    int hora_atual = t.horas * 60 + t.minutos;

    if(hora_atual>hora_voo)
        return 1;
    else
        return 0;
}

void parteBrevemente(voo v[], tempo t, int total){
    int hora_voo, falta, hora_atual = t.horas * 60 + t.minutos;
    for(int i=0; i<total; i++){
        hora_voo = v[i].agenda.horas * 60 + v[i].agenda.minutos;
        falta = hora_voo - hora_atual;
        if(falta <= 30 && falta >= 0){
            printf("Faltam %d minutos para o voo n. %d partir para %s\n", falta, v[i].n_voo, v[i].cidade);
        }
    }
}

void removeVoo(voo v[], tempo t, int* total){
    int hora_voo, falta, hora_atual = t.horas * 60 + t.minutos;
    for(int i=0; i<(*total); i++){
        hora_voo = v[i].agenda.horas * 60 + v[i].agenda.minutos;
        falta = hora_voo - hora_atual;
        if(falta < 0) {
            for(int j=i; j<(*total)-1; j++){
                v[j] = v[j+1];
            }
            (*total)--;
        }
    }
}

struct tempo hora_atual(){
    time_t a;
    struct tm* b;
    struct tempo atual;
    time(&a);
    b = localtime(&a);
    atual.horas = b->tm_hour;
    atual.minutos = b->tm_min;
    return atual;
}