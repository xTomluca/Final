#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "utn.h"
#include "LogEntry.h"
void* parser(char* filePath)
{
    char date[11];
    char time[6];
    char serviceIdStr[4];
    char gravedadStr[4];
    char msg[65];
    int cantidadLeida;
    ArrayList* pArray = al_newArrayList();
    LogEntry* aux;
    FILE* fp;
    fp = fopen(filePath,"r");
    if(pArray!=NULL && fp!=NULL)
    {
        do
        {
            cantidadLeida = fscanf(fp,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",date,time,serviceIdStr,gravedadStr,msg);
            if(cantidadLeida==5)
            {
                aux = LogEntry_newConParametrosStr(date,time,serviceIdStr,gravedadStr,msg);
                if(aux!=NULL)
                    al_add(pArray,aux);
            }

        }while(!feof(fp));
        fclose(fp);
    }
    return pArray;
}

int checkGravedad(void* pElement)
{
    int gravedad;
    int retorno = 0;
    if(pElement!=NULL)
    {
        LogEntry_getGravedad(pElement,&gravedad);
        if(gravedad==3)
            retorno = 1;
        else if(gravedad>=4 && gravedad<=7)
            retorno = 2;
        else if(gravedad>7)
            retorno = 3;
    }
    return retorno;
}
void procesarInfo(ArrayList* pArray)
{
    ArrayList* newFile = al_newArrayList();
    LogEntry* aux;
    int gravedad=0;
    int i;
    int cantegoriaGravedad;
    if(pArray!=NULL)
    {
        for(i=0;i<al_len(pArray);i++)
        {
            aux = al_get(pArray,i);
            if(aux!=NULL)
                cantegoriaGravedad = checkGravedad(aux);
                if(cantegoriaGravedad==1)
                {

                }
                else if(cantegoriaGravedad==2)
                {
                    LogEntry_getGravedad(aux,&gravedad);
                    al_add(newFile,aux);
                    printf("\nLA GRAVERDAD ES: %d\n",gravedad);
                }
                else if(cantegoriaGravedad==3)
                {

                }
        }
        if(al_len(newFile)>0);
            ///***Grabo nuevo archivo

    }

}
