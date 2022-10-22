#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int isEmpty;
} eTipos;



#endif // TIPOS_H_INCLUDED
void mostrarTipo(eTipos tipo, eTipos listaTipo[],int tamTipo);
int mostrarTipos(eTipos listaTipo[], int tamTipo);
int asignarNombreTipo(eTipos listaTipo[],int tam, int idTipo, char descTipo[]);
