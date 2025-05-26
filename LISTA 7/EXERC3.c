#include <stdio.h>
#include <string.h>

// Função que verifica se o valor x está presente no vetor A de tamanho T
int contem(int A[], int T, int x) {
	
	int i;
	
    for(i = 0; i < T; i++) {
        if(A[i] == x) {
            return 1;  // achou
        }
    }
    return 0;  // não achou
}

int main()
{
    int A[5], x, i;

    printf("Digite 5 valores para o vetor A:\n");
    for(i = 0; i < 5; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("Digite o valor que deseja procurar: ");
    scanf("%d", &x);

    if(contem(A, 5, x)) {
        printf("O valor %d esta presente no vetor.\n", x);
    } else {
        printf("O valor %d NAO esta presente no vetor.\n", x);
    }

    return 0;
}
