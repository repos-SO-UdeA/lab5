#ifndef LISTAS_H_
#define LISTAS_H_
#include <stdlib.h>
#include <stdio.h>

// Estructura asociada al nodo
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo;

// Declaracion de funciones
nodo *crearNodo(int d);
void insertarPrimero(nodo **cabeza, int d);
void insertarFinal(nodo **cabeza, int d);
void insertar(nodo **cabeza, int d_cmp, int d);
nodo *localizar(nodo *cabeza, int d);
nodo *buscarPosicion(nodo *cabeza, int pos);
void eliminar(nodo **cabeza, int d);
void recorrer(nodo *cabeza);

#endif
