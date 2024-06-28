//
// Created by footr on 26/06/2024.
//
#include <stdio.h>
int f(int x){
    if(x<=1) //acaba
        return x;
    else if(x%2 == 0){ //imprime se for par e chama novamente com x dividido por 2
        printf("%d\t", x);
        return f(x/2);
    }
    else //se for impar retorna x mais o valor que surge dividindo x por 3
        return x + f(x / 3);
}
int main() {
    printf("%d\n", f(13));
    //4       2       14
    return 0;
}