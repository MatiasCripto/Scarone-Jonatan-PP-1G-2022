#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "aerolineas.h"
#include "menuesYValidaciones.h"
#include "destino.h"
#include "tipos.h"
#include "aviones.h"

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
void mostrarAerolinea(eAerolinea Aerolinea, eAerolinea listaAero[],int tamAero)
{
    char desAerolinea[25];

    asignarNombreAerolineas(listaAero,tamAero, Aerolinea.id, desAerolinea);

    printf("|%5d | %-15s|\n",
           Aerolinea.id,
           desAerolinea);
}

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
                mostrarAerolinea(listaAero[i], listaAero, tamAero);
                flag = 0;
            }

        }
        printf("======================================================\n");
        if(flag)
        {
            printf("No hay Aerolineas para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
