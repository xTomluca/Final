#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayList.h"
#include "parser.h"
int main()
{
    int opcion;
    char seguir = 's';
    ArrayList* pArray = al_newArrayList();
    ArrayList* pService = al_newArrayList();

    while(seguir!='n')
    {
        printf("1) Leer LOGS\n");
        printf("2) Procesar Informacion\n");
        printf("3) Mostrar estadistica\n");
        printf("4) Salir\n");
        opcion = getInt("");
        switch(opcion)
        {
            case 1:
                pArray=parser("log.txt");
                break;
            case 2:
                procesarInfo(pArray);
                break;
            case 3:
                break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
