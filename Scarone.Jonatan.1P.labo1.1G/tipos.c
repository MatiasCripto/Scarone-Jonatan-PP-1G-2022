#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "aerolineas.h"
#include "menuesYValidaciones.h"
#include "destino.h"
#include "tipos.h"
#include "aviones.h"
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
void mostrarTipo(eTipos tipo, eTipos listaTipo[],int tamTipo)
{
    char desTipo[25];

    asignarNombreTipo(listaTipo,tamTipo, tipo.id, desTipo);

    printf("|%5d | %-15s|\n",
           tipo.id,
           desTipo);
}
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
                mostrarTipo(listaTipo[i], listaTipo, tamTipo);
                flag = 0;
            }

        }
        printf("======================================================\n");
        if(flag)
        {
            printf("No hay tipos para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
