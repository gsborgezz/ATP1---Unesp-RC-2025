#include <stdio.h>
#include <stdlib.h>

#define MAX_ITENS 100
#define MAX_NOME 50

typedef struct {
  char nome[MAX_NOME];
  float preco;
} ItemMenu;

main()
{
  // Declaração dos ponteiros para arquivos
  FILE *arquivoMenu;    // Ponteiro para arquivo do menu (leitura)
  FILE *arquivoBoleto;  // Ponteiro para arquivo do boleto (escrita)

  int quantidadeItens;
  ItemMenu itens[MAX_ITENS];
  int escolha, quantidadeCompra;
  float total = 0;

  // Abre o arquivo menu.txt para ler o cardápio
  // fopen retorna um ponteiro FILE* que aponta para o arquivo aberto
  arquivoMenu = fopen("menu.txt", "r"); // "r" = modo leitura
  if (arquivoMenu == NULL) // Verifica se o arquivo abriu corretamente
  {
    printf("Erro ao abrir o arquivo menu.txt\n");
    return 1;
  }

  // Lê a quantidade de itens que o cardápio tem (primeira linha)
  fscanf(arquivoMenu, "%d", &quantidadeItens);

  // Lê nome e preço de cada item do cardápio
  for (int i = 0; i < quantidadeItens; i++)
    fscanf(arquivoMenu, "%s %f", itens[i].nome, &itens[i].preco);

  fclose(arquivoMenu); // Fecha o arquivo para liberar o recurso no sistema

  // Abre boleto.txt para gravar o pedido do cliente
  // fopen no modo "w" cria o arquivo ou sobrescreve se já existir
  arquivoBoleto = fopen("boleto.txt", "w");
  if (arquivoBoleto == NULL) // Verifica se o arquivo foi criado corretamente
  {
    printf("Erro ao criar o arquivo boleto.txt\n");
    return 1;
  }

  fprintf(arquivoBoleto, "Pedido:\n"); // Cabeçalho simples do boleto

  do
  {
    // Mostra o menu para o cliente escolher
    printf("\nMenu:\n");
    for (int i = 0; i < quantidadeItens; i++)
      printf("%d - %s - R$ %.2f\n", i + 1, itens[i].nome, itens[i].preco);

    printf("0 - Finalizar pedido\n");
    printf("Escolha um item pelo número: ");
    scanf("%d", &escolha);

    if (escolha > 0 && escolha <= quantidadeItens)
    {
      printf("Quantidade do item %s: ", itens[escolha - 1].nome);
      scanf("%d", &quantidadeCompra);

      float precoItem = itens[escolha - 1].preco * quantidadeCompra;
      total += precoItem;

      // Escreve o item comprado no arquivo boleto.txt
      fprintf(arquivoBoleto, "%s %d R$ %.2f\n", itens[escolha - 1].nome, quantidadeCompra, precoItem);

      printf("Item adicionado.\n");
    }
    else if (escolha != 0)
    {
      printf("Opção inválida, tente novamente.\n");
    }

  } while (escolha != 0);

  fprintf(arquivoBoleto, "Total R$ %.2f\n", total);

  fclose(arquivoBoleto); // Fecha o arquivo boleto.txt para salvar tudo

  printf("\nPedido finalizado! Boleto salvo no arquivo boleto.txt\n");

  getchar();
  return 0;
}
