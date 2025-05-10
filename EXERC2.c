#include <stdio.h>
#include <stdlib.h>

float a = 2.0f;
float b = 3.0f;

float quadratica(float x) {
    return a * x * x + b * x + c; 
}

int main() 
{
    int x;

    scanf("%d", &x);

    printf("y(%.2f) = %.2f * %.2f + %.2f = %.2f\n", x, a, x, b, quadratica(x));

    getchar();
    return 0;
}