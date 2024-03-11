#include <stdio.h>

void rotacao(float *p1, float *p2, float *p3){
    float temp = *p3;
    *p3 = *p2;
    *p2 = *p1;
    *p1 = temp;
}

int main(){
    float a=1, b=2, c=3;
    printf("Valores iniciais: a=%f; b=%f; c=%f;\n", a,b,c);
    rotacao(&a,&b,&c);
    printf("\nValores apos rotacao: a=%f; b=%f; c=%f;\n", a,b,c);
    return 0;
}