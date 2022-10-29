#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int isEmpty;
} eTipos;



#endif // TIPOS_H_INCLUDED
void mostrarTipo(eTipos tipo);
int mostrarTipos(eTipos listaTipo[], int tamTipo);
int asignarNombreTipo(eTipos listaTipo[],int tam, int idTipo, char descTipo[]);
int buscarTipoLibre(eTipos listaTipo[], int tamTipo);
int altaTipo(eTipos listatipo[], int tamTipo, int* pId);
int buscarTipoId(int id, eTipos listaTipo[], int tamTipo);
int bajaTipo(eTipos listaTipo[], int tamTipo);
int modificarTipo(eTipos listaTipo[], int tamTipo);
int menuModificacionTipos();
int harcodearTipo(int* pTipo, eTipos listaTipo[], int tamTipo, int cant);
