#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "aerolineas.h"
#include "menuesYValidaciones.h"
#include "destino.h"
#include "tipos.h"
#include "aviones.h"

int inicializarAvion(eAvion lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaAvion(eAvion lista[], int tam, int* pId)
{
    int todoOk = 0;
    int indice;
    int auxInt;
    char auxCad[50];
    eAvion auxAvion;

    strlwr(auxCad);
    if(lista != NULL && pId != NULL && tam > 0)
    {

        system("cls");
        printf("            ***  ALTA AVION  ***\n\n");
        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar ");
        }
        else
        {
            auxAvion.id = *pId;
            (*pId)++;

            fflush(stdin);

            utn_getNumero(&auxInt,"  ***ID Aerolinea*** \n1000 - LAN\n1001 - IBERIA\n1002 - NORWEGIAN\n1003 - AMERICAN\n1004 - AUSTRAL\nIngrese una opcion: \n","Opcion no valida\n",1000,2000,99);

            auxAvion.idAerolinea = auxInt;

            utn_getNumero(&auxInt,"  ***ID Tipo*** \n5000 - JET\n5001 - HELICE\n5002 - PLANEADOR\n5003 - CARGA\nIngrese una opcion: \n","Opcion no valida\n",5000,6000,99);

            auxAvion.idTipo = auxInt;

            utn_getNumero(&auxInt,"Ingrese capacidad de personas entre  10 y 300","Opcion no valida\n",10,300,99);

            auxAvion.capacidad = auxInt;

            auxAvion.isEmpty = 0;

            lista[indice] = auxAvion;

            todoOk = 1;
        }
    }
    return todoOk;
}
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
int mostrarAviones(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo)
{
    int todoOk = 0;
    int flag;
    eAvion auxAvion;

    if(lista != NULL && tam >0 && listaAero != NULL && tamAero >0 && listaTipo != NULL && tamTipo >0)
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

        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarAvion(lista[i], listaAero, tamAero ,listaTipo ,tamTipo);

            }
        }

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
                fflush(stdin);
                switch(menuModificacion())
                {
                case 1:
                    utn_getNumero(&lista[indice].idTipo,"ingrese nuevo tipo \n", "Error, reingrese nuevo tipo\n",5000,6000,99);

                    break;
                case 2:
                    utn_getNumero(&lista[indice].capacidad,"Ingrese nueva capacidad", "Error, reingrese capacidad",10,300,99);
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

