#include <stdio.h>
#include <stdlib.h>

// Função que verifica se um número é palíndromo
int eh_palindromo(int num) {
    if (num < 0) {
        return 0; // Números negativos não são considerados palíndromos
    }

    int original = num;   // Guarda o número original para comparar depois
    int invertido = 0;    // Variável que vai armazenar o número invertido

    // Enquanto ainda houver dígitos no número
    while (num > 0) {
        int digito = num % 10;               // Pega o último dígito do número
        invertido = invertido * 10 + digito; // Constrói o número invertido
        num /= 10;                           // Remove o último dígito do número
    }

    // Compara o número original com o número invertido
    if (original == invertido) {
        return 1; // É palíndromo
    } else {
        return 0; // Não é palíndromo
    }
}

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);
    getchar(); // Consome o ENTER que sobra do scanf

    if (eh_palindromo(numero)) {
        printf("E palindromo!\n");
    } else {
        printf("Nao e palindromo.\n");
    }

    getchar();
    return 0;
}
