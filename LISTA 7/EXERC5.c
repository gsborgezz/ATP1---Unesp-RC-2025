#include <stdio.h>
#include <string.h>

void inverterArray(int *inicio, int *fim) 
{
    while (inicio < fim) {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }
}

int main() 
{
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original: ");
    for (int i = 0; i < tamanho; i++) 
    {
        printf("%d ", vetor[i]);
    }

    inverterArray(vetor, vetor + tamanho - 1);

    printf("\nVetor invertido: ");
    for (int i = 0; i < tamanho; i++) 
    {
        printf("%d ", vetor[i]);
    }

    getchar(); // Para manter a janela aberta em alguns ambientes
    return 0;
}
