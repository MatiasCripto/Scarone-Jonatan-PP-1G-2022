#ifndef VUELOS_H_INCLUDED
#define VUELOS_H_INCLUDED
#include "fecha.h"
#include "aviones.h"
#include "destino.h"
#include "tipos.h"
#include "aerolineas.h"

typedef struct
{
    int id;
    int idAvion;
    int idDestino;
    eFecha fechaVuelo;
    int isEmpty;
} eVuelo;

#endif // VUELOS_H_INCLUDED

int buscarVueloId(int id, eVuelo vuelos[], int tamVuelo);
int buscarVueloLibre(eVuelo vuelos[], int tamVuelo);
int mostrarVuelos(eVuelo Vuelo[], int tamVuelo, eDestino listaDest[], int tamDest);
void mostrarVuelo(eVuelo vuelo, int tamVuelo, eDestino listaDest[],int tamDest);
int altaVuelo(eVuelo vuelo[], int tamVuelo, eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo, eDestino listaDest[], int tamDest, int* pId);
int inicializarVuelo(eVuelo vuelo[], int tamVuelo);
int harcodearVuelos(int* pVuelos, eVuelo listaVuelos[], int tamVuelos, int cant);






