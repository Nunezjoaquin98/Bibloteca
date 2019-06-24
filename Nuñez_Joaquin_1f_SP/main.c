#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "LinkedList.h"
#include "dominio.h"
#include "input.h"


int main()
{
    int salir = 0;
    LinkedList* listaDominios = ll_newLinkedList();
    do
    {
        switch(menu())
        {
        case 1:
            if(loadFromKeyboard(listaDominios))
            {
            system("cls");
                printf("Se cargo correctamente...\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("No se pudo cargar correctamente...\n");
                system("pause");
            }
            break;

        case 2:
                //ll_map(listaDominios,setearTipoPorCriterio(listaDominios));
                system("cls");
                system("pause");
                break;

        case 3:

        case 4:
            guardarArchivosAuto("auto.csv",listaDominios);
            guardarArchivosMoto("moto.csv",listaDominios);
            break;
        case 5:
                printf("\nSaliendo...\n\n");
                salir = 1;
                break;
        default:
                printf("\nERROR - Debe ingresar un numero del 1 al 5.\n");
                system("pause");
                system("cls");
                break;
                    }
    }
    while(salir == 0);
    return 0;
}
