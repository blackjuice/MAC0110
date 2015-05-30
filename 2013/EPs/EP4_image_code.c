/*	POR FAVOR LEIA: FOI USADO A BIBLIOTECA <math.h>	*/
#include <stdio.h>
#include <math.h>	/*foi usado function -floor- e -sqrt- na funcao int BeDeu*/
#define MAX	800
#define MAX2	640000
#define FNMAX	200
#define cinza	int
#define ON	1
#define OFF	0

int LeDesenho		 (char nomearq [FNMAX], cinza M[MAX][MAX], int *pm, int *pn, int *pmax);
int LeTexto		 (char nomearq [FNMAX], char T[MAX2], int *pk);
int BeDeu		 (int k, int m, int n, int *pb, int *pd);
int ProximosBBits	 (char T[MAX2], int b, int *pik, int *pib);
void Codifica		 (cinza D[MAX][MAX], int m, int n, char T[MAX2], int k, cinza D1[MAX][MAX], int b, int d, int modo);
cinza Maximo		 (cinza D[MAX][MAX], int m, int n);
void DeBeDeu		 (cinza D[MAX][MAX], cinza D1[MAX][MAX], int m, int n, int *pb, int *pd);
int DeCodifica		 (cinza D[MAX][MAX], cinza D1[MAX][MAX], int m, int n, int b, int d, char T[MAX2], int modo);
int EscreveDesenho	 (char nomearq[FNMAX], cinza M[MAX][MAX], int m, int n, int max);
int EscreveTexto	 (char nomearq[FNMAX], char T[MAX2], int k);
/*funcoes extras*/
int pot			 (int base, int exp);
int convertebin		 (int n);		/*converte numeros para binarios*/

int main ()
{
	int pm, pn, pmax;
	int pk;
	int i,j;
	int b,d;
	int operacao=ON;
	int modo=OFF;
	int max_cinza;
	int status; /*verifica se leitura de arquivos feita com sucesso*/
	char nomearq[FNMAX];
	char T[MAX2];
	cinza M[MAX][MAX];
	cinza N[MAX][MAX];

	printf("--------------------------------------------------------------\n");
	printf("------------PROGRAMA DE OCULTACAO POR MARCA D'AGUA------------\n");
	printf("--------------------------------------------------------------\n");
	while(operacao!=0)
	{
		printf("Indique a operacao desejada:\n Para terminar o programa: 			0\n Para codificar um arquivo .pgm: 		1\n Para decodificar um arquivo .pgm: 		2\n Para vizualizar um arquivo .txt: 		3\n Para ativar/desativar o modo verborragico: 	4\n");
		printf("Operacao: ");
		scanf("%d",&operacao);
		if(operacao==0)
		{
			printf("Operacao 0 selecionada.\n***************************FIM DO PROGRAMA***************************\n ");
			break;
		}

		if(operacao==4)
		{
			if (modo==OFF)
			{
				modo=ON;
				printf("////////////////////////////////////////////\n");
				printf("/////////Modo verborragico ATIVADO//////////\n");
				printf("////////////////////////////////////////////\n");
			}
			else
			{
				modo=OFF;
				printf("////////////////////////////////////////////\n");
				printf("//////Modo verborragico DESATIVADO//////////\n");
				printf("////////////////////////////////////////////\n");
			}
		}

		if(operacao==1)
		{
			printf("Digite nome do arquivo em .pgm que contem um desenho: ");
			scanf("%s",nomearq);
			status=LeDesenho (nomearq,M,&pn,&pm,&pmax);
			if (status==OFF)
			{
				printf("Digite nome do arquivo em .txt: ");
				scanf("%s",nomearq);
				status=LeTexto (nomearq,T,&pk);

				if (status==OFF)
				{
					/*em caso de numero de caracteres equivaler a 0*/
					if(pk==0)
					for (i=0;i<pm;i++)
						for (j=0;j<pn;j++)
							N[i][j]=M[i][j];

					else
					{
						/******funcoes********/
						BeDeu (pk,pn,pm,&b,&d);
						Codifica (M,pn,pm,T,pk,N,b,d,modo);
						max_cinza=Maximo (N,pn,pm);
					}

					printf("Digite nome do arquivo em .pgm que contera o desenho com a marca d'agua falsa: ");
					scanf("%s",nomearq);
					EscreveDesenho (nomearq,N,pn,pm,max_cinza);

					printf("Operacao concluida!\n");
				}
			}
		}

		if(operacao==2)
		{
			printf("Digite nome do arquivo em .pgm que contem um desenho: ");
			scanf("%s",nomearq);
			status=LeDesenho (nomearq,M,&pn,&pm,&pmax);
			
			if (status==OFF)
			{
				printf("Digite nome do arquivo em .pgm com a marca d'agua falsa: ");
				scanf("%s",nomearq);
				status=LeDesenho (nomearq,M,&pn,&pm,&pmax);

				if (status==OFF)
				{
					DeBeDeu (M,N,pn,pm,&b,&d);
					DeCodifica (M,N,pn,pm,b,d,T,modo);

					printf("b= %d d=%d\n",b,d);

					printf("Digite nome do arquivo em .txt que contera texto decodificado: ");
					scanf("%s",nomearq);
					EscreveTexto (nomearq,T,pk);

					printf("Operacao concluida!\n");
				}
			}
		}

		if(operacao==3)
		{
			printf("Digite nome do arquivo em .txt: "); 
			scanf("%s",nomearq);
			status=LeTexto (nomearq,T,&pk);

			if(status==OFF)
			{
				printf("Texto contido no arquivo:\n");
				for(i=0;i<pk;i++)
					printf("%c",T[i]);
				printf("Operacao concluida!\n");
			}
		}

		if(operacao>4)
			printf("---------------------------------------------\nOperacao invalida!\n");

	}
	return 0;
}

int LeDesenho (char nomearq [FNMAX], cinza M[MAX][MAX], int *pm, int *pn, int *pmax)
{
	FILE *file;
	char p2 [MAX];
	int i,j;

	/*abrindo arquivo*/
	file=fopen (nomearq,"r");
	if (file==NULL)	
	{
		printf("ERRO ao abrir arquivo.\n");
		return 1;
	}
	fscanf(file,"%s",p2);
	/* verificando proxima linha depois
	 * obtendo valores de pm, pn, pmax
	*/
	fscanf(file,"%d",&*pn);
	fscanf(file,"%d",&*pm);
	fscanf(file,"%d",&*pmax);

	/*impressao de m,n*/
	printf("Desenho lido com sucesso.\nm: %d   n: %d\n",*pm,*pn);

	/*desenho entrando na matriz M*/
	for (i=0;i<*pm;i++)
		for (j=0;j<*pn;j++)
			fscanf(file,"%d",&M[i][j]);

	fclose (file);
	/*fechando arquivo*/
	return 0;
}

int LeTexto (char nomearq [FNMAX], char T[MAX2], int *pk)
{
	FILE *file;
	int i;

	file=fopen (nomearq,"r");
	if (file==NULL)	
	{
		printf("ERRO ao abrir arquivo.\n");
		return 1;
	}
	(*pk)=-2;	/*Ocorre uma contagem a mais no texto, e para ignorar essa contagem extra, pk inicia -1*/
	for(i=0;!feof(file);i++)
	{
		fscanf(file,"%c",&T[i]);
		(*pk)++;
	}
	printf("Texto lido com sucesso.\nk: %d\n",*pk);
	return 0;
}

int BeDeu (int k, int m, int n, int *pb, int *pd)
{
	float fb;
	int min;

	min=m;
	if(m>n)	
		min=n;

	/*calculo de *pb */
	fb=(float)(8*k)/(m*n-1);

	if (k==0) /*b=0 <=> k=0*/
		*pb=0;
	if (fb<=1 && fb>0)
		*pb=1;
	if (fb<=2 && fb>1)
		*pb=2;
	if (fb<=4 && fb>2)
		*pb=4;
	if (fb<=8 && fb>4)
		*pb=8;
	if (fb>8)
		return 1;

	/*calculo *pd */
	*pd=sqrt((m*n*(*pb))/(8*k+(*pb)));
	*pd=floor(*pd);

	if((*pd)>=1 && (*pd)<=min)
		printf("Parametros calculados com sucesso.\nb: %d   d: %d\n",*pb,*pd);
	else
		return 1;
	return 0;
}

int EscreveDesenho (char nomearq[FNMAX], cinza M[MAX][MAX], int m, int n, int max)
{
	FILE *file;
	int  i,j;
	file=fopen(nomearq,"w");

	if (file==NULL)
	{
		printf("ERRO ao abrir arquivo.\n");
		return 1;
	}

	fprintf(file,"P2\n");
	fprintf(file,"%d	%d\n",n,m);
	fprintf(file,"%d\n",max);

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			fprintf(file,"%d	",M[i][j]);
		fprintf(file,"\n");
	}

	fclose(file);
	return 0;
}

int EscreveTexto (char nomearq[FNMAX], char T[MAX2], int k)
{
	FILE *file;
	int  i;
	char c;
	file=fopen(nomearq,"w");

	if (file==NULL)
	{
		printf("Erro ao abrir arquivo.\n");
		return 1;
	}

	for(i=0;i<k;i++)
	{
		c=T[i];
		fprintf(file,"%c",c);
	}

	fclose(file);
	return 0;
}

cinza Maximo (cinza D[MAX][MAX], int m, int n)
{
	int i,j;
	int maior=0;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(maior<D[i][j])
				maior=D[i][j];
	return maior;
}

int pot (int base, int exp)
{
	int result=1;
	int i;
	for(i=0;i<exp;i++)
		result*=base;
	return result;
}

int ProximosBBits (char T[MAX2], int b, int *pik, int *pib)
{
	int proximos;
	proximos=((T[*pik]/pot(2,*pib))%(pot(2,b)));
	(*pib)+=b;
	if(*pib==8)
	{
		(*pik)++;
		*pib=0;
	}
	return proximos;
}

void Codifica (cinza D[MAX][MAX], int m, int n, char T[MAX2], int k, cinza D1[MAX][MAX], int b, int d, int modo)
{
	int i,j;
	int t=0;
	int icord=d-1;
	int jcord=d-1;
	int pik=0;
	int pib=0;
	int potencia	=	pot(2,b);
	int proximosb	=	ProximosBBits(T,b,&pik,&pib);

	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			if (i==icord && j==jcord && t<8*k)
			{
				D1[i][j]=((D[icord][jcord]/potencia)*potencia)+((D[icord][jcord]+proximosb)%potencia);
				jcord+=d;
				t+=b;
				if(modo==ON)
					printf("%d	%d	%02d	%02d\n",pik,proximosb,D[i][j],D1[i][j]);
			}
			else
				D1[i][j]=D[i][j];
			if (jcord>=n)
				jcord=d-1;
		}
		icord+=d;
	}
} 

int DeCodifica (cinza D[MAX][MAX], cinza D1[MAX][MAX], int m, int n, int b, int d, char T[MAX2], int modo)
{
	int i,j;
	int t=0;
	int icord=d-1;
	int jcord=d-1;

	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			if (i==icord && j==jcord)
			{
				T[t]=((D1[i][j]-D[i][j]+256)%pot(2,b));
				jcord+=d;
				t++;
				if(modo==ON)
					printf("%d	%d	%02d	%02d\n",icord,b,D[i][j],D1[i][j]);
			}
		}
		icord+=d;
	}
} 

int convertebin (int n)
{
	int bin=0;
	int d=1;
	while(n>0)
	{
		bin+=d*(n%2);
		d*=10;
		n/=2;
	}
	return bin;
}

void DeBeDeu (cinza D[MAX][MAX], cinza D1[MAX][MAX], int m, int n, int *pb, int *pd)
{
	int i,j;
	int dbin,d1bin;
	int bin;
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			if (D1[i][i]-D[i][i]!=0)
			{
				dbin=convertebin(D[i][j]);
				d1bin=convertebin(D1[i][j]);
				bin=d1bin-dbin;
				if (bin==1)	*pb=1;
				if (bin==10)	*pb=2;
				if (bin==100)	*pb=4;
				if (bin==1000)	*pb=8;
				/*foi calculado acima o valor de b*/
				(*pd)=i+1;
				break;
			}
		}
	}
}
