#ifndef AVIONES_H_INCLUDED
#define AVIONES_H_INCLUDED
#include "tipos.h"
#include "aerolineas.h"


typedef struct
{
    int id;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int isEmpty;
} eAvion;

#endif // AVIONES_H_INCLUDED

int menuModificacionAvion();
int altaAvion(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo, int* pId);
void mostrarAvion(eAvion avion, eAerolinea listaAero[], int tamAero, eTipos listaTipo[],int tamTipo);
int mostrarAviones(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo);
int bajaAvion(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo);
int modificarAvion(eAvion lista[], int tam, eAerolinea listaAero[], int tamAero, eTipos listaTipo[], int tamTipo);
int buscarAvionId(int id, eAvion lista[], int tam);
int inicializarAvion(eAvion lista[], int tam);
int buscarLibre(eAvion lista[], int tam);
int ordenarAvionesDobleCriterio(eAvion lista[], int tam);
int harcodearAvion(int* pAvion, eAvion lista[], int tam, int cant);

