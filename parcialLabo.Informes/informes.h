#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "vuelos.h"



#endif // INFORMES_H_INCLUDED
int mostrarAvionesIdAerolinea(int idAero, eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo);
int mostrarAvionesAerolineas(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo);
int mostrarAvionesIdTipo(int idTipo, eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo);
int mostrarAvionesTipos(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo);
int mostrarPromedioAvionesJet(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo);
int mostrarInformes(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo, eDestino listaDest[], int tamDest, eVuelo listaVuelo[], int tamVuelo);
int mostrarAvionPorAerolinea(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipos[], int tamTipo);
int mostrarAerolineaMenorCAntidadAviones(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero);
int mostrarAerolineaMasCapacidad(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero);
int mostrarVueloAviones(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eDestino listaDest[], int tamDest, eTipos listaTipo[], int tamTipo, eVuelo listaVuelo[], int tamVuelo);
int mostrarPreciosAvion(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo, eDestino listaDest[], int tamDest);
