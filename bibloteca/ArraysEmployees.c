#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "ArraysEmployees.h"

int initEmployees(eEmployee list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        }
    }
    else
    {
        ret = -1;
    }

    return ret;
}

int searchEmpty(eEmployee list[],int len)
{
    int index = -1;
    for(int i=0; i<len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        }
    }
    return index ;
}

int findEmployeeById(eEmployee list[], int len, int id)
{

    for(int i=0; i < len; i++)
    {

        if( list[i].id == id && list[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return -1;

}

void showEmployees(eEmployee list[],int len)
{
    printf("\n\nID\t\tNOMBRE\t\tAPELLIDO\t\tSALARIO\t\tSECTOR\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            showEmployee(list[i]) ;
        }
    }

}

void showEmployee(eEmployee list)
{
    printf("\n%d\t\t%s\t\t%s\t\t%.2f\t%d\n",list.id,list.name,list.lastName,list.salary,list.sector);
}

int addEmployee(eEmployee list[], int len)
{
    eEmployee newEmployee ;
    int ret;
    int index ;
    char auxName[21];
    char auxLastName[21];
    char auxSalary[10] ;
    char auxSector[10] ;


    if(list != NULL && len > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmpty(list,len) ;
        printf("\n\t------- Alta empleado -------\n\n");

        if(index == -1)
        {
            printf("No hay lugar en el sistema. \n") ;
            ret = -1 ;
            system("pause");

        }
        else
        {

            index++; // se suma uno asi el primer empleado no tiene id "0"
            printf("\nNuevo empleado, ID numero %d. \n\n",index) ;
            newEmployee.id = index ;
            while(!function_getStringLetras("Ingrese nombre: ",auxName))
            {
                printf("El nombre solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");

            }
            while(!function_getStringLetras("Ingrese apellido: ",auxLastName))
            {
                printf("El apellido debe tener solo letras.\n\n") ;
                system("pause");
                system("cls");

            }
            while(!function_getStringNumeros("Ingrese el salario: ",auxSalary) && auxSalary > 0)
            {
                printf("**** Error ****\n\n");
                system("pause");
                system("cls");

            }
            while(!function_getStringNumeros("Ingrese el sector: ",auxSector))
            {
                printf("Error el sector debe tener solo numeros.\n\n");
                system("pause");
                system("cls");
            }
            // se copian todos los datos del nuevo empleado.

            strcpy(newEmployee.name,auxName) ;
            strcpy(newEmployee.lastName,auxLastName) ;
            newEmployee.salary = atoi(auxSalary) ;
            newEmployee.sector = atoi(auxSector) ;
            newEmployee.isEmpty = 0;
            list[index] = newEmployee ;
            system("pause");
            system("cls");
            printf("\n\nEMPLEADO DADO DE ALTA CON EXITO:\n\n");
            showEmployee(list[index]);
            printf("\n\n\n");
            system("pause");
            ret = 0 ;
        }
    }
    else
    {
        ret = -1 ;
    }
    return ret;
}

void modifyEmployee(eEmployee list[], int len)
{
    int id;
    int index;
    char salir = 'n';

    char auxId[5];
    char newSalary[5];
    char newSector[5];
    char newName[51] ;
    char newLastName[51] ;


    system("cls");
    printf("\t\t  *** Modificar  empleado ***\n\n");
    showEmployees(list,len);
    if(!function_getStringNumeros("\nIngrese id: ",auxId))
    {
        printf("*** ERROR *** El id debe contener solo numeros.\n") ;
    }

    id = atoi(auxId) ;
    index = findEmployeeById(list, len, id);


    if( index == -1)
    {
        printf("No hay ningun empleado con id %d.\n\n", id);
        system("pause");
    }
    else
    {


        showEmployee(list[index]) ;
        do
        {

            switch(menuModificar())
            {
            case 1:
                showEmployee(list[index]) ;
                printf("\n\n");
                //modificar nombre
                while(!function_getStringLetras("Ingrese nuevo nombre: ",newName))
                {
                    printf("*** Error *** El nombre debe tener solo letras.");
                }
                strcpy(list[index].name,newName);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls");
                break ;
            case 2:
// Modifica apellido
                showEmployee(list[index]) ;
                printf("\n\n");
                while(!function_getStringLetras("Ingrese nuevo apellido: ",newLastName))
                {
                    printf("*** ERROR *** El apellido debe tener solo letras.\n\n");
                }
                strcpy(list[index].lastName,newLastName);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls");
                break ;
            case 3:
                // modifica sueldo
                showEmployee(list[index]) ;
                printf("\n\n");
                while(!function_getStringNumeros("Ingrese nuevo sueldo: ",newSalary))
                {
                    printf("*** ERROR *** El salario debe contener solo numeros.\n\n") ;
                }
                list[index].salary = atoi(newSalary);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls") ;
                break ;
            case 4:
                // MODIFICA SECTOR
                showEmployee(list[index]) ;
                printf("\n\n");
                while(!function_getStringNumeros("Ingrese nuevo sector: ",newSector))
                {
                    printf("*** ERROR *** El sector tiene que ser un numero\n\n") ;
                }
                list[index].sector = atoi(newSector);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls") ;
                break ;
            case 5:
                printf("\n\t***Regresando***\n\n");
                salir = 's';
                system("pause");
                system("cls");
                break;
            default:
                printf("*** ERROR *** Debe ingresar un numero del 1 al 5.\n");
                system("pause");
                break;
            }
        }
        while(salir == 'n');
    }
}

void hardcodeoEmpleados(eEmployee* list)
{

    eEmployee empleados[]=
    {
        {1,"Roman", "Riquelme",10000,2},
        {2,"Martin", "Palermo",90055,1},
        {3,"Carlos", "Bianchi",15000,2},
        {4,"Pipa", "Benedetto",40000,3},
        {5,"Sabandija", "Andrada",72000,1},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = empleados[i];
    }
};

int removeEmployee(eEmployee list[], int len,int id)
{
    char auxId[10];
    char auxYes[10];
    int yes,index,ret;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("\t\t  ***Baja de Empleado***\n");
        showEmployees(list,len);
        while(!function_getStringNumeros("\nIngrese ID del empleado a borrar: ",auxId))
        {
            printf("***Error*** Debe ingresar un numero.\n");
            system("pause");
        }
        id = atoi(auxId);
        index = findEmployeeById(list, len, id);
        if( index == -1)
        {
            printf("No hay ningun empleado con id %d.\n\n", id);
            system("pause");
        }
        else
        {
            showEmployee(list[index]);

            while(!function_getStringNumeros("\nEs este el empleado/a que desea borrar?\nIngrese 1 si es correcto / Otro numero si es incorrecto: ",auxYes))
            {
                printf("***Error*** Debe ingresar un numero.\n");
                system("pause");
            }
            yes = atoi(auxYes);
            if(yes == 1)
            {
                system("cls");
                printf("El empleado/a ha sido borrado con exito!\n");
                system("pause");
                list[index].isEmpty = 1 ;
            }
            else
            {
                printf("Baja cancelada.\n");
                system("pause");
            }

        }

    }
    else
    {
        ret = -1;
    }

    return ret;
}

int sortEmployees(eEmployee list[], int len)
{
    eEmployee auxEmployee;
    char auxOrder[1] ;
    int ret,order;


    if(list != NULL && len > 0)
    {
        while(!function_getStringNumeros("\n Ingrese 1 para ordenar de manera ascendente o ingrese 2 para ordenar de manera descendente: ",auxOrder))
        {
            printf("*** ERROR DEBE INGRESAR UN NUMERO ***");

        }
        order = atoi(auxOrder);
        switch(order)
        {
        case 1:
            for(int i = 0; i < len - 1; i++)
            {
                for(int j = i + 1; j < len; j++)
                {
                    if(strcmp(list[j].lastName, list[i].lastName) < 0  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                    else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }
            printf("\n\nEl ordenado ascendente se ha realizado con exito.\n");
            system("pause") ;
            system("cls") ;
            break;
        case 2:
            for(int i = 0; i < len-1; i++)
            {
                for(int j = i+1; j < len; j++)
                {
                    if(strcmp(list[j].lastName, list[i].lastName) > 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                    else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }

            system("pause") ;
            system("cls") ;
            break;
        default:
            printf("No ingreso 1 o 2");
        }

    }
    else
    {
        ret = -1;
    }


    return ret;

}

void function_averageSalary (eEmployee list[],int len)
{
    float acum,promedio,contador;
    int contEmplSuperan;

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            acum = acum + list[i].salary;
            contador++;
        }
    }

    promedio = funcion_dividir(acum,contador);

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0 && list[i].salary > promedio)
        {
            contEmplSuperan++;
        }
    }

    printf("\nEl total de todos los salarios es de: %.2f \nEl promedio de los salarios es: %.2f \nLa cantidad de empleados que superan el promedio es de: %d\n\n",acum,promedio,contEmplSuperan);

}

int hayEmpleadoCargado (eEmployee list[],int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                ret = 1;
                break;
            }
        }


    }
    else
    {
        ret = -1;
    }

    return ret;
}

