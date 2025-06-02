#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *v = NULL;
    int num, tamanho = 0;

    while (1) {
        printf("Digite um numero (-1 para parar): ");
        scanf("%d", &num);

        // Se o usuário digitar -1, termina o loop
        if (num == -1) {
            break;
        }

        // Realoca o vetor para caber mais um número
        int *temp = realloc(v, (tamanho + 1) * sizeof(int));
        if (!temp) {
            printf("Erro ao realocar memoria.\n");
            free(v);
            return 1;
        }

        v = temp;
        v[tamanho] = num;
        tamanho++;
    }

    // Mostra os números armazenados
    printf("Valores armazenados:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");

    // Libera a memória usada
    free(v);

    getchar();
    getchar();

    return 0;
}
