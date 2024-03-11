#include <stdio.h>

void espiral(int dim, int mat[][dim]){
    int cima = 0, esquerda = 0, direita = dim - 1, baixo = dim - 1;

    while (cima <= baixo && esquerda <= direita) {
        // esquerda para direita
        for (int i = esquerda; i <= direita; i++)
            printf("%d, ", mat[cima][i]);
        cima++;

        // onde ficou para baixo
        for (int i = cima; i <= baixo; i++)
            printf("%d, ", mat[i][direita]);
        direita--;

        // onde ficou para a esquerda
        if (cima <= baixo) {
            for (int i = direita; i >= esquerda; i--)
                printf("%d, ", mat[baixo][i]);
            baixo--;
        }

        // onde ficou para cima
        if (esquerda <= direita) {
            for (int i = baixo; i >= cima; i--)
                printf("%d, ", mat[i][esquerda]);
            esquerda++;
        }
    }
}

int main(){
    int M;
    printf("Qual o tamanho MxM da matriz?");
    scanf("%d", &M);

    int mat[M][M], i, j;
    for(i=0; i<M; i++){
        for(j=0; j<M; j++){
            printf("Valor %d da linha %d:", j, i);
            scanf("%d",&mat[i][j]);
        }
        putchar('\n');
    }

    printf("\nComo ficou a matriz:\n");
    for(i=0; i<M; i++){
        for(j=0; j<M; j++){
            printf("%d\t",mat[i][j]);
        }
        putchar('\n');
    }
    printf("\nComo fica a espiral:\n");
    espiral(M,mat);
    return 0;
}
