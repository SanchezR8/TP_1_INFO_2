#ifndef FUNCIONES_H
#define FUNCIONES_H

#define CANT_ARTICULOS 60

typedef struct {
    char descripcion[90];
    int cantidad_sucursal[3];
    int total;
} articulos_t;

int buscar_o_crear_articulo(articulos_t articulos[], char* nombre);
void cargar_cantidad(articulos_t* articulo, int sucursal);
void calcular_total(articulos_t* articulo);
void imprimir_articulos(articulos_t articulos[]);
void ordenar_articulos(articulos_t articulos[]);
int hay_mas_articulos();

#endif
