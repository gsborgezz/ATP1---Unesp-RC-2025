#include <stdio.h>
#include <stdlib.h>

// Função para buscar um número em uma matriz 3x3
int buscarNumero(int matriz[3][3], int numero, int *linha, int *coluna) 
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == numero) {
                *linha = i;
                *coluna = j;
                return 1; // Número encontrado
            }
        }
    }
    return 0; // Número não encontrado
}

int main() 
{
    int matriz[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int numero;
    int linha, coluna;

    printf("Digite um número para buscar na matriz: ");
    scanf("%d", &numero);

    if (buscarNumero(matriz, numero, &linha, &coluna)) 
    {
        printf("Número %d encontrado na posição: linha %d, coluna %d\n", numero, linha, coluna);
    }
    else 
    {
        printf("Número %d não encontrado na matriz.\n", numero);
    }

    getchar(); // Consumir '\n' deixado pelo scanf
    getchar(); // Pausa para visualizar a saída
    return 0;
}
