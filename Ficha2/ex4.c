#include <stdio.h>

int matrizUnica(int mat[][3], int nLin) {
    //ciclo para percorrer a matriz
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < 3; j++) {
            //ciclo para verificar os numeros
            for (int k = 0; k < nLin; k++) {
                for (int l = 0; l < 3; l++) {
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

    int mat[nLin][3];
    for(int i=0; i<nLin; i++){
        for(int j=0; j<3; j++){
            printf("%d valor da linha %d:",j+1,i+1);
            scanf("%d",&mat[i][j]);
        }
    }
    printf("Resultado: %d\n", matrizUnica(mat,nLin));
    return 0;
}