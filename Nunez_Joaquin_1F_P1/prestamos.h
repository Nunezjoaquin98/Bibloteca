typedef struct
{
    int codigoDePrestamo;
    eLibro codigoLib;
    eSocios codigoSoc;
    eFecha fechaDePrestamo;
    int isEmpty;

}ePrestamos;

int iniciarPrestamo(ePrestamos list[], int len);

int searchEmptyPrestamo(ePrestamos list[],int len);
