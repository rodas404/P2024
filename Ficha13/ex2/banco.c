
#include <stdio.h>
#include <string.h>
#include "banco.h"

// Escreve conteudo do ficheiro binario na consola
// O nome do ficheiro érecebido como parâmetro
void printFile(char *nomeF){
    cliente a;
    FILE *f;

    f = fopen(nomeF, "rb");
    if(f == NULL){
        printf("Erro no acesso ao ficheiro.\n"); return;
    }
    while(fread(&a, sizeof(cliente), 1, f) == 1)
        printf("%s - %s - %d - %d\n", a.nome, a.morada, a.conta, a.montante);
    fclose(f);
}

// Escreve tamanho do ficheiro binario e numero de clientes armazenados na consola
// O nome do ficheiro érecebido como parâmetro
void printDados(char *nomeF){
    FILE *f;

    f = fopen(nomeF, "rb");
    if(f == NULL){
        printf("Erro no acesso ao ficheiro.\n"); return;
    }
    fseek(f, 0, SEEK_END);
    printf("\nTamanho do ficheiro: %ld\n", ftell(f));
    printf("Numero de clientes: %ld\n", ftell(f) / sizeof(cliente));

    fclose(f);
}

// Corrige morada de um cliente armazenado no ficheiro
// Recebe nome do ficheiro, nome do cliente e nova morada
// Devolve 1 se a correcao for efetuada com sucesso, ou 0, caso contrario
int corrigeMorada(char *nomeF, char *nomeC, char *nMorada){
    cliente a;
    FILE *f;
    int flag = 0;
    f = fopen(nomeF, "r+b"); // abrir o ficheiro em modo de leitura e escrita
    if(f == NULL){
        printf("Erro no acesso ao ficheiro.\n"); return flag;
    }
    while(fread(&a, sizeof(cliente), 1, f) == 1){
        if(strcmp(a.nome, nomeC) == 0){
            strcpy(a.morada, nMorada);
            flag = 1;
            fseek(f, -sizeof(cliente), SEEK_CUR);
            fwrite(&a, sizeof(cliente), 1, f);
            break;
        }
    }
    fclose(f);
    return flag;
}

// Escreve conteudo do ficheiro binario na consola. A informação deve ser listada por ordem alfabética inversa
// O nome do ficheiro érecebido como parâmetro
void printFileInv(char *nomeF) {
    cliente a[20];
    int num = 0, i;

    FILE *f;

    f = fopen(nomeF, "rb");
    if(f == NULL){
        printf("Erro no acesso ao ficheiro.\n"); return;
    }
    while(fread(&a[num], sizeof(cliente), 1, f) == 1)
        num++;

    for(i=0; i<num; i++){
        for(int j= i+1; j<num; j++){
            if(strcmp(a[i].nome, a[j].nome) < 0) {
                cliente temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nClientes escritos de forma inversa:\n");
    for(i=0; i<num; i++)
        printf("%s - %d\n", a[i].nome, a[i].conta);

    printf("\n");

    fclose(f);
}


// Transfere montante entre 2 clientes
// Recebe nome do ficheiro, identificacaos clientes envolvidos na operacaa e montante a transferir
// Devolve 1 se a transferencia for efetuada com sucesso, ou 0, caso contrario
int transfere(char *nomeF, char *or, char *dest, int valor){
    cliente a[20];
    int num = 0, i, j, flag = 0;

    FILE *f;

    f = fopen(nomeF, "r+b");
    if(f == NULL){
        printf("Erro no acesso ao ficheiro.\n"); return 0;
    }
    while(fread(&a[num], sizeof(cliente), 1, f) == 1)
        num++;

    for(i=0; i<num; i++){
        if(strcmp(a[i].nome, or) == 0){
            flag = 1;
            if(a[i].montante - valor >= 0){
                a[i].montante -= valor;
            }
            else{
                printf("montante insuficiente na conta do cliente %s\n", or);
                fclose(f);
                return 0;
            }
            break;
        }
    }

    if(!flag){
        printf("cliente %s nao encontrado\n", or);
        fclose(f);
        return 0;
    }

    flag = 0;
    for(j=0; j<num; j++){
        if(strcmp(a[j].nome, dest) == 0){
            flag = 1;
            a[j].montante += valor;
            break;
        }
    }
    if(!flag){
        printf("cliente %s nao encontrado\n", dest);
        fclose(f);
        return 0;
    }

    fseek(f, 0, SEEK_SET);
    fwrite(a, sizeof(cliente), num, f);

    fclose(f);
    return 1;
}

// Elimina um cliente do ficheiro, mantendo a ordem alfabetica
// Recebe nome do ficheiro e nome do cliente a eliminar
// Devolve 1 se a eliminação for efetuada com sucesso, ou 0, caso contrario
int eliminaC(char *nomeF, char *nome){
    cliente a[20];
    int num = 0, i, flag = 0;

    FILE *f = fopen(nomeF, "rb");
    if(f == NULL){
        printf("Erro no acesso ao ficheiro.\n");
        return 0;
    }

    FILE *g = fopen("temp.dat", "wb");
    if(g == NULL){
        printf("Erro ao criar ficheiro temporario.\n");
        fclose(f);
        return 0;
    }

    while(fread(&a[num], sizeof(cliente), 1, f) == 1)
        num++;

    for(i = 0; i < num; i++){
        if(strcmp(a[i].nome, nome) != 0){
            if(fwrite(&a[i], sizeof(cliente), 1, g) != 1){
                printf("Erro ao escrever no ficheiro temporário.\n");
                fclose(f);
                fclose(g);
                remove("temp.dat");
                return 0;
            }
        } else {
            flag = 1; // Cliente encontrado e não será copiado para o ficheiro temporário
        }
    }

    fclose(f);
    fclose(g);

    if(flag){
        remove(nomeF);
        if(rename("temp.dat", nomeF) != 0){
            printf("Erro ao renomear ficheiro temporario.\n");
            return 0;
        }
    } else {
        remove("temp.dat");
        printf("Cliente %s nao encontrado.\n", nome);
        return 0;
    }

    return 1;
}