#include <stdio.h>
#include <stdlib.h>

int calcula_imc(float peso, float altura) 
{
    float imc = peso / (altura * altura);
    if (imc < 18.5)
    {
        return (0); 
    } 
        
    if (imc <= 24.9)
    {
        return (1);
    } 
        
    if (imc <= 29.9)
    {
        return (2);
    }

    if (imc > 29.9)
    {
        return(3);
    }          
    
}

void imprima_imc(float peso, float altura) 
{
    int result = calcula_imc(peso, altura);

    if(result == 0)
    {
        printf("Magreza");
    }

    else if(result == 1)
    {
        printf("Saudavel");
    }

    else if(result == 2)
    {
        printf("Sobrepeso");
    }

    else if(result == 3)
    {
        printf("Obesidade");
    }


}

int main() 
{
    float p, a;

    // Solicita ao usuário o peso e a altura
    scanf("%f %f", &p, &a);

    // Chama a função para imprimir a classificação do IMC
    imprima_imc(p, a);

    return 0;
}
