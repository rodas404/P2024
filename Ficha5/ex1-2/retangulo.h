//
// Created by footr on 01/03/2024.
//

#ifndef RETANGULO_H
#define RETANGULO_H

#include "ponto.h"

typedef struct retangulo ret;
struct retangulo{
    ponto2D canto;
    int alt, larg;
};

// Prototipos das funções definidas no modulo retangulo.c

void printRet(ret r);

void initRet(ret* p);

int areaR(ret r);

int dentroR(ponto2D a, ret r);

void moveR(ret* p, int dx, int dy);

int intersetaR(ret r1, ret r2);

float IoU(ret r1, ret r2);

#endif
