#include <stdio.h>
#include "ponto.h"

// Escreve as coordenadas do ponto recebido como parâmetro
void printPonto(ponto2D a){
    printf("Ponto: (%d,%d)\n", a.x, a.y);
}

// Inicializa as coordenadas do ponto referenciado pelo parâmetro recebido. O utilizador indica os valores
void initPonto(ponto2D* p){
    printf("\nPonto x:");
    scanf("%d",&(p->x));
    printf("Ponto y:");
    scanf("%d",&(p->y));
    printf("\n");
}

// Recebe endereço de um ponto e valores para o deslocamento ao longo dos eixos
// Atualiza as coordenadas do ponto
void movePonto(ponto2D* p, int dx, int dy){
    (p->x)+=dx;
    (p->y)+=dy;
}

// Devolve o quadrante a que pertence o ponto recebido por parâmetro
int quadrante(ponto2D a){
    if(a.x>0 && a.y>0)
        return 1;
    else if(a.x<0 && a.y>0)
        return 2;
    else if(a.x<0 && a.y<0)
        return 3;
    else if(a.x>0 && a.y<0)
        return 4;
    else
        return -1;
}

// Recebe 3 pontos
// Devolve 1 se estiverem na mesma reta, 0 se não estiverem
int eReta(ponto2D a, ponto2D b, ponto2D c){
    int dx1 = a.x-c.x;
    int dx2 = b.x-c.x;
    int dy1 = a.y-c.y;
    int dy2 = b.y-c.y;

    if(dx1*dy2 == dx2*dy1)
        return 1;
    else
        return 0;
}
