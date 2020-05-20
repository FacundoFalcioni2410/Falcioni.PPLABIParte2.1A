#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


int menuInformes();

void informar(eAutos x[],int tam,eTrabajos trabajo[], int tamTrabajo,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente, eServicios servicio[],int tamServicio);

void mostrarAutosPorColorSeleccionado(eAutos x[], int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente);

void mostrarAutoPorMarcaSeleccionada(eAutos x[],int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente);

void informarAutosMasViejos(eAutos x[],int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente);

void mostrarAutosPorMarca(eAutos x[],int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente);

void cantidadAutosColorYMarca(eAutos x[],int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente);

void mostrarMarcasMasElegidas(eAutos x[],int tam,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente);

void mostrarTrabajosEnUnAuto(eAutos x[],int tam,eTrabajos trabajo[], int tamTrabajo,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente, eServicios servicio[],int tamServicio);

void informarImporteServiciosDeAuto(eAutos x[],int tam,eTrabajos trabajo[], int tamTrabajo,eMarcas marca[], int tamMarca, eColores color[], int tamColor, eClientes cliente[], int tamCliente, eServicios servicio[],int tamServicio);






