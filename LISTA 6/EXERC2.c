#include <stdio.h>
#include <stdlib.h>

// Função recursiva para somar de 1 até n
int somaRecursiva(int n) 
{
    if (n <= 1) 
    {
        return n; // Caso base: se n é 1 ou 0, retorna n
    }
    return n + somaRecursiva(n - 1); // Passo recursivo
}

int main() 
{
    int numero;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 1) {
        printf("O número deve ser maior ou igual a 1.\n");
    } else {
        int resultado = somaRecursiva(numero);
        printf("A soma de 1 até %d é: %d\n", numero, resultado);
    }

    getchar(); // Para pausar antes de sair
    getchar();
    return 0;
}
