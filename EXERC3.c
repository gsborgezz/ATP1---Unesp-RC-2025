#include <stdio.h>
#include <stdlib.h>



float celsius_para_fahrenheit(float celsius) 
{
    return ((celsius * 9.0f / 5.0f) + 32.0f);
}

int main() 
{
    float celsius;

    scanf("%f",&celsius);
    printf("Valor em Fahrenheit: %f",celsius_para_fahrenheit(celsius));

    

    getchar();
    return 0;
}