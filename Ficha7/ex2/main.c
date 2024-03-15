#include <stdio.h>
#include <stdlib.h>

#include "agenda.h"

int main() {

    pct tab = NULL;
    char nome[200];
    int i, total=0, novo_num;

    for(i=0; i<3; i++)
        tab = addC(tab, &total);

    listaC(tab, total);

    printf("Nome a procurar:");
    scanf(" %[^\n]", nome);
    printf("Numero de %s: %d\n\n", nome, getTel(tab, total, nome));

    printf("Nome a atualizar:");
    scanf(" %[^\n]", nome);
    printf("Novo numero:");
    scanf("%d", &novo_num);
    if(atualizaTel(tab, total, nome, novo_num) == 1)
        printf("Contacto atualizado com sucesso\n\n");
    else
        printf("Contacto nao encontrado\n\n");

    printf("Nome a eliminar:");
    scanf(" %[^\n]", nome);
    tab = eliminaC(tab, &total, nome);
    listaC(tab, total);
    free(tab);

    return 0;
}
