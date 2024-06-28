#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {int h, m;} tempo;
typedef struct Voo voo;
struct Voo{
    char codigo[6]; // código do voo
    char destino[4]; // código do destino
    int emTerra; // sim = 1; não = 0;
    tempo t; // hora de partida
};
void criarFicheiroBinario() {
    FILE *fp = fopen("voo.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }
    voo voos[] = {
            {"ST123", "FNC", 1, {07, 25}},
            {"AP434", "FAO", 1, {18, 35}},
            {"AP435", "FNC", 1, {9, 15}},
            {"AP535", "OPO", 1, {11, 45}},
            {"RA342", "DUB", 1, {12, 15}},
            {"EJ262", "BCN", 1, {10, 25}},
            {"RA343", "DUB", 1, {11, 15}}
    };

    fwrite(voos, sizeof(voo), 7, fp);
    fclose(fp);
    printf("Ficheiro binario criado com sucesso.\n");
}

voo* ex1(char* nomeF, tempo t, char* dest, int* tam){
    FILE *f;
    f = fopen(nomeF, "rb+");
    if(f == NULL){
        printf("erro ao abrir o ficheiro\n");
        return NULL;
    }
    voo voos, *voosDestino = NULL;
    (*tam)=0;
    while(fread(&voos, sizeof(voo), 1,f) == 1){
        if(voos.t.h > t.h || (voos.t.h == t.h && voos.t.m > t.m)){
            voos.emTerra = 0;
            fseek(f, -sizeof(voo), SEEK_CUR);
            fwrite(&voos, sizeof(voo), 1, f);
            fseek(f, 0, SEEK_CUR);
            printf("Voo '%s' alterado\n", voos.codigo);
        }
        if(strcmp(voos.destino, dest) == 0){
            voosDestino = realloc(voosDestino, (*tam +1)*sizeof(voo));
            if(voosDestino == NULL){
                printf("erro de alocacao de memoria\n");
                return NULL;
            }
            voosDestino[*tam] = voos;
            (*tam)++;
        }
    }
    fclose(f);
    return voosDestino;
}

int main(void) {
    criarFicheiroBinario();

    tempo t = {18, 34};
    int tam;
    voo* voosDestino = ex1("voo.bin", t, "DUB", &tam);

    if(voosDestino != NULL){
        for(int i = 0; i < tam; i++){
            printf("Voo: %s, Destino: %s\n",voosDestino[i].codigo, voosDestino[i].destino);
        }
        free(voosDestino);
    }

    return 0;
}
