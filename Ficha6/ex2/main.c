#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main(){

    voo tab[300]={{1,"pila turbo", "cagalhao", {10,19}}};
    tempo t= hora_atual();
    int total = 1, index, op;

    do{
        printf("1. Introduzir novos voos\n");
        printf("2. Listar todos os voos\n");
        printf("3. Listar proximos voos\n");
        printf("4. Atualizar tabela de voos\n");
        printf("5. Terminar\n");
        printf("Opcao:");
        scanf("%d", &op);
        printf("\n");
        switch(op){
            case 1:
                addVoo(tab, &total);
                break;
            case 2:
                imprime_voos(tab, total);
                break;
            case 3:
                parteBrevemente(tab,t,total);
                break;
            case 4:
                removeVoo(tab,t,&total);
                break;
            case 5: break;
            default: printf("Opcao invalida\n");
        }
    } while(op != 5);

    return 0;
}
