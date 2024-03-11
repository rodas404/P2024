// NOTAS IMPORTANTES

// 1. Altere o nome deste ficheiro. Deve passar a ter o seu numero de aluno como nome, mantendo a extensão .c
// Por exemplo, se o número de aluno for 1234567, o ficheiro deve passar a chamar-se: 1234567.c

// 2. Complete a sua identificação nas linhas 11 e 12

// 3. Só pode escrever código dentro da função desafio1(). Não pode alterar mais nada neste ficheiro
// Esta função não deve escrever nada na consola

// Nome completo: Rodrigo Miguel Pessoa da Bernarda
// Número de aluno: 2021136740

#include <stdio.h>

// Recebe:
// Endereço inicial de uma tabela de inteiros (tab)
// Dimensão de uma tabela de inteiros (tam)
// Endereço de uma variável inteira (contaP)

// Devolve número de elementos duplicados (número de elementos que aparecem exatamente 2 vezes na tabela)
// Coloca na variável referenciada por contaP o número de picos do array
// Considera-se que um pico é um elemento do array que está rodeado por valores menores à sua esquerda e à sua direita
int desafio1(int *tab, int tam, int *contaP){
    int repetido, duplicado=0, i;
    int verificacao[tam]; //tabela auxiliar para certificar que um numero é avaliado exclusivamente uma vez

    for(i=0; i<tam; i++){
        verificacao[i]=0;
    }

    for(i=0; i<tam; i++){
        repetido = 0;
        if((i!=0 && i<tam-1) && (tab[i]>tab[i+1] && tab[i]>tab[i-1]))
            (*contaP)++; //nao analisa valores nas extremidades da tabela

        if(verificacao[i]==1)
            continue; //caso o ciclo principal passe por um numero ja analisado, passa a frente

        for(int j=i+1; j<tam; j++){
            if(tab[i]==tab[j]) {
                repetido++;
                verificacao[j]=1; //sempre que e encontrado um valor repetido, marca na tabela auxiliar como verificado
            }
        }

        if(repetido==1)
            duplicado++; // se repetiu apenas uma vez, significa que esse numero so aparece 2 vezes
    }
    return duplicado;
}

int main() {
    int tab1[5] = {5, 3, 3, 2, 2};
    int tab2[10] = {-3, -2, 0, 0, 1, 4, 3, -2, 9, 1};
    int tab3[8] = {1, 1, 4, 10, 4, 8, 1, 9};
    int c1=0, c2=0, c3=0, d1, d2, d3;

    d1 = desafio1(tab1, 5, &c1);
    d2 = desafio1(tab2, 10, &c2);
    d3 = desafio1(tab3, 8, &c3);

    printf("%d %d %d %d %d %d\n", d1, c1, d2, c2, d3, c3);
    return 0;
}
