#include <stdio.h>
#include <stdlib.h>

// Função para calcular a transposta de uma matriz 3x3
void calcularTransposta(int matriz[3][3], int transposta[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
}
