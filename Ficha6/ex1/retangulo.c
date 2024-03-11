#include <stdio.h>
#include "retangulo.h"


void printRet(ret r){
    printf("Canto inf esq: (%d,%d)\n", r.canto.x, r.canto.y);
    printf("Canto inf dir: (%d,%d)\n", (r.canto.x+r.larg), r.canto.y);
    printf("Canto sup esq: (%d,%d)\n", r.canto.x, (r.canto.y+r.alt));
    printf("Canto sup dir: (%d,%d)\n",(r.canto.x+r.larg),(r.canto.y+r.alt));
}

void initRet(ret* p){
    printf("Ponto x:");
    scanf("%d", &(p->canto.x));
    printf("Ponto y:");
    scanf("%d",&(p->canto.y));
    printf("Altura:");
    scanf("%d",&(p->alt));
    printf("Largura:");
    scanf("%d",&(p->larg));
}

int areaR(ret r){
    int area = r.larg * r.alt;
    return area;
}

int dentroR(ponto2D a, ret r){
    if(a.x>r.canto.x && a.y>r.canto.y && a.x<(r.canto.x+r.larg) && a.y<(r.canto.y+r.alt))
        return 1;
    else
        return 0;
}

void moveR(ret* p, int dx, int dy){
    p->canto.x += dx;
    p->canto.y += dy;
}

int intersetaR(ret r1, ret r2){
    if(r1.canto.x +r1.larg <= r2.canto.x || r2.canto.x + r2.larg <= r1.canto.x)
        return 0;
    if (r1.canto.y + r1.alt <= r2.canto.y || r2.canto.y + r2.alt <= r1.canto.y)
        return 0;
    return 1;
}

float IoU(ret r1, ret r2){
  int x1, x2, y1, y2, area1, area2, intersecao=0, uniao;
  float IoU;

  if(r1.canto.x>r2.canto.x)
      x1 = r1.canto.x;
  else
      x1 = r2.canto.x;

  if(r1.canto.y>r2.canto.y)
      y1 = r1.canto.y;
  else
      y1 = r2.canto.y;

  if((r1.canto.x+r1.larg)<(r2.canto.x+r2.larg))
      x2 = (r1.canto.x+r1.larg);
  else
      x2 = (r2.canto.x+r2.larg);

  if((r1.canto.y+r1.alt)<(r2.canto.y+r2.alt))
      y2 = (r1.canto.y+r1.alt);
  else
      y2 = (r2.canto.y+r2.alt);

  area1 = r1.larg*r1.alt;
  area2 = r2.larg*r2.alt;

  if(x1<x2 && y1<y2)
      intersecao = (x2-x1)*(y2-y1);

  uniao = area1 + area2 - intersecao;
  IoU = (float)intersecao/(float)uniao;

  return IoU;

}
