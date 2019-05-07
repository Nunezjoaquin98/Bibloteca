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

void mostrarPrestamo(ePrestamos listPrest,int lenPrest,eLibro listLibros[],int lenLibros,eSocios listSocios[],int lenSocios) ;

void mostrarPrestamos(ePrestamos listPrest[],int lenPrest,eLibro listLibros[],int lenLibros,eSocios listSocios[],int lenSocios);

int addPrestamo(eSocios listSocios[],int tamSoc,eLibro listLibros[],int tamLibro,ePrestamos listPrest[],int tamPrest,eAutores listAut[],int tamAuto);

int menuPrestamos();
