#include <stdio.h>
#include <string.h>

typedef struct artigo art;
struct artigo{
    char ref[10];
    int qtd;
    float preco;
};

void criarFicheiroBinario() {
    FILE *fp = fopen("artigos.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }
    float precoMedio = 168.6;
    fwrite(&precoMedio, sizeof(float), 1, fp);

    art artigos[] = {
            {"X12DF", 12, 23.5},
            {"VG56", 7, 341.9},
            {"LP34", 1, 12.0},
            {"KLM13", 102, 297.2}
    };
    fwrite(artigos, sizeof(art), 4, fp);
    fclose(fp);

    printf("Ficheiro binario criado com sucesso.\n");
}
int ex1(char* nomeF, int quant){
    FILE *f, *newF;
    f = fopen(nomeF, "rb+");
    newF = fopen("ex1.txt", "w");

    if(f == NULL || newF == NULL){
        printf("erro no acesso aos ficheiros\n");
        return -1;
    }

    art artigos;
    float precoMedio = 0;
    int total = 0;
    fseek(f, sizeof(float), SEEK_CUR);

    while(fread(&artigos, sizeof(art),1,f) == 1){
        if(artigos.qtd < quant){
            fprintf(newF, "%s %d\n",artigos.ref, artigos.qtd);
        }
        artigos.preco = artigos.preco + (artigos.preco * 0.1);
        fseek(f, -sizeof(art), SEEK_CUR);
        fwrite(&artigos, sizeof(art), 1, f);
        fseek(f, 0, SEEK_CUR);
        precoMedio += artigos.preco;
        total++;
    }
    precoMedio = precoMedio/ (float) total;
    fseek(f,0,SEEK_SET);
    fwrite(&precoMedio, sizeof(float), 1, f);
    fclose(f);
    fclose(newF);
    return 1;
}

int main(void) {
    //criarFicheiroBinario();
    ex1("artigos.bin", 10);
    return 0;
}
