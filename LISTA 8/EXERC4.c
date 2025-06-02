#include <stdio.h>
#include <stdlib.h>

// Função que cria um novo vetor com os valores pares
int* filtrar_pares(int *v, int n, int *qtd_pares) 
{
    int *s = NULL;
    int i, cont = 0;

    for (i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            // Aumenta o vetor pra caber mais um par
            int *temp = realloc(s, (cont + 1) * sizeof(int));
            if (!temp) {
                printf("Erro ao alocar memoria.\n");
                free(s);
                *qtd_pares = 0;
                return NULL;
            }
            s = temp;
            s[cont] = v[i];
            cont++;
        }
    }

    *qtd_pares = cont;
    return s;
}

int main()
{
    int n, i;
    int *v, *s, qtd_pares;

    printf("Quantos numeros deseja digitar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Valor invalido.\n");
        return 1;
    }

    v = malloc(n * sizeof(int));
    if (!v) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    // Chama a função para pegar apenas os pares
    s = filtrar_pares(v, n, &qtd_pares);

    if (s != NULL && qtd_pares > 0) {
        printf("Valores pares encontrados:\n");
        for (i = 0; i < qtd_pares; i++) {
            printf("%d ", s[i]);
        }
        printf("\n");
    } else {
        printf("Nenhum numero par foi encontrado.\n");
    }

    // Libera a memória usada
    free(v);
    free(s);

    getchar();
    getchar();

    return 0;
}
