#include <stdio.h>

float mod (float value)
{
    if (value<0)    return value*=(-1);
}


float seno_x (float x)
{
    float seno=0,termo;
    int k;
    termo=x;
    for(k=0;mod(termo)>=0.00000001;k++)
    {
        termo*=(-1)*(x*x)/((2*k+1)*(2*k));
        seno+=termo;
        printf("entrou");
    }
    return seno;
}


int main ()
{
    float sin,seed;

    printf("Indique x entre 0 a 1: ");
    scanf("%f",&seed);
    sin=seno_x(seed);
    printf("sen(x) vale=%f\n",sin);

    return 0;
}
