#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"
#include "vuelos.h"
#include "validaciones.h"

/** \brief muestra un vuelo
 *
 * \param vuelo eVuelo principal a recorrer
 * \param tamVuelo int tamanio del array
 * \param listaDest[] eDestino array de destino a recorrer par buscar la descripcion y asignarla al id
 * \param tamDest int tamanio del array de destino
 * \return void
 *
 */
void mostrarVuelo(eVuelo vuelo, int tamVuelo, eDestino listaDest[],int tamDest)
{
    char descDestino[25];


    asignarNombreDestino(listaDest,tamDest, vuelo.idDestino, descDestino);
    printf("|   %5d   |    %d     | %-15s| %02d/%02d/%d|\n",
           vuelo.id,
           vuelo.idAvion,
           descDestino,
           vuelo.fechaVuelo.dia,
           vuelo.fechaVuelo.mes,
           vuelo.fechaVuelo.anio );

}
/** \brief muestra todos los vuelos
 *
 * \param vuelo[] eVuelo array principal a recorrer
 * \param tamVuelo int tamanio del vuelo
 * \param listaDest[] eDestino array de destino
 * \param tamDest int tamanio del array de destino
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int mostrarVuelos(eVuelo vuelo[], int tamVuelo, eDestino listaDest[], int tamDest)
{
    int todoOk = 0;
    int flag;


    if(vuelo != NULL && tamVuelo >0 && listaDest != NULL && tamDest >0)
    {
        system("cls");
        printf("                  *** LISTA DE VUELOS   ***\n");
        printf("=====================================================\n");
        printf("|  ID VUELO | ID AVION |   DESTINO      | FECHA     |\n");
        printf("-----------------------------------------------------\n");

        for(int i = 0; i <tamVuelo; i++)
        {
            if(vuelo[i].isEmpty == 0)
            {
                mostrarVuelo(vuelo[i], tamVuelo,listaDest ,tamDest);
                flag = 0;
            }

        }
        printf("=====================================================\n");
        if(flag)
        {
            printf("No hay vuelos para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
/** \brief busca una posicion libre en el array de vuelos
 *
 * \param vuelo[] eVuelo array a recorrer
 * \param tamVuelo int tamanio del array
 * \return int retorna -1 si no hay posiciones libres, y si las hay, retorna la posicion
 *
 */
int buscarVueloLibre(eVuelo vuelo[], int tamVuelo)
{
    int posicionLibre = -1;
    if(vuelo != NULL && tamVuelo > 0)
    {
        for(int i = 0; i < tamVuelo; i++)
        {
            if(vuelo[i].isEmpty == 1)
            {
                posicionLibre = i;
                break;
            }
        }
    }
    return posicionLibre;
}
/** \brief busca un vuelo por id
 *
 * \param id int id recibido a buscar
 * \param vuelos[] eVuelo array a recorrer para la busqueda
 * \param tamVuelo int tamanio del array
 * \return int retorna -1 si el id no existe y si existe retorna la posicion
 *
 */
int buscarVueloId(int id, eVuelo vuelos[], int tamVuelo)
{
    int indice = -1;
    if(vuelos != NULL && tamVuelo > 0)
    {
        for(int i = 0; i < tamVuelo; i++)
        {
            if(!vuelos[i].isEmpty && vuelos[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
/** \brief da de alta un vuelo
 *
 * \param vuelo[] eVuelo array principal a recorrer
 * \param tamVuelo int tamanio del array principal
 * \param lista[] eAvion array de avion para dar de alta
 * \param tam int tamanio del array del avion
 * \param listaAero[] eAerolinea array de aerolinea para dar de alta
 * \param tamAero int tamanio del array de aerolinea
 * \param listaTipo[] eTipos array de tipo para dar de alta
 * \param tamTipo int tamanio del array de tipo
 * \param listaDest[] eDestino array de destino para dar de alta
 * \param tamDest int tamanio del array de destino
 * \param pId int* puntero al id
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int altaVuelo(eVuelo vuelo[], int tamVuelo, eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo, eDestino listaDest[], int tamDest, int* pId)
{
    int todoOk = 0;
    int indice;
    int auxInt;
    char auxCad[50];
    eVuelo auxVuelo;

    strlwr(auxCad);
    if(vuelo != NULL && listaAero != NULL && tamAero > 0 && listaTipo != NULL && tamTipo > 0 && pId != NULL && tamVuelo > 0 && listaDest != NULL && tamDest > 0)
    {

        system("cls");
        printf("            ***  ALTA VUELO  ***\n\n");
        indice = buscarVueloLibre(vuelo, tamVuelo);
        if(indice == -1)
        {
            printf("No hay lugar \n");
        }
        else
        {
            auxVuelo.id = *pId;
            (*pId)++;

            fflush(stdin);

            mostrarAviones(lista,tam,listaAero,tamAero,listaTipo, tamTipo);
            utn_getNumero(&auxInt,"Ingrese una opcion: \n","Opcion no valida\n",1,999,99);

            auxVuelo.idAvion = auxInt;

            mostrarDestinos(listaDest, tamDest);
            utn_getNumero(&auxInt,"Ingrese una opcion: \n","Opcion no valida\n",20000,30000,99);

            auxVuelo.idDestino = auxInt;

            utn_getNumero(&auxInt,"Ingrese la fecha en este formato dd/mm/aaaa\n Ingrese dia:","Error, parametro no valido",1,31,99);

            auxVuelo.fechaVuelo.dia = auxInt;

            utn_getNumero(&auxInt,"Ingrese mes:","Error, parametro no valido",1,12,99);

            auxVuelo.fechaVuelo.mes = auxInt;

            utn_getNumero(&auxInt,"Ingrese anio:","Error, parametro no valido",1900,2022,99);

            auxVuelo.fechaVuelo.anio = auxInt;

            auxVuelo.isEmpty = 0;

            vuelo[indice] = auxVuelo;

            todoOk = 1;
        }
    }
    return todoOk;
}
/** \brief recorre el array y deja libre las posiciones
 *
 * \param vuelo[] eVuelo array a recorrer
 * \param tamVuelo int tamanio del array
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int inicializarVuelo(eVuelo vuelo[], int tamVuelo)
{
    int todoOk = 0;
    if(vuelo != NULL && tamVuelo > 0)
    {
        for(int i = 0; i < tamVuelo; i++)
        {
            vuelo[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}
/** \brief harcodea los vuelos
 *
 * \param pVuelos int* puntero al id
 * \param listaVuelos[] eVuelo array de vuelos
 * \param tamVuelos int tamanio del array
 * \param cant int cantidad de harcodeos
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int harcodearVuelos(int* pVuelos, eVuelo listaVuelos[], int tamVuelos, int cant)
{
    int todoOk = 0;
    eVuelo vuelos[10] = {
        {10000,2,20000,{3,5,1987},0},
        {10001,4,20002,{12,5,2019},0},
        {10002,3,20001,{8,6,2012},0},
        {10003,1,20003,{31,12,1999},0},
        {10004,5,20003,{15,8,2022},0} };
    if(pVuelos != NULL && listaVuelos != NULL && tamVuelos > 0 && cant<= tamVuelos && cant <= 10)
    {
        for(int i = 0; i < cant; i++)
        {
            listaVuelos[i] = vuelos[i];

            (*pVuelos)++;
        }
        todoOk = 1;
    }
    return todoOk;

}

