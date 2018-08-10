#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "ArrayList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Empleado;

Empleado* persona_new();
void persona_delete();
Empleado* persona_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo);
Empleado* persona_newConParametrosStr(/*char* sId,*/char* nombre,char* sHorasTrabajadas,char* sSueldo);
void ordenar(void* this, int tipoOrden, int ordenarPor);
int persona_setId(Empleado* this,int id);
int persona_getId(Empleado* this,int* id);

int persona_setNombre(Empleado* this,char* nombre);
int persona_getNombre(Empleado* this,char* nombre);

int persona_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int persona_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int persona_setSueldo(Empleado* this,int sueldo);
int persona_getSueldo(Empleado* this,int* sueldo);
void persona_carga(ArrayList* pArray);
void imprimirTodo(void* this,int limit);
int parser(void* pArray, char* path);
void eliminarDuplicados(ArrayList* pArray,int (*pFunc)(void*,void*));
int sort_porNombre(void* element1,void*element2);

#endif // PERSONA_H_INCLUDED
