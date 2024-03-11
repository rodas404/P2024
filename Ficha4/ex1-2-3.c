#include <stdio.h>

void printMat(int nLin, int nCol, int m[][nCol]){
    int i, j;

    for(i=0; i<nLin; i++){
        for(j=0; j<nCol; j++)
            printf("%d\t", m[i][j]);
        putchar('\n');
    }
}
void calcMediaCol(int nLin, int nCol, int m[][nCol], int* iMin, int* iMax){
    int media,soma, maxMedia=0, minMedia=100;
    for(int i=0; i<nCol; i++){
        soma = 0;
        for(int j=0; j<nLin; j++){
            soma += m[j][i];
        }
        media = soma/nLin;
        if(media > maxMedia){
            maxMedia = media;
            *iMax = i;
        }
        if(media < minMedia){
            minMedia=media;
            *iMin = i;
        }
    }
}

void tMat(int n, int mat[][n]){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            temp = mat[i][j];
            mat[i][j]= mat[j][i];
            mat[j][i] = temp;
        }
    }
}

int main() {

    int mat1[3][3] = {{1,2,3},{7,8,9},{12,13,14}};
    int mat2[2][5] = {{10,2,13,4,8},{5, 9, 12, 1, 0}};

    int a=-1,b=-1;

    printf("Mat 1:\n");
    printMat(3, 3, mat1);
    printf("\nMat 2:\n");
    printMat(2, 5, mat2);

    calcMediaCol(2, 5, mat2, &a, &b);
    printf("\n\nCol. com menor media: %d\nCol. com maior media: %d\n", a, b);

    tMat(3, mat1);
    printf("\nMat 1 Transposta:\n");
    printMat(3, 3, mat1);
    return 0;
}