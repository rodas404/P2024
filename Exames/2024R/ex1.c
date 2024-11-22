#include <stdio.h>


typedef struct a autor;
struct a{
char nome[100];
int idA;
int nLivros;
};

void criarFicheiroBinario() {
    FILE *fp = fopen("livraria.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    int numAutores = 3;
    fwrite(&numAutores, sizeof(int), 1, fp);

    autor autores[] = {
            {"Artur Pires", 12, 0},
            {"Carlos Vaz", 37, 0},
            {"Luisa Pais", 15, 0}
    };
    fwrite(autores, sizeof(autor), numAutores, fp);
    fclose(fp);

    printf("Ficheiro binario criado com sucesso.\n");
}

int ex1(char *nomeFB, char *nomeFT){
    FILE *ft, *fb;
    ft = fopen(nomeFT, "r");
    fb = fopen(nomeFB, "rb+");
    if(ft == NULL ) {
        printf("erro texto\n");
        return 0;
    }
    if(fb == NULL ){
        printf("erro binario\n");
        return 0;
    }

    int numAutores;

    fread(&numAutores, sizeof(int),1, fb);
    autor a[numAutores];
    for(int i=0; i<numAutores; i++)
        fread(&a[i], sizeof(autor), 1, fb);

    float medias[numAutores];
    char titulo[50];
    int id;
    float preco;

    for(int i = 0; i < numAutores; i++) {
        medias[i] = 0.0;
    }

    while(fscanf(ft, "%[^#] # %d # %f\n", titulo, &id, &preco) == 3){
        printf("li: %s # %d %f\n", titulo, id, preco);
        for(int i=0; i<numAutores; i++){
            if(id == a[i].idA){
                medias[i] += preco;
                a[i].nLivros++;
            }
        }
    }

    for(int i=0; i<numAutores; i++){
        printf("%d livros\n", a[i].nLivros);
        medias[i] = medias[i] / (float) a[i].nLivros;
        printf("media do id '%d': %f\n", a[i].idA, medias[i]);
    }
    fseek(fb, sizeof(int), SEEK_SET);
    for(int i=0; i<numAutores; i++){
        fwrite(&a[i], sizeof(autor), 1, fb);
    }
    fclose(fb);
    fclose(ft);
    return 1;

}

void le(char *nome){
    FILE *f;
    f = fopen(nome, "rb");

    int numAutores;

    fread(&numAutores, sizeof(int),1, f);
    autor a[numAutores];
    for(int i=0; i<numAutores; i++) {
        fread(&a[i], sizeof(autor), 1, f);
        printf("%s - %d - %d\n", a[i].nome, a[i].idA, a[i].nLivros);
    }
    fclose(f);

}
int main(void) {
    //criarFicheiroBinario();
    //ex1("livraria.bin", "livros.txt");
    le("livraria.bin");
    return 0;
}
