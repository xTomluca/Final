#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Entregas.h"
#include "utn.h"
#include "Parser.h"
#include "Controller.h"


int main()
{
    int opcion;
    char seguir = 's';
    ArrayList* pEntregas = al_newArrayList();
    ArrayList* pLocalidades = al_newArrayList();

    while(seguir!='n')
    {
        printf("1) Parsear archivo\n");
        printf("2) Imprimir todo\n");
        printf("3) Imprimir localidades\n");
        printf("4) Imprimir entregas\n");
        opcion = getInt("");
        switch(opcion)
        {
            case 1:
                parser_Deposito("DATA_FINAL_V3.csv",pEntregas);
                break;
            case 2:
                al_map(pEntregas,imprimirProducto);
                break;
            case 3:
                map(pEntregas,pLocalidades,add_localidades);
                break;
            case 4:
                imprimirLocalidades(pEntregas,pLocalidades);
                break;
            case 6:
                pedirLocalidades(pEntregas);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
