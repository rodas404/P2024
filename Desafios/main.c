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
    int tab[5] = {1, 2, 1, 2, 1}, i;

    f1(tab, 5);
    for(i=0; i<5; i++){
        printf("%d ", tab[i]);
    }
    return 0;
}