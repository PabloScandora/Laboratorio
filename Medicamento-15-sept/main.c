#include <stdio.h>
#include <stdlib.h>
#include "Medicamento.h"
#define TAM 5

int main()
{
    eMedicamento lista[TAM];
    int i;
    inicializarMedicamentos(lista, TAM);
    for(i = 0; i < TAM; i++)
    {
        mostrarMedicamentos(lista);
    }
    printf("FUNCIONA");
    printf("\n--------");
    return 0;
}
