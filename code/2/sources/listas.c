#include "listas.h"

// Definicion de funciones
nodo *crearNodo(int d) {
  nodo *a = malloc(sizeof(nodo));
  a->dato = d;
  a->siguiente = NULL;
  return a;
}

void insertarPrimero(nodo **cabeza, int d) {
  nodo *nuevo;
  nuevo = malloc(sizeof(nodo));
  nuevo->dato = d;
  nuevo->siguiente = *cabeza;
  *cabeza = nuevo;
}

void insertarFinal(nodo **cabeza, int d) {
  nodo *ultimo;
  ultimo = *cabeza;
  if(ultimo == NULL) {
    *cabeza = crearNodo(d);
  }
  else {
    for(;ultimo->siguiente;) {
      ultimo = ultimo->siguiente;
    }
    ultimo->siguiente = crearNodo(d);
  }
}

void insertar(nodo **cabeza, int d_cmp, int d) {
  nodo *nuevo, *despues;
  nuevo = crearNodo(d);
  if(*cabeza == NULL) {
    *cabeza = nuevo;
  }
  else {
    int ban = 0;
    despues = *cabeza;
    /* Etapa de busqueda */
    while((despues != NULL) && !ban) {
      if(despues->dato != d_cmp) {
        despues = despues->siguiente;
      }
      else {
        ban = 1;
      }
    }
    /* Etapa de insercion */
    if(ban) {
      nuevo->siguiente = despues->siguiente;
      despues->siguiente = nuevo;
    }
  }
}

nodo *localizar(nodo *cabeza, int d) {
  nodo *indice;
  for(indice = cabeza; indice != NULL; indice = indice->siguiente) {
    if(d == indice->dato) {
      return indice;
    }
  }
  return NULL;
}

nodo *buscarPosicion(nodo *cabeza, int pos) {
  nodo *indice;
  int i;
  if(pos < 1) {
    return NULL;
  }
  indice = cabeza;
  for(i = 1; (i < pos) && (indice != NULL); i++) {
    indice = indice->siguiente;
  }
  return indice;
}

void eliminar(nodo **cabeza, int d) {
  nodo *actual, *anterior;
  int encontrado = 0;
  actual = *cabeza;
  anterior = NULL;
  /* Busqueda del nodo y del anterior */
  while((actual != NULL) && (!encontrado)) {
    encontrado = (actual->dato == d);
    if(!encontrado) {
      anterior = actual;
      actual = actual->siguiente;
    }
  }
  /* Enlace de nodo anterior con siguiente */
  if(actual != NULL) {
    /* Distingue que el nodo sea cabecera o del resto de la lista */
    if(actual == *cabeza) {
      *cabeza = actual->siguiente;
    }
    else {
      anterior->siguiente = actual->siguiente;
    }
  }
  free(actual);
}

void recorrer(nodo *cabeza) {
  for(;cabeza;cabeza = cabeza->siguiente) {
    printf("%d ", cabeza->dato);
  }
  printf("\n");
}
