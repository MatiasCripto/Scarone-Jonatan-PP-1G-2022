#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aviones.h"
#include "informes.h"
#include "destino.h"
#include "validaciones.h"
#include "vuelos.h"

int mostrarAvionesAerolineas(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo)
{
    int todoOk = 0;
    int idAerolinea;
    if(lista != NULL && tam > 0 && listaAero != NULL && tamAero > 0)
    {
        system("cls");
        printf("    *** Datos de Aerolineas ***\n");
        mostrarAerolineas(listaAero, tamAero);
        fflush(stdin);
        utn_getNumero(&idAerolinea,"Ingrese una Opcion: \n","Error, Opcion no valida\n",1000,1004,99);

        mostrarAvionesIdAerolinea(idAerolinea,lista,tam,listaAero,tamAero,listaTipo,tamTipo);
        todoOk = 1;
    }
    return todoOk;
}
int mostrarAvionesIdAerolinea(int idAero, eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo)
{
    int todoOk = 0;
    int flag = 1;
    if(lista != NULL && tam > 0 && listaAero != NULL && tamAero > 0)
    {
        system("cls");
        printf("                  *** LISTA DE AVIONES ***\n");
        printf("======================================================\n");
        printf("|  ID  |    AEROLINEA   |   TIPO         | CAPACIDAD |\n");
        printf("------------------------------------------------------\n");
        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].idAerolinea == idAero)
            {
                mostrarAvion(lista[i],listaAero,tamAero,listaTipo,tamTipo);
                flag = 0;
            }

        }
        if(flag)
        {
            printf("No hay nada que mostrar\n");
        }
        printf("======================================================\n");
        todoOk = 1;
    }
    return todoOk;
}
int mostrarAvionesTipos(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo)
{
    int todoOk = 0;
    int idTipo;
    if(lista != NULL && tam > 0 && listaAero != NULL && tamAero > 0)
    {
        system("cls");
        printf("    *** Aviones por tipo ***\n");
        mostrarTipos(listaTipo, tamTipo);
        fflush(stdin);
        utn_getNumero(&idTipo,"Ingrese una Opcion: \n","Error, Opcion no valida\n",5000,5003,99);

        mostrarAvionesIdTipo(idTipo,lista,tam,listaAero,tamAero,listaTipo,tamTipo);
        todoOk = 1;
    }
    return todoOk;
}
int mostrarAvionesIdTipo(int idTipo, eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0 && listaAero != NULL && tamAero > 0)
    {
        system("cls");
        printf("                  *** LISTA DE AVIONES ***\n");
        printf("======================================================\n");
        printf("|  ID  |    AEROLINEA   |   TIPO         | CAPACIDAD |\n");
        printf("------------------------------------------------------\n");
        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].idTipo == idTipo)
            {
                mostrarAvion(lista[i],listaAero,tamAero,listaTipo,tamTipo);
            }

        }

        printf("======================================================\n");
        todoOk = 1;
    }
    return todoOk;
}
int mostrarPromedioAvionesJet(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo)
{
    int todoOk = 0;
    int contador = 0;
    float AcumJet  = 0;
    float porcentaje;
    int idAero;

    mostrarAerolineas(listaAero,tamAero);
    fflush(stdin);
    utn_getNumero(&idAero,"Ingrese una Aerolinea\n", "id no valido\n",1000,1004,99);

    if(lista != NULL && tam > 0 && listaAero != NULL && tamAero >0)
    {
        for(int i = 0; i < tamAero; i++)
        {
            if(lista[i].isEmpty == 0 && (strcmp(listaTipo[i].nombre,"Jet") == 0))
            {
                AcumJet+=lista[i].id;
                contador++;
            }
        }

        porcentaje = (contador  / AcumJet )* 100 ;


        if(contador == 0)
        {
            printf("No hay aviones para mostrar\n");
        }
        else
        {
            porcentaje = (contador / AcumJet )* 100 ;
            printf("El promedio de aviones Jet es: %.2f\n", porcentaje);
        }

        todoOk = 1;
    }
    return todoOk;
}
int mostrarInformes(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo, eDestino listaDest[], int tamDest, eVuelo listaVuelo[], int tamVuelo)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0 && listaAero != NULL && tamAero > 0)
    {
        switch(menuInformes())
        {
        case 1:
            mostrarAvionesAerolineas(lista,tam,listaAero,tamAero,listaTipo,tamTipo);
            break;
        case 2:
            mostrarAvionesTipos(lista, tam, listaAero, tamAero, listaTipo, tamTipo);
            break;
        case 3:
            mostrarPromedioAvionesJet(lista, tam, listaAero, tamAero, listaTipo, tamTipo);
            break;
        case 4:
            mostrarAvionPorAerolinea(lista,tam,listaAero,tamAero,listaTipo,tamTipo);
            break;
        case 5:
            mostrarAerolineaMasCapacidad(lista,tam,listaAero,tamAero);
            break;
        case 6:
            mostrarAerolineaMenorCAntidadAviones(lista,tam,listaAero,tamAero);
            break;
        case 7:
            mostrarVueloAviones(lista,tam,listaAero,tamAero,listaDest,tamDest,listaTipo,tamTipo,listaVuelo,tamVuelo);
            break;
        case 8:
            mostrarPreciosAvion(lista,tam,listaAero,tamAero,listaTipo,tamTipo,listaDest,tamDest);
            break;
        case 9:
            break;
        case 10:
            break;
        }
        todoOk = 1;
    }
    return todoOk;
}
int mostrarAvionPorAerolinea(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipos[], int tamTipo)
{
	int todoOk = 0;

     if(lista != NULL && tam > 0 && listaAero != NULL && tamAero > 0)
     {
         system("cls");
         printf("     ***infome de viones y aerolineas***\n");
         printf("-----------------------------------------\n");

             for(int i = 0; i < tamAero; i++)
             {
                 printf("Aerolinea : %s\n", listaAero[i].nombre);

                 for(int j = 0; j < tam; j++)
                 {
                     if(!lista[j].isEmpty && lista[j].idAerolinea == listaAero[i].id)
                     {
                         mostrarAvion(lista[i],listaAero,tamAero,listaTipos,tamTipo);

                     }

                 }
             }
		todoOk = 1;
	}
	return todoOk;
}
int mostrarAerolineaMenorCAntidadAviones(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero)
{
    int todoOk = 0;
    int minimo;
    int contadores[] = {0,0,0,0,0,0};
    int flag = 0;

    if(lista != NULL && tam > 0 && listaAero != NULL && tamAero > 0)
    {
        system("cls");
        printf("    *** Aerolinea con menos aviones ***\n\n\n");
        for(int i = 0; i < tamAero; i++)
        {
            for(int j = 0; j < tam; j++)
            {
                if(lista[j].isEmpty == 0 && lista[j].idAerolinea == listaAero[i].id)
                {
                    contadores[i]+= lista[j].idTipo;
                }
            }
        }
        for(int i = 0; i < tamAero; i++)
        {
            if(flag == 0 || contadores[i] < minimo)
            {
                minimo = contadores[i];
                flag = 1;
            }
        }
        for(int i = 0; i < tamAero; i++)
        {
            if(contadores[i] == minimo)
            {
                printf("%s\n\n", listaAero[i].nombre);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
int mostrarAerolineaMasCapacidad(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero)
{
    int todoOk = 0;
    int maximo;
    int contadores[] = {0,0,0,0,0};
    int flag = 0;

    if(lista != NULL && tam > 0 && listaAero != NULL && tamAero > 0)
    {
        system("cls");
        printf("    *** Aerolinea Mayor Capacidad ***\n");
        for(int i = 0; i < tamAero; i++)
        {
            for(int j = 0; j < tam; j++)
            {
                if(lista[j].isEmpty == 0 && lista[j].idAerolinea == listaAero[i].id)
                {
                    contadores[i]+= lista[j].capacidad;
                }
            }
        }
        for(int i = 0; i < tamAero; i++)
        {
            if(flag == 0 || contadores[i] > maximo)
            {
                maximo = contadores[i];
                flag = 1;
            }
        }
        for(int i = 0; i < tamAero; i++)
        {
            if(contadores[i] == maximo)
            {
                printf("%s\n", listaAero[i].nombre);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarVueloAviones(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eDestino listaDest[], int tamDest, eTipos listaTipo[], int tamTipo, eVuelo listaVuelo[], int tamVuelo)
{
    int todoOk = 0;
    int idAvion;
    if(lista != NULL && tam > 0 && listaAero != NULL && tamAero > 0)
    {
        system("cls");
        printf("    *** Vuelos por avion ***\n");
        mostrarAviones(lista,tam,listaAero,tamAero,listaTipo,tamTipo);
        fflush(stdin);
        utn_getNumero(&idAvion,"Ingrese una Opcion: \n","Error, Opcion no valida\n",1,50,99);
        for(int i = 0; i > tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].id == idAvion)
            {
                mostrarVuelos(listaVuelo,tamVuelo,listaDest,tamDest);
            }
        }

        todoOk = 1;
    }
    return todoOk;
}
int mostrarPreciosAvion(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo, eDestino listaDest[], int tamDest)
{
    int todoOk = 0;
    int contador = 0;
    float AcumPrecio  = 0;
    int idAvion;

    mostrarAviones(lista,tam,listaAero,tamAero,listaTipo,tamTipo);
    fflush(stdin);
    utn_getNumero(&idAvion,"Ingrese un Avion\n", "id no valido\n",1,100,99);

    if(lista != NULL && tam > 0 && listaAero != NULL && tamAero >0)
    {
        for(int i = 0; i < tam; i++)
        {
            for(int j = 0; j < tamDest; j++)
            {

                if(lista[i].isEmpty == 0 && lista[i].id == idAvion)
                {
                    AcumPrecio+=listaDest[j].precio;
                    contador++;
                }
            }
        }

        if(contador == 0)
        {
            printf("No hay nada para mostrar\n");
        }
        else
        {

            printf("El total de costos es: %.2f\n", AcumPrecio);
        }

        todoOk = 1;
    }
    return todoOk;
}
