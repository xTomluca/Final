#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Entregas.h"
#include "view.h"
#include "utn.h"
#include "Parser.h"
#include "Localidades.h"
#include "Controller.h"

void printf_ImprimirLocalidad(void* p)
{
    if(p!=NULL)
    {
        Localidades* aux = p;
        char localidad[128];
        Localidades_getLocalidad(aux,localidad);
        printf("%s \n",localidad);
    }
}
void printf_ImprimirProducto(void* p)
{
    if(p!=NULL)
    {
        Entregas* aux = p;
        int id;
        char producto[128];
        char direccion[128];
        char localidad[128];
        char recibe[128];
        Entregas_getId(aux,&id);
        Entregas_getProducto(aux,producto);
        Entregas_getDireccion(aux,direccion);
        Entregas_getLocalidad(aux,localidad);
        Entregas_getRecibe(aux,recibe);
        printf("    %d  -   %s  -  %s   -  %s   -  %s\n",id,producto,direccion,localidad,recibe);
    }
}
void printf_Productos(ArrayList* pEntregas)
{
    if(pEntregas!=NULL)
    {
        al_map(pEntregas,printf_ImprimirProducto);
    }
}
void printf_Localidades(ArrayList* pLocalidades, ArrayList* pEntregas)
{
    int i, j, index;
    char localidad1[128];
    char localidad2[128];
    if(pEntregas!=NULL)
    {
        Localidades* aux1;
        Localidades* aux2;
        if(!Localidades_add(pEntregas,pLocalidades))
        {
           if(pLocalidades!=NULL)
           {
                al_sort(pLocalidades,localidades_sort,0);
                for(i=0;i<al_len(pLocalidades);i++)
                {
                    aux1 = al_get(pLocalidades,i);
                    if(aux1!=NULL)
                        Localidades_getLocalidad(aux1,localidad1);
                    for(j=i+1;al_len(pLocalidades);j++)
                    {
                        aux2 = al_get(pLocalidades,j);
                        if(aux2!=NULL)
                        {
                            Localidades_getLocalidad(aux2,localidad2);
                            if(strcmp(localidad1,localidad2)==0)
                            {
                                index = al_indexOf(pLocalidades,aux2);
                                al_remove(pLocalidades,index);
                            }
                        }
                    }
                }
           }
            //al_map(Localidades,printf_ImprimirLocalidad);
        }

    }
}



