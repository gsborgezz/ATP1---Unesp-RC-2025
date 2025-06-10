#include <stdio.h>
#include <stdlib.h>

// Calcula o produto vetorial entre dois vetores de 3 elementos
void produtoVetorial(int a[3], int b[3], int resultado[3])
{
    resultado[0] = a[1] * b[2] - a[2] * b[1];
    resultado[1] = a[2] * b[0] - a[0] * b[2];
    resultado[2] = a[0] * b[1] - a[1] * b[0];
}

// Aplica o produto vetorial entre linhas correspondentes de duas matrizes 3x3
void produtoVetorialMatrizes(int A[3][3], int B[3][3], int C[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        produtoVetorial(A[i], B[i], C[i]);
    }
}

// Imprime uma matriz 3x3
void imprimirMatriz(int M[3][3])
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    int B[3][3] = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };

    int C[3][3];

    produtoVetorialMatrizes(A, B, C);

    printf("Produto vetorial linha a linha:\n");
    imprimirMatriz(C);

    getchar(); // Aguarda entrada para pausar o programa
    return 0;
}
