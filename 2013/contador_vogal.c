#include <stdio.h>
#define TRUE 1
#define FALSE 0

int yes (char c)
{
    if (c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')
        return TRUE;
    return FALSE;
}

int main ()
{
    int n,i,count;
    char letra;

    printf("Quantas letras possuem sua palavra:");
    scanf("%d",&n);
    count=0;
    for (i=0;i<n;i++)
    {
        printf("Write the shit down:\n");
        scanf(" %c",&letra);
        if(yes(letra)==TRUE)    count++;
    }
    printf("Existem %5.2f%% de vogais",(float)count*100/n);
    return 0;
}
