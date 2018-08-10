#ifndef LOCALIDADES_H_INCLUDED
#define LOCALIDADES_H_INCLUDED
typedef struct
{
    char producto[128];
}Localidades;

Localidades* Localidades_new();
void Localidades_delete();
Localidades* Localidades_newConParametros(char* producto);

int Localidades_setProducto(Localidades* this,char* producto);
int Localidades_getProducto(Localidades* this,char* producto);

#endif // LOCALIDADES_H_INCLUDED
