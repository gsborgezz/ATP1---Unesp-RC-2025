include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para arredondar um número para uma quantidade de casas decimais
double arredondar(double valor, int casas) 
{
    if (casas < 0) {
        casas = 0; // Se o número de casas for negativo, arredonda para 0 casas
    }

    double fator = pow(10, casas); // Calcula 10 elevado ao número de casas
    double resultado = round(valor * fator) / fator; // Faz o arredondamento

    return resultado; // Retorna o número já arredondado
}

int main() 
{
    double numero;
    int casas;

    // Pede o número para o usuário
    printf("Digite o número que deseja arredondar: ");
    scanf("%lf", &numero);

    // Pede o número de casas decimais
    printf("Digite o número de casas decimais (digite -1 para usar 0 casas): ");
    scanf("%d", &casas);

    // Chama a função e mostra o resultado
    double resultado = arredondar(numero, casas);
    printf("Resultado arredondado: %.10f\n", resultado); // Mostra até 10 casas pra garantir

    getchar(); 
    return 0; 
}
