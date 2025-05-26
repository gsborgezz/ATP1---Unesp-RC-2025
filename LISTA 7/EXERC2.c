#include <stdio.h>
#include <string.h>

int main() 
{
    int A[5], B[5], i;

    printf("Digite os valores do vetor A: ");
    scanf("%d %d %d %d %d", &A[0], &A[1], &A[2], &A[3], &A[4]);
    
    printf("Digite os valores do vetor B: ");
    scanf("%d %d %d %d %d", &B[0], &B[1], &B[2], &B[3], &B[4]);

    printf("\nValores intercalados:\n");
    for(i = 0; i < 5; i++) {
        printf("%d %d ", A[i], B[i]);  // imprime A[i] e B[i] na mesma linha, com espaço
    }

    printf("\n");  // quebra de linha final

    return 0;
}
