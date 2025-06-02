#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, i;
    int *v;

    // Pede ao usuário quantos números ele vai digitar
    printf("Quantos numeros deseja armazenar? ");
    scanf("%d", &n);

    // Verifica se o valor é válido
    if (n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    // Aloca espaço na memória para armazenar os números
    v = malloc(n * sizeof(int));
    if (!v) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Pede os números um por um
    for (i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    // Mostra os valores que foram armazenados
    printf("Valores armazenados:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");

    // Libera a memória que foi alocada
    free(v);

    // Pausa antes de sair (só pra manter a tela parada se precisar)
    getchar();
    getchar();

    return 0;
}
