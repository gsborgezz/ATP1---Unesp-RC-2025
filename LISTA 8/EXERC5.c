#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *mat;
    int i, j;

    // Aloca espaço para 9 inteiros (3x3)
    mat = malloc(9 * sizeof(int));
    if (!mat) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Preenche com zeros
    for (i = 0; i < 9; i++) {
        mat[i] = 0;
    }

    // Imprime no formato de matriz 3x3
    printf("Matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", mat[i * 3 + j]);
        }
        printf("\n");
    }

    // Libera a memória
    free(mat);

    getchar();
    getchar();

    return 0;
}
