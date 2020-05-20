#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include "marca.h"
#include "color.h"
#include "cliente.h"

typedef struct
{
    int anio;
}eFecha;


typedef struct
{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int isEmpty;
    int idCliente;
    eFecha anioFabricacion;
}eAutos;

#endif // AUTO_H_INCLUDED

/** \brief inicializa el array de autos en vacios
 *
 * \param array de autos
 * \param tamaño del array
 *
 */
void inicializarAutos(eAutos x[], int tam);

/** \brief busca un lugar libre en el array de autos
 *
 * \param array de autos
 * \param tamaño del array
 * \return devuelve -1 si no hay lugar, de haber lugar retorna el indice del array que esta libre
 *
 */
int buscarEspacioLibreAutos(eAutos x[], int tam);

/** \brief busca un auto en el array por el id
 *
 * \param array de autos en el que se realiza la busqueda
 * \param tamaño del array
 * \param id del auto que se desea buscar
 * \return devuelve -1 si no se encuentra un auto con ese id, en caso de encontrarlo devuelve el indice de dicho auto
 *
 */
int buscarAutoPorId(eAutos x[], int tam, int id);

/** \brief muestra un elemento del array autos
 *
 * \param elemento del array autos
 * \param parametro requerido por la funcion "cargarDescripcionMarca"
 * \param parametro requerido por la funcion "cargarDescripcionMarca"
 * \param parametro requerido por la funcion "cargarDescripcionColor"
 * \param parametro requerido por la funcion "cargarDescripcionColor"
 *
 */
void mostrarAuto(eAutos x,eMarcas marca[], int tamMarca, eColores color[], int tamColor,eClientes cliente[], int tamCliente);

/**  \brief muestra el array de autos entero, siempre y cuando cada elemento no este vacio
  *  \param elemento del array autos
  *  \param tamaño del array autos
  *  \param parametro requerido por la funcion "cargarDescripcionMarca"
  *  \param parametro requerido por la funcion "cargarDescripcionMarca"
  *  \param parametro requerido por la funcion "cargarDescripcionColor"
  *  \param parametro requerido por la funcion "cargarDescripcionColor"
  */
void mostrarAutos(eAutos x[],int tam, eMarcas marca[], int tamMarca, eColores color[], int tamColor,eClientes cliente[], int tamCliente);

/** \brief muestra el menu de las marcas a elegir
 *  \return devuelve la opcion elegida por el usuario
 */
int menuMarcas();

/** \brief se realiza el alta de un auto agregandolo al array correspondiente
 *
 * \param array de autos
 * \param tamaño del array de autos
 * \param id autoincremental
 * \param parametro requerido por la funcion "mostrarMarcas"
 * \param parametro requerido por la funcion "mostrarMarcas"
 * \param parametro requerido por la funcion "mostrarColores"
 * \param parametro requerido por la funcion "mostrarColores"
 * \return devuelve 1 si el alta se realizo con exito, de lo contrario retorna un 0
 *
 */
int altaAuto(eAutos x[], int tam, int proximoId, eMarcas marca[], int tamMarca, eColores color[], int tamColor,eClientes cliente[], int indiceCliente);

/** \brief menu en el que se muestra las opciones a modificar del auto solicitado
 * \return retorna la opcion ingresada por el usuario
 *
 */
int menuModificarAuto();

/** \brief realiza una modificacion del auto solicitado
 *
 * \param elemento del array autos
 * \param tamaño del array autos
 * \param parametro requerido por la funcion "mostrarAuto"
 * \param parametro requerido por la funcion "mostrarAuto"
 * \param parametro requerido por la funcion "mostrarAuto"
 * \param parametro requerido por la funcion "mostrarAuto"
 * \return devuelve 1 si se realizo la modificacion con exito, de lo contrario retorna un 0
 *
 */
int modificarAuto(eAutos x[],int tam, eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente);

/** \brief da de baja un auto solicitado
 *
 * \param elemento del array autos
 * \param tamaño del array autos
 * \param parametro requerido por la funcion "mostrarAuto"
 * \param parametro requerido por la funcion "mostrarAuto"
 * \param parametro requerido por la funcion "mostrarAuto"
 * \param parametro requerido por la funcion "mostrarAuto"
 * \return devuelve 1 si se realizo la baja con exito, de lo contrario retorna un 0
 *
 */
int bajaAuto(eAutos x[],int tam, eMarcas marca[], int tamMarca, eColores color[], int tamColor,eClientes cliente[], int tamCliente);

/** \brief carga el nombre de la marca en una cadena
 *
 * \param cadena a la cual se le quiere guardar la marca
 * \param id de la marca
 * \param array de marcas
 * \param tamaño del array de marcas
 *
 */
void cargarDescripcionMarca(char descripcion[],int id, eMarcas marca[], int tamMarca);

/** \brief carga el nombre del color en una cadena
 *
 * \param cadena a la cual se le quiere guardar el color
 * \param id del color
 * \param array de colores
 * \param tamaño del array de colores
 *
 */
void cargarDescripcionColor(char descripcion[],int id, eColores color[], int tamColor);

void cargarDescripcionCliente(char descripcion[],int id, eClientes cliente[], int tamCliente);
