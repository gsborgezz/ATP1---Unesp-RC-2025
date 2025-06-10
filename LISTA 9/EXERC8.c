#include <stdio.h>
#include <stdlib.h>

// Preenche uma matriz dinâmica com valores fornecidos pelo usuário
void preencherMatriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Digite o valor para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}
