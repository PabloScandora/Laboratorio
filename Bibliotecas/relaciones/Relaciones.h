#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idLaboratorio; //PK
    char razonSocial[25];
    char direccion[50];
    char telefono[20];
} eLaboratorio;

typedef struct
{
    int idMedicamento; //PK
    char descripcion[50];
    float precio;
    int idLaboratorio; //FK
    int stock;
    eFecha fechaElaboracion;
    eFecha fechaVencimiento;
} eMedicamento;

typedef struct
{
    int idCliente; //PK
    char nombre[50];
    int idMedicamento; //FK
} eCliente;

typedef struct
{
    int idCliente; //FK
    int idMedicamento; //FK
    eFecha fechaVenta;
    int cantidad;
} eClienteMedicamento;


void inicializarLaboratorios(eLaboratorio[], int);
void inicializarMedicamentos(eMedicamento[], int);
void inicializarClientes(eCliente[], int);
void mostrarMedicamentos(eMedicamento[], int);
void mostrarClientes(eCliente[], int);
void mostrarClientesConMedicamento(eCliente[], int, eMedicamento[], int);
void mostrarClientesIbuprofeno(eCliente[], int, eMedicamento[], int);


/** \brief
 *
 * \param laboratorios[] eLaboratorio
 * \param sizeLab int
 * \return void
 *
 */
void inicializarLaboratorios(eLaboratorio laboratorios[], int sizeLab)
{
    int id[]= {1,2,3};
    char razon[][30]= {"Roemers","Bago","Bayer"};
    char direccion[][30]= {"mitre 750","Belgrano 788","Sarmiento 1258"};
    char telefono[][30]= {"12345","678910","1112131415"};
    int i;

    for(i=0; i<sizeLab; i++)
    {
        laboratorios[i].idLaboratorio=id[i];
        strcpy(laboratorios[i].razonSocial, razon[i]);
        strcpy(laboratorios[i].direccion, direccion[i]);
        strcpy(laboratorios[i].telefono, telefono[i]);
    }
}

/** \brief
 *
 * \param medicamentos[] eMedicamento
 * \param sizeMed int
 * \return void
 *
 */
void inicializarMedicamentos(eMedicamento medicamentos[], int sizeMed)
{

    int id[]= {100,101,102,103,104};
    char descripcion[][30]= {"Ibuprofeno","Tafirol","Diclofenac","Bayaspirina", "Mejoralito"};
    float precio[]= {60,85,105,15,28};
    int laboratorio[]= {1,1,2,3,3,1};
    int stock[]= {3,2,3,10,0};
    eFecha elaboracion[]= {{22,9,2017},{15,2,2016},{10,6,2016},{22,9,2017},{5,10,2000}};
    eFecha vencimiento[]= {{22,9,2030},{5,12,2017},{30,8,2019},{3,12,2020},{12,8,2005}};
    int i;

    for(i=0; i<sizeMed; i++)
    {
        medicamentos[i].idMedicamento=id[i];
        strcpy(medicamentos[i].descripcion, descripcion[i]);
        medicamentos[i].precio = precio[i];
        medicamentos[i].idLaboratorio=laboratorio[i];
        medicamentos[i].stock = stock[i];
        medicamentos[i].fechaElaboracion=elaboracion[i];
        medicamentos[i].fechaVencimiento=vencimiento[i];

    }
}

/** \brief
 *
 * \param clientes[] eCliente
 * \param sizeCli int
 * \return void
 *
 */
void inicializarClientes(eCliente clientes[], int sizeCli)
{

    int id[]= {111,222,333,444,555,666,777,888,999,101010};
    char nombre[][30]= {"Geronimo","Adalberto","Inocencia","Felipe","Lucrecia","Ermenegildo","Efigenia","Dora","Anastacia","Armando"};
    int medicamento[]= {104,100,101,101,101,102,103,101,101,100};
    int i;

    for(i=0; i<sizeCli; i++)
    {
        clientes[i].idCliente=id[i];
        strcpy(clientes[i].nombre, nombre[i]);
        clientes[i].idMedicamento=medicamento[i];
    }
}

/** \brief
 *
 * \param medicamentos[] eMedicamento
 * \param sizeMed int
 * \return void
 *
 */
void mostrarMedicamentos(eMedicamento medicamentos[], int sizeMed)
{
    int i;
    printf("ID\t%10s\tPRECIO\tLAB\tSTOCK\tF. ELAB\t\tF.VTO\n", "DESCRIPCION");
    for(i=0; i<sizeMed; i++)
    {
        printf("%d\t%10s\t%.2f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\n", medicamentos[i].idMedicamento
               ,medicamentos[i].descripcion, medicamentos[i].precio, medicamentos[i].idLaboratorio
               ,medicamentos[i].stock, medicamentos[i].fechaElaboracion.dia, medicamentos[i].fechaElaboracion.mes
               ,medicamentos[i].fechaElaboracion.anio,medicamentos[i].fechaVencimiento.dia
               ,medicamentos[i].fechaVencimiento.mes,medicamentos[i].fechaVencimiento.anio);
    }

}

/** \brief
 *
 * \param clientes[] eCliente
 * \param sizeCli int
 * \return void
 *
 */
void mostrarClientes(eCliente clientes[], int sizeCli)
{
    int i;
    printf("ID\t%10s\tMEDICAMENTO\n", "NOMBRE");
    for(i=0; i<sizeCli; i++)
    {
        printf("%d\t%10s\t%d\n", clientes[i].idCliente, clientes[i].nombre, clientes[i].idMedicamento);
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
