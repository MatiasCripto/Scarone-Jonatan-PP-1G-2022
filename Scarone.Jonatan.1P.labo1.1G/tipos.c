#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "tipos.h"

/** \brief recibe un id y le asigna la descripcion del tipo
 *
 * \param listaTipo[] eTipos arra a recorrer para buscar el id
 * \param tam int tamanio del array
 * \param idTipo int id recibido
 * \param descTipo[] char descripcion a asignar al id
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int asignarNombreTipo(eTipos listaTipo[],int tam, int idTipo, char descTipo[])
{
    int todoOk = 0;
    if(listaTipo != NULL && tam >0 && descTipo)
    {
        for(int i = 0; i < tam; i++)
        {
            if(listaTipo[i].id == idTipo)
            {
                strcpy(descTipo, listaTipo[i].nombre);
                break;
            }
        }

        todoOk = 1;
    }

    return todoOk;
}
/** \brief muestra un tipo de avion
 *
 * \param tipo eTipos variable para designar los datos
 * \return void
 *
 */
void mostrarTipo(eTipos tipo)
{

    printf("|%5d | %-15s|\n",
           tipo.id,
           tipo.nombre);
}
/** \brief muestra todos los tipos de aviones
 *
 * \param listaTipo[] eTipos array a recorrer
 * \param tamTipo int tamanio del array
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int mostrarTipos(eTipos listaTipo[], int tamTipo)
{
    int todoOk = 0;
    int flag;

    if(listaTipo != NULL && tamTipo >0)
    {
        system("cls");
        printf(" *** LISTA DE TIPOS ***\n");
        printf("=========================\n");
        printf("|  ID  |   TIPO         |\n");
        printf("-------------------------\n");

        for(int i = 0; i <tamTipo; i++)
        {
            if(listaTipo[i].isEmpty == 0)
            {
                mostrarTipo(listaTipo[i]);
                flag = 0;
            }

        }
        printf("=========================\n");
        if(flag)
        {
            printf("No hay tipos para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief busca una posicion libre en el array
 *
 * \param listaTipo[] eTipos array a recorrer
 * \param tamTipo int tamanio del array
 * \return int retorna -1 si no hay posiciones libres, y si las hay, retorna la posicion
 *
 */
int buscarTipoLibre(eTipos listaTipo[], int tamTipo)
{
    int posicionLibre = -1;
    if(listaTipo != NULL && tamTipo > 0)
    {
        for(int i = 0; i < tamTipo; i++)
        {
            if(listaTipo[i].isEmpty == 1)
            {
                posicionLibre = i;
                break;
            }
        }
    }
    return posicionLibre;
}

/** \brief busca un tipo por id
 *
 * \param id int id recibido
 * \param listaTipo[] eTipos array a recorrer
 * \param tamTipo int tamanio del array
 * \return int retorna -1 si el id no existe, y si existe retorna la posicion
 *
 */
int buscarTipoId(int id, eTipos listaTipo[], int tamTipo)
{
    int indice = -1;
    if(listaTipo != NULL && tamTipo > 0)
    {
        for(int i = 0; i < tamTipo; i++)
        {
            if(!listaTipo[i].isEmpty && listaTipo[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
/** \brief harcodea los tipos de aviones
 *
 * \param pDestino int* puntero al id
 * \param lista[] eDestino array de tipos
 * \param tamDest int tamanio del array
 * \param cant int cantidad a harcodear
 * \return int  retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int harcodearTipo(int* pTipo, eTipos listaTipo[], int tamTipo, int cant)
{
    int todoOk = 0;
    eTipos tipo[20] =
    {
        {5000,"Jet",0},
        {5001,"Helice",0},
        {5002,"Planeador",0},
        {5003,"Carga",0}
    };
    if(pTipo != NULL && listaTipo != NULL && tamTipo > 0 && cant<= tamTipo && cant <= 10)
    {
        for(int i = 0; i < cant; i++)
        {
            listaTipo[i] = tipo[i];
            (*pTipo)++;
        }
        todoOk = 1;
    }
    return todoOk;
}



