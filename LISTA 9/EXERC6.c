#include <stdio.h>
#include <stdlib.h>

// Função que aloca uma matriz de linhas x colunas
int **alocar_matriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória !!!");
        exit(1);
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória !!!", i);
            exit(1);
        }
    }

    return matriz;
}
