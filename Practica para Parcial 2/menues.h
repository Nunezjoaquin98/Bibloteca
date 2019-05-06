typedef struct
{
    int id;
    int importe;
    char descripcion[51];

}eMenues;

void hardcodeoMenues(eMenues* list) ;

void showMenu (eMenues list,int len);

void showMenues (eMenues list[],int len);

int findMenuById(eMenues list[], int len, int id);

int obtenerMenu(eMenues list[], int len, int idM, char descripcion[]);

int obtenerImporteMenu(eMenues list[], int len, int idM, int precio);
