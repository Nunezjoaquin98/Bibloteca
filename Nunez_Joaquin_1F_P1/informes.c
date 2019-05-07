#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "fecha.h"
#include "autores.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"

int menuInformes()
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n\t\t*** MENU INFORMES ***\n\n");
    printf("1-ALTAS \n");
    printf("2-LISTAR \n") ;
    printf("3-Listar todos los socios que solicitaron un prestamo\nde un libro determinado(punto C)\n") ;
    printf("4-Listar todos los libros que fueron solicitados a prestamo\npor un socio determinado (punto D)\n") ;
    printf("9-Listar todos los libros ordenados por titulo(descendente),\nutilizando el metodo de burbujeo mas eficiente.\n") ;
    printf("11-VOLVER AL MENU PRINCIPAL\n\n") ;
    while(!function_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 3. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}

void listarSociosDeLibro(eLibro list[],int lenLibro,eSocios listSoc[],int lenSocios,eAutores listAu[],int lenAut,ePrestamos listPrest[],int lenPrest)
{
    char auxCodigoLibro[5];
    int indexLibro,indexSocio,codigoSocio;

    system("cls");
    printf("Seleccione el libro a buscar:\n");
    showLibros(list,lenLibro,listAu,lenAut);
    while(!function_getStringNumeros("Ingrese el codigo del libro: ",auxCodigoLibro))
    {
        printf("\n***ERROR*** Debe ingresar solo numeros\n\n");
    }

    indexLibro = findLibroById(list,lenLibro,atoi(auxCodigoLibro));
    printf("\n\nEl libro %s fue solicitado por: \n",list[indexLibro].titulo);

    //ahora que tenemos el index del libro, recorremos la lista de prestamos

    for(int i = 0;i < lenPrest;i++)
    {
        if(atoi(auxCodigoLibro) == listPrest[i].codigoLib.codigoDelLibro)
        {
            codigoSocio = listPrest[i].codigoSoc.codigoDeSocio; //copio el codigo del socio
            indexSocio = findSocioById(listSoc,lenSocios,codigoSocio); //busco la posicon en el array de socios
            printf("\n");
            showSocio(listSoc[indexSocio]); // muestro el socio
            printf("\n");
        }


    }



}

void listarLibrosDeSocio(eLibro list[],int lenLibro,eSocios listSoc[],int lenSocios,eAutores listAu[],int lenAut,ePrestamos listPrest[],int lenPrest)
{
    char auxCodigoSocio[5];
    int indexLibro,indexSocio,codigoLibro;

    system("cls");
    printf("Seleccione el socio/a a buscar:\n");
    showSocios(listSoc,lenSocios);
    while(!function_getStringNumeros("Ingrese el codigo del socio/a: ",auxCodigoSocio))
    {
        printf("\n***ERROR*** Debe ingresar solo numeros\n\n");
    }

    indexSocio = findSocioById(listSoc,lenSocios,atoi(auxCodigoSocio));
    printf("\n\nEl socio %s %s solicito los libros: \n",listSoc[indexSocio].nombre,listSoc[indexSocio].apellido);

    //ahora que tenemos el index del socio, recorremos la lista de prestamos

    for(int i = 0;i < lenPrest;i++)
    {
        if(atoi(auxCodigoSocio) == listPrest[i].codigoSoc.codigoDeSocio)
        {
            codigoLibro = listPrest[i].codigoLib.codigoDelLibro;//copio el codigo del libro
            indexLibro = findLibroById(list,lenLibro,codigoLibro); //busco la posicon en el array de libros
            printf("\n");
            showLibro(list[indexLibro],listAu,lenAut); // muestro el socio
            printf("\n");
        }


    }



}

int listarLibrosPorTituloBurbujeo(eLibro list[], int len)
{
    eLibro auxLibro;
    int ret;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].titulo,list[j].titulo) < 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxLibro   = list[i];
                    list[i] = list[j];
                    list[j] = auxLibro ;
                }

            }

            ret = 1;

        }
    }
    else
    {
        ret = -1;
    }


    return ret;

}

