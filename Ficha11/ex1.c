//
// Created by footr on 26/04/2024.
//
#include <stdio.h>

struct dados{
    int a;
    char b;
};

int main() {
    struct dados x = {4, 'k'};
    char c = 'w';
    int i;
    FILE *f;
    f = fopen("fich.bin", "wb");
    if(f == NULL)
        return 0;
    fwrite(&x, sizeof(struct dados), 1, f);
    fwrite(&c, sizeof(char), 1, f);
    fwrite(&(x.a), sizeof(int), 1, f);
    fclose(f);

    printf("\n--------------------------\n");

    f = fopen("fich.bin", "rb");
    if(f == NULL)
        return 0;
    fread(&x, sizeof(struct dados), 1, f);
    fread(&c, sizeof(char), 1, f);
    fread(&i, sizeof(int), 1, f);
    printf("%d - %d - %c - %c\n", x.a, i, x.b, c);
    fclose(f);

    return 0;
}