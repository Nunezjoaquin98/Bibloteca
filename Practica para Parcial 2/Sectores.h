typedef struct
{
    int id;
    char descripcion[51];
}eSector;

/** \brief Muestra todos los sectores cargados con su id y descripcion
 *
 *
 *
 */
void mostrarSectores();

int obtenerSector(eSector sec[], int len, int idS, char desc[]);

/** \brief se carga un array de sectores
 *
 * \param eSector array
 *
 */
void hardcodeoSectores(eSector* list);
