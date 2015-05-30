#include <stdio.h>

int main () {

    int a,b,m,n,resto;

    printf("Indique um par de numeros para calcular seu m.d.c.: ");
    scanf("%d %d",m,n);

    m=a;
    n=b;

    while (resto!=0)    {
        resto=a%b;
        a=b;
        b=resto;
        }
    printf("mdc de %d e %d vale %d",m,n,b);
    return 0;
}
