
typedef struct
{
    int id;
    char dominio[9];
    int anio;
    char tipo;
}eDominio;

eDominio* dominio_new();

int dominio_setId(eDominio* this,int id) ;
int dominio_getId(eDominio* this,int* id);

int dominio_setDominio(eDominio* this,char* dominio);
int dominio_getDominio(eDominio* this,char* dominio);

int dominio_setAnio(eDominio* this,int anio);
int dominio_getAnio(eDominio* this,int* anio);

int dominio_setTipo(eDominio* this,char* tipo);
int dominio_getTipo(eDominio* this,char* tipo);

void setearTipoPorCriterio (eDominio* this);
