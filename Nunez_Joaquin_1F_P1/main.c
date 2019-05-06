#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "fecha.h"
#include "autores.h"
#include "socios.h"
#define tamSocios 100
#define tamAutores 5

int main()
{
    //declaro variables
    char salir = 'n';
    eSocios sociosBiblioteca[tamSocios]; // se define al tipo eSocios el tamanio con el tamSocios
    eAutores escritores[tamAutores];


    initSocios(sociosBiblioteca,tamSocios); //se inicializa todos los isEmpty en 1 indicando que estan vacios
    hardcodeoSocios(sociosBiblioteca);
    hardcodeoAutores(escritores);


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
        case 6:
            showAutores(escritores,tamAutores);
            printf("\n\n");
            system("pause");
            break;


        }



    }
    while(salir == 'n');

    return 0;
}
