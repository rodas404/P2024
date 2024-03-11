#include <stdio.h>
#include "ponto.h"
#include "retangulo.h"

int main(){

    ponto2D p1 = {3, 5}, p2;
    /*
    printPonto(p1);

    initPonto(&p2);
    printPonto(p2);

    movePonto(&p1, -4, -1);
    printPonto(p1);
    printf("Quadrante deste ponto: %d\n", quadrante(p1));
    */
    ret r1={p1, 2, 5}, r2;

    printRet(r1);

    initRet(&r2);
    printRet(r2);

    printf("Area do retangulo: %d\n", areaR(r2));
    printf("Dentro? %d\n", dentroR(p1, r2));

    moveR(&r2,2,2);
    printRet(r2);

    printf("Intersecao entre os 2 retangulos? %d\n", intersetaR(r1,r2));
    printf("IoU = %f\n", IoU(r1,r2));

    return 0;
}
