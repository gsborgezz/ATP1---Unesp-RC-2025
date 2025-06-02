#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, i;
    int *v;

    // Pede ao usuário o tamanho do vetor
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    // Verifica se o valor é válido
    if (n < 1) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    // Aloca memória para o vetor
    v = malloc(n * sizeof(int));
    if (!v) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    // Preenche o vetor com valores de 0 até n-1
    for (i = 0; i < n; i++) {
        v[i] = i;
    }

    // Mostra os valores na tela
    printf("Valores no vetor:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");

    // Libera a memória usada
    free(v);

    // Pausa antes de sair (útil em alguns casos no Windows)
    getchar(); // lê o Enter que ficou no buffer
    getchar(); // espera o usuário apertar Enter

    return 0;
}
