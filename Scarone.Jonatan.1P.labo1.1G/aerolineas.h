#ifndef AEROLINEAS_H_INCLUDED
#define AEROLINEAS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[20];
    int isEmpty;
} eAerolinea;



#endif // AEROLINEAS_H_INCLUDED
void mostrarAerolinea(eAerolinea aerolinea/*, eAerolinea listaAero[],int tamAero*/);
int mostrarAerolineas(eAerolinea listaAero[], int tamAero);
int asignarNombreAerolineas(eAerolinea listaAero[],int tam, int idAerolinea, char descAerolinea[]);
int harcodearAerolineas(int* pAerolineas, eAerolinea lista[], int tam, int cant);
int buscarAerolineaLibre(eAerolinea listaAero[], int tam);
int buscarAerolineaId(int id, eAerolinea listaAero[], int tamAero);

