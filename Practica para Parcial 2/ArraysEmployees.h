typedef struct
{
    int legajo;
    char lastName[51];
    char name [51];
    char sex[10];
    float salary;
    int isEmpty;
    eFecha ingreso;
    eSector sec;
} eEmployee;

//Funciones de empleados

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(eEmployee list[], int len) ;

/** \brief Busca un indice libre
 *
 * \param Array a buscar.
 * \param Tama�o del array
 * \return Devuelve el indice dond eesta vacio, y si no lo esta devuelve -1.
 *
 */
int searchEmpty(eEmployee list[],int len);


/** \brief  find an Employee by Id en returns the index position in array.
 *
 * \param list employee
 * \param len int
 * \param id int
 * \return  Return employee index position or (-1) if the employee not found.
 *
 */
int findEmployeeById(eEmployee list[], int len, int id) ;

/** \brief show employee of a list
 *
 * \param array
 *
 */
void showEmployee(eEmployee list,eSector listC[],int lenSector);

/** \brief show employee of a list
 *
 * \param array employee
 * \param array sector
 * \param lenght sector int
 *
 */
void showEmployees(eEmployee list[],int len,eSector listSec[],int lenSector);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(eEmployee list[], int len,eSector listSec[],int lenSec) ;

void modifyEmployee(eEmployee list[], int len,eSector listSeC[],int lenSec);


/** \brief carga una lista de empleados
 *
 * \param array employee
 *
 */
void hardcodeoEmpleados(eEmployee* list);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param lenght int
 * \param id int
 * \param list Sector
 * \param lenght sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee list[], int len,int id,eSector listSec[],int lenSec) ;

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee list[], int len) ;

void function_averageSalary (eEmployee list[],int len);

int hayEmpleadoCargado (eEmployee list[],int len);

