#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Entregas.h"
#include "Localidades.h"
#include "utn.h"
#include "Parser.h"


void imprimirProducto(void* pElement)
{
    Entregas* aux=NULL;
    int id;
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];

    if(pElement!=NULL)
    {
        aux = pElement;
        if(aux!=NULL)
        {
            Entregas_getId(aux,&id);
            Entregas_getProducto(aux,producto);
            Entregas_getDireccion(aux,direccion);
            Entregas_getLocalidad(aux,localidad);
            Entregas_getRecibe(aux,recibe);
            printf("%d  -   %s  -   %s  -   %s  -   %s\n",id,producto,direccion,localidad,recibe);
        }
    }
}

int sort_localidades(void* pElement1,void* pElement2)
{
    char loc1[128];
    char loc2[128];
    if(pElement1!=NULL && pElement2!=NULL)
    {
        Localidades_getProducto(pElement1,loc1);
        Localidades_getProducto(pElement2,loc2);
        if(strcmp(loc1,loc2)>0)
            return 1;
        else if(strcmp(loc1,loc2)<0)
            return -1;
    }
    return -2;
}

void imprimirLocalidad(void* pElement)
{
    if(pElement!=NULL)
    {
        Localidades* auxLoc=pElement;
        char localidad[128];
        if(auxLoc!=NULL)
        {
            Localidades_getProducto(auxLoc,localidad);
            printf("%s\n",localidad);
        }
    }
}
void map(ArrayList* pEntregas, ArrayList* pLocalidades, void (*pFunc)(ArrayList*,void*))
{
    int i;
    int j;
    Localidades* aux1=NULL;
    Localidades* aux2=NULL;
    ArrayList* new = al_newArrayList();
    char loc1[128];
    char loc2[128];
    if(al_len(pLocalidades)==0)
    {
        for(i=0;i<al_len(pEntregas);i++)
        {
                pFunc(pLocalidades,al_get(pEntregas,i));
        }

    }
    if(al_len(pLocalidades)>0)
    {
        al_sort(pLocalidades,sort_localidades,1);
        for(i=0;i<al_len(pLocalidades)-1;i++)
        {
           for(j=i+1;j<al_len(pLocalidades);j++)
           {
                aux1 = al_get(pLocalidades,i);
               aux2 = al_get(pLocalidades,j);
               if(aux1!=NULL && aux2!=NULL)
               {
                    Localidades_getProducto(aux1,loc1);
                    Localidades_getProducto(aux2,loc2);
                    if(strcmp(loc1,loc2)==0)
                    {
                        al_remove(pLocalidades,j);
                        //al_add(new,aux1);
                        j-=1;
                        //al_add(new,aux1);
                        //i++;
                    }
                    else
                    {

                    }
               }
           }
           //printf("%s\n",loc1);
        }
        al_map(pLocalidades,imprimirLocalidad);

    }
}
void add_localidades(ArrayList* pLocalidades,void* pElement)
{

    if(pElement!=NULL)
    {
        Entregas* aux=pElement;
        Localidades* auxLoc=NULL;
        char localidad[128];
        Entregas_getLocalidad(aux,localidad);
        auxLoc = Localidades_newConParametros(localidad);
        if(auxLoc!=NULL)
            al_add(pLocalidades,auxLoc);
    }
}

/*void imprimirLocalidades(ArrayList* pLocalidades, ArrayList* pEntregas)
{
    int i,j;
    char locEnt[128];
    char locLoc[128];
    Localidades* auxLoc=NULL;
    Entregas* auxEnt=NULL;
    for(i=0;i<al_len(pEntregas);i++)
    {
        auxEnt = al_get(pEntregas,i);
        Entregas_getLocalidad(auxEnt,locEnt);
        if(!i && auxEnt!=NULL)
        {
            printf("ADD");
            auxLoc = Localidades_newConParametros(locEnt);
            if(auxLoc!=NULL)
                al_add(pLocalidades,auxLoc);
        }
        for(j=0;j<al_len(pLocalidades);j++)
        {
            auxLoc = al_get(pLocalidades,j);
            Localidades_getProducto(auxLoc,locLoc);
            if(strcmp(locEnt,locLoc)==0)
            {
                continue;
            }
                auxLoc = Localidades_newConParametros(locEnt);
                if(auxLoc!=NULL)
                    al_add(pLocalidades,auxLoc);
        }
    }
    if(al_len(pLocalidades)>0)
        al_map(pLocalidades,imprimirLocalidad);
}*/

/*void imprimirLocalidades(ArrayList* pLocalidades, ArrayList* pEntregas)
{
    int i,j,add=1;
    int ok=-1;
    char localidadEntr[128];
    char localidadI[128];
    char localidadJ[128];
    Entregas* auxEntrega=NULL;
    Localidades* auxLocalidades=NULL;
    Localidades* auxLocalidades2=NULL;
    ArrayList* aux = al_newArrayList();
    if(pLocalidades!=NULL&&pEntregas!=NULL)
    {
        for(i=0;i<al_len(pEntregas);i++)
        {
            auxEntrega=al_get(pEntregas,i);
            if(auxEntrega!=NULL)
            {
                Entregas_getLocalidad(auxEntrega,localidadEntr);
                auxLocalidades= Localidades_newConParametros(localidadEntr);
                al_add(pLocalidades,auxLocalidades);
                ok=0;
            }
        }
        if(!ok)
        {
            for(i=0;i<al_len(pLocalidades);i++)
            {
                auxLocalidades = al_get(pLocalidades,i);
                Localidades_getProducto(auxLocalidades,localidadI);
                if(!i && auxLocalidades!=NULL)
                {
                    al_add(aux,auxLocalidades);
                }
                for(j=0;j<al_len(aux);j++)
                {
                    auxLocalidades2=al_get(aux,j);
                    Localidades_getProducto(auxLocalidades2,localidadJ);
                    if(strcmp(localidadI,localidadJ)==0)
                    {
                        i++;
                        add=1;
                    }
                    else if(!add&&auxLocalidades!=NULL)
                    {
                        al_add(aux,auxLocalidades);
                        printf("%s\n",localidadI);
                    }
                }
            }
        }
    }
}*/

int compareLoc(void* loc1, ArrayList* pLoc)
{
    int i,retorno=-1;
    char loc2[128];
    if(loc1!=NULL && loc2!=NULL)
    {
        for(i=0;i<al_len(pLoc);i++)
        {
            Localidades* auxLoc=al_get(pLoc,i);
            Localidades_getProducto(auxLoc,loc2);
            if(!strcmp(loc1,loc2))
            {
               retorno = 0;
               break;
            }
        }
    }
    return retorno;
}

int compareEntr(void* loc1, ArrayList* pEntr)
{
    int i,retorno=-1;
    char loc2[128];
    if(loc1!=NULL && loc2!=NULL)
    {
        printf("%s",loc1);
        for(i=0;i<al_len(pEntr);i++)
        {
            Entregas* auxEnt=al_get(pEntr,i);
            Entregas_getLocalidad(auxEnt,loc2);
            if(!strcmp(loc1,loc2))
            {
               retorno = 0;
               break;
            }
        }
    }
    return retorno;
}

void imprimirPedidos(void* loc1, ArrayList* pEntr)
{
    int i;
    int id;
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];

    if(loc1!=NULL && pEntr!=NULL)
    {
        for(i=0;i<al_len(pEntr);i++)
        {
            Entregas* auxEnt=al_get(pEntr,i);
            Entregas_getLocalidad(auxEnt,localidad);
            if(!strcmp(loc1,localidad))
            {
                Entregas_getId(auxEnt,&id);
                Entregas_getProducto(auxEnt,producto);
                Entregas_getDireccion(auxEnt,direccion);
                Entregas_getRecibe(auxEnt,recibe);
                printf("%s  -   %d  -   %s  -   %s  -   %s\n",localidad,id,producto,direccion,recibe);
            }
        }
    }
}


void imprimirLocalidades(ArrayList* pEntr,ArrayList* pLoc)
{
    int i;
    Entregas* auxLocEntr;
    Localidades* auxLocLoc;
    char localidadEntr[128];
    for(i=0;i<al_len(pEntr);i++)
    {
        auxLocEntr=al_get(pEntr,i);
        Entregas_getLocalidad(auxLocEntr,localidadEntr);
        if(!i && auxLocEntr!=NULL && auxLocLoc!=NULL)
        {
            auxLocLoc = Localidades_newConParametros(localidadEntr);
            al_add(pLoc,auxLocLoc);
        }
        else
            if(compareLoc(localidadEntr,pLoc))
            {
                auxLocLoc = Localidades_newConParametros(localidadEntr);
                al_add(pLoc,auxLocLoc);
            }
    }
    al_map(pLoc,imprimirLocalidad);
}

void pedirLocalidades(ArrayList* pEntregas)
{
    int i;
    int ok=0;
    char localidades[3][128];
    if(pEntregas!=NULL)
    {
        for(i=0;i<3;i++)
        {
            getStringLetras("Ingrese localidad",localidades[i]);
            if(!compareEntr(localidades[i],pEntregas))
            {
                ok++;
                printf("OK:%d!\n",ok);
                //continue;

            }
            else
            {
                printf("ERROR!\n");
                break;
            }
        }
        if(ok==3)
        {
            for(i=0;i<3;i++)
            {
                imprimirPedidos(localidades[i],pEntregas);
            }
        }
    }
}
