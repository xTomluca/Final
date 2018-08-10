#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "parser.h"
int parser(void* pArray, char* path)
{
    FILE* fp;
    fp = fopen(path,"r");
    int retorno = -1;
    int cantidad = 0;
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            char bName[50];
            char bHoras[10];
            char bSueldo[10];
            Empleado* aux;
            cantidad = fscanf(fp,"%[^,],%[^,],%[^\n]\n",bName,bHoras,bSueldo);
            if(cantidad==3)
            {
                aux = persona_newConParametrosStr(bName,bHoras,bSueldo);
                if(aux==NULL)
                    exit(1);
                al_add(pArray,aux);
                retorno = 0;
            }
        }
        fclose(fp);
    }
    return retorno;
}


