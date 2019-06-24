#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "dominio.h"



eDominio* dominio_new()
{

    eDominio* nuevo;

    nuevo = (eDominio*)malloc(sizeof(eDominio));

    return nuevo;


}

int dominio_setId(eDominio* this,int id)
{
    int ret = 0;

    if(this != NULL)
    {
        if(id>0)
        {
            this->id = id;
            ret = 1;
        }

    }

    return ret;
}

int dominio_getId(eDominio* this,int* id)
{
    int ret = 0;

    if(this != NULL)
    {
        *id = this->id;
        ret = 1;

    }

    return ret;

}


int dominio_setDominio(eDominio* this,char* dominio)
{
    int ret = 0;

    if(this != NULL)
    {
        strcpy(this->dominio,dominio);
        ret = 1;
    }

    return ret;
}

int dominio_getDominio(eDominio* this,char* dominio)
{

    int ret = 0;

    if(this != NULL)
    {
        strcpy(dominio,this->dominio);
        ret = 1;

    }

    return ret;
}


int dominio_setAnio(eDominio* this,int anio)
{
    int ret = 0;

    if(this != NULL)
    {
        if(anio>0)
        {
            this->anio = anio;
            ret = 1;
        }

    }

    return ret;
}

int dominio_getAnio(eDominio* this,int* anio)
{
    int ret = 0;

    if(this != NULL)
    {
        *anio = this->anio;
        ret = 1;

    }

    return ret;

}

int dominio_setTipo(eDominio* this,char* tipo)
{
    int ret = 0;

    if(this != NULL)
    {
        strcpy(this->tipo,tipo);
        ret = 1;
    }

    return ret;
}

int dominio_getTipo(eDominio* this,char* tipo)
{

    int ret = 0;

    if(this != NULL)
    {
        strcpy(tipo,this->tipo);
        ret = 1;

    }

    return ret;
}

void setearTipoPorCriterio (eDominio* this)
{
    if(this->dominio[0] >= 48 && this->dominio[0] <= 57)
    {
        dominio_setTipo(this,"M");
    }else
    {
        dominio_setTipo(this,"A");
    }
}

