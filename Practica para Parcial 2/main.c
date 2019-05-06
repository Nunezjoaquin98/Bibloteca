#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "Sectores.h"
#include "Fecha.h"
#include "ArraysEmployees.h"
#include "menues.h"
#include "almuerzos.h"
#define SIZE 100
#define SIZEALMUERZO 20


int main()
{
    char salir = 'n';
    char salirEmp = 'n';
    char salirAlm = 'n';
    char salirMenues = 'n';


    eEmployee empleados[SIZE];// se crea un arrays tipo eEmployee con el tamaño de 1000
    eSector sectores[6];
    eMenues comidas[6];
    eAlmuerzos alm[SIZEALMUERZO];
    initEmployees(empleados,SIZE); // Se inicializa todos los empleados en 1.
    initLunch(alm,SIZEALMUERZO);//se inicializa a todos los almuerzos.
    hardcodeoEmpleados(empleados);
    hardcodeoSectores(sectores);
    hardcodeoMenues(comidas);
    hardcodeoAlmuerzos(alm);
    do
    {
        switch(menu())
        {
        case 1: //menues
            do
            {
                switch(menuDeLosMenues())
                {
                case 4:
                    showMenues(comidas,5);
                    printf("\n\n");
                    system("pause");
                    break;
                case 5:
                    printf("\n\t***Volviendo***\n\n");
                    salirMenues = 's';
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
            while(salirMenues == 'n');
            break;
        case 2://EMPLEADOS
            do
            {
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
                        system("cls");
                        sortEmployees(empleados,SIZE);
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
                case 5:
                    printf("\n\t***Volviendo***\n\n");
                    salirEmp = 's';
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
            while(salirEmp == 'n');
            break;
        case 3: // ALMUERZOS

            do
            {

                switch(menuLunches())
                {
                case 1:
                    addLunch(empleados,SIZE,comidas,5,alm,SIZEALMUERZO,sectores,5);
                    break;
                case 2:
                    system("cls");
                    showLunches(alm,SIZEALMUERZO,comidas,5,empleados,SIZE);
                    system("pause");
                    break;
                case 3:
                    printf("\n\t***Volviendo***\n\n");
                    salirAlm = 's';
                    system("pause");
                    system("cls");
                    break;
                default:
                    printf("*** ERROR *** Debe ingresar un numero del 1 al 3\n\n") ; // el default se utiliza por si se ingresa un numero que no sea del 1 al 5
                    system("pause");
                    system("cls");
                    break;
                }
            }
            while(salirAlm == 'n');
            break;
        case 5:
            printf("\n\t***Saliendo***\n\n");
            salir = 's';
            system("pause");
            system("cls");
            break;
        }
    }
    while(salir == 'n');


    return 0;
}

