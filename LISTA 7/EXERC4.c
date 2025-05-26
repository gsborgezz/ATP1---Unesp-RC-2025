#include <stdio.h>
#include <string.h>

void imprimirElementos(int A[], int B[], int T) 
{
    printf("Elementos em comum:\n");
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            if (A[i] == B[j]) {
                // Verifica se já foi impresso
                int ja_impresso = 0;
                for (int k = 0; k < i; k++) {
                    if (A[k] == A[i]) {
                        ja_impresso = 1;
                        break;
                    }
                }
                if (!ja_impresso) {
                    printf("%d ", A[i]);
                }
                break; // Evita múltiplas impressões do mesmo valor em B
            }
        }
    }
    printf("\n");
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {3, 4, 5, 6, 7};
    int T = 5;

    imprimirElementos(A, B, T);

    getchar(); // Para manter a janela aberta em alguns ambientes
    return 0;
}
