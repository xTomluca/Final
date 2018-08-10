#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Localidades.h"
#include "Pedidos.h"
#include "Controller.h"
#include "utn.h"

void imprimirLista(ArrayList* pPedidos)
{
    if(pPedidos!=NULL&&!al_map(pPedidos,imprimirPedido));
    else
        printf("ERROR\n");
}

void imprimirPedido(void* pedido)
{
    Pedidos* aux=NULL;
    int id;
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
    if(pedido!=NULL)
    {
        aux = pedido;
        Pedidos_getId(aux,&id);
        Pedidos_getDireccion(aux,direccion);
        Pedidos_getProducto(aux,producto);
        Pedidos_getLocalidad(aux,localidad);
        Pedidos_getRecibe(aux,recibe);
        printf("%d  -   %s      -%s      -%s      -%s\n",id,producto,direccion,localidad,recibe);
    }
    else
        printf("ERROR!\n");
}

void imprimirLocalidad(void* pedido)
{
    Localidades* aux=NULL;
    char localidad[128];
    if(pedido!=NULL)
    {
        aux = pedido;
        Localidades_getLocalidad(aux,localidad);
        printf("%s\n",localidad);
    }
    else
        printf("ERROR!\n");
}

void listarLocalidades(ArrayList* pPedidos, ArrayList* pLocalidades)
{
    int i;
    char locPed[128];
    Pedidos* auxPed=NULL;
    Localidades* auxLoc=NULL;
    if(pPedidos!=NULL && pLocalidades!=NULL)
    {
        for(i=0;i<al_len(pPedidos);i++)
        {
            auxPed = al_get(pPedidos,i);
            Pedidos_getLocalidad(auxPed,locPed);
            if(al_len(pLocalidades)==0 && auxPed!=NULL)
            {
                auxLoc = Localidades_newConParametros(locPed);
                if(auxLoc!=NULL&&auxPed!=NULL)
                    al_add(pLocalidades,auxLoc);
            }
            else if(!buscarLocalidad(pLocalidades,locPed))
            {
                auxLoc = Localidades_newConParametros(locPed);
                if(auxLoc!=NULL)
                    al_add(pLocalidades,auxLoc);
            }
        }
        if(al_len(pLocalidades)>0)
            al_map(pLocalidades,imprimirLocalidad);
    }
}

int buscarLocalidad(ArrayList* pLocalidades,char* locPed)
{
    Localidades* aux=NULL;
    int i=0;
    int retorno=-1;
    char locLoc[128];

    for(i=0;i<al_len(pLocalidades);i++)
    {
        aux=al_get(pLocalidades,i);
        if(aux!=NULL)
        {
            Localidades_getLocalidad(aux,locLoc);
            if(strcmp(locLoc,locPed)==0)
            {
                retorno = 1;
                break;
            }
            retorno=0;
        }
    }
    return retorno;
}
int buscarLocalidadPedidos(ArrayList* pPedidos,char* auxLocalidad)
{
    Pedidos* aux=NULL;
    int i=0;
    int retorno=-1;
    char locLoc[128];

    for(i=0;i<al_len(pPedidos);i++)
    {
        aux=al_get(pPedidos,i);
        if(aux!=NULL)
        {
            Pedidos_getLocalidad(aux,locLoc);
            if(strcmp(locLoc,auxLocalidad)==0)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
void imprimirPedidosPorLoc(ArrayList* pPedidos,char* auxLocalidad,int apertura,char *nombreArchivo)
{
    Pedidos* aux=NULL;
    int i=0;
    int id;
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
    FILE* fp = NULL;

    if(!apertura)
    {
        strcat(nombreArchivo,".csv");
        fp = fopen(nombreArchivo,"w");
    }
    else
    {
        fp = fopen(nombreArchivo,"a");
    }

    if(fp!=NULL)
    {
        for(i=0;i<al_len(pPedidos);i++)
        {
            aux=al_get(pPedidos,i);
            if(aux!=NULL)
            {
                Pedidos_getLocalidad(aux,localidad);
                if(strcmp(localidad,auxLocalidad)==0)
                {
                    Pedidos_getId(aux,&id);
                    Pedidos_getDireccion(aux,direccion);
                    Pedidos_getProducto(aux,producto);
                    Pedidos_getRecibe(aux,recibe);
                    fprintf(fp,"%d      -       %s      -       %s      -       %s      -       %s\n",id,producto,direccion,localidad,recibe);
                }
            }
        }
    }
}



void listarPedidos(ArrayList* pPedidos)
{
    int i;
    int imprimir=0;
    char auxLocalidad[3][128];
    char nombreArchivo[128];
    if(pPedidos!=NULL)
    {
        for(i=0;i<3;i++)
        {
            getString("INGRESE LOCALIDAD: ",auxLocalidad[i]);
            if(!buscarLocalidadPedidos(pPedidos,auxLocalidad[i]))
            {
                imprimir++;
            }
            else
            {
                printf("ERROR!\n");
                break;
            }
        }
        if(imprimir==3)
        {
            if(!getValidString("Ingrese nombre archivo a guardar: ","ERROR\n","SUPERA LARGO",nombreArchivo,128,1))
                for(i=0;i<3;i++)
                    imprimirPedidosPorLoc(pPedidos,auxLocalidad[i],i,nombreArchivo);
        }

    }
}

