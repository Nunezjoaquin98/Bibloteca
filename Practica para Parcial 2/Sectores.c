#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sectores.h"

void hardcodeoSectores(eSector* list)
{
    eSector sectores[] =
    {
        {1, "Recursos Humanos"},
        {2, "Sistemas"},
        {3, "Ventas"},
        {4, "Administracion"},
        {5, "Legales"},

    };
    for(int i = 0;i < 5;i++)
    {
        list[i] = sectores[i];
    }

}

void mostrarSectores()
{
    printf("\t\t***Sectores***\n");
    printf("ID\t\tDescripcion");
    printf("\n1\t\tRecursos Humanos\n2\t\tSistemas\n3\t\tVentas\n4\t\tAdministracion\n5\t\tLegales\n");
}

int obtenerSector(eSector sec[], int len, int idS, char desc[])
{

    int ret = 0;

    for(int i=0; i < len; i++)    {

        if(idS == sec[i].id)
        {

            strcpy(desc, sec[i].descripcion);
            ret = 1;
            break;
        }
    }

    return ret;
}

