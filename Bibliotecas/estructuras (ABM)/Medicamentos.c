#include <stdio.h>
#include <conio.h>
#include "Medicamentos.h"

void cargarMedicamentos(eMedicamento lista[], int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        if(lista[i].estado==0)
        {
            printf("Ingrese codigo: ");
            scanf("%d", &lista[i].codigo);
            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(lista[i].descripcion);
            printf("Ingrese precio: ");
            scanf("%f", &lista[i].precio);
            printf("Ingrese laboratorio: ");
            fflush(stdin);
            gets(lista[i].laboratorio);

            lista[i].estado = 1;

            break;
        }

    }
}

void mostraTodosMedicamentos(eMedicamento lista[], int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarMedicamento(lista[i]);
        }
    }
}

void mostrarMedicamento(eMedicamento med)
{
    printf("%d ---- %s ---- $%.2f ---- %s\n", med.codigo, med.descripcion, med.precio, med.laboratorio);
}

void ordenarMedicamentos(eMedicamento lista[], int tam)
{
    int i, j;
    eMedicamento auxMedicamento;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(stricmp(lista[i].laboratorio, lista[j].laboratorio)>0)
            {
                auxMedicamento=lista[i];
                lista[i]=lista[j];
                lista[j]=auxMedicamento;
            }
            else
            {
                if(stricmp(lista[i].laboratorio, lista[j].laboratorio) == 0)
                {
                    if(stricmp(lista[i].descripcion, lista[j].descripcion) > 0)
                    {
                        auxMedicamento=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxMedicamento;
                    }
                }
            }
        }
    }
}

void inicializarMedicamentos(eMedicamento lista[], int tam)
{
    int codigo[]= {1,2,3,4,5};
    char descripcion[][50]= {"Valium","Ibuprofeno","Diclofenac","Roma","Caracas"};
    float precio[]= {5,10,7,8,12};
    char laboratorio[][30]= {"Bago","Bayer","Roemer", "Bago", "Bago"};
    int estado[]= {1,1,1,1,1};

    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].codigo = codigo[i];
        lista[i].precio = precio[i];
        lista[i].estado = estado[i];
        strcpy(lista[i].descripcion,descripcion[i]);
        strcpy(lista[i].laboratorio,laboratorio[i]);
    }

}

void modificacionMedicamento(eMedicamento lista[], int tam)
{
    int i;
    int modif;
    printf("Ingrese codigo del medicamento para modificar: ");
    scanf("%d", &modif);

    for(i = 0; i < tam; i++)
    {
        if(modif != lista[i].codigo)
        {
            printf("El codigo ingresado no corresponde a uno ya ingresado\n");
            break;
        }
        else
        {
            printf("Ingrese el nuevo laboratorio para el codigo que quiere modificar");
        }
    }
}

void bajaMedicamento(eMedicamento baja[], int tam)
{

}

