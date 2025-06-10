#include <stdio.h>
#include <stdlib.h>

// EXERC 6: Alocar matriz dinâmica
int **alocar_matriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória !!!");
        exit(1);
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória !!!");
            exit(1);
        }
    }

    return matriz;
}

// EXERC 7: Liberar matriz dinâmica
void libera_matriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// EXERC 8: Preencher matriz dinâmica
void preencherMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o valor para [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// EXERC 9: Imprimir matriz dinâmica
void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função que calcula o produto vetorial entre dois vetores de 3 elementos
void produtoVetorial(int a[3], int b[3], int resultado[3]) {
    resultado[0] = a[1] * b[2] - a[2] * b[1];
    resultado[1] = a[2] * b[0] - a[0] * b[2];
    resultado[2] = a[0] * b[1] - a[1] * b[0];
}

// Função que calcula o produto vetorial linha a linha entre duas matrizes 3x3
void produtoVetorialMatrizes(int **A, int **B, int **C) {
    for (int i = 0; i < 3; i++) {
        produtoVetorial(A[i], B[i], C[i]);
    }
}

int main() {
    int linhasA, colunasA, linhasB, colunasB;

    printf("Digite o número de linhas da matriz A: ");
    scanf("%d", &linhasA);
    printf("Digite o número de colunas da matriz A: ");
    scanf("%d", &colunasA);

    printf("Digite o número de linhas da matriz B: ");
    scanf("%d", &linhasB);
    printf("Digite o número de colunas da matriz B: ");
    scanf("%d", &colunasB);

    if (linhasA != 3 || colunasA != 3 || linhasB != 3 || colunasB != 3) {
        printf("Produto vetorial só é possível para matrizes 3x3.\n");
        return 1;
    }

    int **matrizA = alocar_matriz(linhasA, colunasA);
    int **matrizB = alocar_matriz(linhasB, colunasB);
    int **matrizC = alocar_matriz(3, 3); // Resultado 3x3

    printf("\nPreencha a matriz A:\n");
    preencherMatriz(matrizA, linhasA, colunasA);

    printf("\nPreencha a matriz B:\n");
    preencherMatriz(matrizB, linhasB, colunasB);

    produtoVetorialMatrizes(matrizA, matrizB, matrizC);

    printf("\nMatriz A:\n");
    imprimirMatriz(matrizA, linhasA, colunasA);

    printf("\nMatriz B:\n");
    imprimirMatriz(matrizB, linhasB, colunasB);

    printf("\nProduto vetorial linha a linha (matriz C):\n");
    imprimirMatriz(matrizC, 3, 3);

    libera_matriz(matrizA, linhasA);
    libera_matriz(matrizB, linhasB);
    libera_matriz(matrizC, 3);

    getchar(); // Consumir '\n' após scanf
    getchar(); // Pausar programa
    return 0;
}
