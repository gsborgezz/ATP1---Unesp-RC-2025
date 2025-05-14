#include <stdio.h>
#include <stdlib.h>

// Função recursiva para calcular base^expoente
int potencia(int base, int expoente) {
    if (expoente == 0)
        return 1;  // Caso base: qualquer número elevado a 0 é 1
    else
        return base * potencia(base, expoente - 1);  // Passo recursivo
}

int main() {
    int base, expoente;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente (positivo): ");
    scanf("%d", &expoente);

    if (expoente < 0) {
        printf("Erro: o expoente deve ser positivo.\n");
    } else {
        int resultado = potencia(base, expoente);
        printf("%d elevado a %d é %d\n", base, expoente, resultado);
    }

    getchar(); // Para manter a janela aberta (em alguns sistemas)
    return 0;
}
