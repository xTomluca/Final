#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED
typedef struct
{
    int id;
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
}Entregas;

Entregas* Entregas_new();
void Entregas_delete();
Entregas* Entregas_newConParametros(int id,char* producto,char* direccion,char* localidad,char* recibe);
Entregas* Entregas_newConParametrosStr(char* idStr,char* producto,char* direccion,char* localidad,char* recibe);
int Entregas_setId(Entregas* this,int id);
int Entregas_getId(Entregas* this,int* id);

int Entregas_setProducto(Entregas* this,char* producto);
int Entregas_getProducto(Entregas* this,char* producto);

int Entregas_setDireccion(Entregas* this,char* direccion);
int Entregas_getDireccion(Entregas* this,char* direccion);

int Entregas_setLocalidad(Entregas* this,char* localidad);
int Entregas_getLocalidad(Entregas* this,char* localidad);

int Entregas_setRecibe(Entregas* this,char* recibe);
int Entregas_getRecibe(Entregas* this,char* recibe);

#endif // ENTREGAS_H_INCLUDED
