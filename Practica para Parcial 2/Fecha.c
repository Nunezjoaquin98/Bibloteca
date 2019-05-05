#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fecha.h"

eFecha ingresarFecha()
{
    char auxDia[5];
    char auxMes[5];
    char auxAnio[5];
    int dia,mes;

    eFecha fechaAuxiliar;
    do //do while para validar
    {
    while(!function_getStringNumeros("Ingrese el dia(Del 1 al 31):",auxDia))
    {
                printf("**** Error ****Debe ingresar un numero del 1 al 31.\n\n");
                system("pause");
                system("cls");
    }
    dia = atoi(auxDia);
    if(dia < 0 || dia > 31)
    {
                printf("**** Error ****Debe ingresar un numero del 1 al 31.\n\n");

    }else
    {
        fechaAuxiliar.dia = dia;
    }
    }while(dia < 0 || dia > 31);

    do //do while para validar el mes
    {
    while(!function_getStringNumeros("Ingrese el mes(Del 1 al 12):",auxMes))
    {
                printf("**** Error ****Debe ingresar un numero del 1 al 12.\n\n");
                system("pause");
                system("cls");
    }
    mes = atoi(auxMes);
    if(mes < 0 || mes > 12)
    {
        printf("***Error*** El mes debe ser del 1 al 12");
    }else
    {
        fechaAuxiliar.mes = mes;
    }
    }while(mes < 0 || mes > 12);

     while(!function_getStringNumeros("Ingrese el anio(4 digitos, EJ:1998):",auxAnio))
    {
                printf("**** Error ****Debe ingresar numeros.\n\n");
                system("pause");
                system("cls");
    }
    fechaAuxiliar.anio = atoi(auxAnio);

   return fechaAuxiliar;

}
