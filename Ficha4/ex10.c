#include <stdio.h>
#include <string.h>
#define TAM 100

void apresentaSinonimos(char *s[][2], int nlinhas) {
    printf("Tabela de sinonimos:\n");
    for (int i = 0; i < nlinhas; i++) {
        printf("%s - %s\n", s[i][0], s[i][1]);
    }
}

char *encontraSinonimo(char *s[][2], int nlinhas, char *palavra){
    for(int i=0; i<nlinhas; i++){
        if(stricmp(palavra, s[i][0])==0)
            return s[i][1];
        else if(stricmp(palavra, s[i][1])==0)
            return s[i][0];
    }
    return NULL;
}

char* alfaMin(char *sin[][2], int tot_lin){
    char *pequena = sin[0][0];
    for(int i=0; i<tot_lin; i++){
        for(int j=0; j<2; j++){
            if(strcmp(sin[i][j], pequena)<0)
                pequena = sin[i][j];
        }
    }
    return pequena;
}

int aparece( char *tab[][2], int nlinhas){
    int nPalavras = 0;
    for(int i=0; i<nlinhas; i++){
        for(int j=0; j<2; j++){
           char *palavraAtual = tab[i][j];
            for(int k=i; k<nlinhas; k++){
                for(int l=0; l<2; l++){
                    if(k!=i || l!=j) {
                        if (strcmp(palavraAtual, tab[k][l]) == 0) {
                            nPalavras++;
                            break;
                        }
                    }
                }
            }
        }
    }
    return nPalavras;
}

void frase(char *sin[][2], int tot_lin){
    char frase[TAM];
    printf("\nFrase:");
    gets(frase);
    char *token = strtok(frase," ,;.");
    char* palavra;

    while(token != NULL){
        palavra = encontraSinonimo(sin,tot_lin,token);

        if(palavra != NULL){
            printf("A palavra %s e sinonimo de %s\n", palavra, token);
        }
        token = strtok(NULL, " ,.;");
    }
}

int main(){
    char *tabela[5][2] = {{"estranho", "bizarro"},{"desconfiar", "suspeitar"}, {"vermelho", "encarnado"}, {"duvidar", "desconfiar"}, {"carro", "automovel"}};
    apresentaSinonimos(tabela, 5);

    char palavra[TAM], *sinonimo, *pequena;
    printf("\nSinonimo a procurar:");
    gets(palavra);
    sinonimo = encontraSinonimo(tabela, 5, palavra);

    if(sinonimo==NULL)
        printf("A palavra %s nao tem nenhum sinonimo armazenado\n", palavra);
    else
        printf("%s tem como sinonimo %s\n", palavra, sinonimo);

    pequena= alfaMin(tabela, 5);
    printf("\nA palavra mais pequena armazenada e %s\n", pequena);

    int comum = aparece(tabela, 5);
    printf("\nNumero de palavras repetidas na tabela: %d\n", comum);

    frase(tabela, 5);

    return 0;
}