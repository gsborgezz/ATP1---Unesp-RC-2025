#include <stdio.h>
#include <stdlib.h>

// Função recursiva para contar os dígitos de um número inteiro
int contarDigitos(int n) 
{
    if (n < 0) {
        n = -n; // Torna o número positivo para simplificar a contagem
    }

    if (n < 10) {
        return 1; // Caso base: números de 0 a 9 têm 1 dígito
    }

    return 1 + contarDigitos(n / 10); // Divide por 10 e conta recursivamente
}

int main() 
{
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    int quantidade = contarDigitos(numero);
    printf("O número %d tem %d dígito(s).\n", numero, quantidade);

    getchar(); // Pausa antes de sair
    getchar();
    return 0;
}
