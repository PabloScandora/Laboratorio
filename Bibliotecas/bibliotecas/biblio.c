#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <conio.h>
#include "biblio.h"


/** \brief
 *
 * \param laboratorios[] eLaboratorio
 * \param tamLab int
 * \return void
 *
 */
void inicioDeLaboratorio(eLaboratorio laboratorios[], int tamLab)
{
    int id[] = {1, 2, 3};
    char razon[][30] = {"Una", "Dos", "Tres"};
    char direccion[][30] = {"Primera", "Segunda", "Tercera"};
    char telefono[][30] = {"4534-3423", "4549-5435", "4234-3754"};

    int i;
    for(i = 0; i < tamLab; i++)
    {
        laboratorios[i].id = id[i];
        strcpy(laboratorios[i].razonSocial, razon[i]);
        strcpy(laboratorios[i].direccion, direccion[i]);
        strcpy(laboratorios[i].telefono, telefono[i]);
    }
}

/** \brief
 *
 * \param clientes[] eCliente
 * \param tamCliente int
 * \return void
 *
 */
void inicioDeCliente(eCliente clientes[], int tamCliente)
{
    int id[] = {100, 200, 300};
    char nombre[][50] = {"Juan", "Ricardo", "Alberto"};
    char dni[][15] = {"36.565.153", "32.235.987", "40.123.598"};

    int i;
    for(i = 0; i < tamCliente; i++)
    {
        clientes[i].id = id[i];
        strcpy(clientes[i].nombre, nombre[i]);
        strcpy(clientes[i].dni, dni[i]);
    }
}

/** \brief
 *
 * \param laboratorios[] eLaboratorio
 * \param tamLab int
 * \return void
 *
 */
void mostrarLaboratorios(eLaboratorio laboratorios[], int tamLab)
{
    int i;

    for(i = 0; i < tamLab; i++)
    {
        printf("%d -- %s -- %s -- %s \n", laboratorios[i].id, laboratorios[i].razonSocial,
               laboratorios[i].direccion, laboratorios[i].telefono);
    }
}

/** \brief
 *
 * \param clientes[] eCliente
 * \param tamCliente int
 * \return void
 *
 */
void mostrarClientes(eCliente clientes[], int tamCliente)
{
    int i;
    printf("************************************************* \n");

    for(i = 0; i < tamCliente; i++)
    {
        printf("%d -- %s -- %s \n", clientes[i].id, clientes[i].nombre, clientes[i].dni);
    }
}

/** \brief
 *
 * \param clientes[] eCliente
 * \param tamCliente int
 * \param laboratorios[] eLaboratorio
 * \param tamLab int
 * \return void
 *
 */
void mostrarLaboratorioYCliente(eCliente clientes[], int tamCliente, eLaboratorio laboratorios[], int tamLab)
{
    int i;
    int j;
    printf("************************************************* \nmostrarLaboratorioYCliente \n");
    for(i = 0; i < tamCliente; i++)
    {
        printf("%d -- %s -- ", clientes[i].id, clientes[i].nombre);
        printf("%d -- %s -- Tel: %s \n", laboratorios[i].id, laboratorios[i].razonSocial, laboratorios[i].telefono);
    }
}

/** \brief
 *
 * \param lista[] eMedicamento
 * \param tam int
 * \return void
 *
 */
void ordenarMedicamentosDobleCriterio(eMedicamento lista[], int tam)
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

/** \brief
 *
 * \param lista[] eMedicamento
 * \param tam int
 * \return void
 *
 */
void modificacionMedicamento(eMedicamento lista[], int tam)
{
    int i;
    int modif;
    printf("Ingrese codigo del medicamento para modificar: ");
    scanf("%d", &modif);

    for(i = 0; i < tam; i++)
    {
        if(modif == lista[i].codigo)
        {
            printf("Se modificara el codigo ingresado\n");
            break;
        }
    }
}

/** \brief
 *
 * \param lista[] eMedicamento
 * \param tam int
 * \return void
 *
 */
void bajaMed(eMedicamento lista[], int tam)
{
    int i;
    int modif;
    printf("Ingrese codigo del medicamento para eliminar: ");
    scanf("%d", &modif);

    for(i = 0; i < tam; i++)
    {
        if(modif == lista[i].codigo)
        {
            printf("Se modificara el codigo ingresado\n");
            break;
        }
    }
}

/** \brief
 *
 * \param clientes[] eCliente
 * \param sizeCli int
 * \param medicamentos[] eMedicamento
 * \param sizeMed int
 * \return void
 *
 */
void mostrarClientesConMedicamento(eCliente clientes[], int sizeCli, eMedicamento medicamentos[], int sizeMed)
{
    int i, j;
    printf("ID\t%10s\tMEDICAMENTO\n", "NOMBRE");
    for(i=0; i<sizeCli; i++)
    {
        printf("%d\t%10s\t", clientes[i].idCliente, clientes[i].nombre);
        for(j=0; j<sizeMed; j++)
        {
            if(clientes[i].idMedicamento==medicamentos[j].idMedicamento)
            {
                printf("%s\n", medicamentos[j].descripcion);
                break;
            }
        }
    }
}

/** \brief
 *
 * \param clientes[] eCliente
 * \param sizeCli int
 * \param medicamentos[] eMedicamento
 * \param sizeMed int
 * \return void
 *
 */
void mostrarClientesIbuprofeno(eCliente clientes[], int sizeCli, eMedicamento medicamentos[], int sizeMed)
{
    int idIbuprofeno;
    int i, j;

    for(i=0; i<sizeMed; i++)
    {
        if(strcmp(medicamentos[i].descripcion,"Ibuprofeno")==0)
        {
            idIbuprofeno = medicamentos[i].idMedicamento;
            break;
        }
    }
    printf("ID\t%10s\n", "NOMBRE");
    for(j=0; j<sizeCli; j++)
    {
        if(clientes[j].idMedicamento==idIbuprofeno)
        {
            printf("%d\t%10s\n", clientes[j].idCliente, clientes[j].nombre);
        }
    }


}

/** \brief
 *
 * \param lista[] eNombre
 * \param tam int
 * \return void
 *
 */
void inicializar(eNombre lista[], int tam)
{
    char nombre[][50] = {"C", "A", "D", "A", "F", "T", "Y", "O", "Z", "I"};
    int i;
    for(i = 0; i < tam; i++)
    {
        strcpy(lista[i].nombre, nombre[i]);
    }
}

/** \brief
 *
 * \param lista[] eNombre
 * \param tam int
 * \return void
 *
 */
void mostrarTodo(eNombre lista[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        mostrar(lista[i]);
    }
}

/** \brief
 *
 * \param nombre eNombre
 * \return void
 *
 */
void mostrar(eNombre nombre)
{
    printf("Nombre: %s \n", nombre.nombre);
}

/** \brief
 *
 * \param lista[] eNombre
 * \param tam int
 * \return void
 *
 */
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
