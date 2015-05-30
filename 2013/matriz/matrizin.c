#include <stdio.h>
#define MAX	500
#define FNMAX	200
#define ON	1
#define OFF	0

int LeDesenho	(char nomearq [FNMAX], int M[MAX][MAX], int *m, int *n);
void multiplicacao (int A[MAX][MAX], int m, int n, int B[MAX][MAX], int x, int y, int C[MAX][MAX]);
int EscreveDesenho (char nomearq [FNMAX], int M[MAX][MAX], int m, int n);
void simetria (int A[MAX][MAX], int m);

int main ()
{
	int i,j;
	int ml,mc;
	int nl,nc;
	int M[MAX][MAX];
	int N[MAX][MAX];
	int X[MAX][MAX];
	int operacao=ON;
	char nomearq [FNMAX];
	char c;

	printf ("------------------------------------------------------------\n");
	printf ("------------------------------------------------------------\n");
	printf ("---------------------------WELCOME--------------------------\n");
	printf ("------------------------------------------------------------\n");
	printf ("------------------------------------------------------------\n");
	printf ("---------YOUR PERSONAL MATRICE MANIPULATION PROGRAM---------\n");
	printf ("------------------------------------------------------------\n");
	printf ("------------------------------------------------------------\n");
	printf ("\nProgram iniciated.\n");
	scanf ("%c",&c);

	while (operacao!=OFF)
	{

		printf ("Select your operation:\n");
		printf ("0 - To terminate the program\n");
		printf ("1 - To load PRIMARY matrice\n");
		printf ("2 - To load SECONDARY matrice\n");
		printf ("3 - To format your PRIMARY .txt\n");
		printf ("4 - To format your SECONDARY .txt\n");
		printf ("5 - To create new matrice\n");
		printf ("6 - To multiplicate PRIMARY with SECONDARY\n");
		printf ("7 - To create new matrice from operation /6/\n");
		printf ("8 - To verify if matrice is symetric matrice\n");
		printf ("9 - To verify if SECONDARY is inside PRIMARY\n");
		printf ("-------------------------------------------------\n");
		printf ("11 - To run in circles inside the matrice\n");
		printf ("-------------------------Operacao-------------------------\n================> ");
		scanf ("%d",&operacao);

		if (operacao==OFF)
		{
			printf ("--------------------------------------\n");
			printf ("----------PROGRAM TERMINATED----------\n");
			printf ("--------------------------------------\n");
			break;
		}

		if (operacao==1)
		{
			printf("FILE NAME - THE MAIN MATRICE: ");
			scanf("%s",nomearq);
			LeDesenho ( nomearq, M, &ml, &mc );
			printf("/*PRIMARY*/\n");
			for (i=0 ; i<ml ; i++)
			{ 	
				for (j=0 ; j<mc ; j++)
					printf("%d ",M[i][j]);
				printf("\n");
			}
		}

		if (operacao==2)
		{
			printf("FILE NAME - THE SECONDARY MATRICE: ");
			scanf("%s",nomearq);
			LeDesenho ( nomearq, N, &nl, &nc );
			printf("/*SECONDARY*/\n");
			for (i=0 ; i<nl ; i++)
			{
				for (j=0 ; j<nc ; j++)
					printf("%d ",N[i][j]);
				printf("\n");
			}
		}

		if (operacao==6)	/*MULTIPLICAO*/
		{
			if (mc==nl)
			{
				multiplicacao (M, ml, mc, N, nl, nc, X);
				printf ("The new matrice equals to...\n");
				for (i=0; i<ml; i++)
				{
					for (j=0; j<nc; j++)
						printf ("%d ",X[i][j]);
					printf ("\n");
				}
			}
			else
			{
				printf ("\n//////////////////////////////////////////\n");
				printf ("The MULTIPLICACAO operation is not possible.\n");
				printf ("\n//////////////////////////////////////////\n");
			}
		}
		if (operacao==7)
		{
			printf ("\nWARNING:\nThis operation only manipulate your PRIMARY matrice\nType new name of the file: ");
			scanf ("%s", nomearq);
			EscreveDesenho ( nomearq, X, ml, nc);
			printf ("/////////////////////////////////\n");
			printf ("FILE creation process terminated.\n");
			printf ("/////////////////////////////////\n");
		}
		if (operacao==3)
		{
			printf ("\nWARNING:\nThis operation only manipulate your PRIMARY matrice\nType new name of the file: ");
			scanf ("%s", nomearq);
			EscreveDesenho ( nomearq, M, ml, mc);
			printf ("/////////////////////////////////\n");
			printf ("FILE creation process terminated.\n");
			printf ("/////////////////////////////////\n");
		}
		if (operacao==4)
		{
			printf ("\nWARNING:\nThis operation only manipulate your SECONDARY matrice\nType new name of the file: ");
			scanf ("%s", nomearq);
			EscreveDesenho ( nomearq, N, nl, nc);
			printf ("/////////////////////////////////\n");
			printf ("FILE creation process terminated.\n");
			printf ("/////////////////////////////////\n");
		}

		if (operacao==8)
			simetria (M, ml);

		if (operacao==9)
		{
			printf ("---------ONLY for SQUARED matrices---------\n");
			for (i=0; i<ml-nl; i++) {
				for (j=0; j<mc-nc; j++) {
					if (isinside(M, N, i, j, nl)==ON) {
						printf ("----------------------------\n");
						printf ("SECONDARY is inside PRIMARY.\n");
						printf ("----------------------------\n");
					}
					else {	
						printf ("---------------------\n");
						printf ("Didn't happen, buddy.\n");
						printf ("---------------------\n");
					}
				}
			}
		}
		
		if (operacao==11)
		{
			for (j=0; j<mc; j++)	//direita
				printf ("%d ",M[0][j]);
			for (i=1; i<ml; i++)	//desce
				printf ("%d ",M[i][mc-1]);
			for (j=mc-1; j>=0; j--) //esquerda
				printf ("%d ",M[ml-1][j]);
			for (i=ml-1; i>0; i--)	//sobe
				printf ("%d ",M[i][0]);
			for (j=0; j<mc-1; j++)	//direita
				printf ("%d ",M[i+1][j]);
		}
	}
	return 0;
}
int isinside (int A[MAX][MAX], int B[MAX][MAX], int i, int j, int n)
{
	int k, l;
	for (k=0; k<n; k++)
		if (B[k][l]!=A[i+k][j+l])
			return OFF;
	return ON;
}

int LeDesenho (char nomearq [FNMAX], int M[MAX][MAX], int *m, int *n )
{	
	FILE *file;
	int i,j;
	file=fopen (nomearq,"r");
	if (file==NULL)	
	{
		printf ("---------------------------\n");
		printf ("ERROR! Could not load file.\n");
		printf ("---------------------------\n");
		return 1;
	}
	fscanf(file,"%d",&*m);
	fscanf(file,"%d",&*n);
	for (i=0;i<*m;i++)
		for (j=0;j<*n;j++)
			fscanf(file,"%d",&M[i][j]);
	fclose (file);
	return 0;
}

int EscreveDesenho (char nomearq[FNMAX], int M[MAX][MAX], int m, int n)
{
	FILE *file;
	int  i,j;
	file=fopen(nomearq,"w");

	if (file==NULL)
	{
		printf ("\n---------------------------\n");
		printf ("ERROR! Could not creat file.\n");
		printf ("---------------------------\n");
	}

	fprintf(file,"%d %d\n",m,n);

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			fprintf(file,"%d ",M[i][j]);
			//fprintf(file,"%0.3d ",M[i][j]);
		fprintf(file,"\n");
	}
	fclose(file);
	return 0;
}

void multiplicacao (int A[MAX][MAX], int m, int n, int B[MAX][MAX], int x, int y, int C[MAX][MAX])
{
	int linha,coluna;
	int k;
	for (linha=0; linha<m; linha++)
		for (coluna=0; coluna<y; coluna++)
		{
			C[linha][coluna]=0;
			for (k=0; k<n; k++)
				C[linha][coluna]+=A[linha][k]*B[k][coluna];
		}
}

void simetria (int A[MAX][MAX], int m)
{
	int linha, coluna;
	int x;
	int sym=ON;
	for (linha=1; linha<m && sym==ON; linha++)
		for (coluna=0,x=1; coluna<x && x<=m && sym==ON; coluna++,x++)
			if (A[linha][coluna]!=A[coluna][linha])
				sym=OFF;
	if (sym==ON)	printf ("---------------------------You have SYMMETRY!\n");
	if (sym==OFF)	printf ("---------------------------You don't have SYMMETRY!\n");
}
