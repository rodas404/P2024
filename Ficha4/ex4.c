#include <stdio.h>

int unicaMat(int nLin, int nCol, int mat[][nCol]) {
    //ciclo para percorrer a matriz
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            //ciclo para verificar os numeros
            for (int k = 0; k < nLin; k++) {
                for (int l = 0; l < nCol; l++) {
                    //para nao verificar a mesma posicao
                    if(i != k || j != l) {
                        if (mat[i][j] == mat[k][l]) {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}


int main(){
    int nLin;
    printf("Qual o numero de linhas da matriz?");
    scanf("%d", &nLin);

    int nCol;
    printf("E o numero de colunas?");
    scanf("%d", &nCol);

    int mat[nLin][nCol];
    for(int i=0; i<nLin; i++){
        for(int j=0; j<nCol; j++){
            printf("%d valor da linha %d:",j+1,i+1);
            scanf("%d",&mat[i][j]);
        }
    }
    printf("Resultado: %d\n", unicaMat(nLin,nCol,mat));
    return 0;
}