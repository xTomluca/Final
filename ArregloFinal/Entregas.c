#include "utn.h"
#include "Entregas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Entregas* Entregas_new()
{
    Entregas* this;
    this=malloc(sizeof(Entregas));
    return this;
}

void Entregas_delete(Entregas* this)
{
    free(this);
}

Entregas* Entregas_newConParametros(	int id,char* producto,char* direccion,char* localidad,char* recibe)
{
    Entregas* this;
    this=Entregas_new();

    if(
    !Entregas_setId(this,id)&&
    !Entregas_setProducto(this,producto)&&
    !Entregas_setDireccion(this,direccion)&&
    !Entregas_setLocalidad(this,localidad)&&
    !Entregas_setRecibe(this,recibe))
        return this;

    Entregas_delete(this);
    return NULL;
}

Entregas* Entregas_newConParametrosString(char* idStr,char* producto,char* direccion,char* localidad,char* recibe)
{
    Entregas* this;
    this=Entregas_new();
    int id;
    if(esNumerico(idStr)&&esSoloLetras(producto)&&esSoloLetras(localidad)&&esSoloLetras(recibe)&&esAlfaNumerico(direccion))
    {
        id = atoi(idStr);
        if(
        !Entregas_setId(this,id)&&
        !Entregas_setProducto(this,producto)&&
        !Entregas_setDireccion(this,direccion)&&
        !Entregas_setLocalidad(this,localidad)&&
        !Entregas_setRecibe(this,recibe))
            return this;
    }

    Entregas_delete(this);
    return NULL;
}

int Entregas_setId(Entregas* this,	int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Entregas_getId(Entregas* this,	int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Entregas_setProducto(Entregas* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

int Entregas_getProducto(Entregas* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(producto,this->producto);
        retorno=0;
    }
    return retorno;
}

int Entregas_setDireccion(Entregas* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(this->direccion,direccion);
        retorno=0;
    }
    return retorno;
}

int Entregas_getDireccion(Entregas* this,char* direccion)
{
    int retorno=-1;
    if(this!=NULL && direccion!=NULL)
    {
        strcpy(direccion,this->direccion);
        retorno=0;
    }
    return retorno;
}

int Entregas_setLocalidad(Entregas* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(this->localidad,localidad);
        retorno=0;
    }
    return retorno;
}

int Entregas_getLocalidad(Entregas* this,char* localidad)
{
    int retorno=-1;
    if(this!=NULL && localidad!=NULL)
    {
        strcpy(localidad,this->localidad);
        retorno=0;
    }
    return retorno;
}

int Entregas_setRecibe(Entregas* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(this->recibe,recibe);
        retorno=0;
    }
    return retorno;
}

int Entregas_getRecibe(Entregas* this,char* recibe)
{
    int retorno=-1;
    if(this!=NULL && recibe!=NULL)
    {
        strcpy(recibe,this->recibe);
        retorno=0;
    }
    return retorno;
}

