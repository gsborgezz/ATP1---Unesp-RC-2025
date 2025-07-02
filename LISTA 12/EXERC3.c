#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da matriz
typedef struct No {
  int valor;               // Valor do elemento da matriz
  struct No *direita;      // Ponteiro para o próximo elemento na mesma linha
  struct No *abaixo;       // Ponteiro para o próximo elemento na mesma coluna
} No;

// Estrutura principal da matriz
typedef struct {
  int linhas;              // Quantidade de linhas
  int colunas;             // Quantidade de colunas
  No *inicio;              // Ponteiro para o primeiro nó (canto superior esquerdo)
} Matriz;

// Função que cria um novo nó com valor 0
No* criarNo()
{
  No *novo = (No*) malloc(sizeof(No));
  if (novo == NULL) {
    printf("Erro ao alocar memória!\n");
    exit(1);
  }

  novo->valor = 0;
  novo->direita = NULL;
  novo->abaixo = NULL;

  return novo;
}

// Função para criar a matriz encadeada com todos os valores iniciando em 0
Matriz* criarMatriz(int linhas, int colunas)
{
  int i, j;

  Matriz *mat = (Matriz*) malloc(sizeof(Matriz));
  mat->linhas = linhas;
  mat->colunas = colunas;
  mat->inicio = NULL;

  // Vetor para guardar os primeiros nós de cada linha (usado para ligar os "abaixo")
  No *linhaAnterior[colunas];

  for (j = 0; j < colunas; j++) {
    linhaAnterior[j] = NULL;
  }

  No *linhaAtual, *anterior;

  for (i = 0; i < linhas; i++) {
    anterior = NULL;
    for (j = 0; j < colunas; j++) {
      No *novo = criarNo();

      // Define o primeiro nó da matriz
      if (i == 0 && j == 0) {
        mat->inicio = novo;
      }

      // Liga o nó à esquerda (se existir)
      if (anterior != NULL) {
        anterior->direita = novo;
      }

      anterior = novo;

      // Liga com o nó acima (se existir)
      if (linhaAnterior[j] != NULL) {
        linhaAnterior[j]->abaixo = novo;
      }

      // Atualiza a posição para a próxima linha
      linhaAnterior[j] = novo;
    }
  }

  return mat;
}

// Função para imprimir os valores da matriz
void imprimirMatriz(Matriz *mat)
{
  No *linha, *coluna;
  linha = mat->inicio;

  while (linha != NULL) {
    coluna = linha;
    while (coluna != NULL) {
      printf("%d ", coluna->valor);
      coluna = coluna->direita;
    }
    printf("\n");
    linha = linha->abaixo;
  }
}

// Função principal
main()
{
  int linhas = 3, colunas = 4;

  Matriz *mat = criarMatriz(linhas, colunas);

  printf("Matriz criada (%dx%d):\n", linhas, colunas);
  imprimirMatriz(mat);

  getchar(); // Espera o Enter antes de sair
  return 0;
}
