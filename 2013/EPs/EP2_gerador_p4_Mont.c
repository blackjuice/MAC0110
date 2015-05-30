#include <stdio.h>

int     fatorial    (int);
float   pot         (float,int);
float   seno_x      (float);
float   modulo      (float);
float   frac        (float);
float   generator   (float);

/*NUMBER COLLECTOR:
7.2 & 1 - 648 hz;
*/

float pot (float base, int exp)
{
    int cont1;
    float result1=1;

    for (cont1=0;cont1<exp;cont1++) result1*=base;
    return result1;
}

int fatorial (int n)
{
    int cont2,result2=1;

    for (cont2=1;cont2<=n;cont2++)  result2*=cont2;
    return result2;
}

float seno_x (float x)
{
    float seno=0.0,termo=1,modtermo=1,a=-1;
    int k;
    for(k=0;modulo(termo)>=0.00000001;k++)
    {
        termo=pot(a,k)*pot(x,(2*k+1))/fatorial((2*k+1));
        seno+=termo;
    }
    return seno;
}

float modulo (float valor_mod)
{
    if (valor_mod<0)    valor_mod*=-1;
    return valor_mod;
}

float frac (float frac1)
{
    float fracf;
    fracf=frac1-(int)frac1;
    return fracf;
}

float generator (float ngn)
{
    float ngn1;
    ngn1=frac(7.2*modulo(1+seno_x(ngn)));     //THE # NEXT TO SIN SHOUD BE SMALLER
    return ngn1;
}



int main ()
{
    FILE *teste1 = fopen ("teste1.txt","w");
    float x,a,seed,prob1,prob2,prob3,prob4,prob5,prob6;
    int n,cont,face,numero_de_faces=0,i,cont1,cont2,cont3,cont4,cont5,cont6;

    cont1=cont2=cont3=cont4=cont5=cont6=0;

    seed=0.8124329;
    printf("Indique n>0 para gerar n números aleatórios: ");
    scanf("%d",&n);
    for (cont=0;cont<n;cont++)
    {
        a=generator(seed);
        printf("n= %f\n",a);

        //sequence;

        //if (y0<funcao)  i++;

        seed=a;    //RECEBE

        fprintf (teste1,"%f\n",a*1000);
                //fprintf (teste1,"%f\n",a*1000);
    }




    fclose (teste1);
    return 0;
}
