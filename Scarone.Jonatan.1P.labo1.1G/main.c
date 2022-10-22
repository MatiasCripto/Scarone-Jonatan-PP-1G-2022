#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "aerolineas.h"
#include "menuesYValidaciones.h"
#include "destino.h"
#include "tipos.h"
#include "aviones.h"



#define TAM_AER 5
#define TAM_TIPO 4
#define TAM_DEST 4
#define TAM 20


typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;


typedef struct
{
    int id;
    int idAvion;
    int idDestino;
    int fecha;
} eVuelo;
//////////



int main()
{
    char seguir = 's';
    int nexIdAerolinea = 1000;
    int nexIdTipo = 5000;
    int nexIdDestino = 20000;
    int nexIdAvion = 1;


    eAerolinea listaAerolinea[TAM_AER] = { {1000,"Lan"},{1001,"Iberia"}, {1002,"Norwegian"}, {1003,"American"}, {1004,"Austral"} };

    eTipos listaTipo[TAM_TIPO] = { {5000,"Jet"}, {5001,"Helice"}, {5002,"Planeador"}, {5003,"Carga"} };

    eDestino listaDestino[TAM_DEST] = { {2000,"Calafate:", 22250}, {20001,"Miami:", 103000}, {20002,"Milan:", 84400}, {20003,"Amsterdam:", 95600} };

    eAvion lista[TAM];

    if(!inicializarAvion(lista, TAM))
    {
        printf("Error al cargar datos ");
    }


    do
    {
        switch(menu())
        {
        case 'A':
            if(!altaAvion(lista, TAM, &nexIdAvion))
            {
                printf("No se pudo realizar el Alta\n");
            }
            else
            {
                printf("El Alta se realizo con exito\n");
            }
            break;
        case 'B':
            if(!modificarAvion(lista,TAM,listaAerolinea,TAM_AER,listaTipo,TAM_TIPO))
            {
                printf("No se pudo realizar la modificacion\n");
            }
            else
            {
                printf("La modificacion se realizo con exito\n");
            }
            break;
        case 'C':
             if(!bajaAvion(lista,TAM,listaAerolinea,TAM_AER,listaTipo,TAM_TIPO))
             {
                 printf("Baja cancelada por el usuario\n");
             }
             else
             {
                 printf("Baja exitosa\n");
             }

            break;
        case 'D':
            mostrarAviones(lista,TAM,listaAerolinea,TAM_AER,listaTipo,TAM_TIPO);
            break;
        case 'E':
            mostrarAerolineas(listaAerolinea, TAM_AER);
            break;
        case 'F':
            mostrarTipos(listaTipo,TAM_TIPO);
            break;
        case 'G':
            mostrarDestinos(listaDestino, TAM_DEST);
            break;
        case 'H':

            break;
        case 'I':

            break;
        case 'J':
            printf("Salir\n");
            seguir = 'n';
            break;
        default:
            printf("Opcion Invalida!!!\n");
        }
        system("pause");
    }
    while(seguir == 's');


    return 0;
}

