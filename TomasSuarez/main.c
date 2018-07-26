#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Entregas.h"
#include "utn.h"
#include "Parser.h"
#include "view.h"
#include "Controller.h"

int main()
{
    ArrayList* pEntregas = al_newArrayList();
    ArrayList* pLocalidades = al_newArrayList();
    int opcion=0;
    char seguir = 's';
    do
    {
        printf("MENU DE OPCIONES: \n");
        printf("1) PARSER \n");
        printf("2) LISTAR PRODUCTO \n");
        printf("3) LISTAR LOCALIDADES \n");
        printf("4) LISTAR LOCALIDADES \n");
        printf("5) SALIR \n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
            case 1:
                parser_Deposito(pEntregas);
                break;
            case 2:
                printf_Productos(pEntregas);
                break;
            case 3:

                printf_Localidades(pLocalidades,pEntregas);
                break;

                Localidades_add(pEntregas,pLocalidades);
                al_sort(pLocalidades,localidades_sort,0);
                al_map(pLocalidades,printf_ImprimirLocalidad);
                break;

                //if(!Deposito_migrar(dep0,dep1))
                  //  printf_OperacionExitosa();
                //else
                  //  printf_OperacionErronea();
                //break;
            case 4:
                //if(!Deposito_DescontarStock(dep0,dep1))
                  //  printf_OperacionExitosa();
                //else
                  //  printf_OperacionErronea();
                //break;
            case 5:

                //if(!Deposito_AgregarStock(dep0,dep1))
                  //  printf_OperacionExitosa();
                //else
                 //   printf_OperacionErronea();
                //break;
            case 6:
                seguir = 'n';
                break;

        }
    }
    while(seguir!='n');

    return 0;
}
