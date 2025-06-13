#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"


int main(void)
{
    articulos_t articulos[CANT_ARTICULOS] = {0};
    char nombre[90];
    int sucursal;

    printf("Bienvenido al final de Info 1\n\n");

    do
    {
        printf("Ingrese la descripcion del articulo: ");
        scanf("%s", nombre);

        int idx = buscar_o_crear_articulo(articulos, nombre);
        printf("Para que sucursal va a realizar la carga? (1, 2, 3): ");
        scanf("%d", &sucursal);

        cargar_cantidad(&articulos[idx], sucursal);
        calcular_total(&articulos[idx]);

    } while (hay_mas_articulos());

    printf("\nListado cargado:\n");
    imprimir_articulos(articulos);

    ordenar_articulos(articulos);

    printf("\nListado ordenado por total:\n");
    imprimir_articulos(articulos);
    
    system("pause");
    
    return 0;
   
}
