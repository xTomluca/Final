#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayList.h"
#include "Deposito.h"

/***
* 1- Cargar depositos: Se deberan leer ambos archiuos y generar dos Arraylist con los datos.
* 2- Listar productos de deposito: Se le pedira al usuario el numero de deposito (1 o 2) y se imprimira la lista de productos en dicho deposito.
* 3- Mover productos a deposito: Se le pedira al usuario que ingrese el numero de deposito origen y luego el numero de deposito destino. Luego se le pedira al usuario que ingrese el
* codigo del producto a mover(debera existir en el deposito origen). Los productos deberan borrarse del deposito origen y agregarse al deposito destino.
* (Esta operacion se hace sobre la cantidad total de los productos, no puede quedar el mismo codigo de producto en ambos depositos).
* 4- Descontar productos de deposito: Se ingresara el codigo del producto, se debera detectar en que deposito se encuentra. Se le pedira al usuario que ingrese
* la cantidad de productos a descontar y dicha cantidad se restara a la cantidad actual de productos de ese tipo en el deposito correspondiente,
* si es que existe esa cantidad disponible.
* 5- Agregar productos a deposito: Se ingresara el codigo del producto, se debera detectar en que deposito se encuentra. Luego se le pedira al usuario que ingrese
* la camntidad de productos a sumar y dicha cantidad se sumara a la cantidad actual de productos de ese tipo en el deposito correspondiente.
* 6- Salir.
*
* NOTA: Cada vez que se haga una modificacion sobre un deposito, la misma se debe reflejarse en el archivo csv correspondiente a dicho deposito
* El cambio no puede realizarse solo en el ArrayList.
***/



void printfProductos(void* aux)
{
    int cantidad;
    int producto;
    char descripcion[128];
    if(aux!=NULL)
    {
        Deposito_getCantidad(aux,&cantidad);
        Deposito_getDescripcion(aux,descripcion);
        Deposito_getProducto(aux,&producto);
        printf("%d  -   %s  -   %d\n",producto,descripcion,cantidad);
    }
}

void printfDepositos(ArrayList* dep0,ArrayList* dep1)
{
    int deposito;
    printf("INGRESE NUMERO DE DEPOSITO A LISTAR <0 - 1>\n");
    scanf("%d",&deposito);
    fflush(stdin);
    if(!deposito)
        al_map(dep0,printfProductos);
    else if(deposito==1)
        al_map(dep1,printfProductos);
}

void* buscarProductoDeposito(ArrayList* dep, int producto)
{
    void* retorno= NULL;
    int i;
    int auxProducto;
    Deposito* aux = NULL;
    if(dep!=NULL)
    {
        for(i=0;i<al_len(dep);i++)
        {
            aux = al_get(dep,i);
            if(aux!=NULL)
            {
                Deposito_getProducto(aux,&auxProducto);
                if(auxProducto==producto)
                {
                    retorno = aux;
                    break;
                }
            }
        }
    }
    return retorno;
}

int deposito_sort(void* pElement1,void* pElement2)
{
    int producto0;
    int producto1;
    int retorno = -2;

    if(pElement1!=NULL && pElement2!=NULL)
    {
        Deposito* dep0 = pElement1;
        Deposito* dep1 = pElement2;
        Deposito_getProducto(dep0,&producto0);
        Deposito_getProducto(dep1,&producto1);
        if(producto0>producto1)
            retorno = 1;
        else if(producto0==producto1)
            retorno = 0;
        else if(producto0<producto1)
            retorno = -1;
    }
    return retorno;

}

int guardarArchivo(ArrayList* pArray, char* filePath)
{
    int retorno=-1;
    int i;
    int producto;
    char descripcion[50];
    int cantidad;
    Deposito* aux=NULL;
    FILE* fp;
    fp = fopen(filePath,"w");

    if(fp!=NULL && pArray!=NULL)
    {
        fprintf(fp,"producto,descripcion,cantidad\n");
        if(!al_sort(pArray,deposito_sort,1))
        {
            for(i=0;i<al_len(pArray);i++)
            {
                aux=al_get(pArray,i);
                if(aux!=NULL)
                {
                    Deposito_getCantidad(aux,&cantidad);
                    Deposito_getDescripcion(aux,descripcion);
                    Deposito_getProducto(aux,&producto);
                    fprintf(fp,"%d,%s,%d\n",producto,descripcion,cantidad);
                    retorno = 0;
                }
            }
        }
    }
    fclose(fp);
    return retorno;
}



int Deposito_mover(ArrayList* dep0,ArrayList* dep1)
{
    int retorno= -1;
    int origen=-1;
    int index=-1;
    int producto=-1;
    int destino=-1;
    Deposito* aux = NULL;
    origen = getInt("INGRESE ORIGEN : <0-1>");
    destino = getInt("INGRESE DESTINO : <0-1>");

    if(origen==destino)
        printf("ERROR!! ORIGEN = DESTINO!\n");
    else if(!origen && destino == 1)
    {
        producto = getInt("INGRESE PRODUCTO: ");
        aux = buscarProductoDeposito(dep0,producto);
        if(aux!=NULL)
        {
            index = al_indexOf(dep0,aux);
            al_remove(dep0,index);
            if(!al_add(dep1,aux) && !guardarArchivo(dep0,"dep0.csv") && !guardarArchivo(dep1,"dep1.csv"))
                retorno = 0;
        }
        else
            printf("\nNO SE ENCONTRO PRODUCTO\n");
    }
    else if(origen==1 && !destino)
    {
        producto = getInt("INGRESE PRODUCTO: ");
        aux = buscarProductoDeposito(dep1,producto);
        if(aux!=NULL)
        {
            index = al_indexOf(dep1,aux);
            al_remove(dep1,index);
            if(!al_add(dep0,aux) && !guardarArchivo(dep0,"dep0.csv") && !guardarArchivo(dep1,"dep1.csv"))
                retorno = 0;

        }
        else
            printf("\nNO SE ENCONTRO PRODUCTO\n");
    }

    return retorno;
}

int parser(ArrayList* pArray, char* filePath)
{
    int retorno=-1;
    char producto[50];
    char descripcion[50];
    char cantidad[50];
    int cantidadLeida=0;
    Deposito* aux=NULL;
    FILE* fp;
    fp = fopen(filePath,"r");

    if(fp!=NULL && pArray!=NULL)
    {
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",producto,descripcion,cantidad);
        while(!feof(fp))
        {
            cantidadLeida = fscanf(fp,"%[^,],%[^,],%[^\n]\n",producto,descripcion,cantidad);
            if(cantidadLeida==3)
            {
                aux = Deposito_newConParametrosStr(producto,descripcion,cantidad);
                if(aux!=NULL)
                {
                    al_add(pArray,aux);
                    retorno = 0;
                }
            }
        }
    }
    fclose(fp);
    return retorno;
}

int descontarStock(ArrayList* dep0,ArrayList* dep1)
{
    int retorno=-1;
    int index;
    int producto;
    int cantidadADescontar=0;
    int cantidadActual=0;
    Deposito* aux0=NULL;
    Deposito* aux1=NULL;
    if(dep0!=NULL && dep1!=NULL)
    {
        producto=getInt("INGRESE N PRODUCTO A DESCONTAR STOCK: \n");
        aux0 = buscarProductoDeposito(dep0,producto);
        aux1 = buscarProductoDeposito(dep0,producto);
        if(aux0!=NULL)
        {
            cantidadADescontar = getInt("INGRESE CANTIDAD A DESCONTAR\n");
            Deposito_getCantidad(aux0,&cantidadActual);
            if(cantidadActual==cantidadADescontar)
            {
                index = al_indexOf(dep0,aux0);
                al_remove(dep0,index);
                if(!guardarArchivo(dep0,"dep0.csv"))
                    retorno = 0;
            }
            else if(cantidadActual>cantidadADescontar)
            {
                cantidadActual = cantidadActual-cantidadADescontar;
                Deposito_setCantidad(aux0,cantidadActual);
                if(!guardarArchivo(dep0,"dep0.csv"))
                    retorno = 0;
            }
            else if(cantidadActual<cantidadADescontar)
                printf("\nERROR! STOCK ACTUAL : %d - CANTIDAD A DESCONTAR : %d\n",cantidadActual,cantidadADescontar);
            else
                printf("\nERROR!\n");
        }
        else if(aux1!=NULL)
        {
            cantidadADescontar = getInt("INGRESE CANTIDAD A DESCONTAR\n");
            Deposito_getCantidad(aux1,&cantidadActual);
            if(cantidadActual==cantidadADescontar)
            {
                index = al_indexOf(dep1,aux1);
                al_remove(dep1,index);
                if(!guardarArchivo(dep1,"dep1.csv"))
                    retorno = 0;
            }
            else if(cantidadActual>cantidadADescontar)
            {
                cantidadActual = cantidadActual-cantidadADescontar;
                Deposito_setCantidad(aux1,cantidadActual);
                if(!guardarArchivo(dep1,"dep1.csv"))
                    retorno = 0;
            }
            else if(cantidadActual<cantidadADescontar)
                printf("\nERROR! STOCK ACTUAL : %d - CANTIDAD A DESCONTAR : %d\n",cantidadActual,cantidadADescontar);
            else
                printf("\nERROR!\n");
        }
        else
            printf("NO SE ENCONTRO EL PRODUCTO\n");
    }
    return retorno;
}

int agregarStock(ArrayList* dep0,ArrayList* dep1)
{
    int retorno=-1;
    int producto;
    int cantidadAgregar=0;
    int cantidadActual=0;
    Deposito* aux0=NULL;
    Deposito* aux1=NULL;
    if(dep0!=NULL && dep1!=NULL)
    {
        producto=getInt("INGRESE N PRODUCTO A DESCONTAR STOCK: \n");
        aux0 = buscarProductoDeposito(dep0,producto);
        aux1 = buscarProductoDeposito(dep0,producto);
        if(aux0!=NULL)
        {
            cantidadAgregar = getInt("INGRESE CANTIDAD A DESCONTAR\n");
            Deposito_getCantidad(aux0,&cantidadActual);
            if(cantidadAgregar>0)
            {
                cantidadActual = cantidadActual+cantidadAgregar;
                Deposito_setCantidad(aux0,cantidadActual);
                if(!guardarArchivo(dep0,"dep0.csv"))
                    retorno = 0;
            }
            else
                printf("\nERROR!\n");
        }
        else if(aux1!=NULL)
        {
            cantidadAgregar = getInt("INGRESE CANTIDAD A DESCONTAR\n");
            Deposito_getCantidad(aux1,&cantidadActual);
            if(cantidadAgregar>0)
            {
                cantidadActual = cantidadActual+cantidadAgregar;
                Deposito_setCantidad(aux1,cantidadActual);
                if(!guardarArchivo(dep1,"dep1.csv"))
                    retorno = 0;
            }
            else
                printf("\nERROR!\n");
        }
        else
            printf("NO SE ENCONTRO EL PRODUCTO\n");
    }
    return retorno;
}

int main()
{
    ArrayList* deposito0 = al_newArrayList();
    ArrayList* deposito1 = al_newArrayList();
    int opcion;
    char seguir='s';
    if(!parser(deposito0,"dep0.csv") && !parser(deposito1,"dep1.csv"))
    {
        do
        {
            printf("1)CARGAR DEPOSITO\n2)LISTAR PRODUCTOS\n3)MOVER PRODUCTO\n4)DESCONTAR STOCK\n5)SUMAR STOCK\n6)SALIR\n");
            scanf("%d",&opcion);
            fflush(stdin);
            switch(opcion)
            {
                case 1:
                    break;
                case 2:
                    printfDepositos(deposito0,deposito1);
                    break;
                case 3:
                    if(!Deposito_mover(deposito0,deposito1))
                        printf("\nEXITO!\n\n");
                    break;
                case 4:
                   if(!descontarStock(deposito0,deposito1))
                        printf("\nEXITO!\n\n");
                    break;
                case 5:
                    if(!agregarStock(deposito0,deposito1))
                        printf("\nEXITO!\n\n");
                    break;
                case 6:
                    seguir='n';
                    break;
            }
        }while(seguir!='n');
    }
    else
    {
        printf("ERROR!");
    }
    return 0;
}
