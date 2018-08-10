#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** \brief Verifica que el array de char contenga solo NUMEROS.
 *
 * \param auxCarga char* Array de char a validar.
 * \param mensajeError char* Mensaje de error a mostrar si se ingresa alguna LETRA.
 * \param tamanioVector int tamaño del array/vector.
 * \return int retorno [0] si no contiene LETRAS. [1] = ERROR.
 *
 */
int verificacionDigito(char *auxCarga, char *mensajeError, int tamanioVector,int intentos)
{
    int i=0;
    int j=strlen(auxCarga);
    int retorno =1;
    while(i<j)
    {
        if((auxCarga[0]== '-') ||(auxCarga[1]== '.')|| isdigit(auxCarga[i])!=0)
        {
            i++;
            retorno =0;
        }
        else
        {
            if(!intentos)
                return 1;
            printf("%s",mensajeError);
            fflush(stdin);
            fgets(auxCarga, tamanioVector, stdin);
            auxCarga[strlen(auxCarga) - 1] = '\0';
            j=strlen(auxCarga);
            i=0;
            retorno =1;
            intentos-=1;

        }
    }
    return retorno;
}

/** \brief Verifica que el array de char contenga solo LETRAS.
 *
 * \param auxCarga char* Array de char a validar.
 * \param mensajeError char* Mensaje de error a mostrar si se ingresa algun NUMERO.
 * \param tamanioVector int tamaño del array/vector.
 * \return int retorno [0] si no contiene NUMEROS. [1] = ERROR.
 *
 */

int verificacionChar(char *auxCarga, char *mensajeError, int tamanioVector,int intentos)
{
    int i=0;
    int j=strlen(auxCarga);
    int retorno =1;
    while(i<j)
    {
        if(!isdigit(auxCarga[i]))
        {
            i++;
            retorno =0;
        }
        else
        {
            if(!intentos)
                return 1;
            printf("%s", mensajeError);
            fflush(stdin);
            fgets(auxCarga, tamanioVector, stdin);
            auxCarga[strlen(auxCarga) - 1] = '\0';
            j=strlen(auxCarga);
            i=0;
            retorno =1;
            intentos-=1;
        }
    }
    return retorno;
}

/** \brief Valida NOMBRE.
 *
 * \param nombre char* Mediante puntero paso array de char.
 * \return int retorno [0] si se cargo el NOMBRE con exito. [1] = ERROR.
 *
 */

int getArrayTexto(char* texto,char* textoInstruccion,char* textoError, int limite, int intentos)
{
    int retorno=1;
    char auxTexto[limite];
    printf("%s",textoInstruccion);
    fflush(stdin);
    fgets(auxTexto, limite, stdin);
    auxTexto[strlen(auxTexto) - 1] = '\0';
    if(!verificacionChar(auxTexto,textoError,limite,intentos))
    {
        strcpy(texto, auxTexto);
        retorno=0;
    }
    else
    {
        printf("\nERROR!\n\n");
    }
    return retorno;
}

/** \brief Valida NOMBRE.
 *
 * \param nombre char* Mediante puntero paso array de char.
 * \return int retorno [0] si se cargo el NOMBRE con exito. [1] = ERROR.
 *
 */

int getCadenaAZ(char* texto,char* textoInstruccion,char* textoError, int limite, int intentos)
{
    int i,retorno;
    char auxTexto[limite];
    do
    {
        printf("%s",textoInstruccion);
        fflush(stdin);
        fgets(auxTexto, limite, stdin);
        auxTexto[strlen(auxTexto) - 1] = '\0';
        for(i=0;i<strlen(auxTexto);i++)
        {
            if(((auxTexto[i]>='a') && (auxTexto[i]<='z')) || ((auxTexto[i]>='A') && (auxTexto[i]<='Z')))
            {
                retorno = 0;
            }
            else
            {
                printf("\n%s\n\n",textoError);
                retorno = 1;
                intentos--;
                break;
            }
        }
    }while(retorno == 1 &&intentos!=0);
    if(!retorno)
    {
        strcpy(texto, auxTexto);
    }



    return retorno;
}
/** \brief Valida ALFANUMERICO.
 *
 * \param texto char* Mediante puntero paso array de char.
 * \return int retorno [0] si se cargo el TEXTO con exito. [1] = ERROR.
 *
 */

int getAlfaNumerico(char* texto,char* textoInstruccion,char* textoError, int limite, int intentos)
{
    int i,retorno;
    char auxTexto[limite];
    do
    {
        printf("%s",textoInstruccion);
        fflush(stdin);
        fgets(auxTexto, limite, stdin);
        auxTexto[strlen(auxTexto) - 1] = '\0';
        for(i=0;i<strlen(auxTexto);i++)
        {
            if(((auxTexto[i]>='a') && (auxTexto[i]<='z')) || ((auxTexto[i]>='A') && (auxTexto[i]<='Z'))|| ((auxTexto[i]>='0') && (auxTexto[i]<='9')))
            {
                retorno = 0;
            }
            else
            {
                printf("\n%s\n\n",textoError);
                retorno = 1;
                intentos--;
                break;
            }
        }
    }while(retorno == 1 &&intentos!=0);
    if(!retorno)
    {
        strcpy(texto, auxTexto);
    }
    return retorno;
}

/** \brief Valida NUMERICO INT.
 *
 * \param num int* Mediante puntero paso INT.
 * \param modo int* [0] = MAXIMO MINIMO ACTIVADO [1] = SIN IMPORTAR MAX/MIN.
 * \return int retorno [0] si se cargo el NUM con exito. [1] = ERROR.
 *
 */


int getNumericoInt(int* num,int minNum,int maxNum,char* textoInstruccion,char* textoError, int limite, int intentos,int modo)
{
    int auxNum,i,verificacion,retorno=1;
    char auxTexto[limite];
    do
    {
        printf("%s",textoInstruccion);
        fflush(stdin);
        fgets(auxTexto, limite, stdin);
        auxTexto[strlen(auxTexto) - 1] = '\0';
        if(strlen(auxTexto)>0)
        {
            for(i=0;i<strlen(auxTexto);i++)
            {
                if(((auxTexto[i]>='0') && (auxTexto[i]<='9')) || (auxTexto[i]=='.'))
                {
                    verificacion = 0;
                }
                else
                {
                    printf("\n%s\n\n",textoError);
                    verificacion = 1;
                    intentos--;
                    break;
                }
            }
        }
        else
        {
            printf("\n%s\n\n",textoError);
            verificacion = 1;
            intentos--;
        }
    }while(verificacion == 1 &&intentos!=0);
    if(!verificacion)
    {
        auxNum = atoi(auxTexto);
        if(((auxNum >= minNum && auxNum <= maxNum) && !modo) || (modo==1))
        {
            *num = auxNum;
            printf("\nENTRO IGUAL MODO = %d\n\n",modo);
            retorno=0;
        }
    }

    return retorno;

}

/** \brief Valida NUMERICO FLOAT.
 *
 * \param num float* Mediante puntero paso FLOAT.
 * \param modo int* [0] = MAXIMO MINIMO ACTIVADO [1] = SIN IMPORTAR MAX/MIN.
 * \return int retorno [0] si se cargo el TEXTO con exito. [1] = ERROR.
 *
 */


int getNumericoFloat(float* num,int minNum,int maxNum,char* textoInstruccion,char* textoError, int limite, int intentos,int modo)
{
    int auxNum,i,verificacion=1,retorno=1;
    char auxTexto[limite];
    do
    {
        printf("%s",textoInstruccion);
        fflush(stdin);
        fgets(auxTexto, limite, stdin);
        auxTexto[strlen(auxTexto) - 1] = '\0';
        if(strlen(auxTexto)>0)
        {
            for(i=0;i<strlen(auxTexto);i++)
            {
                if(((auxTexto[i]>='0') && (auxTexto[i]<='9')) || (auxTexto[i]=='.'))
                {
                    verificacion = 0;
                }
                else
                {
                    printf("\n%s\n\n",textoError);
                    verificacion = 1;
                    intentos--;
                    break;
                }
            }
        }
        else
        {
            printf("\n%s\n\n",textoError);
            verificacion = 1;
            intentos--;
        }
    }while(retorno == 1 &&intentos!=0);
    if(!verificacion)
    {
        auxNum = atof(auxTexto);
        if(((auxNum >= minNum && auxNum <= maxNum) && !modo) || (modo==1))
        {
            *num = auxNum;
            retorno=0;
        }
    }

    return retorno;
}

/** \brief Valida NUMERO ENTERO.
 *
 * \param numMax int Defino NUMERO maximo.
 * \param numMin int Defino NUMERO minima.
 * \param numero int* Mediante puntero paso NUMERO.
 * \return int retorno [0] si se cargo la NUMERO con exito. [1] = ERROR.
 *
 */
int getNumeroInt(int numMax, int numMin, int *numero,int intentos,int limiteVector,char *mensaje, char *mensajeError){
    char auxCharNum[limiteVector];
    int retorno=1;
    int auxNum;
    int verificacion=0;
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxCharNum, limiteVector, stdin);
    auxCharNum[strlen(auxCharNum) - 1] = '\0';
    if(!verificacionDigito(auxCharNum,"\nNO PUEDE CONTENER LETRAS, REINGRESE NUMERO: ",limiteVector,intentos))
    {
        auxNum = atoi(auxCharNum);

        while(auxNum > numMax || auxNum < numMin || verificacion==1)
        {
            if(intentos==0)
                return 1;
            printf("%s",mensajeError);
            fflush(stdin);
            fgets(auxCharNum, limiteVector, stdin);
            auxCharNum[strlen(auxCharNum) - 1] = '\0';
            intentos-=1;
            verificacion = verificacionDigito(auxCharNum,"\nNO PUEDE CONTENER LETRAS, REINGRESE NUMERO: ", limiteVector,intentos);
            if(!verificacion)
            {
                auxNum = atoi(auxCharNum);
            }
        }
        *numero = auxNum;
        retorno=0;
    }
    else
    {
        printf("\nERROR!\n\n");
    }
    return retorno;
}


/** \brief Valida NUMERO FLOTANTE.
 *
 * \param numMax int Defino NUMERO maximo.
 * \param numMin int Defino NUMERO minima.
 * \param numero int* Mediante puntero paso NUMERO.
 * \return int retorno [0] si se cargo la NUMERO con exito. [1] = ERROR.
 *
 */
 int getNumeroFloat(float numMax, float numMin, float *numero,int intentos,int limiteVector,char *mensaje, char *mensajeError){
    char auxCharNum[limiteVector];
    int retorno=1;
    float auxNum;
    int verificacion=0;
    printf("%s",mensaje);
    fflush(stdin);
    fgets(auxCharNum, limiteVector, stdin);
    auxCharNum[strlen(auxCharNum) - 1] = '\0';
    if(!verificacionDigito(auxCharNum,"\nNO PUEDE CONTENER LETRAS, REINGRESE NUMERO: ",limiteVector,intentos))
    {
        auxNum = atof(auxCharNum);

        while(auxNum > numMax || auxNum < numMin || verificacion==1)
        {
            if(intentos==0)
                return 1;
            printf("%s",mensajeError);
            fflush(stdin);
            fgets(auxCharNum, limiteVector, stdin);
            auxCharNum[strlen(auxCharNum) - 1] = '\0';
            intentos-=1;
            verificacion = verificacionDigito(auxCharNum,"\nNO PUEDE CONTENER LETRAS, REINGRESE NUMERO: ", limiteVector,intentos);
            if(!verificacion)
            {
                auxNum = atof(auxCharNum);
            }
        }
        *numero = auxNum;
        retorno=0;
    }
    else
    {
        printf("\nERROR!\n\n");
    }
    return retorno;
}

/** \brief Obtiene Cadena Alfanumerica
 *
 * \param array char* Mediante puntero pasa texto
 * \param mensaje char* Instruccion usuario
 * \param mensajeError char* Muestra error
 * \return int retorna [0] si se obtuvo cadena, [1] ERROR
 *
 */
int getCadena(char* array, char *mensaje, char *mensajeError, int limite, int intentos)
{
    int retorno=1;
    int error=0;
    char auxArray[limite];
    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(auxArray, limite, stdin);
        auxArray[strlen(auxArray) - 1] = '\0';
        if((strlen(auxArray))>0 && auxArray!=NULL)
        {
            strcpy(array, auxArray);
            retorno=0;
        }
        else
        {
            printf("%s",mensajeError);
            error=1;
            intentos-=1;
        }
    }while(error && intentos!=0);


    return retorno;
}

/** \brief VALIDA TODO LOS DATOS INGRESADOS POR EL USUARIO
 *
 * \param title char* VALIDA TITULO
 * \param genre char* VALIDA GENERO
 * \param duration float* VALIDA DURACION
 * \param description char* VALIDA DESCRIPCION
 * \param score float* VALIDA PUNTAJE
 * \param linkImagen char* VALIDA IMAGEN
 * \return int RETORNA 0 SI SE INGRESARON LOS DATOS CORRECTAMENTE 1 ERROR
 *
 */
int isValidAll(char* title, char* genre, float* duration, char* description, float* score, char* linkImagen,int intentos)
{
    int retorno=1;
    if(!getCadena(title,"\nIngrese titulo pelicula (MAX 50 CARACTERES): ", "\nSE PRODUJO ERROR AL INGRESAR TITULO!\n", 50,intentos)
    && !getCadena(genre,"\nIngrese genero pelicula(MAX 20 CARACTERES): ", "\nSE PRODUJO ERROR AL INGRESAR GENERO!\n", 20,intentos)
    && !getCadena(description,"\nIngrese descripcion pelicula(MAX 400 CARACTERES): ", "\nSE PRODUJO ERROR AL INGRESAR DESCRIPCION!\n", 400,intentos)
    && !getNumeroFloat(5,0.01,duration,intentos,10,"\nIngrese duracion de la pelicula(0.01 a 5.00HS): ","\nERROR, REINGRESE DURACION: ")
    && !getNumeroFloat(5,1,score,intentos,10,"\nIngrese puntaje pelicula(1 a 5): ","\nERROR, REINGRESE PUNTAJE: ")
    && !getCadena(linkImagen,"\nIngrese link imagen pelicula(MAX 400 CARACTERES): ", "\nSE PRODUJO ERROR AL INGRESAR LINK!\n", 400,intentos))
    {
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida NOMBRE.
 *
 * \param nombre char* Mediante puntero paso array de char.
 * \return int retorno [0] si se cargo el NOMBRE con exito. [1] = ERROR.
 *
 */

int getNombre(char* nombre)
{
    int retorno=1;
    char auxNombre[50];
    printf("\nIngrese Nombre: ");
    fflush(stdin);
    auxNombre[strlen(auxNombre) - 1] = '\0';
    if(!verificacionChar(auxNombre,"\nEL NOMBRE NO PUEDE CONTENER NUMEROS, REINGRESE NOMBRE: ",50,2))
    {
            strcpy(nombre, auxNombre);
            retorno=0;
    }
    return retorno;
}

/** \brief Valida DNI.
 *
 * \param dni int* Mediante puntero devuelve DNI ingresado y validado.
 * \return int retorno [0] si se cargo el DNI con exito. [1] = ERROR.
 *
 */
int getDni(int *dni,int limite,int intentos){

    char auxDni[limite];
    int retorno=1,longitudDni=0, verificacion=0;
    if(!getAlfaNumerico(auxDni,"\nIngrese DNI: ","El DNI ingresado no es valido.",limite,intentos))
    {
        /*printf("\nIngrese DNI: ");
        fflush(stdin);
        fgets(auxDni, limite, stdin);
        auxDni[strlen(auxDni) - 1] = '\0';*/
        if(!verificacionDigito(auxDni,"\nEl DNI no contiene letras, Reingrese DNI valido: ", limite,intentos))
        {
            longitudDni = strlen(auxDni);
            while((!(longitudDni == 7 || longitudDni == 8) || verificacion==1) && intentos!=0)
            {
                /*printf("\nEl DNI ingresado no es valido. REINGRESE DNI: ");
                fflush(stdin);
                fgets(auxDni, limite, stdin);
                auxDni[strlen(auxDni) - 1] = '\0';*/
                printf("\nERROR! ");
                if(!getAlfaNumerico(auxDni,"Reingrese DNI: ","El DNI ingresado no es valido.",limite,intentos))
                {
                    verificacion = verificacionDigito(auxDni,"\nEl DNI no contiene letras, Reingrese DNI valido: ", limite,intentos);
                    if(!verificacion)
                        longitudDni = strlen(auxDni);
                    intentos--;
                }
            }
            if(longitudDni == 7 || longitudDni == 8)
            {
                *dni = atoi(auxDni);
                retorno=0;
            }
        }
    }

    return retorno;
}

int getEmail(char* email)
{
    char sEmail[128];
    int longEmail=0;
    char sIndices[10];
    int flagArroba=1,flagPunto=1,i=1,j=0;
    int retorno=-1;
    if(!getCadena(sEmail,"\nINGRESE MAIL: ","\nEMAIL INCORRECTO! ",128,2)){
        longEmail = strlen(sEmail);
        if(longEmail>0)
        {
            for(i=0;i<longEmail;i++)
            {
                if(sEmail[i]=='@'){
                    sIndices[0]=i;
                    flagArroba =0;
                }
                if(sEmail[i]=='.'){
                    j++;
                    sIndices[j]=i;
                    flagPunto=0;
                }
            }
        }

        if(!flagArroba&&!flagPunto){
                if(sIndices[0]<sIndices[j])
                {
                    strcpy(email,sEmail);
                    return 0;
                }
                else
                    printf("\nMAIL INVALIDO, FORMATO VALIDO: 'xxxxx@xxxxx.xxx'\n\n");
        }
    }

    return retorno;
}

int getCuit(char* cuit,char* textoInstruccion,char* textoError, int intentos)
{
    int testG=1,i,verificacion,retorno=1;
    char auxTexto[15];
    do
    {
        printf("%d",sizeof("-"));
        printf("%s",textoInstruccion);
        fflush(stdin);
        fgets(auxTexto, 15, stdin);
        auxTexto[strlen(auxTexto) - 1] = '\0';
        if(strlen(auxTexto)>=13)
        {
            if((auxTexto[2]=='-')&&(auxTexto[11]=='-'))
            {

                for(i=0;i<strlen(auxTexto);i++)
                {
                    if(((auxTexto[i]>='0') && (auxTexto[i]<='9')) || (auxTexto[i]=='-'))
                    {
                        verificacion = 0;
                    }
                    else
                    {
                        printf("\n%s\n\n",textoError);
                        verificacion = 1;
                        intentos--;
                        break;
                    }
                }
                testG = 0;
            }

        }
        else
        {
            printf("\n%s\n\n",textoError);
            verificacion = 1;
            intentos--;
        }
    }while(verificacion == 1 &&intentos!=0);
    if(!verificacion&&!testG)
    {
        strcpy(cuit,auxTexto);
        retorno=0;
    }


    return retorno;

}
