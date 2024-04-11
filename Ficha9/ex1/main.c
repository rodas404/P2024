#include <stdio.h>
#include <stdlib.h>

#include "parque.h"


int main(){
    int x, minutos;
    pCliente lista = criaExemploED();

    if (lista == NULL)
        return 0;

    mostraTudo(lista);

    // Alinea a)
    printf("\nExistem %d clientes dentro do parque\n", dentroParque(lista));

    // Alinea b)
    printf("Foram efetuadas %d utilizacoes completas\n", utilCompletas(lista));

    // Alinea c)
    x = maisMinutos(lista, &minutos);
    if(x == -1)
        printf("Nao existem clientes com utilizacoes completas\n");
    else
        printf("O cliente %d passou %d minutos no parque\n", x, minutos);

    // Alinea d)
    lista = eliminaCliente(lista, 22);

    mostraTudo(lista);

    // Alinea f)
    lista = acessoParque(lista, 17, (hora){17,03});
    lista = acessoParque(lista, 13, (hora){18,05});
    lista = acessoParque(lista, 19, (hora){18,15});
    mostraTudo(lista);


    libertaTudo(lista);
    return 0;
}