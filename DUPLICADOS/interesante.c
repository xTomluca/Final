#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interesante.h"

Empleado* persona_newConParametrosStr(/*char* sId,*/char* nombre,char* sHorasTrabajadas,char* sSueldo)
{
    Empleado* this;
    this=persona_new();
    //int id = atoi(sId);
    int horasTrabajadas = atoi(sHorasTrabajadas);
    int sueldo = atoi(sSueldo);

    if(
    //!persona_setId(this,id)&&
    !persona_setNombre(this,nombre)&&
    !persona_setHorasTrabajadas(this,horasTrabajadas)&&
    !persona_setSueldo(this,sueldo))
        return this;

    persona_delete(this);
    return NULL;
}


void persona_carga(ArrayList* pArray)
{
    static int id=0;
    Empleado* this;
    char name[50];
    int horasTrabajadas;
    int sueldo;
    if(!getArrayTexto(name,"\nINGRESE NOMBRE: ","\nERROR\n\n",50,2))
    {
        if(!getNumeroInt(200,0,&horasTrabajadas,2,5,"\nINGRESE HORAS TRABAJADAS: ","\nERROR\n\n"))
        {
            sueldo = horasTrabajadas * 200;
            id++;
            printf("\nINGRESO A CARGA PERSONA \n");
            this = persona_newConParametros(id,name,horasTrabajadas,sueldo);
            al_add(pArray,this);
        }
    }

}

void imprimirTodo(void* this,int limit)
{
    int i;
    //int id;
    int hs;
    int sueldo;
    char name[50];
    Empleado* aux;
    if(this!=NULL && limit >0)
    {
        for(i=0;i<limit;i++)
        {
            aux = al_get(this,i);
           //persona_getId(aux,&id);
            persona_getHorasTrabajadas(aux,&hs);
            persona_getNombre(aux,name);
            persona_getSueldo(aux,&sueldo);
            printf("\nNombre: %s\nHoras trabajadas:%d\nSueldo:%d\n",name,hs,sueldo);

        }
    }
    else
    {
        printf("\nERROR A LA HORA DE IMPRIMIR\n\n");
    }

}

int sort_porInt(void* element1,void*element2)
{
    if(element1!=NULL&&element2!=NULL)
    {
        int sueldo1;
        int sueldo2;
        Empleado* num1 = element1;
        Empleado* num2 = element2;
        if(!persona_getSueldo(num1,&sueldo1))
            if(!persona_getSueldo(num2,&sueldo2))
            {
                if(sueldo1 > sueldo2)
                    return 1;
                if(sueldo1==sueldo2)
                    return 0;
                if(sueldo1 < sueldo2)
                    return -1;
            }
    }
    return -2;
}

int sort_porNombre(void* element1,void*element2)
{
    if(element1!=NULL&&element2!=NULL)
    {
        Empleado* str1=element1;
        Empleado* str2=element2;
        char name1[128];
        char name2[128];
        persona_getNombre(str1,name1);
        persona_getNombre(str2,name2);
        if(strcmp(name1,name2)>0)
            return 1;
        if(!strcmp(name1,name2))
            return 0;
        if(strcmp(name1,name2)<0)
            return -1;
    }
    return -2;
}

/** \brief ORDENAR ARRAYLIST
 *
 * \param this void* Puntero a arrayList
 * \param tipoOrden int [0] MAYOR A MENOR [1] MENOR A MAYOR
 * \param ordenarPor int [0] ORDENAR POR NOMBRE [1] POR SALARIO
 * \return void
 *
 */
void ordenar(void* this, int tipoOrden, int ordenarPor)
{
    int option, order;
    int (*funcionSalario)(void*,void*) = &sort_porInt;
    int (*funcionNombre)(void*,void*) = &sort_porNombre;
    if(this!=NULL)
        if(!tipoOrden || tipoOrden == 1 || !getNumeroInt(1,0,&order,2,3,"\n0)MAYOR A MENOR\n1)MENOR A MAYOR\n","\nRESPUESTA ERRONEA"));
        {
            if(!tipoOrden || tipoOrden == 1){order=tipoOrden;}
            if(!ordenarPor || ordenarPor == 1 || !getNumeroInt(1,0,&option,2,3,"\n0)ORDENAR POR NOMBRE\n1)ORDENAR POR SALARIO\n","\nRESPUESTA ERRONEA"))
            {
                if(!ordenarPor || ordenarPor == 1){option=ordenarPor;}
                if(!option)
                    al_sort(this,funcionNombre,order);
                else if(option==1)
                    al_sort(this,funcionSalario,order);
            }
        }
}



/*void em_calcularSueldo(void* p)
{
    int horasTrabajadas,horasPromedio;
    if(p!=NULL)
    {
        Empleado_getHorasTrabajadas(p,&horasTrabajadas);
        if(horasTrabajadas>=120)
        {
            horasPromedio  = 120 * 180;
            if(horasTrabajadas>=160)
            {
                horasPromedio = horasPromedio + 40*240 +(horasTrabajadas-160)*350;
            }
            else
            {
                horasPromedio = horasPromedio + (horasTrabajadas-120)*240;
            }
        }
        else
        {
            horasPromedio = horasTrabajadas*180;
        }
        Empleado_setSueldo(p,horasPromedio);
    }
}*/


void eliminarDuplicados(ArrayList* pArray)
{
    ArrayList* clone = al_newArrayList();
    ArrayList* blackList = al_newArrayList();
    char nombreAux[50];
    char nombreAux2[50];
    Empleado* pElement=NULL;
    Empleado* pElement2=NULL;
    int i,j,index;
    if(pArray!=NULL && al_len(pArray)>0)
    {
        if(!parser(blackList,"listaBlack.txt"))
        {
            if(blackList!=NULL)
            {
                ordenar(blackList,1,0);
                ordenar(pArray,1,0);
                clone = al_clone(pArray);
                if(clone != NULL)
                {
                    ordenar(clone,1,0);
                    for(i=0;i<al_len(blackList);i++)
                    {
                        pElement = al_get(blackList,i);
                        persona_getNombre(pElement,nombreAux);
                        for(j=1;j<al_len(clone);j++)
                        {
                            pElement2 = al_get(clone,j);
                            persona_getNombre(pElement2,nombreAux2);
                            if(strcmp(nombreAux,nombreAux2)==0)
                            {
                                index = al_indexOf(clone,pElement);
                                al_remove(pArray,index);
                            }
                        }
                    }
                    al_deleteArrayList(clone);
                }
            }
        }
    }
}
