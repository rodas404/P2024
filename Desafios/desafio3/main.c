
#include <stdio.h>
#include "lista.h"

int main() {
    pno l1=NULL, l2=NULL, l3=NULL, l4 = NULL, lteste = NULL;

    lteste = criaLista((no[]){{"A",5, NULL},{"C",3, NULL},{"D",1, NULL},{"E",6, NULL},{"F",7, NULL}, {"G",4, NULL}}, 6);
    printf("\n\nLista teste inicial:\n");
    mostraLista(lteste);
    lteste = desafio3(lteste, "D", "AA");
    printf("\nLista teste final: \n");
    mostraLista(lteste);

    // Exemplo 1
    // Lista Inicial: { A-5,	B-3,	C-1,	M-6,	N-7,	R-4}
    // Lista Final: { A-5,	N-7,	X-1}
    l1 = criaLista((no[]){{"A",5, NULL},{"B",3, NULL},{"C",1, NULL},{"M",6, NULL},{"N",7, NULL}, {"R",4, NULL}}, 6);
    printf("\n\nLista 1 inicial:\n");
    mostraLista(l1);
    l1 = desafio3(l1, "C", "X");
    printf("\nLista 1 final: \n");
    mostraLista(l1);



    // Exemplo 2
    // Lista Inicial: { AAAA-5,	DD-6}
    // Lista Final: { AAAA-5,	DD-6}
    l2 = criaLista((no[]){{"AAAA",5, NULL},{"DD",6, NULL}}, 2);
    printf("\n\nLista 2 inicial:\n");
    mostraLista(l2);
    l2 = desafio3(l2, "DD", "A");
    printf("\nLista 2 final: \n");
    mostraLista(l2);

    // Exemplo 3
    // Lista Inicial: { AA-5,	DD-6,	XYZ-7}
    // Lista Final: { AA-5,	C-7}
    l3 = criaLista((no[]){{"AA",5, NULL},{"DD",6, NULL},{"XYZ",7, NULL}}, 3);
    printf("\n\nLista 3 inicial:\n");
    mostraLista(l3);
    l3 = desafio3(l3, "XYZ", "C");
    printf("\nLista 3 final: \n");
    mostraLista(l3);

    // Exemplo 4
    // Lista Inicial: { AA-5,	ABC-3,	B-1,	DD-6,	XYZ-7}
    // Lista Final: { A-7,	AA-5,	B-1}
    l4 = criaLista((no[]){{"AA",5, NULL},{"ABC",3, NULL},{"B",1, NULL},{"DD",6, NULL},{"XYZ",7, NULL}}, 5);
    printf("\n\nLista 4 inicial:\n");
    mostraLista(l4);
    l4 = desafio3(l4, "XYZ", "A");
    printf("\nLista 4 final: \n");
    mostraLista(l4);

    eliminaLista(l1);
    eliminaLista(l2);
    eliminaLista(l3);
    eliminaLista(l4);
    return 0;
}
