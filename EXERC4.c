#include <stdio.h>
#include <math.h>  // Para a função sqrt()

// Função que verifica se o número é primo
int eh_primo(int n) {
    if (n <= 1) {
        return 0;  // Números menores ou iguais a 1 não são primos
    }

    // Verifica divisibilidade de 2 até a raiz quadrada de n
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;  // Encontrou um divisor, não é primo
        }
    }

    return 1;  // Não encontrou divisores, o número é primo
}

int main() 
{
    int numero;

    // Leitura do número
    printf("Digite um número para verificar se é primo: ");
    scanf("%d", &numero);

    // Chama a função e verifica se o número é primo
    if (eh_primo(numero)) {
        printf("%d é primo.\n", numero);
    } else {
        printf("%d não é primo.\n", numero);
    }

    return 0;
}
