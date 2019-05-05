#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menues.h"

void hardcodeoMenues(eMenues* list)
{
    eMenues menuNuevo[] =
    {
        {1,60,"Sanguche de milenasa completo"},
        {2,120,"Pati completo + Papas con cheddar"},
        {3,40,"Arroz con queso"},
        {4,55,"Cafe + 2 medialunas"},
        {5,25,"Galletitas Pitusas"},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = menuNuevo[i];
    }
}

void mostrarMenu (eMenues list,int len)
{
    printf("%d %s\t%d",list.id,list.descripcion,list.importe);
}

void mostrarMenues (eMenues list[],int len)
{
    printf("\n\nID Descripcion\t\t\tPrecio\n");
    for(int i = 0; i<5;i++)
    {
      printf("%d %s\t%d\n\n",list[i].id,list[i].descripcion,list[i].importe);
    }

}
