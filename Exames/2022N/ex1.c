#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cliente cl;
struct cliente{
    int id; // id numérico do cliente
    char cc[10]; // Número do cartão de cidadão
    float valor; // Valor gasto em compras desde o início do mês
    float v_divida; // Valor em divida desde o início do mês
    char cCert; // Cliente certificado (S/N)
};

void criarFicheiroBinario() {
    FILE *fp = fopen("clientes.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    int numClientes = 5;
    fwrite(&numClientes, sizeof(int), 1, fp);
    int numCertificados = 0;
    fwrite(&numCertificados, sizeof(int), 1, fp);

    cl clientes[] = {
            {1, "111", 500, 100, 'X'},
            {2, "222", 123, 400, 'X'},
            {3, "333", 231, 333, 'X'},
            {4, "444", 800, 0, 'X'},
            {5, "555", 200, 80, 'X'}
    };
    fwrite(clientes, sizeof(cl), numClientes, fp);


    fclose(fp);

    printf("Ficheiro binario criado com sucesso.\n");
}

void ex1(char* nomeF){
    FILE *f;
    f = fopen(nomeF, "rb+");
    if(f == NULL){
        printf("erro\n");
        return;
    }
    int numClientes, numCertificados;
    cl clientes;
    fread(&numClientes, sizeof(int), 1, f);
    fread(&numCertificados, sizeof(int), 1, f);
    printf("%d - %d\n", numClientes,numCertificados);

    for(int i=0; i<numClientes; i++){
        fread(&clientes, sizeof(cl),1,f);
        printf("%d - %s - %f -%f - %c\n", clientes.id, clientes.cc, clientes.valor, clientes.v_divida, clientes.cCert);

        if(clientes.v_divida < 0.1 * clientes.valor) {
            clientes.cCert = 'S';
            numCertificados++;
        }
        else
            clientes.cCert = 'N';

        strcpy(clientes.cc, "NA");
        fseek(f, -sizeof(cl), SEEK_CUR);
        fwrite(&clientes, sizeof(cl), 1, f);
        fseek(f, 0, SEEK_CUR);
    }
    fseek(f, sizeof(int), SEEK_SET);
    fwrite(&numCertificados, sizeof(int), 1,f);
    fclose(f);
}
int main(void) {
    // criarFicheiroBinario();
    ex1("clientes.bin");
    return 0;
}
