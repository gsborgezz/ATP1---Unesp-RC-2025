#include <stdio.h>
#include <stdlib.h>

int **soma_matrizes(int A[3][3], int B[3][3])
{
    int **C = alocar_matriz(3,3);
    for (int i = 0; i < 3; i++) 
    {
        C[i] = (int*)malloc(3 * sizeof(int));
    }
    // Realiza a soma
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}
