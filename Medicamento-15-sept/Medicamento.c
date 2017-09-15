#include <stdio.h>
#include <stdlib.h>
#include "Medicamento.h"

void inicializarMedicamentos(eMedicamento lista[], int sizeMed)
{
    int codigo[]= {1,2,3,4,5};
    char descripcion[][50]= {"Valium","Ibuprofeno","Diclofenac","Roma","Caracas"};
    float precio[]= {5,10,7,8,12};
    char laboratorio[][30]= {"Bago","Bayer","Roemer", "Bago", "Bago"};
    int estado[]= {1,1,1,1,1};
}

void inicializarLaboratorios(eLaboratorio lista[], int sizeLab)
{
    int idLaboratorio[] = {1, 2, 3};
    char nombre[][30] = {"Bayer", "Bago", "Roemmers"};
    char direccion[][30] = {"Av. de Mayo", "Liniers", "9 de Julio"};
    char telefono[][10] = {"4255-6989", "4698-8963", "4621-9810"};
}

void inicializarClientes(eCliente lista[], int sizeClien)
{
    int idCliente[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char nombre[][30] = {"Juan", "Mario", "Carlos", "Lautaro", "Diego", "Laura", "Pablo", "German", "Pedro", "Marcelo"};
    int codigoMedicamento[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
}

void mostrarMedicamentos(eMedicamento med)
{
    printf("%d ---- %s ---- $%.2f ---- %d\n", med.codigo, med.descripcion, med.precio, med.laboratorio);
}
