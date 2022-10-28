#ifndef MENUESYVALIDACIONES_H_INCLUDED
#define MENUESYVALIDACIONES_H_INCLUDED



#endif // MENUESYVALIDACIONES_H_INCLUDED
int menu();
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int esNumerica(char* cadena);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int getString(char *pBuffer, int limite);
int utn_getNombre(  char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);
int isValidNombre(char *pBuffer, int limite);
