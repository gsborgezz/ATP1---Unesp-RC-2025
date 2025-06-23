#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para verificar se o número é primo
int ehPrimo(int num) 
{
    if (num < 2) 
    { // Números menores que 2 não são primos
        return 0;
    }

    // Testa se o número tem algum divisor além de 1 e ele mesmo
    for (int i = 2; i <= sqrt(num); i++) 
    {
        if (num % i == 0) 
        {
            return 0; // Não é primo
        }
    }

    return 1; // Se passou por tudo sem achar divisor, é primo
}

int main() 
{
    int inicio, fim;

    // Pede para o usuário digitar o intervalo
    printf("Digite o valor inicial: ");
    scanf("%d", &inicio);

    printf("Digite o valor final: ");
    scanf("%d", &fim);

    // Verifica se o intervalo faz sentido
    if (inicio > fim) 
    {
        printf("O valor inicial deve ser menor ou igual ao final.\n");
        getchar(); 
        return 1;
    }

    // Mostra os primos dentro do intervalo
    printf("Números primos entre %d e %d:\n", inicio, fim);

    for (int i = inicio; i <= fim; i++) {
        if (ehPrimo(i)) {
            printf("%d ", i); // Imprime o número primo
        }
    }

    printf("\n");

    getchar(); 
    return 0; 
}
