#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tam 100
struct cliente{
    char id[20];
    int cc;
    float valor;
    char cVIP;
};

int ex1(char *nomeFB, char *nomeFT){
    FILE *fb, *ft;
    fb = fopen(nomeFB, "wb");
    ft = fopen(nomeFT, "r");
    if(fb == NULL){
        printf("erro ao abrir ficheiro binario\n");
        return 0;
    }
    if(ft == NULL){
        printf("erro ao abrir ficheiro texto\n");
        return 0;
    }
    struct cliente c[tam];
    int i=0;
    float media, soma = 0;

    while(fscanf(ft,"%s %d %f", c[i].id, &c[i].cc, &c[i].valor) == 3) {
        soma += c[i].valor;
        i++;
    }
    media = soma / (float) i;
    for(int j=0; j<i; j++){
        if(c[j].valor > media) {
            c[j].cVIP = 'S';
            fwrite(&c[j], sizeof(struct cliente), 1, fb);
        }
        else {
            c[j].cVIP = 'N';
            fwrite(&c[j], sizeof(struct cliente), 1, fb);
        }
    }
    fclose(fb);
    fclose(ft);
    return 1;

}


void le(char *nomeB){
    FILE *f;
    f = fopen(nomeB, "rb");
    struct cliente c;
    while(fread(&c, sizeof(struct cliente), 1, f)==1){
        printf("ID: %s, CC: %d, Valor: %f, VIP: %c\n", c.id, c.cc, c.valor, c.cVIP);
    }
}
int main(void) {
    ex1("mercearia.bin", "mercearia.txt");
    le("mercearia.bin");
    return 0;
}
