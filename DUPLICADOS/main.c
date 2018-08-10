#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "valid.h"
#include "persona.h"
#include "ArrayList.h"
int compararMail(void* nombre, void* pArray);
void getreservedSize(ArrayList* pArray){
    int reserved=0;
    int size=0;
    if(pArray!=NULL)
    {
        size = pArray->size;
        reserved = pArray->reservedSize;
        printf("EL RESERVED ES: %d Y EL SIZE: %d",reserved, size);
    }
}
int main()
{
    ArrayList* pArray= al_newArrayList();
    char seguir = 's';
    int opcion;
    parser(pArray,"lista.txt");
    while(seguir=='s')
    {
            printf("OPCIONES DE CARGA:\n1)ORDENAR POR NOMBRE\n2)PARSEAR ARCHIVO\n3)MOSTRAR ORDENADO\n4)ELIMINAR BLACKLIST!\n4)VERIFICAR SIZE!\n\n");
            getNumeroInt(7,1,&opcion,0,3,"","");
            switch(opcion){
                case 1:
                    ordenar(pArray,2,2);
                    break;
                case 2:
                    break;
                case 3:
                    imprimirTodo(pArray,al_len(pArray));
                    break;
                case 4:
                    eliminarDuplicados(pArray,compararMail);
                    break;
                case 5:
                    getreservedSize(pArray);
                    break;
                case 6:
                    break;
                case 7:
                    seguir = 'n';
                    break;
            }
    }
    return 0;
}

int compararMail(void* nombre, void* pArray)
{
    int i,index =-1;
    Empleado* aux=NULL;
    char nombre2[50];
    for(i=0;i<al_len(pArray);i++)
    {
        aux = al_get(pArray,i);
        persona_getNombre(aux,nombre2);
        if(strcmp(nombre,nombre2)==0)
        {
            index = i;
            break;
        }
    }

    return index;
}
