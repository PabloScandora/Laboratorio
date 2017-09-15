typedef struct
{
    int codigo;
    char descripcion[50];
    float precio;
    int laboratorio;
    int stock;
    int diaElab;
    int mesElab;
    int anioElab;
    int diaVenc;
    int mesVenc;
    int anioVenc;
    int estado;
} eMedicamento;

typedef struct
{
    int idCliente;
    char nombre[30];
    int codigoMedicamento;
} eCliente;

typedef struct
{
    int idLaboratorio;
    char nombre[30];
    char direccion[30];
    char telefono[10];
} eLaboratorio;

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

void inicializarMedicamentos(eMedicamento lista[], int j);
void inicializarLaboratorios(eLaboratorio lista[], int j);
void inicializarClientes(eCliente lista[], int j);
void mostrarMedicamentos(eMedicamento med);
