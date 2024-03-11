#include <stdio.h>

char* f1(char *a, char b){
    while((*a!='\0') && (*(a++) !=b))
        ;
    return a-1;
}

int main(){
    char *c[]={"abcdef", "ghijk", "lmnop"}, st[15] = "maio";
    int i;

    for(i=0; i<3; i++)
        puts(f1(c[i], st[i+1]));

    int a[3][2] = {{1,2},{3,4},{5,6}};
    int *q, *p[3]={&a[0][0],a[1],a[2]+1};

    for(i=0; i<2; i++) {
        for (q = p[i]; q <= p[i+1]; q++)
            printf("%d\t", *q);
        putchar('\n');
    }

    return 0;
}
