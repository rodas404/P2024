#include <stdio.h>
#include <string.h>

void procuraPal(int nLin, int nCol, char tab[][nCol], char *pal) {
    int pal_len = strlen(pal);
    printf("A palavra %s surge:\n", pal);

    // verifica linhas
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j <= nCol - pal_len; j++) {
            char temp[pal_len + 1];
            for (int k = 0; k < pal_len; k++) {
                temp[k] = tab[i][j + k];
            }
            temp[pal_len] = '\0';

            if (strcmp(temp, pal) == 0) {
                printf("\t- Ao longo da linha %d com inicio na coluna %d\n", i, j);
            }
        }
    }

    // verifica colunas
    for (int j = 0; j < nCol; j++) {
        for (int i = 0; i <= nLin - pal_len; i++) {
            char temp[pal_len + 1];
            for (int k = 0; k < pal_len; k++) {
                temp[k] = tab[i + k][j];
            }
            temp[pal_len] = '\0';

            if (strcmp(temp, pal) == 0) {
                printf("\t- Ao longo da coluna %d com inicio na linha %d\n", j, i);
            }
        }
    }
}


int main() {
    char quebra_cabeca[5][6] = {
            {'e', 'B', 'a', 'u', 'l', 'q'},
            {'l', 'e', 'r', 'r', 's', 's'},
            {'u', 'w', 'u', 'q', 'g', 'r'},
            {'a', 'a', 'l', 'l', 'u', 'a'},
            {'p', 'm', 'h', 'u', 'd', 'j'}
    };

    char palavra[] = "lua";

    procuraPal(5, 6, quebra_cabeca, palavra);

    return 0;
}

