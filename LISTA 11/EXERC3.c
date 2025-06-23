#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_COLUNAS 5
#define TOTAL_LINHAS 5

// Função para gerar um número aleatório dentro de um intervalo
int gerarNumero(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}

// Função para preencher uma coluna com números únicos
void preencherColuna(int *coluna, int min, int max, int tamanho, int temFree) 
{
    int count = 0;
    while (count < tamanho) 
    {
        int num = gerarNumero(min, max);
        int repetido = 0;

        // Verifica se o número já foi sorteado na coluna
        for (int i = 0; i < count; i++) 
        {
            if (coluna[i] == num) 
            {
                repetido = 1;
                break;
            }
        }

        if (!repetido)
        {
            coluna[count] = num;
            count++;
        }
    }

    // Se for a coluna N, coloca o espaço "FREE" no meio
    if (temFree) 
    {
        coluna[2] = -1; // Representa o espaço livre
    }
}

int main() 
{
    int quantidade;

    // Inicializa a semente do random com o tempo atual
    srand(time(NULL));

    // Pede ao usuário quantas cartelas ele quer gerar
    printf("Quantas cartelas deseja gerar? ");
    scanf("%d", &quantidade);

    // Abre o arquivo CSV para escrita
    FILE *arquivo = fopen("cartelas_bingo.csv", "w");
    if (arquivo == NULL) 
    {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    // Escreve o cabeçalho do CSV
    fprintf(arquivo, "B,I,N,G,O\n");

    for (int c = 0; c < quantidade; c++) 
    {
        int B[5], I[5], N[5], G[5], O[5];

        // Preenche cada coluna com os números certos
        preencherColuna(B, 1, 15, 5, 0);
        preencherColuna(I, 16, 30, 5, 0);
        preencherColuna(N, 31, 45, 5, 1); // Coluna N tem espaço livre
        preencherColuna(G, 46, 60, 5, 0);
        preencherColuna(O, 61, 75, 5, 0);

        // Escreve a cartela no CSV (linha por linha)
        for (int i = 0; i < 5; i++) 
        {
            if (N[i] == -1) 
            {
                fprintf(arquivo, "%d,%d,FREE,%d,%d\n", B[i], I[i], G[i], O[i]);
            }
            else 
            {
                fprintf(arquivo, "%d,%d,%d,%d,%d\n", B[i], I[i], N[i], G[i], O[i]);
            }
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Cartelas geradas com sucesso no arquivo 'cartelas_bingo.csv'!\n");

    getchar();
    return 0;
