#include <stdio.h>
#include <stdlib.h>

void libera_matriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);  // libera a memória de cada linha
    }
    free(matriz);  // libera a memória do vetor de ponteiros
}
