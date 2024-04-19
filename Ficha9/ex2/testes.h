//
// Created by footr on 18/04/2024.
//

#ifndef FICHA9_TESTES_H
#define FICHA9_TESTES_H

struct sala{
    char id[10];
    int total;
};
typedef struct pessoa no, *pno;
struct pessoa{
    char nome[100], num[20]; // Nome e número do aluno
    struct sala* p;
    pno prox;
};

void mostraInfo(pno p, struct sala* s, int tam);
void mostraMaxSala(pno p, struct sala* s, int tam);
int mesmaSala(pno p, char* aluno1, char* aluno2);
pno adicionaAl(pno lista, struct sala *s, int tot, char *nome, char *num);
struct sala* transfereAl(pno lista, struct sala *s, int *tot, char *nome, char *nSala);
pno criaAlunos(struct sala* s);
struct sala* criaSalas(int *tot);


#endif //FICHA9_TESTES_H
