#include <stdio.h>
#include <string.h>

typedef struct a {
    char nome[100]; // Nome do autor
    int idA; //Identificador numérico do autor
    int nLivros; // Número de títulos no catálogo da livraria
} autor;

typedef struct b {
    char titulo[100], isbn[20]; // Título e isbn do livro
    int idA; // Identificador do autor
    float preco; // Preço do livro
} livro;

void criarFicheiroBinario() {
    FILE *fp = fopen("livraria.bin", "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return;
    }

    int numAutores = 2;
    fwrite(&numAutores, sizeof(int), 1, fp);

    autor autores[] = {
            {"Artur Pires", 12, 3},
            {"Carlos Vaz", 37, 1}
    };
    fwrite(autores, sizeof(autor), numAutores, fp);

    int numLivros = 4;
    fwrite(&numLivros, sizeof(int), 1, fp);

    livro livros[] = {
            {"A Casa", "3X5RT", 12, 18.9},
            {"O Gato", "DFG544", 12, 25.0},
            {"O Pato", "ASD23", 37, 9.1},
            {"O Jardim", "PDF12", 12, 31.5}
    };
    fwrite(livros, sizeof(livro), numLivros, fp);

    fclose(fp);

    printf("Ficheiro binario criado com sucesso.\n");
}

int ex1(char *nomeF, int id){
    autor a;
    livro l;
    FILE *f, *newF;
    char nomeID[100] = "";

    f = fopen(nomeF, "rb+");
    newF = fopen("ex1.txt", "w");
    if(f == NULL || newF == NULL){
        printf("erro ao abrir ficheiro\n");
        return 0;
    }

    int numAutores, maxLivros = 0, idAutor = -1, numLivros, numMaxLivros;
    fread(&numAutores, sizeof(int), 1, f);

    for(int i=0; i<numAutores; i++){
        fread(&a, sizeof(autor), 1, f);
        if(a.nLivros > maxLivros){
            maxLivros = a.nLivros;
            idAutor = a.idA;
            numMaxLivros = 1;
        }
        else if(a.nLivros == maxLivros)
            numMaxLivros++;

        if(a.idA == id)
            strcpy(nomeID, a.nome);
    }
    if(numMaxLivros != 1){
        printf("ha empate no numero max de livros\n");
        idAutor = -1;
    }

    if(strcmp(nomeID, "") == 0) {
        fprintf(newF, "Autor inexistente\n");
        fclose(newF);
    }

    fread(&numLivros, sizeof(int), 1, f);

    for(int i=0; i<numLivros; i++){
        fread(&l, sizeof(livro), 1, f);
        if(l.idA == idAutor){
            l.preco = l.preco + (l.preco * 0.1);
            fseek(f, -sizeof(livro), SEEK_CUR);
            fwrite(&l, sizeof(livro), 1, f);
            fseek(f, 0, SEEK_CUR);
            printf("Novo preco de '%s': %f\n", l.titulo, l.preco);
        }
        if(l.idA == id){
            fprintf(newF, "%s - %s, %s\n", l.isbn, l.titulo, nomeID);
        }
    }

    fclose(f);
    fclose(newF);
    return 1;
}

int main(void) {
    //criarFicheiroBinario();
    ex1("livraria.bin", 37);

    return 0;
}
