#include <stdio.h>
#define PI 3.14159

void calcular_circulo(float raio, float *perimetro, float *area) {
    *perimetro = 2 * PI * raio;
    *area = PI * raio * raio;
}

int main() {
    float raio, perimetro, area;

    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);

    calcular_circulo(raio, &perimetro, &area);

    printf("Perimetro: %.2f\n", perimetro);
    printf("Area: %.2f\n", area);

    getchar(); // Para segurar a tela
    
    return 0;
}
