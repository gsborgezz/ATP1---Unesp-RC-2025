#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);  // lê uma palavra (sem espaços)

    char primeira_letra = palavra[0];  // pega a primeira letra

    printf("%s comeca com %c\n", palavra, primeira_letra);

    return 0;
}
