#include <stdio.h>
#include <string.h>
#include "funciones.h"

int buscar_o_crear_articulo(articulos_t articulos[], char* nombre) 
{
    int i = 0;
    while (articulos[i].descripcion[0] && strcmp(nombre, articulos[i].descripcion) != 0) {
        i++;
    }
    if (articulos[i].descripcion[0] == 0) {
        strcpy(articulos[i].descripcion, nombre);
    }
    return i;
}

void cargar_cantidad(articulos_t* articulo, int sucursal)
{
    int cantidad;
    printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
    scanf("%d", &cantidad);
    (*articulo).cantidad_sucursal[sucursal - 1] += cantidad;
}

void calcular_total(articulos_t* articulo) 
{
    (*articulo).total = 0;
    for (int i = 0; i < 3; i++) {
        (*articulo).total += (*articulo).cantidad_sucursal[i];
    }
}

void imprimir_articulos(articulos_t articulos[]) 
{
    int i = 0;
    printf("\nArticulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while (i < CANT_ARTICULOS && articulos[i].descripcion[0]) {
        printf("%s\t%9d\t%9d\t%9d\t%6d\n",
               articulos[i].descripcion,
               articulos[i].cantidad_sucursal[0],
               articulos[i].cantidad_sucursal[1],
               articulos[i].cantidad_sucursal[2],
               articulos[i].total);
        i++;
    }
}

void ordenar_articulos(articulos_t articulos[]) 
{
    articulos_t aux;
    for (int j = 1; j < CANT_ARTICULOS; j++) {
        for (int i = 0; i < CANT_ARTICULOS - 1; i++) {
            if (articulos[i].total < articulos[i + 1].total) {
                aux = articulos[i];
                articulos[i] = articulos[i + 1];
                articulos[i + 1] = aux;
            }
        }
    }
}

int hay_mas_articulos() 
{
    int opc;
    printf("Desea ingresar otro articulo? 1-Si, 2-No: ");
    scanf("%d", &opc);
    return opc == 1;
}
