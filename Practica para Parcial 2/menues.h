typedef struct
{
    int id;
    int importe;
    char descripcion[51];

}eMenues;

void hardcodeoMenues(eMenues* list) ;

void mostrarMenu (eMenues list,int len);

void mostrarMenues (eMenues list[],int len);
