#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "destino.h"
#include "aerolineas.h"
#include "menuesYValidaciones.h"

#include "tipos.h"
#include "aviones.h"

void mostrarDestino(eDestino destino, eDestino listaDestino[],int tamDest)
{
    char desDest[25];

    asignarNombreTipo(listaDestino,tamDest, destino.id, desDest);

    printf("|%5d | %-15s|\n",
           destino.id,
           desDest);
}
int mostrarDestinos(eDestino listaDest[], int tamDest)
{
    int todoOk = 0;
    int flag;

    if(listaDest != NULL && tamDest >0)
    {
        system("cls");
        printf(" *** LISTA DE TIPOS ***\n");
        printf("=========================\n");
        printf("|  ID  |   DESTINO         |\n");
        printf("-------------------------\n");

        for(int i = 0; i <tamDest; i++)
        {
            if(listaDest[i].isEmpty == 0)
            {
                mostrarDestino(listaDest[i], listaDest, tamDest);
                flag = 0;
            }

        }
        printf("======================================================\n");
        if(flag)
        {
            printf("No hay destinos para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
int asignarNombreDestino(eDestino listaDestino[],int tam, int idDestino, char descDestino[])
{
    int todoOk = 0;
    if(listaDestino != NULL && tam >0 && descDestino)
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
