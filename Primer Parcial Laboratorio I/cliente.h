#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;

}eClientes;

#endif // CLIENTE_H_INCLUDED

void inicializarClientes(eClientes x[], int tamCliente);

void mostrarCliente(eClientes x);

void mostrarClientes(eClientes x[], int tamCliente);
