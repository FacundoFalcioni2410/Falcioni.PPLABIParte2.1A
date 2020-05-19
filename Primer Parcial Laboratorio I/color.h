#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColores;

#endif // COLOR_H_INCLUDED

/** \brief muestra los colores
 *
 * \param array de colores
 * \param tamaño del array
 *
 */
void mostrarColores(eColores color[], int tamColor);
