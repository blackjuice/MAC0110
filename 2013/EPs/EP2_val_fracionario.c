#include <stdio.h>

float fracionaria (float x)
{^M
    float fracao;^M
    int inteiro;^M
    inteiro=((int)(x));
    fracao=x-inteiro;
    return fracao;
}

int main ()
{^M
    int valor;^M
    float fracionario;
    printf("TESTE DO VALOR FRACIONARIO.\nAtencao, o valor 3,14 deve sair 0,14...\nIniciando...\n");
    printf("COloque o valor: ");
    scanf("%f",&valor);
    fracionario=fracionaria(valor);
    printf("O valor pi , na sua parte fracionaria equivale a %f",fracionario);^M
    return 0;
}
