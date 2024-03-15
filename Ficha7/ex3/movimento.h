//
// Created by footr on 15/03/2024.
//

#ifndef FICHA7_MOVIMENTO_H
#define FICHA7_MOVIMENTO_H

typedef struct movimento mov;
typedef struct {int d, m, a;} data;
struct movimento{
    data dMov;
    char nconta[15];
    int val;
};

mov *addMov(mov *tab, int *total);
void mostraMovs(mov *tab, int total);
void listaMovs(mov *tab, int total, data d1, data d2);
mov info();
void mostraMovsConta(mov *tab, int total, char *nconta);
mov *eliminaMovs(mov *tab, int *total, data d);
#endif //FICHA7_MOVIMENTO_H
