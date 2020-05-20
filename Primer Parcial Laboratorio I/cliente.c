#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"

void mostrarCliente(eClientes x)
{
    printf("  %4d    %10s    %c\n",x.id, x.nombre, x.sexo);
}


void mostrarClientes(eClientes x[], int tamCliente)
{
    int flag = 0;

    printf("  ~~~ LISTADO DE CLIENTES~~~ \n\n");
    printf("   ID      NOMBRE     SEXO\n");

    for(int i = 0; i < tamCliente; i++)
    {
        mostrarCliente(x[i]);
        flag = 1;

    }

    if(!flag)
    {
        printf("No hay clientes para mostrar");
    }

    printf("\n\n");
}
