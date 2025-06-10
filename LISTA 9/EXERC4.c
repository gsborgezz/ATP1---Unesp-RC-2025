#include <stdio.h>
#include <stdlib.h>

// Calcula a soma dos elementos da diagonal principal de uma matriz 3x3
int somaDiagonalPrincipal(int matriz[3][3])
{
    int soma = 0;

    for (int i = 0; i < 3; i++) 
    {
        soma += matriz[i][i]; // Elementos da diagonal principal estão nas posições [i][i]
    }

    return soma;
}

int main()
{
    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Matriz:\n");

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    int soma = somaDiagonalPrincipal(matriz);
    
    printf("\nSoma da diagonal principal: %d\n", soma);

    getchar(); // Aguarda entrada para pausar o programa
    return 0;
}
