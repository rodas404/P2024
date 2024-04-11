//
// Created by footr on 11/04/2024.
//

#ifndef FICHA8_CONSULTAS_H
#define FICHA8_CONSULTAS_H



typedef struct paciente pc, *pno;
struct paciente{
    char nome[100];
    int grau;
    pno prox;
};

pno addPaciente(pno lista);
void mostraLista(pno lista);
void freeLista(pno lista);
pno atendePaciente(pno lista);
pno removerPaciente(pno lista, char paciente[100]);
#endif //FICHA8_CONSULTAS_H
