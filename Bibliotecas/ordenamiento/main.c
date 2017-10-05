#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct
{
    char nombre[25];
} eNombre;

void ordenamiento(eNombre[], int);
void inicializar(eNombre[], int);
void mostrarTodo(eNombre[], int);
void mostrar(eNombre);

int main()
{
    eNombre listadenombres[TAM];

    inicializar(listadenombres, TAM);
    mostrarTodo(listadenombres, TAM);
    ordenamiento(listadenombres, TAM);
    mostrarTodo(listadenombres, TAM);
}

void inicializar(eNombre lista[], int tam)
{
    char nombre[][50] = {"C", "A", "D", "A", "F", "T", "Y", "O", "Z", "I"};
    int i;
    for(i = 0; i < tam; i++)
    {
        strcpy(lista[i].nombre, nombre[i]);
    }
}

void mostrarTodo(eNombre lista[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        mostrar(lista[i]);
    }
}

void mostrar(eNombre nombre)
{
    printf("Nombre: %s \n", nombre.nombre);
}

void ordenamiento(eNombre lista[], int tam)
{
    int i, j;
    eNombre auxiliar;
    for(i = 0; i < tam; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if(stricmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                auxiliar = lista[i];
                lista[i] = lista[j];
                lista[j] = auxiliar;
            }
        }
    }
}
