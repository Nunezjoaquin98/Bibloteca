#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int anio;
    int mes;
}eFecha;


/** \brief ingresa una fecha formato dd/mm/aaaa
 *
 * \return una fecha validada
 *
 */
eFecha ingresarFecha();
