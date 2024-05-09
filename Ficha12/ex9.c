#include <stdio.h>
#include <stdlib.h>


typedef struct aluno no, *pno;
struct aluno{
    int id;
    float nota;
    pno prox;
};

// Versão A
// Recebe nome de ficheiro de texto com notas de alunos
// Apresenta na consola o número de alunos e número de provas
void printDadosA(char *nomeF){
    FILE *f;
    int a, b;

    f = fopen(nomeF, "r");
    if(f == NULL){ printf("Erro no acesso ao ficheiro\n"); return;}

    while(fgetc(f) != ':')  // Procurar o caracter relevante -> ':'
        ;
    fscanf(f, "%d", &a);    // A seguir está um inteiro

    while(fgetc(f) != ':')  // Voltar a procurar o caracter relevante -> ':'
        ;
    fscanf(f, "%d", &b);    // A seguir está o outro inteiro

    fclose(f);
    printf("Versao A: Alunos: %d\tProvas: %d\n", a, b);
}

// Versão B
// Recebe nome de ficheiro de texto com notas de alunos
// Apresenta na consola o número de alunos e número de provas
void printDadosB(char *nomeF){
    FILE *f;
    int a, b;

    f = fopen(nomeF, "r");
    if(f == NULL){
        printf("Erro no acesso ao ficheiro\n"); return;
    }

    fscanf(f, " %*[^:] : %d", &a);
    fscanf(f, " %*[^:] : %d", &b);

    fclose(f);
    printf("Versao B: Alunos: %d\tProvas: %d\n", a, b);
}

// Versão C
// Recebe nome de ficheiro de texto com notas de alunos
// Apresenta na consola o número de alunos e número de provas
void printDadosC(char *nomeF){
    FILE *f;
    int a, b;

    f = fopen(nomeF, "r");
    if(f == NULL){
        printf("Erro no acesso ao ficheiro\n"); return;
    }

    fscanf(f, " Numero de alunos: %d", &a);
    fscanf(f, " Numero de provas: %d", &b);

    fclose(f);
    printf("Versao C: Alunos: %d\tProvas: %d\n", a, b);
}

// Recebe nome de ficheiro de texto com notas de alunos
// Apresenta na consola as notas finais de cada aluno
void calculaNotasFinais(char *nomeF){
    FILE *f;
    int nAlunos, nProvas, i, j;
    f = fopen(nomeF, "r");
    if(f == NULL){
        printf("Erro no acesso ao ficheiro\n"); return;
    }
    fscanf(f, " %*[^:] : %d", &nAlunos);
    fscanf(f, " %*[^:] : %d", &nProvas);

    int notas[nProvas], pesos[nProvas];
    while(fgetc(f) != ':')  // Procurar o caracter relevante -> ':'
        ;
    for(i=0; i<nProvas; i++)
        fscanf(f, " %d", &pesos[i]);

    printf("\nNumero de alunos: %d\n", nAlunos);
    for(i=0; i<nAlunos; i++) {
        float notaFinal = 0;

        while(fgetc(f) != ':')  // Procurar o caracter relevante -> ':'
            ;

        for (j = 0; j < nProvas; j++)
            fscanf(f, " %d", &notas[j]);

        for (j = 0; j < nProvas; j++)
            notaFinal += (float) notas[j] * (float) pesos[j] / 100;

        printf("Aluno %d: %.1f\n", i+1, notaFinal);
    }



    fclose(f);
}

pno criaLista(char *nomeF){
    FILE *f;
    pno lista = NULL, ultimo = NULL;
    int nAlunos, nProvas, i, j;
    f = fopen(nomeF, "r");
    if(f == NULL){
        printf("Erro no acesso ao ficheiro\n"); return lista;
    }

    fscanf(f, " %*[^:] : %d", &nAlunos);
    fscanf(f, " %*[^:] : %d", &nProvas);

    int notas[nProvas], pesos[nProvas];
    fscanf(f, " %*[^:] : ");  // Ignorar o texto até o ':'
    for(i=0; i<nProvas; i++)
        fscanf(f, " %d", &pesos[i]);

    for(i=0; i<nAlunos; i++){
        float notaFinal = 0;

        while(fgetc(f) != ':')  // Procurar o caracter relevante -> ':'
            ;

        for(j=0; j<nProvas; j++)
            fscanf(f, " %d", &notas[j]);

        for(j=0; j<nProvas; j++)
            notaFinal += (float) notas[j] * (float) pesos[j]/100;

        pno novo;
        novo = malloc(sizeof(no));
        if(novo == NULL)
            return lista;

        novo->id = i+1;
        novo->nota = notaFinal;
        novo->prox = NULL;

        if(lista == NULL){
            lista = novo;
            ultimo = novo;
        } else{
            ultimo->prox = novo; //mega lógica do copilot que por incrivel que pareça funciona mesmo
            ultimo = novo;
        }
    }
    return lista;
}

void mostraLista(pno p){
    printf("\n\nVersao lista\n");
    while(p != NULL){
        printf("Aluno %d: %.1f\n", p->id, p->nota);
        p = p->prox;
    }
}

void libertaLista(pno lista){
    pno aux = NULL;
    while(lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}
int main(){

    // 3 versões para mostrar o número de alunos e de provas
    printDadosA("notas_ex9.txt");
    printDadosB("notas_ex9.txt");
    printDadosC("notas_ex9.txt");

    calculaNotasFinais("notas_ex9.txt");

    pno lista;
    lista = criaLista("notas_ex9.txt");
    mostraLista(lista);

    libertaLista(lista);
    return 0;
}