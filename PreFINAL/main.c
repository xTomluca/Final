#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Parser.h"
#include "Localidades.h"
#include "Pedidos.h"
#include "Controller.h"
int main()
{
    ArrayList* pPedidos = al_newArrayList();
    ArrayList* pLocalidades = al_newArrayList();
    int opcion;
    char seguir='s';
    do
    {
        printf("1)PARSEAR PEDIDOS\n2)LISTAR PEDIDOS\n3)LISTAR LOCALIDADES\n4)GUARDAR PEDIDOS\n5)SALIR\n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
            case 1:
                parser_Deposito("DATA_FINAL_V3.csv",pPedidos);
                break;
            case 2:
                imprimirLista(pPedidos);
                break;
            case 3:
                listarLocalidades(pPedidos,pLocalidades);
                break;
            case 4:
                listarPedidos(pPedidos);
                break;
            case 5:
                seguir='n';
                break;
        }
    }while(seguir!='n');

    return 0;
}
