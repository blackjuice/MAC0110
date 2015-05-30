#include <stdio.h>

float pot (float base, int exp)
{
    int cont1;
    float result1=1;

    for (cont1=0;cont1<exp;cont1++)
        result1*=base;
    return result1;
}

int fatorial (int n)
{
    int cont2,result2=1;

    for (cont2=1;cont2<=n;cont2++)
        result2*=cont2;
    return result2;
}

int main ()
{
    float seno=0.0,termo=1,x,modtermo=1,a=-1;
    int k;

    printf("Indique x entre 0 a 1: ");
    scanf("%f",&x);

    if(x>0 && x<1)
    {
        for(k=0;modtermo>=0.00000001;k++)
        {
            termo=pot(a,k)*pot(x,(2*k+1))/fatorial((2*k+1));
            modtermo=termo;
            if(modtermo<0)  modtermo*=-1;
            seno+=termo;
        }
    }
    printf("sen(x) vale:%f\n",seno);

    return 0;
}
