#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "fecha.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"

int iniciarPrestamo(ePrestamos list[], int len)
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

int searchEmptyPrestamo(ePrestamos list[],int len)
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

int addPrestamo(eSocios listSocios[],int tamSoc,eLibro listLibros[],int tamLibro,ePrestamos listPrest[],int tamPrest,eAutores listAut[],int tamAuto)
{
    int ret,index,indexLibros,indexSocios;
    ePrestamos newPrestamo;
    char auxLibro[3];
    char auxSocioCod[4];
    char anio[5];
    char mes[5];
    char dia[5];


    if(listPrest != NULL && tamPrest > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmptyPrestamo(listPrest,tamPrest);
        printf("\t\t***ALTA DE PRESTAMO***");
        if(index == -1)
        {
            printf("\nNo hay lugar en el sistema. \n") ;
            ret = -1 ;
            system("pause");

        }
        else
        {

            index++; // se suma uno asi el primer prestamo no tiene id "0"
            printf("\nNuevo prestamo, CODIGO numero %d. \n\n",index) ;



            // SE LE HACE SELECCIONAR UN LIBRO AL USUARIO
            do
            {
                printf("\nSeleccionar el libro correspondiente:\n");
                showLibros(listLibros,tamLibro,listAut,tamAuto);
                while(!function_getStringNumeros("\n\nIngrese el numero de codigo del libro: ",auxLibro))
                {
                    printf("Error el codigo debe tener solo numeros.\n\n");
                    system("pause");
                }
                indexLibros = findLibroById(listLibros,tamLibro,atoi(auxLibro));
                if(indexLibros == -1)
                {
                    printf("\n***ERROR*** El codigo del libro es incorrecto");
                }
                else
                {
                    system("cls");
                    printf("\n\nEl libro seleccionado es:\n");
                    printf("\CODIGO\tTITULO          APELLIDO    NOMBRE\n");
                    printf("      \t                DEL AUTOR   DEL AUTOR\n\n");
                    showLibro(listLibros[indexLibros],tamLibro);
                }

            }
            while(indexLibros == -1);

            // carga de socio
            printf("\nSeleccionar socio:\n");
            showSocios(listSocios,tamSoc);
            do
            {
                while(!function_getStringNumeros("\nIngrese el numero de codigo del socio/a: ",auxSocioCod))
                {
                    printf("\nError el legajo debe tener solo numeros.\n\n");
                    system("pause");
                }
                indexSocios = findEmployeeById(listSocios,tamSoc,atoi(auxSocioCod));
                if(indexSocios == -1)
                {
                    printf("\n***ERROR*** Codigo incorrecto\n");
                    system("pause");
                }
                else
                {
                    printf("\nEl socio seleccionado es:\n");
                    showSocio(listSocios[indexSocios]);
                }

            }
            while(indexSocios == -1);

            //carga de la fecha
            printf("\n\nIngresar fecha del prestamo:\n");
            ingresarDia(dia);
            ingresarMes(mes);
            ingresarAnio(anio);

            //se copian todos los datos al nuevo almuerzo
            newPrestamo.codigoDePrestamo = index;
            newPrestamo.codigoLib.codigoDelLibro = listLibros[indexLibros];
            newPrestamo.codigoSoc.codigoDeSocio = listSocios[indexSocios];
            newPrestamo.fechaDePrestamo.dia = atoi(dia);
            newPrestamo.fechaDePrestamo.mes = atoi(mes);
            newPrestamo.fechaDePrestamo.anio = atoi(anio);
            newPrestamo.isEmpty = 0;
            listPrest[index] = newPrestamo;
            system("cls");
            //showLunch(listPrest[index],tamPrest,listLibros,tamLibro,listSocios,tamSoc);
            printf("\n\n");
            system("pause");

        }
    }
    else
    {
        ret = -1 ;
    }
    return ret;
}
