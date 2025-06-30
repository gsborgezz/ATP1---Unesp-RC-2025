#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nome [50];
    float ex, p1, p2;
}Aluno;

typedef struct no{
    Aluno *aluno;
    struct no *prox;
}No;

float calcular_media(Aluno *aluno)
{
    float provas = (aluno->p1 * 4 + aluno->p2 * 6)/10;
    return(aluno->ex * .2 + provas * .8);
}

void imprime_media(No *listaAluno)
{
    No * atual = listaAluno;
    while (atual != NULL)
    {
        printf("%s: %.2f\n", atual ->aluno->nome, calcular_media(atual->aluno));
        atual = atual ->prox;
    }
}

int main()
{
    Aluno a, b;
    No na, nb;
    na.aluno = &a;
    na.prox = *nb;
    na.aluno = &b;
    nb.prox = NULL;    
    a.ex = 6;
    b.ex = 6;
    a.p1 = 3;
    b.p1 = 3;
    a.p2 = 6;
    b.p2 = 6;
    printf("%.2f", calcular_media(&a));
    getchar();
    return 0;
}
