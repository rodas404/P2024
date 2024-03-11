#include <stdio.h>

void averagePooling(int m, int mat1[][m], float mat2[][m/2]){
    float soma, media;
    for(int i=0; i<m; i+=2){
        for(int j=0; j<m; j+=2){
            soma = 0;
            for(int l=i; l<i+2; l++){
                for(int k=j; k<j+2; k++){
                    soma += mat1[l][k];
                }
            }
            media = soma/4;
            mat2[i/2][j/2]=media;
        }
    }
}

int main(){
    int m;
    printf("Qual a dimensao MxM da matriz?");
    scanf("%d", &m);

    int mat1[m][m], i, j;
    float mat2[m/2][m/2];
    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            printf("%d valor da linha %d:",j+1,i+1);
            scanf("%d",&mat1[i][j]);
        }
        putchar('\n');
    }

    averagePooling(m, mat1, mat2);
    printf("Resultado:\n");
    for(i=0; i<m/2; i++){
        for(j=0; j<m/2; j++){
            printf("%.1f ",mat2[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
