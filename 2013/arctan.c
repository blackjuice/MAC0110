#include <stdio.h>

float pot (float base, int exp) {
    int cont;
    float result=1;

    for (cont=0;cont<exp;cont++)
        result*=base;
    return result;
    }

int main ()
{
    float arctan,termo,x,modtermo,a;
    int k,b;

    modtermo=termo=1;   //AQUI, MUITO IMPORTANTE!!!
    a=-1;
    k=1;
    b=0;
    arctan=0.0;

    printf("Indique x entre 0 a 1: ");
    scanf("%f",&x);

    while (modtermo>=0.0001) {

        termo=pot(a,b)*pot(x,k)/k;
        modtermo=termo;
        if(modtermo<0)  modtermo*=-1;
        arctan+=termo;
        k+=2;
        b+=1;
    }

    printf("arctan:%f\n",arctan);

    return 0;
}
