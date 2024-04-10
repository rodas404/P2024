#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa no, *pno;

struct pessoa{
    char nome[100];
    int id;
    float peso, altura, imc;
    pno prox;
};


// Função auxiliar para obter dados do utilizador e prencher um novo nó a inserir na lista
// Recebe endereço do nó a preencher
void getDados(pno p, pno lista){
    int id;
    pno temp;
    printf("Nome:");
    scanf(" %[^\n]", p->nome);

    do {
        printf("ID:");
        scanf("%d", &id);
        temp = lista;
        while(temp != NULL){
            if(temp->id == id){
                printf("ID ja inserido\n");
                break;
            }
            temp = temp->prox;
        }
    }while(temp!=NULL);
    p->id = id;

    printf("Peso:");
    scanf("%f", &(p->peso));
    printf("Altura:");
    scanf("%f", &(p->altura));
    printf("\n");
    p->imc = p->peso / (p->altura * p->altura);
    p->prox = NULL;
}

// Função para adicionar um novo nó à lista
// Recebe ponteiro de lista e devolve ponteiro de lista depois da inserção
// Esta função não está de acordo com o pedido no enunciado (2b) e tem que ser corrigida em 2 pontos:
// 1. Insere o novo nó no início da liste e não no final
// 2. Não valida se o ID é único. Esta validação poderá ser feita diretamente na função GetDados(), mas,
// para isso, terá que receber o ponteiro de lista como parâmetro adicional
pno addLista(pno lista){
    pno novo, aux;

    novo = malloc(sizeof(no));
    if(novo == NULL)
        return lista;
    getDados(novo, lista);
    if(lista == NULL)
        lista = novo;
    else{
        aux = lista;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return lista;
}

// Função que mostra o conteúdo da lista
// Recebe ponteiro de lista como parâmetro
void mostraLista(pno lista){
    while (lista != NULL){
        printf("%d - %s\n", lista->id, lista->nome);
        printf("P: %.1f\tA: %.1f\tIMC: %.2f\n\n", lista->peso, lista->altura, lista->imc);
        lista = lista->prox;
    }
}
pno eliminaKNos(pno lista, int k){
    pno anterior = NULL, atual, temp;
    //verificar o tamanho da lista
    int tam = 0;
    atual = lista;
    if(atual == NULL){
        printf("lista vazia\n");
        return lista;
    }
    while(atual != NULL) {
        atual = atual->prox;
        tam++;
    }
    if (tam<k){
        printf("lista com nos insuficientes\n");
        return lista;
    }

    //processo principal
    atual = lista;
    for(int i=0; i<tam-k; i++){
        anterior = atual;
        atual = atual->prox;
    }
    while(atual!=NULL){
        temp = atual;
        atual = atual->prox;
        printf("ID %d eliminado com sucesso\n", temp->id);
        free(temp);
    }
    if(anterior != NULL)
        anterior->prox = NULL;
    else
        lista = NULL;

    return lista;
}

// Função para atualizar o peso de uma das pessoas
// Recebe ponteiro de lista, id da pessoa a atualizar e novo peso
// Deve tambem ser atualizado o imc
void atualizaPeso(pno lista, int id, float novoPeso){
    while(lista != NULL){
        if(lista->id==id){
            lista->peso = novoPeso;
            lista->imc = lista->peso / (lista->altura * lista->altura);
            printf("Atualizacao do id %d bem sucedida\n", lista->id);
            break;
        }
        else
            lista = lista->prox;
    }
    if(lista == NULL)
        printf("ID %d nao encontrado\n", id);
}

// Função para eliminar uma pessoa da lista
// Recebe ponteiro de lista e id da pessoa a eliminar
// Devolve ponteiro de lista depois da eliminação
pno elimina(pno lista, int id){
    pno atual, anterior = NULL;
    atual = lista;
    while(atual != NULL && atual->id != id){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL) {
        printf("ID a eliminar nao encontrado\n");
        return lista;
    }
    if(anterior == NULL)
        lista = atual->prox;
    else
        anterior->prox = atual->prox;

    printf("ID %d eliminado\n", atual->id);
    free(atual);
    return lista;
}

pno eliminaIMC(pno lista, float imc_limite){
    pno atual = lista, anterior = NULL, proximo = NULL;
    while(atual != NULL){
        if(atual->imc > imc_limite){
            if (anterior == NULL)
                lista = atual->prox;
            else
                anterior->prox = atual->prox;

            proximo = atual->prox;
            printf("ID %d eliminado (imc = %f)\n", atual->id, atual->imc);
            free(atual);
            atual = proximo;
        }
        else {
            anterior = atual;
            atual = atual->prox;
        }
    }
    return lista;
}

void freeLista(pno lista){
    pno temp;
    while(lista != NULL){
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

int main(){
    pno lista = NULL;   // Criação do ponteiro de lista
    int id, k, op;
    float novoPeso, imc;

    do{
        printf("1. Introduzir novos nos\n");
        printf("2. Ver nos\n");
        printf("3. Atualizar no\n");
        printf("4. Elimina no\n");
        printf("5. Elimina limite imc\n");
        printf("6. Elimina k nos\n");
        printf("7. Terminar\n");
        printf("Opcao:");
        scanf("%d", &op);
        printf("\n");
        switch(op){
            case 1:
                printf("Quantos nos a adicionar:");
                scanf("%d",&k);
                for(int i=0; i<k;i++)
                    lista = addLista(lista);
                break;
            case 2:
                mostraLista(lista);
                break;
            case 3:
                printf("ID a atualizar:");
                scanf("%d", &id);
                printf("Novo peso:");
                scanf("%f", &novoPeso);
                atualizaPeso(lista, id, novoPeso);
                break;
            case 4:
                printf("ID a remover:");
                scanf("%d", &id);
                lista = elimina(lista, id);
                break;
            case 5:
                printf("Limite de IMC:");
                scanf("%f", &imc);
                lista = eliminaIMC(lista, imc);
                break;
            case 6:
                printf("Quantos nos a remover:");
                scanf("%d",&k);
                lista = eliminaKNos(lista, k);
            case 7:
                break;
            default: printf("Opcao invalida\n");
        }
    } while(op != 7);

    freeLista(lista);
    return 0;
}
