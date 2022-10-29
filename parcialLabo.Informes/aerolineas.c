#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aerolineas.h"
#include "validaciones.h"


/** \brief recibe un id para pasarlo a la descripcion que corresponda
 *
 * \param listaAero[] array a recorrer
 * \param tam int tamanio del array
 * \param idAerolinea int id recibido
 * \param descAerolinea[] char descripcion a asignar al id
 * \return int
 *
 */
int asignarNombreAerolineas(eAerolinea listaAero[],int tam, int idAerolinea, char descAerolinea[])
{
    int todoOk = 0;
    if(listaAero != NULL && tam >0 && descAerolinea)
    {
        for(int i = 0; i < tam; i++)
        {
            if(listaAero[i].id == idAerolinea)
            {
                strcpy(descAerolinea, listaAero[i].nombre);
                break;
            }
        }

        todoOk = 1;
    }

    return todoOk;
}
/** \brief muestra una aerolinea
 *
 * \param aerolinea eAerolinea variable para asignar datos a mostrar
 * \return void
 *
 */
void mostrarAerolinea(eAerolinea aerolinea)
{


    printf("|%5d | %-15s|\n",
           aerolinea.id,
           aerolinea.nombre);
}

/** \brief muestra todas las aerolineas
 *
 * \param listaAero[] eAerolinea array a recorrer
 * \param tamAero int tamanio del array
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int mostrarAerolineas(eAerolinea listaAero[], int tamAero)
{
    int todoOk = 0;
    int flag;

    if(listaAero != NULL && tamAero >0)
    {
        system("cls");
        printf(" *** LISTA DE AEROLINEAS ***\n");
        printf("=========================\n");
        printf("|  ID  |   AEROLINEAS   |\n");
        printf("-------------------------\n");

        for(int i = 0; i <tamAero; i++)
        {
            if(listaAero[i].isEmpty == 0)
            {
                mostrarAerolinea(listaAero[i]);
                flag = 0;
            }

        }
        printf("=========================\n");
        if(flag)
        {
            printf("No hay Aerolineas para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
/** \brief harcodea las aerolineas
 *
 * \param pAerolineas int* puntero al id
 * \param lista[] eAerolinea array a recorrer
 * \param tam int tamanio del array
 * \param cant int cantidad de aerolineas a harcodear
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int harcodearAerolineas(int* pAerolineas, eAerolinea lista[], int tam, int cant)
{
    int todoOk = 0;
    eAerolinea aerolinea[10] =
    {{1000,"Lan",0},
    {1001,"Iberia",0},
    {1002,"Norwegian",0},
    {1003,"American",0},
    {1004,"Austral",0}};
    if(pAerolineas != NULL && lista != NULL && tam > 0 && cant<= tam && cant <= 10)
    {
        for(int i = 0; i < cant; i++)
        {
            lista[i] = aerolinea[i];
            (*pAerolineas)++;
        }
        todoOk = 1;
    }
    return todoOk;

}
/** \brief busca las posiciones libres
 *
 * \param listaAero[] eAerolinea array a recorrer
 * \param tamAero int tamanio del array
 * \return int retorna -1 si no hay posiciones libres, y si las hay retorna la posicion
 *
 */
int buscarAerolineaLibre(eAerolinea listaAero[], int tamAero)
{
    int posicionLibre = -1;
    if(listaAero != NULL && tamAero > 0)
    {
        for(int i = 0; i < tamAero; i++)
        {
            if(listaAero[i].isEmpty == 1)
            {
                posicionLibre = i;
                break;
            }
        }
    }
    return posicionLibre;
}


/** \brief busca una aerolinea por el id
 *
 * \param id int recibe el id
 * \param listaAero[] eAerolinea array a recorrer
 * \param tamAero int tamanio del array
 * \return int int retorna -1 si no coincide el id ingresado con los id existentes, y si existe retorna la posicion
 *
 */
int buscarAerolineaId(int id, eAerolinea listaAero[], int tamAero)
{
    int indice = -1;
    if(listaAero != NULL && tamAero > 0)
    {
        for(int i = 0; i < tamAero; i++)
        {
            if(!listaAero[i].isEmpty && listaAero[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
