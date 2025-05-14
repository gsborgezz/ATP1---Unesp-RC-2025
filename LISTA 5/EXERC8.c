#include <stdio.h>
#include <math.h> // Necessário para a função sqrt()

// Função que calcula a distância euclidiana entre dois pontos (x1, y1) e (x2, y2)
double distancia(int x1, int y1, int x2, int y2) {
    // Calcula a distância usando a fórmula de distância euclidiana
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    int x1, y1, x2, y2;

    // Lê as coordenadas dos pontos
    printf("Digite as coordenadas do primeiro ponto (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Digite as coordenadas do segundo ponto (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Chama a função para calcular a distância e imprime o resultado
    printf("A distancia entre os pontos e: %.2f\n", distancia(x1, y1, x2, y2));

    return 0;
}
