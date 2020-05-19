#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"

/** \brief muestra las marcas
 *
 * \param array de marcas
 * \param tamaño del array
 *
 */
void mostrarMarcas(eMarcas marca[], int tamMarca)
{
    printf("\n  ~~~ MARCAS ~~~\n");
    printf(" ID           MARCA\n");

    for(int i = 0; i < tamMarca; i++)
    {
        printf("%4d       %10s\n", marca[i].id, marca[i].descripcion);
    }
}
