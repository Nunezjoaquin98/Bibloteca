#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "funciones.h"
#include "socios.h"

int initSocios(eSocios list[], int len)
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


int searchEmpty(eSocios list[],int len)
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

int findSocioById(eSocios list[], int len, int id)
{
    int ret ;

    for(int i=0; i < len; i++)
    {

        if( list[i].codigoDeSocio == id && list[i].isEmpty == 0)
        {
            ret = i;
            break;
        }
        else
        {
            ret = -1;
        }
    }
    return ret;

}

void showSocios(eSocios list[],int len)
{
    printf("\n\nCODIGO\tAPELLIDO\tNOMBRE\tSEXO\t  TELEFONO\t\tEMAIL\t\t FECHA DE INGRESO\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            showSocio(list[i]);
        }
    }

}

void showSocio(eSocios list)
{
    printf("\n%d\t  %s\t%s\t%s\t%d\t%s\t%d/%d/%d\n",list.codigoDeSocio,list.apellido,list.nombre,list.sexo,list.telefono,list.email,list.fechaDeInscipcion.dia,list.fechaDeInscipcion.mes,list.fechaDeInscipcion.anio);

}



int addSocio(eSocios list[], int len)
{
    eSocios newSocio ;
    int ret,index,sex;
    char auxName[31];
    char auxLastName[31];
    char auxSex[3];
    char auxTelefono[16] ;
    char auxEmail[31] ;
    char auxDia[4];
    char auxMes[4];
    char auxAnio[5];

    if(list != NULL && len > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmpty(list,len) ;
        printf("\n\t------- Alta Socio -------\n\n");

        if(index == -1)
        {
            printf("No hay lugar en el sistema. \n") ;
            ret = -1 ;
            system("pause");

        }
        else
        {

            index++; // se suma uno asi el primer socio no tiene codigo "0"
            printf("\nNuevo socio, codigo de socio numero %d. \n\n",index) ;
            newSocio.legajo = index ;
            while(!function_getStringLetras("Ingrese nombre: ",auxName)) //carga el nombre
            {
                printf("El nombre solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");

            }
            while(!function_getStringLetras("\nIngrese apellido: ",auxLastName)) // carga el apellido
            {
                printf("El apellido debe tener solo letras.\n\n") ;
                system("pause");
                system("cls");

            }

            do //se hace un do while para que el usuario elija 1 o 2 correctamente para seleccionar el genero
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

            }while(!(sex == 1 || sex == 2));

            while(!function_getStringNumeros("\nIngrese el telefono sin comas ni guiones: ",auxTelefono)) //carga del telefono
            {
                printf("**** Error **** El telefono debe tener solo numeros\n\n");
                system("pause");
                system("cls");
            }
            printf("\nIngrese el email: ")
           gets(auxEmail); // carga de mail

                       //FECHA DE SOCIO
            printf("\n\t--FECHA EN LA QUE SE ASOCIO--\n");
            ingresarDia(auxDia);
            ingresarMes(auxMes);
            ingresarAnio(auxAnio);
            printf("\n");

            // se copian todos los datos del nuevo empleado.

            strcpy(newSocio.nombre,auxName) ;
            strcpy(newSocio.apellido,auxLastName) ;
            strcpy(newSocio.sexo,auxSex);
            newSocio.telefono = atoi(auxTelefono) ;
            strcpy(newSocio.email,auxEmail);
            newSocio.fechaDeInscipcion.dia = atoi(auxDia);
            newSocio.fechaDeInscipcion.mes = atoi(auxMes);
            newSocio.fechaDeInscipcion.anio = atoi(auxAnio);
            newSocio.isEmpty = 0;
            list[index] = newSocio ;
            system("pause");
            system("cls");
            printf("\n\nSOCIO DADO DE ALTA CON EXITO:\n\n");
            showSocio(list[index]);
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

void modifySocio(eSocios list[], int len)
{
    int id,index,sexo;
    char salir = 'n';

    char auxCodigo[5];
    char newTelefono[16];
    char newEmail[31];
    char newName[31];
    char newLastName[31] ;
    char newSex[3];
    char auxDia[5];
    char auxMes[5];
    char auxAnio[5];


    system("cls");
    printf("\t\t  *** Modificar  Socio ***\n\n");
    showSocios(list,len);
    if(!function_getStringNumeros("\nIngrese el codigo del socio: ",auxCodigo))
    {
        printf("*** ERROR *** El codigo debe contener solo numeros.\n") ;
    }

    id = atoi(auxCodigo) ;
    index = findSocioById(list, len, id);


    if( index == -1)
    {
        printf("\n\nNo hay ningun socio con legajo %d.\n\n", id);
        system("pause");
    }
    else
    {


       showSocio(list[index]) ;
        do
        {

            switch(menuModificarSocios())
            {
            case 1:
             showSocio(list[index]);
                printf("\n\n");
                //modificar nombre
                while(!function_getStringLetras("Ingrese nuevo nombre: ",newName))
                {
                    printf("*** Error *** El nombre debe tener solo letras.");
                }
                strcpy(list[index].nombre,newName);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls");
                break ;
            case 2:
// Modifica apellido
                showSocio(list[index]);
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
                showSocio(list[index]);
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
                // MODIFICA TELEFONO
                showSocio(list[index]);
                printf("\n\n");
                while(!function_getStringNumeros("Ingrese nuevo telefono sin puntos ni comas: ",newTelefono))
                {
                    printf("*** ERROR *** El telefono debe contener solo numeros.\n\n") ;
                }
                list[index].telefono = atoi(newTelefono);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls") ;
                break ;

            case 5:// FECHA DE INGRESO
                showSocio(list[index]);
                printf("\n\n\tModificar Fecha de ingreso");
                ingresarDia(auxDia);
                ingresarMes(auxMes);
                ingresarAnio(auxAnio);
                list[index].fechaDeInscipcion.dia = atoi(auxDia);
                list[index].fechaDeInscipcion.mes = atoi(auxMes);
                list[index].fechaDeInscipcion.anio = atoi(auxAnio);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls") ;
                break ;

            case 6: //MODIFICA EMAIL
                showSocio(list[index]);
                printf("\n\tModificar email\n\nIngrese el nuevo email:");
                gets(newEmail);
                strcpy(list[index].email,newEmail)
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
                printf("*** ERROR *** Debe ingresar un numero del 1 al 7.\n");
                system("pause");
                break;
            }
        }
        while(salir == 'n');
    }
}

void hardcodeoSocios(eSocios* list)
{

    eSocios socios[]=
    {
        {1,"Riquelme","Juan","Masculino",1136823896,"juanroman10@gmail.com",{12,05,2001},0},
        {2,"Palermo","Martin","Masculino",1135849813,"martin9@gmail.com",{12,12,2012},0},
        {3,"Rocio","Gonzalez","Femenino",1174853197,"rogonzalez@gmail.com",{05,05,2019},0},
        {4,"Joaquin","Nu�ez","Masculino",1136823123,"joaconunez@gmail.com",{16,04,2019},0},
        {5,"Rosa","Duki","Femenino",1112345896,"rositaduko@gmail.com",{02,07,2019},0},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = socios[i];
    }
};


int removeSocio(eSocios list[], int len,int id)
{
    char auxId[10];
    char auxYes[10];
    int yes,index,ret;

    if(list != NULL && len > 0)
    {
        do
        {
            system("cls");
            printf("\t\t  ***Baja de Socio***\n");
            showSocios(list,len);
            while(!function_getStringNumeros("\n\nIngrese el codigo del socio a borrar: ",auxId))
            {
                printf("***Error*** Debe ingresar un numero.\n");
                system("pause");
            }
            id = atoi(auxId);
            index = findSocioById(list,len,id);
            if( index == -1)
            {
                printf("No hay ningun socio con codigo %d.\n\n", id);
                system("pause");
            }
            else
            {
                showSocio(list[index]);

                while(!function_getStringNumeros("\nEs este el empleado/a que desea borrar?\nIngrese 1 si es correcto / Otro numero si es incorrecto: ",auxYes))
                {
                    printf("***Error*** Debe ingresar un numero.\n");
                    system("pause");
                }
                yes = atoi(auxYes);
                if(yes == 1)
                {
                    system("cls");
                    printf("El socio/a ha sido borrado con exito!\n");
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

int sortEmployees(eSocios list[], int len)
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
                }
                else if(strcmp(list[i].lastName,list[j].lastName) == 0 && strcmp(list[i].name,list[j].name)>0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee ;
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


int menuSocios ( )
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n\t\t*** MENU SOCIOS ***\n\n");
    printf("1-ALTAS \n");
    printf("2-MODIFCAR \n") ;
    printf("3-BAJAS \n");
    printf("4-LISTAR \n\n");
    printf("5-VOLVER AL MENU PRINCIPAL\n\n") ;
    while(!function_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 5. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}

int menuModificarSocios ()
{
    char auxOption[2];
    int option;
    printf("\n\n*** Modificar socio ***\n\n1 - Nombre\n2 - Apellido\n3 - Sexo\n4 - Telefono\n5 - Email\n6 - Fecha de ingreso\n\n7 - Regresar al menu principal\n\n");
while(!function_getStringNumeros("Ingrese opcion: ",auxOption))
{
    printf("*** Error *** Debe ingresar un numero.\n");
    system("pause");
    printf("\n");
}
    option = atoi(auxOption);
    return option;
}