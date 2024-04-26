//
// Created by footr on 26/04/2024.
//

#ifndef FICHA9_CIRCULAR_H
#define FICHA9_CIRCULAR_H

typedef struct circulo circ, *pno;
struct circulo{
    char nome[100];
    pno prox;
};
pno sentaPrimeiro(char* nome);
void mostra(pno p);
int nlugares(pno prim, pno seg);
pno sentaAoLado(pno p, char* prim, char* seg);
pno insere(pno p, char* nome);
pno mudaLugar(pno p, char* nome, int num);
#endif //FICHA9_CIRCULAR_H
