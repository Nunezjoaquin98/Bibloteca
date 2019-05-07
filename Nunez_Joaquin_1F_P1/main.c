#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "fecha.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"
#define tamSocios 100
#define tamAutores 5
#define tamLibros 5

int main()
{
    //declaro variables
    char salir = 'n';
    eSocios sociosBiblioteca[tamSocios]; // se define al tipo eSocios el tamanio con el tamSocios
    eAutores escritores[tamAutores];
    eLibro exitos[tamLibros];


    initSocios(sociosBiblioteca,tamSocios); //se inicializa todos los isEmpty en 1 indicando que estan vacios
    hardcodeoSocios(sociosBiblioteca);
    hardcodeoAutores(escritores);
    hardcodeoLibros(exitos);


    do
    {
        switch(menuSocios())
        {
        case 1: //ALTA SOCIO
            addSocio(sociosBiblioteca,tamSocios);
            break;
        case 2: //MODIFICAR SOCIO
            if(haySocioCargado(sociosBiblioteca,tamSocios)) //SE UTILIZA ESTA FUNCION PARA CHEQUEAR QUE SE HAYA CARGADO UN SOCIO
            {
                modifySocio(sociosBiblioteca,tamSocios);
                break;
            }
            else//SI NO HAY NINGUN SOCIO SE INFORMA
            {
                printf("***Error*** No hay ningun socio cargado.\n");
                system("pause");
                system("cls");
            }
            break;
        case 3://BAJA SOCIO
            if(haySocioCargado(sociosBiblioteca,tamSocios))
            {

                removeSocio(sociosBiblioteca,tamSocios,0);
                break;
            }
            else
            {
                printf("***Error*** No hay ningun socio cargado.\n");
                system("pause");
                system("cls");
            }
            break;
        case 4: //listar socios
            if(haySocioCargado(sociosBiblioteca,tamSocios))
            {
                system("cls");
                sortSocios(sociosBiblioteca,tamSocios); //se ordena los socios
                showSocios(sociosBiblioteca,tamSocios); // se muestra los socios
                system("pause");
            }
            else
            {
                printf("***Error*** No hay ningun socio cargado.\n");
                system("pause");
                system("cls");
            }
            break;
        case 5:
            showLibros(exitos,tamLibros,escritores,tamAutores);
            printf("\n\n");
            system("pause");
            break;

        case 6:
            showAutores(escritores,tamAutores);
            printf("\n\n");
            system("pause");
            break;
        default:

            printf("*** ERROR *** Debe ingresar un numero del 1 al 8\n\n") ; // el default se utiliza por si se ingresa un numero que no sea del 1 al 8
            system("pause");
            system("cls");
            break;

        }



    }
    while(salir == 'n');

    return 0;
}
