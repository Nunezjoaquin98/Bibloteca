typedef struct
{
    int id;
    int isEmpty;
    eMenues menu;
    eEmployee empleado;
    eFecha fechaDelAlmuerzo;

}eAlmuerzos;

int initLunch(eAlmuerzos list[], int len);

int searchEmptyAlmuerzo(eAlmuerzos list[],int len);

int addLunch(eEmployee listE[],int lenE,eMenues listM[],int lenM,eAlmuerzos listA[],int lenA,eSector listS[],int lenS);

int menuLunches ( );

void showLunch(eAlmuerzos listAlm,int lenAlm,eMenues listMen[],int lenMen,eEmployee listEmp[],int lenEmp);

void showLunches(eAlmuerzos listAlm[],int lenAlm,eMenues listMen[],int lenMen,eEmployee listEmp[],int lenEmp);

void hardcodeoAlmuerzos(eAlmuerzos* list);
