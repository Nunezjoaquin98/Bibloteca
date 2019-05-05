#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "Sectores.h"
#include "Fecha.h"
#include "ArraysEmployees.h"
#include "menues.h"
#define SIZE 1000


int main()
{
    char salir = 'n';
    eEmployee empleados[SIZE]; // se crea un arrays tipo eEmployee con el tamaño de 1000
    eSector sectores[6];
    eMenues comidas[6];
    initEmployees(empleados,SIZE); // Se inicializa todos los empleados en 1.
    hardcodeoEmpleados(empleados);
    hardcodeoSectores(sectores);
    hardcodeoMenues(comidas);
    do
    {
        switch(menu())
        {
        case 1: //menues
            switch(menuDeLosMenues())
            {
            case 4:
                mostrarMenues(comidas,5);
                printf("\n\n");
                system("pause");
                break;
            default:
                printf("*** ERROR *** Debe ingresar un numero del 1 al 5\n\n") ; // el default se utiliza por si se ingresa un numero que no sea del 1 al 5
                system("pause");
                system("cls");
                break;
            }
            break;
        case 2://EMPLEADOS
            switch(menuEmpleados())
            {
            case 1:
                addEmployee(empleados,SIZE,sectores,5);
                break;
            case 2:
                if(hayEmpleadoCargado(empleados,SIZE))
                {
                    modifyEmployee(empleados,SIZE,sectores,5);
                    break;
                }
                else
                {
                    printf("***Error*** No hay ningun empleado cargado.\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 3:
                if(hayEmpleadoCargado(empleados,SIZE))
                {

                    removeEmployee(empleados,SIZE,0,sectores,5);
                    break;
                }
                else
                {
                    printf("***Error*** No hay ningun empleado cargado.\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 4:
                if(hayEmpleadoCargado(empleados,SIZE))
                {
                    showEmployees(empleados,SIZE,sectores,5);
                    system("pause");
                }
                else
                {
                    printf("***Error*** No hay ningun empleado cargado.\n");
                    system("pause");
                    system("cls");
                }
                break;
            }
            break;
        case 5:
            printf("\n\t***Saliendo***\n\n");
            salir = 's';
            system("pause");
            system("cls");
            break;
        default:
            printf("*** ERROR *** Debe ingresar un numero del 1 al 5\n\n") ; // el default se utiliza por si se ingresa un numero que no sea del 1 al 5
            system("pause");
            system("cls");
            break;
        }
    }
    while(salir == 'n');




    return 0;
}

