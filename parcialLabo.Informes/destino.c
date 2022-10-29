#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "destino.h"
#include "validaciones.h"

/** \brief muestra un destino
 *
 * \param destino eDestino variable para asignar datos a mostrar
 * \return void
 *
 */
void mostrarDestino(eDestino destino)
{

    printf("|%5d | %-15s| $%9.2f |\n",
           destino.id,
           destino.nombre,
           destino.precio);
}
/** \brief muestra todos los destinos
 *
 * \param listaDest[] eDestino array a recorrer
 * \param tamDest int tamanio del array
 * \return int
 *
 */
int mostrarDestinos(eDestino listaDest[], int tamDest)
{
    int todoOk = 0;
    int flag;

    if(listaDest != NULL && tamDest >0)
    {
        system("cls");
        printf("*** LISTA DE DESTINOS ***\n");
        printf("======================================\n");
        printf("|  ID  |   DESTINO      |  PRECIO    |\n");
        printf("--------------------------------------\n");

        for(int i = 0; i <tamDest; i++)
        {
            if(listaDest[i].isEmpty == 0)
            {
                mostrarDestino(listaDest[i]);
                flag = 0;
            }

        }
        printf("======================================\n");
        if(flag)
        {
            printf("No hay destinos para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
/** \brief recibe un id y le asigna la descripcion
 *
 * \param listaDestino[] eDestino array donde esta la descripcion
 * \param tam int tamanio del array
 * \param idDestino int id recibido
 * \param descDestino[] char descripcion a designar
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int asignarNombreDestino(eDestino listaDestino[],int tam, int idDestino, char descDestino[])
{
    int todoOk = 0;
    if(listaDestino != NULL && tam >0 && descDestino != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(listaDestino[i].id == idDestino)
            {
                strcpy(descDestino, listaDestino[i].nombre);
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
/** \brief busca una posicion libre en el array
 *
 * \param listaDest[] eDestino array a recorrer
 * \param tamDest int tamanio del array
 * \return int retorna -1 si esta ocupada la posicion y si no, retorna la posicion libre
 *
 */
int buscarDestinoLibre(eDestino listaDest[], int tamDest)
{
    int posicionLibre = -1;
    if(listaDest != NULL && tamDest > 0)
    {
        for(int i = 0; i < tamDest; i++)
        {
            if(listaDest[i].isEmpty == 1)
            {
                posicionLibre = i;
                break;
            }
        }
    }
    return posicionLibre;
}

/** \brief busca un destino por id
 *
 * \param id int
 * \param listaDest[] eDestino array a recorrer
 * \param tamDest int tamanio del array
 * \return int retorna -1 si no encuentra el id y si lo encuentra retorna la posicion
 *
 */
int buscarDestinoId(int id, eDestino listaDest[], int tamDest)
{
    int indice = -1;
    if(listaDest != NULL && tamDest > 0)
    {
        for(int i = 0; i < tamDest; i++)
        {
            if(!listaDest[i].isEmpty && listaDest[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


/** \brief harcodea los destinos
 *
 * \param pDestino int* puntero al id
 * \param lista[] eDestino array de destinos
 * \param tamDest int tamanio del array
 * \param cant int cantidad a harcodear
 * \return int  retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int harcodearDestino(int* pDestino, eDestino lista[], int tamDest, int cant)
{
    int todoOk = 0;
    eDestino destino[10] = {
         {20000,"Calafate", 22250,0},
         {20001,"Miami", 103000,0},
         {20002,"Milan", 84400,0},
         {20003,"Amsterdam", 95600,0}};
    if(pDestino != NULL && lista != NULL && tamDest > 0 && cant<= tamDest && cant <= 10)
    {
        for(int i = 0; i < cant; i++)
        {
            lista[i] = destino[i];
            (*pDestino)++;
        }
        todoOk = 1;
    }
    return todoOk;
}

