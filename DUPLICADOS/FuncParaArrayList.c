/** \brief ELIMINA ARCHIVOS DUPLICADOS
 *
 * \param void* Puntero a Elemento
 * \param void* Puntero a ArrayList
 * \return int [0] = OK
 *             [-1] = ERROR!
 *
 */
int eliminarDuplicados(ArrayList* pArray,int (*pFunc)(void*,void*))
{
    ArrayList* blackList = al_newArrayList();
    char nombreAux[50];
    Empleado* pElement=NULL;
    int i,index=0,retorno = -1;
    if(pArray!=NULL&& pFunc!=NULL && al_len(pArray)>0)
        if(!parser(blackList,"listaBlack.txt"))
        {
            if(blackList!=NULL)
            {
                ordenar(blackList,1,0);
                ordenar(pArray,1,0);
                while(index!=-1)
                {
                    for(i=0;i<al_len(blackList);i++)
                    {
                        pElement = al_get(blackList,i);
                        persona_getNombre(pElement,nombreAux);
                        index = pFunc(nombreAux,pArray);
                        if(index!=-1)
                        {
                            al_remove(pArray,index);
                            retorno = 0;
                        }
                    }
                }
            }
        }
}


/** \brief COMPARA CHAR
 *
 * \param nombre void* Elemento a comparar
 * \param pArray void* Puntero a Array
 * \return int index != -1 OK!
 *
 */
int compararMail(void* nombre, void* pArray)
{
    int i,index =-1;
    Empleado* aux=NULL;
    char nombre2[50];
    for(i=0;i<al_len(pArray);i++)
    {
        aux = al_get(pArray,i);
        persona_getNombre(aux,nombre2);
        if(strcmp(nombre,nombre2)==0)
        {
            index = i;
            break;
        }
    }

    return index;
}

/** \brief ORDENAR POR INT
 *
 * \param void* element1 PUNTERO A ELEMENTO 1
 * \param void* element2 PUNTERO A ELEMENTO 2
 * \return int [1] element1 > element2
 *             [0] element1 = element2
 *             [-1] element1 < element2
 *             [-2] ERROR!
 *
 */
int sort_porInt(void* element1,void*element2)
{
    if(element1!=NULL&&element2!=NULL)
    {
        int sueldo1;
        int sueldo2;
        Empleado* num1 = element1;
        Empleado* num2 = element2;
        if(!persona_getSueldo(num1,&sueldo1))
            if(!persona_getSueldo(num2,&sueldo2))
            {
                if(sueldo1 > sueldo2)
                    return 1;
                if(sueldo1==sueldo2)
                    return 0;
                if(sueldo1 < sueldo2)
                    return -1;
            }
    }
    return -2;
}

/** \brief ORDENAR POR ORDEN ALFABETICO
 *
 * \param void* element1 PUNTERO A ELEMENTO 1
 * \param void* element2 PUNTERO A ELEMENTO 2
 * \return int [1] element1 > element2
 *             [0] element1 = element2
 *             [-1] element1 < element2
 *             [-2] ERROR!
 *
 */
int sort_porNombre(void* element1,void*element2)
{
    if(element1!=NULL&&element2!=NULL)
    {
        Empleado* str1=element1;
        Empleado* str2=element2;
        char name1[128];
        char name2[128];
        persona_getNombre(str1,name1);
        persona_getNombre(str2,name2);
        if(strcmp(name1,name2)>0)
            return 1;
        if(!strcmp(name1,name2))
            return 0;
        if(strcmp(name1,name2)<0)
            return -1;
    }
    return -2;
}

/** \brief ORDENAR ARRAYLIST
 *
 * \param this void* Puntero a arrayList
 * \param tipoOrden int [0] MAYOR A MENOR [1] MENOR A MAYOR
 * \param ordenarPor int [0] ORDENAR POR NOMBRE [1] POR SALARIO
 * \return void
 *
 */
void ordenar(void* this, int tipoOrden, int ordenarPor)
{
    int option, order;
    if(this!=NULL)
    {
        if(!tipoOrden || tipoOrden == 1 || !getNumeroInt(1,0,&order,2,3,"\n0)MAYOR A MENOR\n1)MENOR A MAYOR\n","\nRESPUESTA ERRONEA"));
        {
            if(!tipoOrden || tipoOrden == 1){order=tipoOrden;}
            if(!ordenarPor || ordenarPor == 1 || !getNumeroInt(1,0,&option,2,3,"\n0)ORDENAR POR NOMBRE\n1)ORDENAR POR SALARIO\n","\nRESPUESTA ERRONEA"))
            {
                if(!ordenarPor || ordenarPor == 1){option=ordenarPor;}
                if(!option)
                    al_sort(this,sort_porNombre,order);
                else if(option==1)
                    al_sort(this,sort_porInt,order);
            }
        }
    }
}

/** \brief IMPRIMIR TODO
 *
 * \param this void* Puntero ARRAYLIST
 * \param limit int Limite ARRAYLIST
 * \return void
 *
 */
void imprimirTodo(void* this,int limit)
{
    int i;
    int hs;
    int sueldo;
    char name[50];
    Empleado* aux;
    if(this!=NULL && limit >0)
    {
        for(i=0;i<limit;i++)
        {
            aux = al_get(this,i);
            persona_getHorasTrabajadas(aux,&hs);
            persona_getNombre(aux,name);
            persona_getSueldo(aux,&sueldo);
            printf("\nNombre: %s\nHoras trabajadas:%d\nSueldo:%d\n",name,hs,sueldo);

        }
    }
    else
        printf("\nERROR A LA HORA DE IMPRIMIR\n\n");
}

/**Los valores de horas varian entre 80 y 240.
- Las primeras 120 horas la hora vale $180
- De 120 a 160 horas, la hora vale $240
- De 160 a 240 horas, la hora vale $350 */

void em_calcularSueldo(void* p)
{
    int horasTrabajadas,horasPromedio;
    if(p!=NULL)
    {
        Empleado_getHorasTrabajadas(p,&horasTrabajadas);
        if(horasTrabajadas>=120)
        {
            horasPromedio  = 120 * 180;
            if(horasTrabajadas>=160)
            {
                horasPromedio = horasPromedio + 40*240 +(horasTrabajadas-160)*350;
            }
            else
            {
                horasPromedio = horasPromedio + (horasTrabajadas-120)*240;
            }
        }
        else
        {
            horasPromedio = horasTrabajadas*180;
        }
        Empleado_setSueldo(p,horasPromedio);
    }
}


/** \brief FILTRA EMPLEADOS +120HS
 *
 * \param item void* PUNTERO A ELEMENTO ARRAYLIST
 * \return int [1] = ADD, [0] = NO ADD
 *
 */
 ///al_filter(listaEmpleados,em_trabajaMasDe120Horas); IMPLEMENTACION (DEVUELVE NUEVO ARRAYLIST FILTRADO.

int em_trabajaMasDe120Horas(void* item)
{

    int horasTrabajadas,retorno=0;
    if(item!=NULL)
    {
        Empleado_getHorasTrabajadas(item,&horasTrabajadas);
        if(horasTrabajadas>=120)
        {
            retorno = 1;
        }
    }
    return retorno;
}
