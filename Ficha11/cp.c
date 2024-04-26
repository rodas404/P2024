
#include <stdio.h>
#include <string.h>

struct paragem{
    char nome[50];
    int minutos;
};

// Recebe nome do ficheiro binário e nomes de 2 paragens
// Verifica se é possivel efetuar a ligação entre as 2 paragens
// Devolve número de minutos que demora a ligar as 2 paragens ou -1, caso seja impossivel
int liga(char *nome, char *or, char *dest){

        return -1;
}

// Recebe nome do ficheiro binário e nome de paragem
// Verifica se paragem faz parte do percurso ou não. Devolve 1(Sim) ou 0 (Não)
int existeParagem(char *nomeF, char *paragem){
    return 0;
}

// Recebe nome do ficheiro binário
// Escreve na consola o nome da origem e do destino do percurso
void orDest(char *nomeF){

}

// Recebe nome do ficheiro binário
// Escreve na consola as varias paragens do percurso armazenado
void mostraPercurso(char *nomeF) {
    FILE *f;
    struct paragem p;

    f = fopen(nomeF, "rb");
    if(f == NULL) {
        printf("Erro no acesso ao ficheiro\n");
        return;
    }

    while(fread(&p, sizeof(struct paragem), 1, f) == 1)
        printf("%s: %d\n", p.nome, p.minutos);

    fclose(f);
}

int main() {

    mostraPercurso("cp_ex1.dat");

    orDest("cp_ex1.dat");

    printf("\nParagem: %d\n", existeParagem("cp_ex1.dat", "Porto"));

    printf("\nLigacao: %d\n", liga("cp_ex1.dat", "Coimbra", "Porto"));


    return 0;
}
