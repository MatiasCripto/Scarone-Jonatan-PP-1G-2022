#ifndef AEROLINEAS_H_INCLUDED
#define AEROLINEAS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[20];
    int isEmpty;
} eAerolinea;



#endif // AEROLINEAS_H_INCLUDED
void mostrarAerolinea(eAerolinea Aerolinea, eAerolinea listaAero[],int tamAero);
int mostrarAerolineas(eAerolinea listaAero[], int tamAero);
int asignarNombreAerolineas(eAerolinea listaAero[],int tam, int idAerolinea, char descAerolinea[]);
