#include <stdio.h>

void printMat(int mat[][3], int nLin){
    int i, j;

    for(i=0; i<nLin; i++){
        for(j=0; j<3; j++)
            printf("%d\t", mat[i][j]);
        putchar('\n');
    }
}

int main(){

    int m1[4][3] = {{1,2,3},{6,7,8},{10,11,12},{20,30,40}};
    printMat(m1, 4);
    printf("\n\t%d",m1[3][0]);
    return 0;
}