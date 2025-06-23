#include <stdio.h>
#include <stdlib.h>

#define MAX 100

main()
{
  FILE *arquivo;                 // Ponteiro para arquivo
  int matrizA[MAX][MAX];         // Matriz A
  int matrizB[MAX][MAX];         // Matriz B
  int matrizSoma[MAX][MAX];      // Matriz que vai guardar a soma das duas
  int n;                        // Dimensão da matriz (n x n)

  // Abre o arquivo "matriz.txt" para leitura
  arquivo = fopen("matriz.txt", "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo matriz.txt\n");
    return 1; // Sai do programa se não conseguir abrir o arquivo
  }

  // Lê a dimensão da matriz, que está na primeira linha do arquivo
  fscanf(arquivo, "%d", &n);

  // Lê os valores da matriz A (n linhas e n colunas)
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      fscanf(arquivo, "%d", &matrizA[i][j]);
    }
  }

  // Lê os valores da matriz B (também n linhas e n colunas)
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      fscanf(arquivo, "%d", &matrizB[i][j]);
    }
  }

  // Fecha o arquivo após a leitura das matrizes
  fclose(arquivo);

  // Calcula a soma das matrizes A e B e armazena na matrizSoma
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matrizSoma[i][j] = matrizA[i][j] + matrizB[i][j]; // Soma elemento a elemento
    }
  }

  // Exibe a matriz soma na tela, formatada como matriz
  printf("Matriz Soma:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", matrizSoma[i][j]); // Imprime o elemento da linha i, coluna j
    }
    printf("\n"); // Quebra a linha para imprimir a próxima linha da matriz
  }

  getchar(); // Pausa o programa para o usuário ver o resultado (no Windows)
  return 0;  // Fim do programa
}
