#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "dominio.h"
#include "funciones.h"


int parser_DominioFromText(FILE* pFile, LinkedList* pArrayListDominio,char* nombreArchivo)
{

    int ret = 0;
    int r;
    char a[50];
    char b[50];
    char c[50];

    pFile = fopen(nombreArchivo,"r");
    if(pFile == NULL)
    {
        printf("El archivo no existe\n");
        system("pause");
    }
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,\n]",a,b,c);
        if(r==4)
        {
            eDominio* auxDominio = dominio_new();
            dominio_setId(auxDominio,atoi(a));
            dominio_setDominio(auxDominio,b);
            dominio_setAnio(auxDominio,atoi(c));
            ll_add(pArrayListDominio,auxDominio);
            ret = 1;
        }
        break;
    }
    while(!feof(pFile));


    fclose(pFile);
    return ret;
}

int loadFromKeyboard(LinkedList* pArrayListDominio)
{
    int ret = 0;
    char auxNombreArchivo[18];

    printf("\nIngrese el nombre del archivo a abrir (Ejemplo: ""archivo.csv""): %s"),fgets(auxNombreArchivo,18,stdin);

    FILE* puntFile = fopen(auxNombreArchivo,"r");

   if(puntFile != NULL)
    {
        ret = parser_DominioFromText(puntFile,pArrayListDominio,auxNombreArchivo);
        system("cls");
        printf("Archivo leido correctamente.\n\n");
        system("pause");
    }

    return ret;
}


int guardarArchivosAuto(char* path, LinkedList* pArrayListDominio)
{

    int ret = 0;
    FILE* pFile;
    pFile = fopen("auto.csv", "w");
    eDominio* dominio;

    if(pArrayListDominio != NULL)
    {
        for(int i = 0; i<ll_len(pArrayListDominio); i++)
        {

            dominio = (eDominio*)ll_get(pArrayListDominio, i);
            if(dominio->tipo == 'A')
            {
            fprintf(pFile, "%d,%s,%d,%d",dominio->id,dominio->dominio,dominio->anio, dominio->tipo);
            }
        }
        fclose(pFile);
        ret = 1;
    }

    else
    {
        printf("No hay Datos\n");
        system("pause");
    }

    return ret;
}


int guardarArchivosMoto(char* path, LinkedList* pArrayListDominio)
{

    int ret = 0;
    FILE* pFile;
    pFile = fopen("moto.csv", "w");
    eDominio* dominio;

    if(pArrayListDominio != NULL)
    {
        for(int i = 0; i<ll_len(pArrayListDominio); i++)
        {

            dominio = (eDominio*)ll_get(pArrayListDominio, i);
            if(dominio->tipo == 'M')
            {
            fprintf(pFile, "%d,%s,%d,%d",dominio->id,dominio->dominio,dominio->anio, dominio->tipo);
            }
        }
        fclose(pFile);
        ret = 1;
    }

    else
    {
        printf("No hay Datos\n");
        system("pause");
    }

    return ret;
}
