#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aerolineas.h"
#include "validaciones.h"
#include "destino.h"
#include "tipos.h"
#include "aviones.h"

/** \brief recorre un array y dejas las posiciones libres
 *
 * \param lista[] eAvion array a recorrer
 * \param tam int tamanio del array
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int inicializarAvion(eAvion lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 10; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief da de alta un avion
 *
 * \param lista[] eAvion array principal a recorrer
 * \param tam int tamanio del array principal
 * \param listaAero[] eAerolinea array de aerolineas para asignar un campo al array principal
 * \param tamAero int tamanio del array de aerolineas
 * \param listaTipo[] eTipos array de tipo de avion para asignar al array principal
 * \param tamTipo int tamanio del array de tipo de avion
 * \param pId int* id autoincremental pasado por puntero
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int altaAvion(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo, int* pId)
{
    int todoOk = 0;
    int indice;
    int auxInt;
    char auxCad[50];
    eAvion auxAvion;

    strlwr(auxCad);
    if(lista != NULL && listaAero != NULL && tamAero > 0 && listaTipo != NULL && tamTipo > 0 && pId != NULL && tam > 0)
    {

        system("cls");
        printf("            ***  ALTA AVION  ***\n\n");
        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar \n");
        }
        else
        {
            auxAvion.id = *pId;
            (*pId)++;

            fflush(stdin);

            mostrarAerolineas(listaAero,tamAero);
            utn_getNumero(&auxInt,"Ingrese una opcion: \n","Opcion no valida\n",1000,2000,99);

            auxAvion.idAerolinea = auxInt;

            mostrarTipos(listaTipo,tamTipo);
            utn_getNumero(&auxInt,"Ingrese una opcion: \n","Opcion no valida\n",5000,6000,99);

            auxAvion.idTipo = auxInt;

            utn_getNumero(&auxInt,"Ingrese capacidad de personas entre  10 y 300: \n","Opcion no valida\n",10,300,99);

            auxAvion.capacidad = auxInt;

            auxAvion.isEmpty = 0;

            lista[indice] = auxAvion;

            todoOk = 1;
        }
    }
    return todoOk;
}
/** \brief muestra un avion
 *
 * \param avion eAvion variable de la estructura avion para asignar los valores a mostrar
 * \param listaAero[] eAerolinea array de aerolineas para ver la descripcion
 * \param tamAero int tamanio del array de aerolineas
 * \param listaTipo[] eTipos array de tipo para ver la descripcion
 * \param tamTipo int tamanio del array de tipo
 * \return void
 *
 */
void mostrarAvion(eAvion avion, eAerolinea listaAero[], int tamAero, eTipos listaTipo[],int tamTipo)
{
    char descAerolinea[25];
    char desTipo[25];

    asignarNombreAerolineas(listaAero, tamAero, avion.idAerolinea, descAerolinea);
    asignarNombreTipo(listaTipo,tamTipo, avion.idTipo, desTipo);
    printf("|%5d | %-15s| %-15s| %4d      |\n",
           avion.id,
           descAerolinea,
           desTipo,
           avion.capacidad);

}
/** \brief muestra todos los aviones
 *
 * \param lista[] eAvion array principar a recorrer
 * \param tam int tamanio del array principal
 * \param listaAero[] eAerolinea array de aerolineas
 * \param tamAero int tamanio del array de aerolineas
 * \param listaTipo[] eTipos array de tipos de avion
 * \param tamTipo int tamanio del array de tipo
 * \return int
 *
 */
int mostrarAviones(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo)
{
    int todoOk = 0;
    int flag;


    if(lista != NULL && tam >0 && listaAero != NULL && tamAero >0 && listaTipo != NULL && tamTipo >0)
    {
        system("cls");
        printf("                  *** LISTA DE AVIONES ***\n");
        printf("======================================================\n");
        printf("|  ID  |    AEROLINEA   |   TIPO         | CAPACIDAD |\n");
        printf("------------------------------------------------------\n");

        ordenarAvionesDobleCriterio(lista,tam);
        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarAvion(lista[i], listaAero, tamAero ,listaTipo ,tamTipo);
                flag = 0;
            }

        }
        printf("======================================================\n");
        if(flag)
        {
            printf("No hay aviones para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
/** \brief da de baja un avion
 *
 * \param lista[] eAvion array principal a recorrer
 * \param tam int tamanio del array principal
 * \param listaAero[] eAerolinea array de aerolineas que pertenesca a ese avion
 * \param tamAero int tamanio del array de aerolinea
 * \param listaTipo[] eTipos array de tipo de avion
 * \param tamTipo int tamanio del array de tipo
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int bajaAvion(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("                  *** LISTA DE AVIONES ***\n");
        printf("======================================================\n");
        printf("|  ID  |    AEROLINEA   |   TIPO         | CAPACIDAD |\n");
        printf("------------------------------------------------------\n");
        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarAvion(lista[i], listaAero, tamAero ,listaTipo ,tamTipo);
            }
        }
        printf("======================================================\n");

        utn_getNumero(&id,"Ingrese id: ","Error, campo no valido",1,500,99);

        indice = buscarAvionId(id,lista, tam);

        if(indice == -1)
        {
            printf("el id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarAvion(lista[indice], listaAero, tamAero ,listaTipo ,tamTipo);
            printf("\nPresione S para confirmar: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}
/** \brief busca a un avion por el id
 *
 * \param id int id ingresado a buscar
 * \param lista[] eAvion array a recorrer para buscar ese id
 * \param tam int tamanio del array
 * \return int retorna -1 si no encontro el id, y si el id existe retorna la posicion del mismo
 *
 */
int buscarAvionId(int id, eAvion lista[], int tam)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!lista[i].isEmpty && lista[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
/** \brief modifica un avion
 *
 * \param lista[] eAvion array principal a recorrer
 * \param tam int tamanio del array principal
 * \param listaAero[] eAerolinea array de aerolinea
 * \param tamAero int tamanio del array de aerolinea
 * \param listaTipo[] eTipos array de tipo
 * \param tamTipo int tamanio del array de tipo
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int modificarAvion(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma = 's';

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("            *** MODIFICAR AVION ***         \n");
        printf("======================================================\n");
        printf("|  ID  |    AEROLINEA   |   TIPO         | CAPACIDAD |\n");
        printf("------------------------------------------------------\n");

        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarAvion(lista[i], listaAero, tamAero ,listaTipo ,tamTipo);
            }
        }
        printf("======================================================\n");
        utn_getNumero(&id,"Ingrese id: ","Error, campo no valido",1,100,99);

        indice = buscarAvionId(id,lista, tam);

        if(indice == -1)
        {
            printf("No existe un avion con el id: %d", id);
        }
        else
        {
            mostrarAvion(lista[indice], listaAero, tamAero ,listaTipo ,tamTipo);
            printf("Confirma modificacion?: s/n :");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {

                switch(menuModificacionAvion())
                {
                case 1:
                    fflush(stdin);
                    mostrarTipos(listaTipo,tamTipo);
                    utn_getNumero(&lista[indice].idTipo,"ingrese nuevo tipo \n", "Error, reingrese nuevo tipo\n",1,5005,99);
                    break;
                case 2:
                    fflush(stdin);
                    utn_getNumero(&lista[indice].capacidad,"Ingrese nueva capacidad de pasajeros entre 10 y 300\n", "Error, reingrese capacidad",10,300,99);
                    break;
                default:
                    printf("La opcion es invalida");

                }
                todoOk = 1;
            }
            else
            {
                printf("Modificacion cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}
/** \brief busca una posicion libre
 *
 * \param lista[] eAvion array a recorrer para buscar esa posicion
 * \param tam int tamanio del array
 * \return int retorna -1 si no encontro una posicion libre, y si existe retorna la posicion del mismo
 *
 */
int buscarLibre(eAvion lista[], int tam)
{
    int posicionLibre = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                posicionLibre = i;
                break;
            }
        }
    }
    return posicionLibre;
}
/** \brief ordena por doble criterio
 *
 * \param lista[] eAvion array a ordenar
 * \param tam int tamanio del array
 * \return int retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int ordenarAvionesDobleCriterio(eAvion lista[], int tam)
{
	int todoOk = 0;
	eAvion auxAvion;

	if(lista != NULL && tam > 0){
		for(int i =0; i<tam-1; i++){
			for(int j =i+1; j<tam; j++){
				if((lista[i].idAerolinea > lista[j].idAerolinea)
                || (lista[i].idAerolinea == lista[j].idAerolinea
                && lista[i].capacidad > lista[j].capacidad))
                {
					auxAvion = lista[i];
					lista[i] = lista[j];
					lista[j] = auxAvion;
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

/** \brief opciones a modificar
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuModificacionAvion()
{
    int opcion;
    system("cls");
    fflush(stdin);
    utn_getNumero(&opcion,"     *** Modificar Aviones ***     \n\n1- MODIFICAR TIPO\n2- MODIFICAR CAPACIDAD\nIngrese Opcion: \n","Error, campo no valido\n",1,2,99);

    return opcion;
}
/** \brief harcodea los aviones
 *
 * \param pDestino int* puntero al id
 * \param lista[] eDestino array de aviones
 * \param tamDest int tamanio del array
 * \param cant int cantidad a harcodear
 * \return int  retorna 0 si si no entro a la validacion y 1 si salio todo bien
 *
 */
int harcodearAvion(int* pAvion, eAvion lista[], int tam, int cant)
{
    int todoOk = 0;
    eAvion aviones[20] =
    {
        {1,1001,5000,150,0},
        {2,1000,5002,250,0},
        {3,1002,5001,177,0},
        {4,1003,5003,145,0},
        {5,1000,5001,123,0},
        {6,1003,5001,160,0},
        {7,1002,5002,255,0},
        {8,1000,5003,185,0},
        {9,1002,5001,152,0},
        {10,1001,5001,251,0}
    } ;
    if(pAvion != NULL && lista != NULL && tam > 0 && cant<= tam && cant <= 10)
    {
        for(int i = 0; i < cant; i++)
        {
            lista[i] = aviones[i];
            (*pAvion)++;
        }
        todoOk = 1;
    }
    return todoOk;
}
