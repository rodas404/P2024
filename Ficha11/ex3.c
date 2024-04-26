
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
        FILE *f;
        struct paragem p;
        int minutos = 0, passou = 0;

        f = fopen(nome,"rb");
        if(f == NULL){
            printf("Erro no acesso ao ficheiro");
            return -1;
        }
    while(fread(&p, sizeof(struct paragem), 1, f) == 1) {
        if(strcmp(p.nome, or) == 0){
            passou = 1;
        }
        if(passou){
            minutos += p.minutos;
            if(strcmp(p.nome, dest) == 0){
                fclose(f);
                return minutos;
            }
        }
    }
    return -1;
}

// Recebe nome do ficheiro binário e nome de paragem
// Verifica se paragem faz parte do percurso ou não. Devolve 1(Sim) ou 0 (Não)
int existeParagem(char *nomeF, char *paragem){
    FILE *f;
    struct paragem p;

    f = fopen(nomeF, "rb");
    if(f == NULL) {
        printf("Erro no acesso ao ficheiro\n");
        return 0;
    }

    while(fread(&p, sizeof(struct paragem), 1, f) == 1) {
        if (strcmp(p.nome, paragem) == 0){
            return 1;
        }
    }
    fclose(f);
    return 0;
}

// Recebe nome do ficheiro binário
// Escreve na consola o nome da origem e do destino do percurso
void orDest(char *nomeF){
    FILE *f;
    int primeiro = 1;
    struct paragem p, ultimo;
    f = fopen(nomeF, "rb");
    if(f == NULL){
        printf("Erro no acesso ao ficheiro\n");
        return;
    }

    while(fread(&p, sizeof(struct paragem),1, f) ==1){
        if(primeiro){
            printf("Origem: %s\n", p.nome);
            primeiro = 0;
        }
        ultimo = p;
    }
    printf("Destino: %s\n", ultimo.nome);
    fclose(f);
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

    printf("\n");
    fclose(f);
}
int duracao(char *nomeF){
    FILE *f;
    struct paragem p;
    int minutos = 0;
    f = fopen(nomeF, "rb");
    if(f == NULL) {
        printf("Erro no acesso ao ficheiro\n");
        return minutos;
    }

    while(fread(&p, sizeof(struct paragem), 1, f) == 1)
        minutos += p.minutos;

    fclose(f);
    return minutos;
}
int main() {

    mostraPercurso("cp_ex3.dat");

    orDest("cp_ex3.dat");

    printf("\nParagem: %d\n", existeParagem("cp_ex3.dat", "Porto"));

    printf("\nLigacao: %d\n", liga("cp_ex3.dat", "Coimbra", "Aveiro"));

    printf("\nDuracao total do percurso: %d min\n", duracao("cp_ex3.dat"));

    return 0;
}
