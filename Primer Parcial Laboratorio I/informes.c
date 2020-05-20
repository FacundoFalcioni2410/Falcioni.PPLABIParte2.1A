#include <stdio.h>
#include <stdlib.h>

#include "auto.h"
#include "color.h"
#include "marca.h"
#include "cliente.h"
#include "trabajo.h"
#include "servicio.h"
#include "informes.h"
#include "utn.h"


int menuInformes()
{
    int opcion;

    system("cls");
    printf("1. AUTOS POR COLOR SELECCIONADO\n");
    printf("2. AUTOS DE MARCA SELECCIONADA\n");
    printf("3. AUTO/S MAS VIEJO\n");
    printf("4. AUTOS SEPARADOS POR MARCA\n");
    printf("5. CANTIDAD DE AUTOS DE COLOR Y MARCA SELECCIONADA\n");
    printf("6. MARCA/S MAS ELEGIDA POR CLIENTES\n");
    printf("7. TRABAJOS REALIZADOS SOBRE UN AUTO\n");
    printf("8. IMPORTE TOTAL SOBRE UN AUTO\n");
    printf("9. SALIR\n\n");
    utn_getEntero(&opcion, 3, "Ingrese una opcion: ", "Error. No es una opcion valida.\n", 1, 9);

    return opcion;
}

void informar(eAutos x[],int tam,eTrabajos trabajo[], int tamTrabajo,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente, eServicios servicio[],int tamServicio)
{
    char respuesta = 'n';

    do
    {
        switch(menuInformes())
        {
        case 1:
            mostrarAutosPorColorSeleccionado(x,tam,marca,tamMarca,color,tamColor,cliente,tamCliente);
            break;
        case 2:
            mostrarAutoPorMarcaSeleccionada(x,tam,marca,tamMarca,color,tamColor,cliente,tamCliente);
            break;
        case 3:
            informarAutosMasViejos(x,tam,marca,tamMarca,color,tamColor,cliente,tamCliente);
            break;
        case 4:
            mostrarAutosPorMarca(x,tam,marca,tamMarca,color,tamColor,cliente,tamCliente);
            break;
        case 5:
            cantidadAutosColorYMarca(x,tam,marca,tamMarca,color,tamColor,cliente,tamCliente);
            break;
        case 6:
            mostrarMarcasMasElegidas(x,tam,marca,tamMarca,color,tamColor,cliente,tamCliente);
            break;
        case 7:
            mostrarTrabajosEnUnAuto(x,tam,trabajo,tamTrabajo,marca,tamMarca,color,tamColor,cliente,tamCliente,servicio,tamServicio);
            break;
        case 8:
            informarImporteServiciosDeAuto(x,tam,trabajo,tamTrabajo,marca,tamMarca,color,tamColor,cliente,tamCliente,servicio,tamServicio);
            break;
        case 9:
            printf("Desea salir?\n");
            fflush(stdin);
            scanf("%c",&respuesta);
            break;
        }
        printf("\n");
        system("pause");
        system("cls");

    }while(respuesta == 'n');
}


void mostrarAutosPorColorSeleccionado(eAutos x[], int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente)
{
    int idColor;
    char nombreColor[20];

    system("cls");

    mostrarColores(color,tamColor);
    if(utn_getEntero(&idColor,3,"Ingrese el ID del color que desea ver los autos: ","ERROR, ID COLOR INVALIDO",5000,5004) == 0)
    {
        cargarDescripcionColor(nombreColor,idColor,color,tamColor);

        printf("\n ~~~ AUTOS DE COLOR %10s ~~~\n",nombreColor);

        for(int i = 0; i < tam; i++)
        {
            if(x[i].isEmpty == 0 && x[i].idColor == idColor)
            {
                mostrarAuto(x[i],marca,tamMarca,color,tamColor,cliente,tamCliente);
            }
        }
    }
}


void mostrarAutoPorMarcaSeleccionada(eAutos x[],int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente)
{
    int idMarca;
    char nombreMarca[20];

    if(utn_getEntero(&idMarca,3,"Ingrese el ID del color que desea ver los autos: ","ERROR, ID COLOR INVALIDO",5000,5004) == 0)
    {
        cargarDescripcionMarca(nombreMarca,idMarca,marca,tamMarca);

        printf("\n ~~~ AUTOS DE COLOR %10s ~~~\n",nombreMarca);


        for(int i = 0; i < tam; i++)
        {
            if(x[i].isEmpty == 0 && x[i].idMarca == idMarca)
            {
                mostrarAuto(x[i],marca,tamMarca,color,tamColor,cliente,tamCliente);
            }
        }
    }
}

void informarAutosMasViejos(eAutos x[],int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente)
{
    system("cls");

    eAutos autoMasViejo;
    int flag = 0;

    for(int i = 0; i < tam; i++)
    {
        if(x[i].isEmpty == 0)
        {
            if(flag == 0 || x[i].anioFabricacion.anio < autoMasViejo.anioFabricacion.anio)
            {
                autoMasViejo = x[i];
            }
        }
    }
    printf("El auto mas viejo es: \n\n");
    printf("   ID    PATENTE     NOMBRE CLIENTE      MARCA          COLOR       MODELO\n");
    for(int i = 0; i < tam; i++)
    {
        if(x[i].isEmpty == 0 && x[i].anioFabricacion.anio == autoMasViejo.anioFabricacion.anio)
        {
            mostrarAuto(x[i],marca,tamMarca,color,tamColor,cliente,tamCliente);
        }
    }

    mostrarAuto(autoMasViejo,marca,tamMarca,color,tamColor,cliente,tamCliente);
}


void mostrarAutosPorMarca(eAutos x[],int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente)
{
    int flag = 0;

    printf("   ID    PATENTE     NOMBRE CLIENTE      MARCA          COLOR       MODELO\n");

    for(int m = 0; m < tamMarca; m++)
    {
        printf("\nMostrando la marca: %10s\n",marca[m].descripcion);
        for(int a = 0; a < tam; a++)
        {
            if(x[a].isEmpty == 0 && x[a].idMarca == marca[m].id)
            {
                mostrarAuto(x[a],marca,tamMarca,color,tamColor,cliente,tamCliente);
                flag = 1;
            }
            if(!flag)
            {
                printf("No hay autos ingresados con esta marca.\n");
            }
        }
        flag = 0;
    }
}


void cantidadAutosColorYMarca(eAutos x[],int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente)
{
    int contador = 0;

    int idMarca;
    int idColor;

    mostrarMarcas(marca,tamMarca);
    utn_getEntero(&idMarca, 3,"Ingrese el id de la marca","ERROR. ID invalido.\n",1000,1004);

    mostrarColores(color,tamColor);
    utn_getEntero(&idColor, 3,"Ingrese el id del color","ERROR. ID invalido.\n",5000,5004);

    for(int i = 0; i<tam; i++)
    {
        if(x[i].isEmpty == 0 && x[i].idMarca == idMarca && x[i].idColor == idColor)
        {
            contador++;
        }
    }

    printf("\n\nHay un total de: %d autos con esa marca y color", contador);
}

void mostrarMarcasMasElegidas(eAutos x[],int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente)
{
    int contadorMarca[] = { {0}, {0}, {0}, {0}, {0} };
    int flagMarca = 0;
    int flag = 0;
    int marcaMaxima;
    char descripcionMarca[20];

    for(int m = 0; m < tamMarca; m++)
    {
        printf("\nMarca: %10s\n",marca[m].descripcion);
        for(int a = 0; a < tam; a++)
        {
            if(x[a].isEmpty == 0 && x[a].idMarca == marca[m].id)
            {
                contadorMarca[m]++;
                flag = 1;
            }
            if(!flag)
            {
                printf("No hay autos ingresados con esta marca.\n");
            }
        }
        flag = 0;

        if(flagMarca == 0 || contadorMarca[m] > marcaMaxima)
        {
            marcaMaxima = contadorMarca[m];
            cargarDescripcionMarca(descripcionMarca,marca[m].id,marca,tamMarca);
        }
    }

    printf("La marca mas elegida es: %10s",descripcionMarca);

    for(int m = 0; m < tamMarca; m++)
    {
        if(contadorMarca[m] == marcaMaxima)
        {
            printf(" y %10s",marca[m].descripcion);
        }
    }
}

// INFORMES BONUS //

void mostrarTrabajosEnUnAuto(eAutos x[],int tam,eTrabajos trabajo[], int tamTrabajo,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente, eServicios servicio[],int tamServicio)
{
    int idAuto;

    mostrarAutos(x,tam,marca,tamMarca,color,tamColor,cliente,tamCliente);

    if(utn_getEntero(&idAuto,3,"\nIngrese el ID del auto: ","ERROR, ID COLOR INVALIDO",1000,20000) == 0)
    {
        if(buscarAutoPorId(x,tam,idAuto)!= -1)
        {
            printf("  ID          PATENTE DEL AUTO       SERVICIO      FECHA DE TRABAJO\n\n");
            for(int i = 0; i < tamTrabajo; i++)
            {
                if(x[i].patente == trabajo[i].patente)
                {
                    mostrarTrabajo(trabajo[i],servicio,tamServicio);
                }

            }

        }
    }

}

void informarImporteServiciosDeAuto(eAutos x[],int tam,eTrabajos trabajo[], int tamTrabajo,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente, eServicios servicio[],int tamServicio)
{
    int idAuto;
    int indiceAutoBuscado;
    float importe;

    mostrarAutos(x,tam,marca,tamMarca,color,tamColor,cliente,tamCliente);

    if(utn_getEntero(&idAuto,3,"\nIngrese el ID del auto: ","ERROR, ID COLOR INVALIDO",1000,20000) == 0)
    {
        indiceAutoBuscado = buscarAutoPorId(x,tam,idAuto);
        if(indiceAutoBuscado != -1)
        {
            for(int s = 0; s<tamServicio; s++)
            {
                printf("\nServicio: %10s",servicio[s].nombreServicio);

                for(int i = 0; i < tam; i++)
                {
                    if(x[indiceAutoBuscado].patente == trabajo[i].patente)
                    {
                        if(trabajo[i].idServicio == servicio[s].id)
                        {
                            importe+= servicio[s].precio;
                        }
                    }
                }
            }
            printf("El importe realizado al auto ingresado es de: %.2f",importe);
        }
    }
}




