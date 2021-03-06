#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Entregas.h"


/** \brief  Parser
 * \param   char* fileName is path file
 * \param   ArrayList* listaEmpleados
 * \return  Return [1]
 *//*
int guardar_Deposito(char* fileName, ArrayList* pArray)
{
    Deposito* aux;
    int producto;
    char descripcion[50];
    int cantidad;
    int i;
    int retorno = -1;
    int canTest = 0;
    char desTest[50];
    int proTest = 0;
    FILE* fp;
    fp = fopen(fileName,"w");
    if(fp!=NULL)
    {
        if(al_len(pArray)>0)
        {
            fprintf(fp,"producto,descripcion,cantidad\n");
            al_sort(pArray,deposito_SortPorProducto,1);
            for(i=0;i<al_len(pArray);i++)
            {
                aux = al_get(pArray,i);
                if(aux!=NULL)
                {
                    Deposito_getCantidad(aux,&cantidad);
                    Deposito_getDescripcion(aux,descripcion);
                    Deposito_getProducto(aux,&producto);
                    fprintf(fp,"%d,%s,%d\n",producto,descripcion,cantidad);
                    retorno = 0;
                }
            }
        }
    }
    fclose(fp);
    return retorno;
}*/

int parser_Deposito(char* fileName, ArrayList* pEntregas)
{
    Entregas* aux;
    char id[5];
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
    int cantidadLeida;
    FILE* fp;
    fp = fopen(fileName,"r");
    if(fp!=NULL)
    {
        fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,producto,direccion,localidad,recibe);
        while(!feof(fp))
        {
            cantidadLeida = fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,producto,direccion,localidad,recibe);
            if(cantidadLeida==5)
            {
                aux = Entregas_newConParametrosString(id,producto,direccion,localidad,recibe);
                if(aux!=NULL)
                    al_add(pEntregas,aux);
            }
        }
    }
    fclose(fp);

    return 1; // OK
}
