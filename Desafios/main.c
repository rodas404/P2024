#include <stdio.h>
#include <string.h>

void f1(int* a, int tam){
    int i, *p = a;

    for(i=0; i<tam; i++){
        if(*p == a[tam-1])
            *p = 0;
        p++;
    }
}

int main(){
    FILE *f;
    f = fopen("teste.txt", "r");
    int a;
    char t[50];
    float b;
    fscanf(f, "%s # %d # %f", t, &a, &b);
    printf("%s  %d  %f", t, a, b);
    return 0;
}