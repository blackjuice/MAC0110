#include <stdio.h>
//DETERMINO A PALAVRA MAIS LONGA TERMINADA POR UM PONTO FINAL dentro de uma frase!!!!!


int main ()
{
    int cont,longa;
    char c;
    printf("Escreva uma frase e termine ela com um ponto final.\n");
    scanf("%c",&c);
    cont=0;longa=0;
    while (c!='.')      //enquanto ainda nao tenha terminado,       //ATENCAO!!!!! COMO COLOCAMOS TUDO DE UMA VEZ, NAO PRECISAMOS DA BARRA ANTES DO %c
    {
        if (c!=' '&& c!=','&& c!=';'&& c!='-')   cont++;

        else                //se a palavra foi terminada com um espaco, faremos a comparacao
        {
            if (cont>longa) longa=cont;
            cont=0;
        }
        scanf("%c",&c);     //LEMOS O PROXIMO CARACTER
    }
    if (cont>longa) longa=cont;

    printf("A maior palavra da frase tem %d caracteres.\n",longa);
    return 0;
}
