#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "fecha.h"
#include "socios.h"
#define tamSocios 100

int main()
{
    eSocios sociosBiblioteca[tamSocios]; // se define al tipo eSocios el tamanio con el tamSocios
    initSocios(sociosBiblioteca,tamSocios); //se inicializa todos los isEmpty en 1 indicando que estan vacios
    hardcodeoSocios(sociosBiblioteca);

    char salir = 'n';

    do
    {
        switch(menuSocios())
        {
        case 1:
            addSocio(sociosBiblioteca,tamSocios);
            break;
        case 2;
             if(haySocioCargado(sociosBiblioteca,SIZE))
                    {
                        modifyEmployee(sociosBiblioteca,SIZE,sectores,5);
                        break;
                    }
                    else
                    {
                        printf("***Error*** No hay ningun empleado cargado.\n");
                        system("pause");
                        system("cls");
                    }
                    break;

        }



    }
    while(salir == 'n');

    return 0;
}
