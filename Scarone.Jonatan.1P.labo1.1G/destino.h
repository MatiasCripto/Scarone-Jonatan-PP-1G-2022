#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[25];
    float precio;
    int isEmpty;
} eDestino;


#endif // DESTINO_H_INCLUDED
void mostrarDestino(eDestino destino, eDestino listaDestino[],int tamDest);
int mostrarDestinos(eDestino listaDest[], int tamDest);
int asignarNombreDestino(eDestino listaDestino[],int tam, int idDestino, char descDestino[]);
