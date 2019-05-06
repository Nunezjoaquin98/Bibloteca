#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autores.h"


void hardcodeoAutores(eAutores* list)
{
    eAutores nuevosAutores[] =
    {
        {1,"Neruda","Pablo",0},
        {2,"Ysy","Alejo",0},
        {3,"Lombardo","Mauro",0},
        {4,"Krupo","Matias",0},
        {5,"Figo","Lorena",0},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = nuevosAutores[i];
    }
}


void showAutor(eAutores list)
{
    printf("\n%d   \t%s\t%s\n",list.codigoDeAutor,list.apellido,list.nombre);

}

void showAutores(eAutores list[],int len)
{
    printf("\n\nCODIGO\tAPELLIDO   NOMBRE\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            showAutor(list[i]);
        }
    }

}
