#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função recursiva que retorna um número aleatório entre 2 e 12
int gerarNumeroEntre2e12() {
    int numero = rand() % 13; // Gera um número entre 0 e 12
    if (numero < 2) {
        // Se o número for menor que 2, chama recursivamente até obter um válido
        return gerarNumeroEntre2e12();
    }
    return numero;
}

int main() {
    // Inicializa a semente do gerador aleatório com o tempo atual
    srand(time(NULL));

    // Chama a função recursiva e imprime o número
    int resultado = gerarNumeroEntre2e12();
    printf("Numero aleatorio entre 2 e 12: %d\n", resultado);

    getchar(); // Pausa o programa até que o usuário pressione Enter
    return 0;
}
