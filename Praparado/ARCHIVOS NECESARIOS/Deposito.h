#ifndef DEPOSITO_H_INCLUDED
#define DEPOSITO_H_INCLUDED
typedef struct
{
    int producto;
    char descripcion[128];
    int cantidad;
}Deposito;