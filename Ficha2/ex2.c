#include <stdio.h>

void preencheMatriz(int mat[][3], int nLin){
    for(int i=0; i < nLin; i++){
        int num;
        printf("Insire o valor para a linha %d:", i+1);
        scanf("%d",&num);

        mat[i][0] = num;
        mat[i][1] = num * num;
        mat[i][2] = num * num * num;
    }
}

int main(){
    int nLin;
    printf("Quantas linhas tera a matriz?");
    scanf("%d",&nLin);

    int mat[nLin][3];
    preencheMatriz(mat,nLin);

    for(int i=0; i<nLin; i++){
        for(int j=0; j<3; j++)
            printf("%d\t", mat[i][j]);
        putchar('\n');
    }

    return 0;
}
