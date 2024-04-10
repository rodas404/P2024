#include <stdio.h>

void teste(int *a){
    int *p = a;
    p[1]= 8;
}

int main() {
    int tab[3] = {0,1,2};
    int tab2[2][2] = {{1,2}, {3,4}};
    printf("%d", tab2[1]);
    return 0;
}
