//
// Created by footr on 08/03/2024.
//

#ifndef FICHA6_AGENDA_H
#define FICHA6_AGENDA_H

typedef struct tempo tempo;
struct tempo{
    int horas, minutos;
};

typedef struct voo voo;
struct voo{
    int n_voo;
    char nome[50], cidade[50];
    tempo agenda;
};

void imprime_voos(voo v[], int total);
void addVoo(voo v[], int *total);
void mudaAgenda(voo* v);
int partiu(voo v, tempo t);
void parteBrevemente(voo v[], tempo t, int total);
void removeVoo(voo v[], tempo t, int* total);
struct tempo hora_atual();
#endif //FICHA6_AGENDA_H
