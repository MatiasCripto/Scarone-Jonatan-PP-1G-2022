#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#include "aerolineas.h"
#include "validaciones.h"
#include "destino.h"
#include "tipos.h"
#include "aviones.h"



/** \brief opciones a elegir segun pida el usuario
 *
 * \return int retorna la opcion elegida
 *
 */
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
    printf("J- INFORMES\n");
    printf("K- Salir\n");
    printf("Ingrese Opcion: \n");
    scanf("%c", &opcion);
    opcion = toupper(opcion);
    fflush(stdin);
    return opcion;
}


/** \brief
 *
 * \param cadena char* cadena a recorrer
 * \param longitud int longitud de la cadena
 * \return int -1 Error: NO es numerica. 0 Es valido
 *
 */
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
/** \brief Obtiene el dato como una cadena de caracteres, para luego
 * 	      validarlo y parsear/formatear el dato a una variable entera.
 *
 * \param pResultado int* Puntero a entero, con el valor a setear.
 * \return int retorna -1 si la validacion fallo y 0 si salio bien
 *
 */
int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }

    }
    return retorno;
}

/** \brief Recibe una cadena de caracteres y devuelve 1
 * 		  en el caso de que el texto este compuesto solo por números.
 *
 * \param cadena char* Cadena de carateres a recorrer.
 * \return int retorna 1 si la validacion fallo y 0 si salio todo bien
 *
 */
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

/** \brief Pide al usuario un numero
 *
 * \param pResultado int* Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param mensaje char* El mensaje que imprime para pedir un valor
 * \param mensajeError char* mensaje que imprime si el rango no es valido
 * \param minimo int valor minimo valido (inclusive)
 * \param maximo int valor maximo valido (no inclusive)
 * \param reintentos int cantidad de reintentos
 * \return int retorna 0  si esta todo OK. -1: Si hubo un error
 *
 */
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
/** \brief valida una cadena de caracteres
 *
 * \param pBuffer char* puntero a guardar el dato
 * \param limite int limite de la cadena
 * \return int retorna 0 si fallo y 1 si salio todo bien
 *
 */
int isValidNombre(char *pBuffer, int limite)
{
    int retorno = 0;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 &&
            ((pBuffer[0]>='A' && pBuffer[0]<='Z') || (pBuffer[0]>='a' && pBuffer[0]<='z')))
    {
        retorno = 1;
    }
    return retorno;
}
/** \brief pide una cadena al usuario y la valida
 *
 * \param pNombre char* cadena a recibir
 * \param limite int limite de caracteres de la cadena
 * \param mensaje char* mensaje de peticion al usuario
 * \param mensajeError char* mensaje de error
 * \param reintentos int cantidad de reintentos
 * \return int retorna -1 si fallo, y 0 si salio todo bien
 *
 */
int utn_getNombre(  char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pNombre != NULL && limite > 0 && mensaje != NULL &&
            mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if(getString(buffer, limite) == 0 &&
                    isValidNombre(buffer, limite))
            {
                strncpy(pNombre, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
/** \brief valida que sea una cadena
 *
 * \param pBuffer char* puntero a guardar el dato
 * \param limite int limite de la cadena
 * \return int  retorna -1 si fallo, y 0 si salio todo bien
 *
 */
int getString(char *pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0 )
    {
        fflush(stdin);
        fgets(bufferString, 4096, stdin);
        len = strlen(bufferString);
        if(len <= limite)
        {
            if(len != limite-1 || bufferString[limite-2] == '\n')
            {
                bufferString[len-1] = '\0';
            }
            strncpy(pBuffer, bufferString, limite);
            retorno = 0;
        }
        else
        {
            printf("Se admite un maximo de %d caracteres\n", limite - 1);
        }
    }
    return retorno;
}
int menuInformes()
{
    int opcion;
    system("cls");
    printf("     *** ABM AVION ***     \n\n");
    printf("1- MOSTRAR AVIONES DE AEROLINEA\n");
    printf("2- MOSTRAR AVION POR TIPO\n");
    printf("3- INFORMAR PROMEDIO DE AVIONES JET\n");
    printf("4- MOSTRAR LISTADO DE AVIONES POR AEROLINEA\n");
    printf("5- INFORMAR AEROLINEA MAS PASAJEROS\n");
    printf("6- MOSTRAR AEROLINEA MENOR CANTIDAD DE AVIONES\n");
    printf("7- MOSTRAR AVION Y SUS VUELOS\n");
    printf("8- INFORMAR PRECION DE VIAJE DE AVION\n");
    printf("9- MOSTRAR AVIONES QUE VIAJARON AL DESTINO Y FECHA\n");
    printf("10- VUELOS QUE SE REALIZARON EN UNA FECHA\n");
    printf("11- Salir\n");
    printf("Ingrese Opcion: \n");
    scanf("%d", &opcion);
    return opcion;
}

