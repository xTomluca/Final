#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayList.h"
#include "Entregas.h"



/** \brief  Parser
 * \param   char* fileName is path file
 * \param   ArrayList* listaEmpleados
 * \return  Return [1]
 */
int guardar_Deposito(ArrayList* pArray)
{
    Entregas* aux;
    int producto;
    char fileName[128];
    char descripcion[128];
    int cantidad;
    int i;
    int retorno = -1;
    int canTest = 0;
    char desTest[50];
    int proTest = 0;
    FILE* fp;
    fp = fopen("entregas.csv","w");
    if(fp!=NULL)
    {
        if(al_len(pArray)>0)
        {

            fprintf(fp,"id,producto,direccion,localidad,recibe\n");
            al_sort(pArray,,1);
            for(i=0;i<al_len(pArray);i++)
            {
                aux = al_get(pArray,i);
                if(aux!=NULL)
                {

                    fprintf(fp,"%d,%s,%d\n",producto,descripcion,cantidad);
                    retorno = 0;
                }
            }
        }
    }
    fclose(fp);
    return retorno;
}


int parser_Deposito(ArrayList* pArray)
{
    Entregas* aux;
    int cantidadLeida;
    char id[128];
    char producto[128];
    char direccion[128];
    char fileName[128];
    char localidad[128];
    char recibe[128];
    FILE* fp;
    getString("INGRESE NOMBRE DEL ARCHIVO\n\n",fileName);
    fp = fopen(fileName,"r");
    if(fp!=NULL)
    {
        fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,producto,direccion,localidad,recibe);
        while(!feof(fp))
        {
            cantidadLeida = fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,producto,direccion,localidad,recibe);
            if(cantidadLeida==5)
            {
                aux = Entregas_newConParametrosStr(id,producto,direccion,localidad,recibe);
                if(aux!=NULL)
                {
                    al_add(pArray,aux);
                }
            }
        }
    }
    fclose(fp);

    return 1; // OK
}

