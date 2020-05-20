#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "trabajo.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "utn.h"
#include "cliente.h"
#include "informes.h"

#define TAM 1000
#define TAMMARCA 5
#define TAMTRABAJO 1000
#define TAMLAVADO 4
#define TAMCOLOR 5
#define TAMCLIENTE 6

int menu();

int main()
{
    eAutos autos[TAM];
    eMarcas marca[TAMMARCA] = { {1000,"Renault"}, {1001,"Fiat"}, {1002,"Ford"}, {1003,"Chevrolet"}, {1004,"Peugeot"} };
    eColores color[TAMCOLOR] = { {5000,"Negro"}, {5001,"Blanco"}, {5002,"Gris"}, {5003,"Rojo"}, {5004,"Azul"} };
    eServicios lavado[TAMLAVADO] = { {20000,"Lavado",250}, {20001,"Pulido", 300}, {20002,"Encerado", 400}, {20003,"Completo", 600} };
    eTrabajos trabajos[TAMTRABAJO] = { {10000,100,20000,0,21,10,2019}, {10001,100,20003,0,24,8,2018}, {10002,200,20002,0,20,11,2019}, {10003,975,20000,0,8,1,2020}, {10004,932,20003,0,15,8,2018}, {10005,540,20003,0,31,5,2019} };
    eClientes clientes[TAMCLIENTE] = { {1000, "Juan", 'M'},{1001, "Pedro", 'M'}, {1002, "Maria", 'F'}, {1003, "Micaela", 'F'},{1004, "Josefina", 'F'}, {1005, "Rodrigo", 'M'} };
    int proximoIdAuto = 1000;
    int proximoIdTrabajo = 10006;
    char respuesta;

    int indiceCliente = 0;

    inicializarAutos(autos,TAM);
    inicializarTrabajos(trabajos,TAMTRABAJO);

    respuesta = 'n';

    do
    {
        switch(menu())
        {
        case 1:
            if(altaAuto(autos,TAM,proximoIdAuto,marca,TAMMARCA,color,TAMCOLOR,clientes,indiceCliente))
            {
                proximoIdAuto++;
                indiceCliente++;
            }
            break;
        case 2:
            modificarAuto(autos,TAM,marca,TAMMARCA,color,TAMCOLOR,clientes,TAMCLIENTE);
            break;
        case 3:
            bajaAuto(autos,TAM,marca,TAMMARCA,color,TAMCOLOR,clientes,TAMCLIENTE);
            break;
        case 4:
            system("cls");
            mostrarAutos(autos,TAM,marca,TAMMARCA,color,TAMCOLOR,clientes,TAMCLIENTE);
            break;
        case 5:
            mostrarMarcas(marca,TAMMARCA);
            break;
        case 6:
            mostrarColores(color,TAMCOLOR);
            break;
        case 7:
            if(altaTrabajo(autos, TAM,trabajos,TAMTRABAJO,proximoIdTrabajo,marca,TAMMARCA,color,TAMCOLOR,lavado,TAMLAVADO,clientes,TAMCLIENTE))
            {
                proximoIdTrabajo++;
            }
            break;
        case 8:
            mostrarTrabajos(trabajos,TAMTRABAJO,lavado,TAMLAVADO);
            break;
        case 9:
            mostrarClientes(clientes,TAMCLIENTE);
            break;
        case 10:
            informar(autos,TAM,trabajos,TAMTRABAJO,marca,TAMMARCA,color,TAMCOLOR,clientes,TAMCLIENTE,lavado,TAMLAVADO);
            break;
        case 11:
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

int menu()
{
    int opcion;

    printf("----------- Parcial 1 de Laboratorio I -----------\n\n");
    printf("1. ALTA AUTO\n");
    printf("2. MODIFICAR AUTO\n");
    printf("3. BAJA AUTO\n");
    printf("4. LISTAR AUTOS\n");
    printf("5. LISTAR MARCAS\n");
    printf("6. LISTAR COLORES\n");
    printf("7. ALTA TRABAJO\n");
    printf("8. LISTAR TRABAJOS\n");
    printf("9. LISTAR CLIENTES\n");
    printf("10. INFORMES\n");
    printf("11. SALIR\n\n");
    utn_getEntero(&opcion, 3, "Ingrese una opcion: ", "Error. No es una opcion valida.\n", 1, 11);

    return opcion;
}
