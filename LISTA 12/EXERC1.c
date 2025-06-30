#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome [50];
    float ex, p1, p2;
}Aluno;

float calcular_media(Aluno *aluno)
{
    float provas = (aluno->p1 * 4 + aluno->p2 * 6)/10;
    return(aluno->ex * .2 + provas * .8);
}


int main()
{
    Aluno a;
    a.ex = 6;
    a.p1 = 3;
    a.p2 = 6;
    printf("%.2f", calcular_media(&a));
    getchar();
    return 0;
}
