//
// Created by footr on 27/06/2024.
//
#include <stdio.h>
#define TAM 5
int fRec(int *a, int n){
    if(n<0 || n>=TAM)
        return n-1;
    else if(a[n] <= 0)
        return a[n]-n;
    else {
        printf("%d\t", a[n]);
        return fRec(a, n+a[n]);
    }
}
int main(){
    int tab[TAM] = {1, 2, 3, -4, -5};
    printf("%d\n", fRec(tab,0));
    //1   2   -7
    return 0;
}
