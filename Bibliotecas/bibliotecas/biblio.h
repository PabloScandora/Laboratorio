typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    char nombre[25];
} eNombre;

typedef struct
{
    int codigo;
    int idMedicamento;
    char descripcion[50];
    float precio;
    char laboratorio[30];
    int estado;
} eMedicamento;

typedef struct
{
    int id;
    char razonSocial[25];
    char direccion[50];
    char telefono[20];
} eLaboratorio;

typedef struct
{
    int idCliente;
    int id;
    char nombre[50];
    char dni[15];
    int idMedicamento;
} eCliente;



void inicioDeLaboratorio(eLaboratorio laboratorios[], int tamLab);
void mostrarLaboratorios(eLaboratorio laboratorios[], int tamLab);
void inicioDeCliente(eCliente clientes[], int tamCliente);
void mostrarClientes(eCliente clientes[], int tamCliente);
void mostrarLaboratorioYCliente(eCliente[], int tamCliente, eLaboratorio[], int tamLab);
void ordenarMedicamentosDobleCriterio(eMedicamento lista[], int tam);
void modificacionMedicamento(eMedicamento lista[], int tam);
void bajaMed(eMedicamento lista[], int tam);
void mostrarClientesConMedicamento(eCliente[], int, eMedicamento[], int);
void mostrarClientesIbuprofeno(eCliente[], int, eMedicamento[], int);
//---------------------------------------------
void ordenamiento(eNombre[], int);
void inicializar(eNombre[], int);
void mostrarTodo(eNombre[], int);
void mostrar(eNombre);
