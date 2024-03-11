#include <stdio.h>
#include <string.h>

void f1(){
    int a=12, *p;
    float x=3.5, *q;
    p = &a;
    q = &x;
    printf("Valores: a=%d\tx=%.2f\n", a, x);
    printf("Valores: a=%d\tx=%.2f\n", *p, *q);
    printf("Endereco/Localizacao: a -> %p\tx -> %p\n", &a, &x);
    printf("Endereco/Localizacao: a -> %p\tx -> %p\n", p, q);
}


void f2(int x, int *p){
    printf("F2: Endereco/Localizacao: x=%p\tb=%p\n", &x, p);
    x++;
    (*p)++;
    printf("Valores em F2: a=%d\tb=%d\n", x, *p);
}

void f12A(char *a, char *b){
    do{
        b--;
        printf("%s\n", b);
    }while(a != b);
}
void f12B(char *a, char *b){
    while(a<b)
        printf("%s\n", a++);
}

int main(){
    /*
    f1();
    printf("\n\n");

    int a=1, b=2;
    printf("Valores Iniciais: a=%d\tb=%d\n", a, b);
    printf("Main: Endereco/Localizacao: a=%p\tb=%p\n", &a, &b);
    f2(a, &b);
    printf("Valores Finais: a=%d\tb=%d\n", a, b);
    printf("\n\n");
    */
    int i, *p, *q;
    int a10[5] = {0, 1, 2, 3, 4};
    for(p=a10; p <= a10+4; p++)
        printf("%d\t", *p);
    putchar('\n');
    for(p=a10,i=1; i<3; i++)
        printf("%d\t", p[i]);
    putchar('\n');
    for(p=a10, q=a10+4; p<=q; p++, q--)
        printf("%d\t%d\t", *p, *q);
    printf("\n\n");

    char st1[10] = "123!";
    f12A(st1, st1+strlen(st1));
    printf("\n");
    f12B(st1, st1+strlen(st1));

    return 0;

}
