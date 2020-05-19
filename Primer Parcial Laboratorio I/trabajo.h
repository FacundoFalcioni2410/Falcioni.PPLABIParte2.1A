#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "servicio.h"
#include "auto.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFechaT;


typedef struct
{
    int id;
    int patente;
    int idServicio;
    int isEmpty;
    eFechaT fechaTrabajo;
}eTrabajos;

#endif // TRABAJO_H_INCLUDED

/** \brief inicializa el array de trabajos en vacios
 *
 * \param array de trabajo
 * \param tamaño del array
 *
 */
void inicializarTrabajos(eTrabajos x[], int tamTrabajo);


/** \brief busca un lugar libre en el array de trabajos
 *
 * \param array de trabajos
 * \param tamaño del array
 * \return devuelve -1 si no hay lugar, de haber lugar retorna el indice del array que esta libre
 *
 */
int buscarEspacioLibreTrabajos(eTrabajos x[], int tamTrabajo);

/** \brief muestra un elemento del array autos
 *
 * \param elemento del array trabajos
 * \param parametro requerido por la funcion "cargarDescripcionServicio"
 * \param parametro requerido por la funcion "cargarDescripcionServicio"
 * \param parametro requerido por la funcion "cargarDescripcionServicio"
 *
 */
void mostrarTrabajo(eTrabajos x,eAutos autos, eServicios servicio[], int tamServicio);

/** \brief muestra un elemento del array autos
 *
 * \param array trabajos
 * \param tamaño del array
 * \param parametro requerido por la funcion "mostrarTrabajo"
 * \param parametro requerido por la funcion "mostrarTrabajo"
 * \param parametro requerido por la funcion "mostrarTrabajo"
 *
 */
void mostrarTrabajos(eTrabajos x[],int tamTrabajo, eAutos autos[], eServicios servicios[], int tamServicios);

/** \brief se realiza el alta de un auto agregandolo al array correspondiente
 *
 * \param array de autos
 * \param tamaño del array de autos
 * \param array de trabajos
 * \param tamaño del array de trabajos
 * \param id autoincremental
 * \param parametro requerido por la funcion "mostrarAutos"
 * \param parametro requerido por la funcion "mostrarAutos"
 * \param parametro requerido por la funcion "mostrarAutos"
 * \param parametro requerido por la funcion "mostrarAutos"
 * \param parametro requerido por la funcion "mostrarServicios"
 * \param parametro requerido por la funcion "mostrarServicios"
 * \return devuelve 1 si el alta se realizo con exito, de lo contrario retorna un 0
 *
 */
int altaTrabajo(eAutos x[], int tam, eTrabajos trabajo[], int tamTrabajo, int proximoId, eMarcas marca[], int tamMarca, eColores color[], int tamColor, eServicios servicios[], int tamServicios);

/** \brief carga el nombre del servicio en una cadena
 *
 * \param cadena a la cual se le quiere guardar el servicio
 * \param id del servicio
 * \param array de servicios
 * \param tamaño del array de servicios
 *
 */
void cargarDescripcionServicio(char descripcion[],int id, eServicios servicio[], int tamServicio);

/** \brief valida que la fecha sea correcta, teniendo en cuenta la cantidad de dia de los meses y si es bisiesto o no
 *
 * \param dia a evaluar
 * \param mes a evaluar
 * \param año a evaluar
 * \return devuelve 1 si la fecha es correcta, de lo contrario devuelve 0
 *
 */
int validateDate(int day, int month, int year);
