#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int pares(int num)
{
    int i;

    for(i=0;i<=num;i++)
    {
        if(!(num%i))
            continue;
        else
            printf("%d",i);
    }
    return i;
}*/

int main()
{
/*typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


typedef struct
{
    int legajo;
    char* nombre;
    char* apellido;
    char sexo;
    eFecha fechaIngreso;
}eEmpleado;
eEmpleado* plantel[10];
eEmpleado aux;
Complete el siguiente algoritmo de ordenamiento para ordenar por sexo ascendente y si son del mismo sexo por
apellido descendente al vector de empleados llamado plantel de tamaño 10. (1.5 ptos)
for( i =0; i < 10 ; i++){
for( j =i; j<10-1; j++){
if(){ ________________________
________________________
________________________
 }
else{
 if( ){
if( ){ ________________________
________________________
________________________
}
 }
 }
}*/
/*strcmpi( )
char *cadena;
cadena = malloc(sizeof(char));
strcpy(cadena,"Programacion I22222222222222222200'''2¿");
printf("%s",cadena);*/
/*    int i=1;
    for(i=0;i<=100;i+=2)
        printf("%d\n",i+1);*/
/*   while(i<100){

        printf("%d\n",i);
        i+=2;

    }*/
    /*
    char cad1[50]="HOLA-PEPE-JOSE";
    char cad2[50]="-";
    char* ptr = strtok(cad1,cad2);
printf("%s",ptr);
    while((ptr = strtok( NULL, cad2 )) != NULL ){printf("%s",ptr);}
*/
    /*
    pares(numero);
*/
 int x, y; x=11; y=13;
muestra(&x, &y);
printf("\n-----valores dentro de main----");
printf("\nx vale %d \ny vale %d", x, y);
return 0;

}


void muestra(int *x, int *y)
{
 *x = *y;
 printf("\n-----valores dentro de la función muestra----");
 printf("\nx vale %d \ny vale %d", *x, *y);
 }
