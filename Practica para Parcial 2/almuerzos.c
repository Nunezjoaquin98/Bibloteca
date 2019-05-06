#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fecha.h"
#include "Sectores.h"
#include "Funciones.h"
#include "ArraysEmployees.h"
#include "menues.h"
#include "almuerzos.h"

int initLunch(eAlmuerzos list[], int len)
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

int searchEmptyAlmuerzo(eAlmuerzos list[],int len)
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

int addLunch(eEmployee listE[],int lenE,eMenues listM[],int lenM,eAlmuerzos listA[],int lenA,eSector listS[],int lenS)
{
    int ret,index,indexMenu,indexEmp;
    eAlmuerzos newLunch;
    char auxMenu[3];
    char auxLegajoEmp[4];
    char anio[5];
    char mes[5];
    char dia[5];


    if(listA != NULL && lenA > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmptyAlmuerzo(listA,lenA);
        printf("\t\t***ALTA DE ALMUERZO***");
        if(index == -1)
        {
            printf("\nNo hay lugar en el sistema. \n") ;
            ret = -1 ;
            system("pause");

        }
        else
        {

            index++; // se suma uno asi el primer almuerzo no tiene id "0"
            printf("\nNuevo almuerzo, CODIGO numero %d. \n\n",index) ;



            // SE LE HACE SELECCIONAR UN MENU AL USUARIO
            do
            {
                printf("\nSeleccionar el menu correspondiente:\n");
                showMenues(listM,lenM);
                while(!function_getStringNumeros("\n\nIngrese el numero de ID del menu: ",auxMenu))
                {
                    printf("Error el ID debe tener solo numeros.\n\n");
                    system("pause");
                }
                indexMenu = findMenuById(listM,lenM,atoi(auxMenu));
                if(indexMenu == -1)
                {
                    printf("\n***ERROR*** El id del menu es incorrecto");
                }
                else
                {
                    system("cls");
                    printf("\n\nEl menu seleccionado es:\n\nID\tDescripcion\tImporte\n");
                    showMenu(listM[indexMenu],lenM);
                }

            }
            while(indexMenu == -1);

            // carga de empleado
            printf("\nSeleccionar empleado:\n");
            showEmployees(listE,lenE,listS,lenS);
            do
            {
             while(!function_getStringNumeros("\nIngrese el numero de legajo del empleado/a: ",auxLegajoEmp))
                {
                    printf("\nError el legajo debe tener solo numeros.\n\n");
                    system("pause");
                }
                indexEmp = findEmployeeById(listE,lenE,atoi(auxLegajoEmp));
                if(indexEmp == -1)
                {
                    printf("\n***ERROR*** Legajo incorrecto\n");
                    system("pause");
                }else
                {
                    printf("\nEl empleado seleccionado es:\n");
                    showEmployee(listE[indexEmp],listS,lenS);
                }

            }
            while(indexEmp == -1);

            //carga de la fecha
            printf("\n\nIngresar fecha del almuerzo:\n");
            ingresarDia(dia);
            ingresarMes(mes);
            ingresarAnio(anio);

            //se copian todos los datos al nuevo almuerzo
            newLunch.id = index;
            newLunch.menu = listM[indexMenu];
            newLunch.empleado = listE[indexEmp];
            newLunch.fechaDelAlmuerzo.dia = atoi(dia);
            newLunch.fechaDelAlmuerzo.mes = atoi(mes);
            newLunch.fechaDelAlmuerzo.anio = atoi(anio);
            newLunch.isEmpty = 0;
            listA[index] = newLunch;
            system("cls");
            showLunch(listA[index],lenA,listM,lenM,listE,lenE);
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


int menuLunches()
{
    char auxOption[3];
    int option;
    system("cls") ;
    printf("\n\t\t*** MENU ALMUERZOS ***\n\n");
    printf("1-ALTAS \n");
    printf("2-VER ALMUERZOS \n\n") ;
    printf("3-VOLVER AL MENU PRINCIPAL\n\n") ;
    while(!function_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 3. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}

void showLunch(eAlmuerzos listAlm,int lenAlm,eMenues listMen[],int lenMen,eEmployee listEmp[],int lenEmp)
{
    int indexEmp,indexMenu;

    printf("\n\n***ALMUERZO***\nFecha: %d/%d/%d\n",listAlm.fechaDelAlmuerzo.dia,listAlm.fechaDelAlmuerzo.mes,listAlm.fechaDelAlmuerzo.anio);
    printf("Codigo de almuerzo: %d\n\n",listAlm.id);

    indexEmp = findEmployeeById(listEmp,lenEmp,listAlm.empleado.legajo); //se busca el empleado y se lo muestra
    printf("Empleado/a: %s %s",listEmp[indexEmp].lastName,listEmp[indexEmp].name);

    indexMenu = findMenuById(listMen,lenMen,listAlm.menu.id);
    printf("\n\nMenu consumido: %s $%d",listMen[indexMenu].descripcion,listMen[indexMenu].importe);

}

void showLunches(eAlmuerzos listAlm[],int lenAlm,eMenues listMen[],int lenMen,eEmployee listEmp[],int lenEmp)
{
    for(int i = 0;i < lenAlm;i++)
    {
        if(listAlm[i].isEmpty == 0)
        {
            printf("\n________________________________________\n");
            showLunch(listAlm[i],lenAlm,listMen,lenMen,listEmp,lenEmp);
            printf("\n\n");
        }
    }
}

void hardcodeoAlmuerzos(eAlmuerzos* list)
{
eAlmuerzos alm[]=
    {
        {1,0,{1,60,"Sanguche de milenasa completo"},{1,"Riquelme","Juan","Masculino",20000,0,{12,05,2001},{1,"Recursos Humanos"}},{06,05,2019}},
        {2,0,{1,60,"Sanguche de milenasa completo"},{5,"Nunez","Diego","Masculino",34000,0,{18,02,2019},{1,"Recursos Humanos"}},{02,03,2019}},
        {3,0,{4,55,"Cafe + 2 medialunas"},{2,"Andrada","Sebastian","Masculino",18500,0,{05,05,2019},{3,"Ventas"}},{03,03,2019}},
        {4,0,{5,25,"Galletitas Pitusas"},{3,"Sotto","Rocio","Femenino",12500,0,{03,05,2018},{4,"Administracion"}},{07,07,2019}},
        {5,0,{2,120,"Pati completo + Papas con cheddar"},{4,"Perez","Sol","Femenino",50000,0,{20,06,2005},{5,"Legales"}},{05,05,2019}},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = alm[i];
    }

}
