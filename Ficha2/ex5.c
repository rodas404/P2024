#include <stdio.h>

int quadradoMagico(int mat[][3]){

    int somaReferencia = 0;
    int i,j;
    for(j=0; j<3; j++){
        somaReferencia += mat[0][j];
    }

    for(i=1; i<3; i++){
        int somaLinhas = 0;
        for(j=0; j<3; j++){
            somaLinhas += mat[i][j];
        }
        if(somaLinhas != somaReferencia) {
            return 0;
        }
    }

   for(j=0; j<3; j++){
       int somaColunas = 0;
        for(i=0; i<3; i++){
            somaColunas += mat[i][j];
        }
        if(somaColunas != somaReferencia) {
            return 0;
        }
   }
    int somaDiagonal1 = 0;
    for (i = 0; i < 3; i++) {
        somaDiagonal1 += mat[i][i];
    }
    if (somaDiagonal1 != somaReferencia) {
        return 0;
    }

    int somaDiagonal2 = 0;
    for(i=0; i<3; i++){
        somaDiagonal2 += mat[i][2-i];
    }
    if(somaDiagonal2 != somaReferencia){
        return 0;
    }

   return 1;
}

int main(){
    int mat[3][3] = {{6,1,8},{7,5,3},{2,9,4}};
    printf("Quadrado Magico? %d", quadradoMagico(mat));
    return 0;
}