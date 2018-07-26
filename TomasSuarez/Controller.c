#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Entregas.h"
#include "view.h"
#include "utn.h"
#include "Localidades.h"

int Localidades_add(ArrayList* pEntregas, ArrayList* pLocalidades)
{
    int retorno = -1;
    int i;
    Entregas* aux;
    Localidades* auxLoc;
    char localidad[128];
    if(pEntregas!=NULL && pLocalidades!=NULL)
    {
        for(i=0;i<al_len(pEntregas);i++)
        {
            aux = al_get(pEntregas,i);
            if(aux!=NULL)
            {
                Entregas_getLocalidad(aux,localidad);
                auxLoc = Localidades_newConParametros(localidad);
                if(auxLoc!=NULL)
                {
                    al_add(pLocalidades,auxLoc);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

int localidades_sort(void* pLocalidad1,void* pLocalidad2)
{
    char localidad1[128];
    char localidad2[128];
    if(pLocalidad1!=NULL && pLocalidad2!=NULL)
    {
        Localidades* aux1=pLocalidad1;
        Localidades* aux2=pLocalidad2;
        Localidades_getLocalidad(aux1, localidad1);
        Localidades_getLocalidad(aux2, localidad2);
        if(strcmp(localidad1,localidad2)>0)
            return 1;
        if(strcmp(localidad1,localidad2)==0)
            return 0;
        if(strcmp(localidad1,localidad2)<0)
            return -1;
    }
    return -2;
}

int localidades_sort(void* pLocalidad1,void* pLocalidad2)
{
    char localidad1[128];
    char localidad2[128];
    if(pLocalidad1!=NULL && pLocalidad2!=NULL)
    {
        Entregas* aux1=pLocalidad1;
        Entregas* aux2=pLocalidad2;
        Localidades_getLocalidad(aux1, localidad1);
        Localidades_getLocalidad(aux2, localidad2);
        if(strcmp(localidad1,localidad2)>0)
            return 1;
        if(strcmp(localidad1,localidad2)==0)
            return 0;
        if(strcmp(localidad1,localidad2)<0)
            return -1;
    }
    return -2;
}
