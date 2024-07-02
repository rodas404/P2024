#include <stdio.h>
#define TAM 50
typedef struct atg artigo;
struct atg{
    char nome[TAM];
    int  peso;
    int  tempo_confecao;
    struct{
        int dia, mes, ano;
    }introducao;
};
void criarFicheiroBinario() {
    FILE *fp = fopen("artigos.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }
    artigo art[] = {
            {"Bola de Berlim", 1, 20, {10,11,2023}},
            {"Pastel de Nata", 2, 15, {12,11,2023}},
            {"Tarte de Maçã", 3, 30, {13,11,2023}},
            {"Pão de Ló", 4, 25, {14,11,2023}},
            {"Queijada", 5, 10, {15,11,2023}}
    };

    fwrite(art, sizeof(artigo), 5, fp);
    fclose(fp);
    printf("Ficheiro binario criado com sucesso.\n");
}

int ex1(char *nomeFB, char* nomeFT, int ano){
    FILE *fb, *ft;
    fb = fopen(nomeFB, "rb");
    ft = fopen(nomeFT, "w");
    if(fb == NULL || ft == NULL){
        printf("erro\n");
        return 0;
    }
    artigo artgs[TAM];
    int i = 0, soma = 0;
    float media;

    while(fread(&artgs[i], sizeof(artigo), 1, fb) == 1){
        soma += artgs[i].peso;
        i++;
    }
    media = (float) soma / (float) i;
    for(int j = 0; j < i; j++){
        if((float)artgs[j].peso >= media && artgs[j].introducao.ano == ano)
            fprintf(ft, "%s %d\n",artgs[j].nome, artgs[j].tempo_confecao);
    }
    fclose(ft);
    fclose(fb);
    return 1;
}

int main(void) {
    criarFicheiroBinario();
    ex1("artigos.bin", "artigos.txt", 2023);
    return 0;
}
