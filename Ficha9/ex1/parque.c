#include <stdlib.h>
#include <stdio.h>

#include "parque.h"


// Liberta todo o espaco ocupado pela estrutura dinamica

void libertaTudo(pCliente p){
    pCliente auxC;
    pAcesso atualA;

    while(p != NULL){
        while(p->lista != NULL){
            atualA = p->lista;
            p->lista = p->lista->prox;
            free(atualA);
        }
        auxC = p;
        p = p->prox;
        free(auxC);
    }
}
// Cria e devolve uma estrutura dinamica exemplo para teste das funções deste exercicio
// A informação criada é igual ao exemplo ilustrado na ficha pratica 9

pCliente criaExemploED(){
    int totC = 3, i, j, k=-1;
    cliente a[] = {{13, 2, NULL, NULL},{17,1,NULL,NULL},{22,3,NULL,NULL}};
    acesso b[] = {{{10,20},{11,52},NULL}, {{14,30},{17,2},NULL}, {{10,50},{-1,-1},NULL},
                  {{9,11},{9,12},NULL},{{10,5},{12,0},NULL},{{14,33},{-1,-1},NULL}};

    pCliente lista = NULL, novoC;
    pAcesso novoA;

    for(i=0; i<totC; i++){
        k+=a[i].contador;
    }
    for(i=totC-1; i>=0; i--){
        novoC = malloc(sizeof(cliente));
        if(novoC == NULL){
            libertaTudo(lista);
            return NULL;
        }
        *novoC = a[i];
        novoC->prox = lista;
        lista = novoC;
        for(j=0; j<novoC->contador; j++){
            novoA = malloc(sizeof(acesso));
            if(novoA == NULL){
                libertaTudo(lista);
                return NULL;
            }
            *novoA = b[k--];
            novoA->prox = novoC->lista;
            novoC->lista = novoA;
        }
    }
    return lista;
}


// Recebe ponteiro para o inicio da estrutura dinamica
// Escreve toda a informação armazenada (clientes e respetivos acessos)
void mostraTudo(pCliente p){
    pAcesso atualA;

    while(p != NULL){
        printf("\nUtilizador com id %d efetuou %d acessos\n", p->id, p->contador);
        atualA = p->lista;
        while(atualA != NULL){
            printf("Entrou as %2.2d:%2.2d. ", atualA->in.h, atualA->in.m);
            if(atualA->out.h == -1)
                printf("Ainda nao saiu do parque\n");
            else
                printf("Saiu as %2.2d:%2.2d\n", atualA->out.h, atualA->out.m);
            atualA = atualA->prox;
        }
        p = p->prox;
    }
}


// Recebe ponteiro para o inicio da estrutura dinamica
// Devolve numero de clientes que se encontram no parque (têm uma utilização em aberto)
int dentroParque(pCliente p){
    int dentro = 0;
    pAcesso atualA;
    while(p != NULL){
        atualA = p->lista;
        while(atualA != NULL){
            if(atualA->out.h == -1)
                dentro++;
            atualA = atualA->prox;
        }
        p = p->prox;
    }
    return dentro;
}


// Recebe ponteiro para o inicio da estrutura dinamica
// Devolve numero de utilizacoes completas (numero de acessos com entrada e saida registadas)
int utilCompletas(pCliente p){
    int completo = 0;
    pAcesso atualA;
    while(p != NULL){
        atualA = p->lista;
        while(atualA != NULL){
            if(atualA->out.h != -1)
                completo++;
            atualA = atualA->prox;
        }
        p = p->prox;
    }
    return completo;
}

// Recebe ponteiro para o inicio da estrutura dinamica e endereço de variável inteira
// Devolve id do cliente que passou mais minutos no parque e coloca esse número de minutos na variável referenciada pelo segundo parametro
int maisMinutos(pCliente p, int *m){
    *m = 0;
    int id = -1, maxM = 0, min;
    pAcesso atualA;

    while(p != NULL){
        atualA = p->lista;
        min = 0;
        while(atualA != NULL){
            if(atualA->out.h != -1){
                min += (atualA->out.h * 60 + atualA->out.m) - (atualA->in.h * 60 + atualA->in.m);
            }
            atualA = atualA->prox;
        }
        if(maxM < min){
            maxM = min;
            id = p->id;
        }
        p = p->prox;
    }
    (*m) = maxM;
    return id;
}

pCliente eliminaCliente(pCliente p, int id){
    if (p == NULL) {
        return p;
    }

    pCliente atual = p, anterior = NULL;
    pAcesso atualA;

    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        while (atual->lista != NULL) {
            atualA = atual->lista;
            atual->lista = atual->lista->prox;
            free(atualA);
        }

        if (anterior == NULL)
            p = atual->prox;
        else
            anterior->prox = atual->prox;

        printf("Cliente %d removido da lista com sucesso\n", atual->id);
        free(atual);

    }
    return p;
}

pCliente eliminaAcessos(pCliente p){
    pCliente auxC, auxCant;
    pAcesso atualA, atualAant;
    auxC = p;
    auxCant = NULL;
    while(auxC != NULL)
    {
        //Para cada elemento da lista principal avalia os elementos da lista secundária
        atualA = auxC->lista;
        atualAant = NULL;
        while(atualA!= NULL && !(atualA->out.h==-1 && atualA->out.m==-1))
        {
            atualAant = atualA;
            atualA = atualA->prox;
        }
        if(atualA == NULL) //Não encontrou nenhum elemento em aberto na lista secundária
        {
            auxCant = auxC;
            auxC = auxC->prox;
        }
        else if(atualAant == NULL) //a lista secundária só tem um acesso e está em aberto - por isso não chega a entrar no while
        {
            auxC->contador--;
            auxC->lista=NULL;
            free(atualA);
            //tenho também de eliminar o nó da lista principal porque não tem acessos
            if(auxCant == NULL) //se o elemento da lista principal for o primeiro da lista
                p = auxC->prox;
            else//senão for o primeiro da lista
                auxCant->prox = auxC->prox;
            free(auxC);
        }
        else //caso geral
        {
            atualAant->prox = atualA->prox;
            free(atualA);
            auxC->contador--;//atualiza contador
            auxCant = auxC;//passa para o próximo elemento da lista principal
            auxC = auxC->prox;
        }
    }
    return p;
}

// Recebe ponteiro para o inicio da estrutura dinamica, id de um cliente e hora de ativação da cancela
// Devolve ponteiro para inicio da estrutura dinamica depois de atualizar o registo do cliente com este novo acesso
pCliente acessoParque(pCliente p, int id, hora x){
    pCliente atualC = p, antC;
    while(atualC != NULL && atualC->id != id){
        antC = atualC;
        atualC = atualC->prox;
    }

    if(atualC == NULL){
        pCliente novo = malloc(sizeof(cliente));
        novo->id = id;
        novo->contador = 1;

        novo->lista = malloc(sizeof(acesso));
        novo->lista->in = x;

        hora saida = {-1,-1};
        novo->lista->out = saida;
        novo->lista->prox = NULL;

        if(antC != NULL) {
            printf("Criei um novo cliente %d no fim da lista\n",novo->id);
            antC->prox = novo;
        }
        else {
            printf("Criei um novo cliente %d no inicio da lista\n",novo->id);
            p = novo;
        }

        novo->prox = NULL;
    }
    else{
        pAcesso atualA = atualC->lista, antA;
        while(atualA != NULL && atualA->out.h != -1) {
            antA = atualA;
            atualA = atualA->prox;
        }
        if(atualA != NULL){
            printf("Atualizei o registo do cliente %d\n", atualC->id);
            atualA->out = x;
        }
        else{
            atualC->contador++;
            pAcesso novo = malloc(sizeof(acesso));
            novo->in = x;
            hora saida = {-1,-1};
            novo->out = saida;
            novo->prox = NULL;
            if(antA != NULL){
                printf("Criei um novo estacionamento ao cliente %d no fim da lista\n", atualC->id);
                antA->prox = novo;
            }
            else{
                printf("Criei um novo estacionamento ao cliente %d no inicio da lista\n", atualC->id);
                atualC->lista = novo;
            }

        }
    }
    return p;
}

