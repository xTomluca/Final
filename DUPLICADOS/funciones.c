#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "valid.h"
#include "funciones.h"
#include "arraylist\examples\example_4\inc\ArrayList.h"

int agregarPelicula(ArrayList* pArray)
{
    char title[50];
    char genre[20];
    char description[400];
    char linkImagen[400];
    float duration;
    float score;
    EMovie* movie = movie_new();

    if(movie!=NULL && pArray!=NULL)
    {
        if(!isValidAll(title,genre,&duration,description,&score,linkImagen,2))
        {
            if( !movie_setTitulo(movie,title) &&
                !movie_setGenero(movie,genre) &&
                !movie_setDescripcion(movie,description) &&
                !movie_setLinkImagen(movie,linkImagen) &&
                !movie_setDuracion(movie,duration) &&
                !movie_setPuntaje(movie,score))
                {
                    printf("\n <<<<--SE REALIZO ALTA--->>>>\n\n");
                    al_add(pArray,movie);
                    return 0;
                }
        }

    }
    movie_delete(movie);
    return -1;
}

int borrarPelicula(ArrayList* pArray)
{
    int retorno=1;
    int index;
    int len=al_len(pArray);
    if(pArray!=NULL)
    {
        if(len>0)
        {
            printf("\n<<<<----- CANTIDAD DE PELICULAS CARGADAS: %d ----->>>>\n",len);
            getNumeroInt(len-1,0,&index,1,10,"\n\nINGRESE INDICE A ELIMINAR, RECUERDE QUE LA CARGA DE PELICULAS INICIALIZA EN <0>\n","\nINDICE NO ENCONTRADO, INTENTELO NUEVAMENTE: \n");
            if(index<len)
            {
                al_remove(pArray,index);
                printf("\nSE BORRO CON EXITO LA PELICULA\n\n");
                retorno=0;
            }
            else
            {
                printf("\nERROR AL BORRAR PELICULA\n\n");
            }
        }
        else
        {
            printf("\nNO CUENTA CON PELICULAS CARGADAS\n\n");
        }

    }
    return retorno;
}

void movie_generarBinario(ArrayList* pArray)
{
    FILE* pFile;
    pFile = fopen("pelicula/peliculas.html","wb");
    int i;
    int len= al_len(pArray);

    float duration,score;
    char title[50], genre[20], description[400], linkImagen[400];
    if(pFile==NULL)
    {
        printf("\nERROR APERTURA ARCHIVO\n");
        exit(1);
    }
    else if(len > 0)
    {
        fprintf(pFile,"<!DOCTYPE html>\n");
        fprintf(pFile,"<!-- Template by Quackit.com -->\n");
        fprintf(pFile,"<html lang='en'>\n");
        fprintf(pFile,"<head>\n");
        fprintf(pFile,"<meta charset='utf-8'>\n");
        fprintf(pFile,"<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(pFile,"<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(pFile,"<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
        fprintf(pFile,"<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(pFile,"<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(pFile,"<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
        fprintf(pFile,"<title>Lista peliculas</title>\n");
        fprintf(pFile,"<!-- Bootstrap Core CSS -->\n");
        fprintf(pFile,"<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(pFile,"<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
        fprintf(pFile,"<link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(pFile,"<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
        fprintf(pFile,"<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n");
        fprintf(pFile,"<!--[if lt IE 9]>\n");
        fprintf(pFile,"<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n");
        fprintf(pFile,"<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
        fprintf(pFile,"<![endif]-->\n");
        fprintf(pFile,"</head>\n");
        fprintf(pFile,"<body>\n");
        fprintf(pFile,"<div class='container'>\n");
        fprintf(pFile,"<div class='row'>\n");
        fprintf(pFile,"<!-- Repetir esto para cada pelicula -->\n");
        for(i=0;i<len;i++)
        {
                EMovie* pelicula = al_get(pArray,i);
                if(pelicula != NULL)
                {
                    movie_getTitulo(pelicula,title);
                    movie_getGenero(pelicula,genre);
                    movie_getDuracion(pelicula,&duration);
                    movie_getDescripcion(pelicula,description);
                    movie_getPuntaje(pelicula,&score);
                    movie_getLinkImagen(pelicula,linkImagen);
                    fprintf(pFile,"<article class='col-md-4 article-intro'>\n");
                    fprintf(pFile,"<a href='#'>\n");
                    fprintf(pFile,"<img class='img-responsive img-rounded' src='%s' alt=''>\n",linkImagen);
                    fprintf(pFile,"<h3>\n");
                    fprintf(pFile,"<a href='#'>%s</a>\n",title);
                    fprintf(pFile,"</h3>\n");
                    fprintf(pFile,"<ul>\n");
                    fprintf(pFile,"<li>Genero: %s</li>\n",genre);
                    fprintf(pFile,"<li>Puntaje: %.2f</li>\n",score);
                    fprintf(pFile,"<li>Duracion: %.2f hs</li>\n",duration);
                    fprintf(pFile,"</ul>\n");
                    fprintf(pFile,"<p>Descripcion:\n%s</p>\n",description);
                    fprintf(pFile,"</article>\n");
                }
        }
        fprintf(pFile,"<!-- Repetir esto para cada pelicula -->\n");
        fprintf(pFile,"</div>\n");
        fprintf(pFile,"<!-- /.row -->\n");
        fprintf(pFile,"</div>\n");
        fprintf(pFile,"<!-- /.container -->\n");
        fprintf(pFile,"<!-- jQuery -->\n");
        fprintf(pFile,"<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(pFile,"<!-- Bootstrap Core JavaScript -->\n");
        fprintf(pFile,"<script src='js/bootstrap.min.js'></script>\n");
        fprintf(pFile,"<!-- IE10 viewport bug workaround -->\n");
        fprintf(pFile,"<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(pFile,"<!-- Placeholder Images -->\n");
        fprintf(pFile,"<script src='js/holder.min.js'></script>\n");
        fprintf(pFile,"</body>\n");
        fprintf(pFile,"</html>\n");
        printf("\n<<<---SE GENERO HTML CON EXITO--->>>\n\n");

    }else{
            printf("\n<<<---NO CUENTA CON PELICULAS CARGADAS--->>>\n\n");
    }
    fclose(pFile);
}
