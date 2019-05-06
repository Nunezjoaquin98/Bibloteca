#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fecha.h"
#include "Sectores.h"
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

        if( list[i].legajo == id && list[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return -1;

}

void showEmployees(eEmployee list[],int len,eSector listSec[],int lenSector)
{
    printf("\n\nLEGAJO\tAPELLIDO\tNOMBRE\tSEXO\tSALARIO\tSECTOR\tFECHA DE\n");
    printf("      \t      \t        \t    \t       \t      \tINGRESO\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            showEmployee(list[i],listSec,5) ;
        }
    }

}

void showEmployee(eEmployee list,eSector listC[],int lenSector)
{
    char descSector[20];


    if(!obtenerSector(listC,5,list.sec.id,descSector))
    {
        strcpy(descSector,"Sin definir");
    }
    printf("\n%d\t%s\t%s\t%s\t%.2f\t%s\t%d/%d/%d\n",list.legajo,list.lastName,list.name,list.sex,list.salary,descSector,list.ingreso.dia,list.ingreso.mes,list.ingreso.anio);

}

int addEmployee(eEmployee list[], int len,eSector listSec[],int lenSec)
{
    eEmployee newEmployee ;
    int ret,index,sex;
    char auxName[21];
    char auxLastName[21];
    char auxSex[10];
    char auxSalary[10] ;
    char auxSector[10] ;
    char auxDia[4];
    char auxMes[4];
    char auxAnio[5];

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
            printf("\nNuevo empleado, LEGAJO numero %d. \n\n",index) ;
            newEmployee.legajo = index ;
            while(!function_getStringLetras("Ingrese nombre: ",auxName))
            {
                printf("El nombre solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");

            }
            while(!function_getStringLetras("\nIngrese apellido: ",auxLastName))
            {
                printf("El apellido debe tener solo letras.\n\n") ;
                system("pause");
                system("cls");

            }

            do
            {
                while(!function_getStringNumeros("\n\tSELLECION DE GENERO \nIngrese 1 si es MASCULINO o 2 si es FEMENINO: ",auxSex))
                {
                    printf("**** Error ****Debe ingresar el numero 1 o 2\n\n");
                    system("pause");
                    system("cls");
                }
                sex = atoi(auxSex);
                if(sex == 1)
                {
                    strcpy(auxSex,"Masculino");
                }
                else if(sex == 2)
                {
                    strcpy(auxSex,"Femenino");
                }

            }
            while(!(sex == 1 || sex == 2));

            while(!function_getStringNumeros("\nIngrese el salario: ",auxSalary) && auxSalary > 0)
            {
                printf("**** Error ****\n\n");
                system("pause");
                system("cls");

            }
            //FECHA DE INGRESO
            printf("\n\tFECHA DE INGRESO\n");
            ingresarDia(auxDia);
            ingresarMes(auxMes);
            ingresarAnio(auxAnio);

            printf("\n");
            mostrarSectores();
            while(!function_getStringNumeros("\nIngrese el ID del sector: ",auxSector))
            {
                printf("Error el sector debe tener solo numeros.\n\n");
                system("pause");
                system("cls");
            }
            // se copian todos los datos del nuevo empleado.

            strcpy(newEmployee.name,auxName) ;
            strcpy(newEmployee.lastName,auxLastName) ;
            strcpy(newEmployee.sex,auxSex);
            newEmployee.salary = atoi(auxSalary) ;
            newEmployee.sec.id = atoi(auxSector) ;
            newEmployee.ingreso.dia = atoi(auxDia);
            newEmployee.ingreso.mes = atoi(auxMes);
            newEmployee.ingreso.anio = atoi(auxAnio);
            newEmployee.isEmpty = 0;
            list[index] = newEmployee ;
            system("pause");
            system("cls");
            printf("\n\nEMPLEADO DADO DE ALTA CON EXITO:\n\n");
            showEmployee(list[index],listSec,5);
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

void modifyEmployee(eEmployee list[], int len,eSector listSeC[],int lenSec)
{
    int id,index,sex;
    char salir = 'n';

    char auxId[5];
    char newSalary[5];
    char newSector[5];
    char newName[51];
    char newLastName[51] ;
    char newSex[20];
    char auxDia[5];
    char auxMes[5];
    char auxAnio[5];


    system("cls");
    printf("\t\t  *** Modificar  empleado ***\n\n");
    showEmployees(list,len,listSeC,lenSec);
    if(!function_getStringNumeros("\nIngrese el legajo: ",auxId))
    {
        printf("*** ERROR *** El legajo debe contener solo numeros.\n") ;
    }

    id = atoi(auxId) ;
    index = findEmployeeById(list, len, id);


    if( index == -1)
    {
        printf("No hay ningun empleado con legajo %d.\n\n", id);
        system("pause");
    }
    else
    {


        showEmployee(list[index],listSeC,lenSec) ;
        do
        {

            switch(menuModificar())
            {
            case 1:
                showEmployee(list[index],listSeC,lenSec);
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
                showEmployee(list[index],listSeC,lenSec);
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
                // modifica genero
                showEmployee(list[index],listSeC,lenSec);
                printf("\n\n");

                do
                {
                    while(!function_getStringNumeros("\n\tSELLECION DE GENERO \nIngrese 1 si es MASCULINO o 2 si es FEMENINO: ",newSex))
                    {
                        printf("**** Error ****Debe ingresar el numero 1 o 2\n\n");
                        system("pause");
                        system("cls");
                    }
                    sex = atoi(newSex);
                    if(sex == 1)
                    {
                        strcpy(newSex,"Masculino");
                    }
                    else if(sex == 2)
                    {
                        strcpy(newSex,"Femenino");
                    }

                }
                while(!(sex == 1 || sex == 2));
                strcpy(list[index].sex,newSex);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls") ;
                break ;
            case 4:
                // MODIFICA SALARIO
                showEmployee(list[index],listSeC,lenSec) ;
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

            case 5:// FECHA DE INGRESO
                showEmployee(list[index],listSeC,lenSec) ;
                printf("\n\n\tModificar Fecha de ingreso");
                ingresarDia(auxDia);
                ingresarMes(auxMes);
                ingresarAnio(auxAnio);
                list[index].ingreso.dia = atoi(auxDia);
                list[index].ingreso.mes = atoi(auxMes);
                list[index].ingreso.anio = atoi(auxAnio);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls") ;
                break ;

            case 6: //MODIFICA SECTOR
                showEmployee(list[index],listSeC,lenSec) ;
                printf("\n\tModificar sector\n");
                mostrarSectores();
                while(!function_getStringNumeros("\nIngrese el ID del sector: ",newSector ))
                {
                    printf("Error el sector debe tener solo numeros.\n\n");
                    system("pause");
                    system("cls");
                }
                list[index].sec.id = atoi(newSector);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls") ;
                break ;

            case 7:
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
        {1,"Riquelme","Juan","Masculino",20000,0,{12,05,2001},{1,"Recursos Humanos"}},
        {2,"Andrada","Sebas","Masculino",18500,0,{05,05,2019},{3,"Ventas"}},
        {3,"Sotto","Rocio","Femenino",12500,0,{03,05,2018},{4,"Administracion"}},
        {4,"Perez","Sol","Femenino",50000,0,{20,06,2005},{5,"Legales"}},
        {5,"Nunez","Diego","Masculino",34000,0,{18,02,2019},{1,"Recursos Humanos"}},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = empleados[i];
    }
};


int removeEmployee(eEmployee list[], int len,int id,eSector listSec[],int lenSec)
{
    char auxId[10];
    char auxYes[10];
    int yes,index,ret;

    if(list != NULL && len > 0)
    {
        do
        {
            system("cls");
            printf("\t\t  ***Baja de Empleado***\n");
            showEmployees(list,len,listSec,lenSec);
            while(!function_getStringNumeros("\nIngrese el legajo del empleado a borrar: ",auxId))
            {
                printf("***Error*** Debe ingresar un numero.\n");
                system("pause");
            }
            id = atoi(auxId);
            index = findEmployeeById(list, len, id);
            if( index == -1)
            {
                printf("No hay ningun empleado con legajo %d.\n\n", id);
                system("pause");
            }
            else
            {
                showEmployee(list[index],listSec,lenSec);

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
        while(index == -1);

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
    int ret;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName) > 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee ;
                }else if(strcmp(list[i].lastName,list[j].lastName) == 0 && strcmp(list[i].name,list[j].name)>0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                          auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee ;
                }

            }

            ret = 1;

        }
    }else
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
