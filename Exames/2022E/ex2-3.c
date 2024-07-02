#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 40

typedef struct atleta no_atleta, *pno_atleta;
typedef struct classe no_classe, *pno_classe;

struct atleta {
    char nome[TAM];
    char categoria[TAM];  // Pode ter os valores: INFANTIL, JUNIOR, SENIOR
    pno_atleta prox_atleta;
};

struct classe {
    char nome_classe[TAM];
    pno_atleta lista_atletas;
    pno_classe prox_equipa;
};

pno_classe ex2(pno_classe c){
    if(c == NULL)
        return NULL;

    pno_classe senior, atual = c;
    int count, max = 0, empate;
    while(atual != NULL){
        pno_atleta atletas = atual->lista_atletas;
        count = 0;
        while(atletas != NULL){
            if(strcmp(atletas->categoria, "SENIOR") == 0)
                count++;
            atletas = atletas->prox_atleta;
        }
        if(count > max){
            max = count;
            senior = atual;
            empate = 0;
        }
        else if (count == max)
            empate = 1;

        atual = atual->prox_equipa;
    }
    if(empate){
        printf("empate\n");
        return NULL;
    }
    printf("a classe com mais seniores e a '%s'\n", senior->nome_classe);
    return senior;

}

pno_classe eliminaINF(pno_classe p, char * nomeC){
    pno_classe atual = p;
    while(atual != NULL){
        if(strcmp(atual->nome_classe, nomeC)==0){
            pno_atleta atletas = atual->lista_atletas;
            pno_atleta anterior = NULL;
            while(atletas != NULL){
                if(strcmp(atletas->categoria, "INFANTIL")==0){
                    if(anterior == NULL)
                        atual->lista_atletas = atletas->prox_atleta;
                    else
                        anterior->prox_atleta = atletas->prox_atleta;

                    pno_atleta temp = atletas;
                    atletas = atletas->prox_atleta;
                    free(temp);
                }
                else {
                    anterior = atletas;
                    atletas = atletas->prox_atleta;
                }
            }
            break;
        }
        atual = atual->prox_equipa;
    }

    atual = p;
    pno_classe aux = NULL;
    while(atual != NULL){
        if(atual->lista_atletas == NULL){
            if(aux == NULL)
                p = atual->prox_equipa;
            else
                aux->prox_equipa = atual->prox_equipa;
            pno_classe temp = atual;
            atual = atual->prox_equipa;
            free(temp);
        }
        else{
            aux = atual;
            atual = atual->prox_equipa;
        }
    }
    return p;
}

















//------powered by chatgpt
pno_classe replicarListaExemplo() {
    // Criar a lista de classes
    pno_classe classe1 = (pno_classe)malloc(sizeof(no_classe));
    pno_classe classe2 = (pno_classe)malloc(sizeof(no_classe));
    pno_classe classe3 = (pno_classe)malloc(sizeof(no_classe));

    // Inicializar a classe A
    strncpy(classe1->nome_classe, "Ases", TAM);
    classe1->lista_atletas = NULL;
    classe1->prox_equipa = classe2;

    // Inicializar a classe B
    strncpy(classe2->nome_classe, "Ganhamos a Brincar", TAM);
    classe2->lista_atletas = NULL;
    classe2->prox_equipa = classe3;

    strcpy(classe3->nome_classe, "Os Furacoes");
    classe3->lista_atletas = NULL;
    classe3->prox_equipa = NULL;

    // Adicionar atletas à classe A
    pno_atleta atleta1 = (pno_atleta)malloc(sizeof(no_atleta));
    strncpy(atleta1->nome, "Carlos", TAM);
    strncpy(atleta1->categoria, "INFANTIL", TAM);
    atleta1->prox_atleta = classe1->lista_atletas;
    classe1->lista_atletas = atleta1;

    pno_atleta atleta2 = (pno_atleta)malloc(sizeof(no_atleta));
    strncpy(atleta2->nome, "Ana", TAM);
    strncpy(atleta2->categoria, "INFANTIL", TAM);
    atleta2->prox_atleta = classe1->lista_atletas;
    classe1->lista_atletas = atleta2;

    pno_atleta atleta3 = (pno_atleta)malloc(sizeof(no_atleta));
    strncpy(atleta3->nome, "Pedro", TAM);
    strncpy(atleta3->categoria, "INFANTIL", TAM);
    atleta3->prox_atleta = classe1->lista_atletas;
    classe1->lista_atletas = atleta3;

    // Adicionar atletas à classe B
    pno_atleta atleta4 = (pno_atleta)malloc(sizeof(no_atleta));
    strncpy(atleta4->nome, "Maria", TAM);
    strncpy(atleta4->categoria, "SENIOR", TAM);
    atleta4->prox_atleta = classe2->lista_atletas;
    classe2->lista_atletas = atleta4;

    pno_atleta atleta5 = (pno_atleta)malloc(sizeof(no_atleta));
    strncpy(atleta5->nome, "Joao", TAM);
    strncpy(atleta5->categoria, "SENIOR", TAM);
    atleta5->prox_atleta = classe2->lista_atletas;
    classe2->lista_atletas = atleta5;

    pno_atleta atleta6 = (pno_atleta)malloc(sizeof(no_atleta));
    strncpy(atleta6->nome, "Tome", TAM);
    strncpy(atleta6->categoria, "SENIOR", TAM);
    atleta6->prox_atleta = classe2->lista_atletas;
    classe2->lista_atletas = atleta6;


    pno_atleta atleta7 = (pno_atleta)malloc(sizeof(no_atleta));
    strncpy(atleta7->nome, "Jose", TAM);
    strncpy(atleta7->categoria, "JUNIOR", TAM);
    atleta7->prox_atleta = classe3->lista_atletas;
    classe3->lista_atletas = atleta7;

    pno_atleta atleta8 = (pno_atleta)malloc(sizeof(no_atleta));
    strncpy(atleta8->nome, "Marco", TAM);
    strncpy(atleta8->categoria, "INFANTIL", TAM);
    atleta8->prox_atleta = classe3->lista_atletas;
    classe3->lista_atletas = atleta8;

    pno_atleta atleta9 = (pno_atleta)malloc(sizeof(no_atleta));
    strncpy(atleta9->nome, "Vasco", TAM);
    strncpy(atleta9->categoria, "SENIOR", TAM);
    atleta9->prox_atleta = classe3->lista_atletas;
    classe3->lista_atletas = atleta9;

    // Retornar o ponteiro para o início da lista de classes
    return classe1;
}

// Função para imprimir a estrutura de dados
void imprimirEstrutura(pno_classe lista) {
    while (lista != NULL) {
        printf("Classe: %s\n", lista->nome_classe);
        pno_atleta atleta = lista->lista_atletas;
        while (atleta != NULL) {
            printf("\tAtleta: %s, Categoria: %s\n", atleta->nome, atleta->categoria);
            atleta = atleta->prox_atleta;
        }
        lista = lista->prox_equipa;
    }
}

void liberarMemoria(pno_classe lista) {
    while (lista != NULL) {
        pno_classe classe_a_liberar = lista;
        pno_atleta atleta = lista->lista_atletas;
        while (atleta != NULL) {
            pno_atleta atleta_a_liberar = atleta;
            atleta = atleta->prox_atleta;
            free(atleta_a_liberar);
        }
        lista = lista->prox_equipa;
        free(classe_a_liberar);
    }
}

int main() {

    pno_classe lista = replicarListaExemplo();

    ex2(lista);
    lista = eliminaINF(lista, "Ases");
    imprimirEstrutura(lista);

    liberarMemoria(lista);

    return 0;
}
