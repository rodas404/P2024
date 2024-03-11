#include <stdio.h>

void preencheMatriz(int mat[][3], int nLin){
    for(int i=0; i < nLin; i++){
        int flag=0;
        do {
            printf("Insire o valor para a linha %d (entre 1 a 100, nao repetido):", i + 1);
            scanf("%d", &mat[i][0]);
            flag=(mat[i][0]<1 || mat[i][0]>100);
            for(int j=0; j<i && !flag;j++){
                if(mat[j][0]==mat[i][0])
                    flag=1;
            }
            if(flag)
                printf("Valor invalido\n");
        }while(flag);

        mat[i][1] = mat[i][0] * mat[i][0];
        mat[i][2] = mat[i][0] * mat[i][0] * mat[i][0];
    }
}

int main(){
    int nLin;
    do {
        printf("Quantas linhas tera a matriz (entre 1 a 100)?");
        scanf("%d", &nLin);
    }while(nLin<1 || nLin>100);

    int mat[nLin][3];
    preencheMatriz(mat,nLin);

    for(int i=0; i<nLin; i++){
        for(int j=0; j<3; j++)
            printf("%d\t", mat[i][j]);
        putchar('\n');
    }

    return 0;
}
