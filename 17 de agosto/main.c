#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entero;
    float flotante;
    char caracter;
    int otroInt = 999;

    entero = 9;
    flotante = 3.25;
    caracter = 'P';

    printf("Entero: %d -- Flotante: %.2f -- Caracter: %c\n", entero, flotante, caracter);
    scanf("%d", &entero);
    printf("Nuevo entero: %d\n", entero);

    int cont = 0;
    printf("Contando hasta diez\n");

    while(cont <= 9)
    {
        cont++;
        printf("%d\n", cont);
    }
}
