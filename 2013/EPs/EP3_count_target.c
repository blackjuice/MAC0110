#include <stdio.h>
#define MAX 20
#define TRUE 1
#define FALSE 0

int identificador (int ng, int nt, char vetorG, char vetorT ,int vetorP;
{
	int i,i_GENESIS,i_TARGET,state,count_TARGET,vetorP[MAX];
	i=0;
	for(i_GENESIS=0,i_TARGET=0;i_GENESIS<ng && i_TARGET<nt;i_GENESIS++)
	{
		if(vetorT[i_TARGET]!=vetorG[i_GENESIS])
		{
			i_TARGET=0;
			if(vetorT[i_TARGET]==vetorG[i_GENESIS])
			{
				i_TARGET++;
				state=TRUE;
				vetorP[i]=i_GENESIS;
				i++;
			}
		}
		else
		{
			i_TARGET++;
			state=TRUE;
			vetorP[i]=i_GENESIS;
			i++;
		}
		
		if(i_TARGET==nt && state==TRUE) 
		{
			count_TARGET++; 
			i_TARGET=0;
		}
	}
	return count_TARGET;
}
int main ()
{
	int i,ng,nt,nx,i_GENESIS,i_TARGET,count_TARGET,state;
	char cg,ct,cx,vetorG[1000],vetorT[MAX],vetorN[MAX];
	count_TARGET=0; state=FALSE;

	printf("Write the size of the text:"); 
	scanf("%d",&ng);
	printf("Write the text now:"); 
	scanf("%c",&cg);
	for(i=0;i<ng;i++) 
	{
		scanf("%c",&cg); 
		vetorG[i]=cg;
	}

	printf("Write the size of the TARGET:"); 
	scanf("%d",&nt);
	printf("Write the wanted word:");
	for(i=0;i<nt;i++) 
	{
		scanf(" %c",&ct);
		vetorT[i]=ct;
	}

	printf("Write the size of the NEO TARGET:"); 
	scanf("%d",&nx);
	printf("Write the wanted word:");
	for(i=0;i<nx;i++) 
	{
		scanf(" %c",&cx);
		vetorN[i]=cx;
	}

	printf("%d",identificador(
	printf("count_TARGET vale %d\n",count_TARGET);
/*
	if(nx==nt) 
	{
		printf("entrou\n");
		for(i=nx-1;i>=0;i--)
		{	
			vetorG[i_GENESIS]=vetorN[i];
			i_GENESIS--;
		}
		i_TARGET=0; i=0;
	}

	if(nx>nt)
	{
		ng+=count_TARGET*(nx-nt);
		printf("NEW ng vale %d\n",ng);
		for(i=ng-1;i>=0;i--)
			vetorG[i]=vetorG[i-1];

		if(i_TARGET==nt && state==TRUE)
			for(i=nx-1;i>=0;i--)
			{	
				vetorG[i_GENESIS]=vetorN[i];
				i_GENESIS--;
			}
			i_TARGET=0; i=0;
	}
*/
	
	for(i=0;i<ng;i++)
		printf("%c",vetorG[i]);
	printf("\n");
	//printf("count_TARGET vale %d\n",count_TARGET);

	return 0;
}
