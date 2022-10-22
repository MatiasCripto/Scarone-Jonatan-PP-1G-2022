#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#include "aerolineas.h"
#include "menuesYValidaciones.h"
#include "destino.h"
#include "tipos.h"
#include "aviones.h"



int menu()
{
    char opcion;
    system("cls");
    printf("     *** ABM AVION ***     \n\n");
    printf("A- ALTA AVION\n");
    printf("B- MODIFICAR AVION\n");
    printf("C- BAJA AVION\n");
    printf("D- LISTAR AVIONES\n");
    printf("E- LISTAR AEROLINEAS\n");
    printf("F- LISTAR TIPOS\n");
    printf("G- LISTAR DESTINOS\n");
    printf("H- ALTA VUELO\n");
    printf("I- LISTAR VUELOS\n");
    printf("J- Salir\n");
    printf("Ingrese Opcion: \n");
    scanf("%c", &opcion);
    return opcion;
}






int menuModificacion()
{
    int opcion;
    system("cls");
    utn_getNumero(&opcion,"     *** Modificar Aviones ***     \n\n1- MODIFICAR TIPO\n2- MODIFICAR CAPACIDAD\nIngrese Opcion: \n","Error, campo no valido",1,2,99);

    return opcion;
}

int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena, longitud, stdin)==cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 0;
    }
    return -1;

}




int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);// cambiar a atof
            retorno = 0;
        }

    }
    return retorno;
}

int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) < 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] <'0' || cadena[i] > '9'/* || cadena[i] != ','*/)// para flotante, contar las comas y que me ermita una sola
            {
                retorno =0;
                break;
            }
            i++;

        }
    }
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = -1;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s", mensaje);
        if(getInt(&bufferInt)==0)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        printf("%s", mensajeError);
    }
    return retorno;
}
