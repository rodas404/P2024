//
// Created by footr on 19/04/2024.
//

#ifndef FICHA9_DADOS_H
#define FICHA9_DADOS_H

typedef struct dados no, *pno;
struct dados{
    int val;
    pno prev, prox;
};

pno insere(pno p, int val);
void mostra(pno p);
#endif //FICHA9_DADOS_H
