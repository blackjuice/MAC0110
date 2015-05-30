#include <stdio.h>

int main ()
{
    int totalalunos,teste,aluno,points,total;
    char alt[6],doaluno[6];

    printf("Numero de alunos: ");
    scanf("%d",&totalalunos);

    printf("Gabarito 2013\n");
    for (teste=0;teste<5;teste++)
    {
        printf("Teste %d:",teste);
        scanf(" %c",&alt[teste]);
    }
    printf("Alunos.\n");
    for (aluno=1;aluno<totalalunos+1;aluno++)
    {
    points=0;
    total=0;
        printf("Aluno %d\n",aluno);
        printf("indique as respostas do aluno\n");
        for (teste=0;teste<5;teste++)           //EU ESTAVA IGNORANDO O VETOR 0!!!!!
        {
            printf("Teste %d:",teste);
            scanf(" %c",&doaluno[teste]);
            if (doaluno[teste]==alt[teste]) points++;
            //total+=points;   O problema eh que ele somava o anterior
        }
        printf("Aluno %d fez %d.\n",aluno,points);
    }
    return 0;
}
