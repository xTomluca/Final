#include "Localidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Localidades* Localidades_new()
{
    Localidades* this;
    this=malloc(sizeof(Localidades));
    return this;
}

void Localidades_delete(Localidades* this)
{
    free(this);
}

Localidades* Localidades_newConParametros(char* producto)
{
    Localidades* this;
    this=Localidades_new();

    if(
    !Localidades_setProducto(this,producto))
        return this;

    Localidades_delete(this);
    return NULL;
}

int Localidades_setProducto(Localidades* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

int Localidades_getProducto(Localidades* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(producto,this->producto);
        retorno=0;
    }
    return retorno;
}

