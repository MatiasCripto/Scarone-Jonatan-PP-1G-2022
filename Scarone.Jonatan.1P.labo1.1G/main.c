#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "aerolineas.h"
#include "validaciones.h"
#include "destino.h"
#include "tipos.h"
#include "aviones.h"
#include "fecha.h"
#include "vuelos.h"



#define TAM_AER 5
#define TAM_TIPO 4
#define TAM_DEST 4
#define TAM 20
#define TAM_V 20






int main()
{
    char seguir = 's';
    int nexIdAvion = 11;
    int nexIdVuelos = 10005;
    int nexIdAerolinea = 1005;
    int nexIdDestino = 20004;
    int nexIdTipo = 5004;




    eAerolinea listaAerolinea[TAM_AER];

    eTipos listaTipo[TAM_TIPO];

    eDestino listaDestino[TAM_DEST];

    eAvion lista[TAM];

    eVuelo listaVuelo[TAM_V];

    if(!inicializarAvion(lista, TAM))
    {
        printf("Error al cargar datos ");
    }
    if(!inicializarVuelo(listaVuelo, TAM_V))
    {
        printf("Error al cargar datos ");
    }


    harcodearAerolineas(&nexIdAerolinea, listaAerolinea, TAM_AER,5);
    harcodearDestino(&nexIdDestino,listaDestino, TAM_DEST,4);
    harcodearVuelos(&nexIdVuelos,listaVuelo, TAM_V,5);
    harcodearAvion(&nexIdAvion,lista,TAM,10);
    harcodearTipo(&nexIdTipo,listaTipo,TAM_TIPO,4);


    do
    {
        switch(menu())
        {
        case 'A':
            if(!altaAvion(lista, TAM, listaAerolinea, TAM_AER, listaTipo, TAM_TIPO, &nexIdAvion))
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
            if(!altaVuelo(listaVuelo,TAM_V,lista, TAM, listaAerolinea, TAM_AER, listaTipo, TAM_TIPO, listaDestino, TAM_DEST, &nexIdVuelos))
            {
                printf("No se pudo realizar el Alta\n");
            }
            else
            {
                printf("El Alta se realizo con exito\n");
            }
            break;
        case 'I':
            mostrarVuelos(listaVuelo, TAM_V,listaDestino, TAM_DEST);
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

