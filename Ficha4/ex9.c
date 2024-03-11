#include <stdio.h>
#include <string.h>
#define TAM 25

int ePlaneta(char *str){
    const char *tabPlanetas[8] = {"Mercurio", "Venus", "Terra", "Marte", "Jupiter", "Saturno", "Urano", "Netuno"};
    for(int i=0; i<8; i++){
        if(stricmp(str,tabPlanetas[i])==0)
            return 1;
    }
    return 0;
}

int main(){
    char planeta[TAM];
    printf("Nome do planeta:");
    gets(planeta);

    printf("Resultado: %d\n", ePlaneta(planeta));
    return 0;
}
