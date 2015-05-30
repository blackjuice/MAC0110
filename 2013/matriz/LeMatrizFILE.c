#include <stdio.h>
#define MAX     500
#define FNMAX   200
#define ON      1
#define OFF     0

int LeDesenho   (char nomearq [FNMAX], int M[MAX][MAX], int *pm, int *pn);

int main ()
{
        int i,j;
        int pm,pn;
        int D[MAX][MAX];
        char nomearq [FNMAX];

        printf("FILE NAME: ");
        scanf("%s",nomearq);
        LeDesenho ( nomearq, D, &pm, &pn );

        for (i=0 ; i<pm ; i++)
        {
                for (j=0 ; j<pn ; j++)
                        printf("%d      ",D[i][j]);
                printf("\n");
        }
        return 0;
}

int LeDesenho (char nomearq [FNMAX], int M[MAX][MAX], int *pm, int *pn )
{
        FILE *file;
        int i,j;

        file=fopen (nomearq,"r");
        if (file==NULL)
        {
                printf("ERRO ao abrir arquivo.\n");
                return 1;
        }

        fscanf(file,"%d",&*pm);
        fscanf(file,"%d",&*pn);

        for (i=0;i<*pm;i++)
                for (j=0;j<*pn;j++)
                        fscanf(file,"%d",&M[i][j]);

        fclose (file);

        return 0;
}
