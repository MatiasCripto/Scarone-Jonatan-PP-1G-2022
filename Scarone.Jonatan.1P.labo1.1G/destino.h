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
void mostrarDestino(eDestino destino/*, eDestino listaDestino[],int tamDest*/);
int mostrarDestinos(eDestino listaDest[], int tamDest);
int asignarNombreDestino(eDestino listaDestino[],int tam, int idDestino, char descDestino[]);
int buscarDestinoLibre(eDestino listaDest[], int tamDest);
int buscarDestinoId(int id, eDestino listaDest[], int tamDest);
int harcodearDestino(int* pDestino, eDestino lista[], int tamDest, int cant);
