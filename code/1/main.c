#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main() {
  nodo *primero = NULL;

  /* Agregando nodos a la lista */
  insertar(&primero, 0, 4);               // (H) -> (4)
  insertar(&primero, 4, 40);              // (H) -> (4) -> (40)
  insertar(&primero, 4, 10);              // (H) -> (4) -> (10) -> (40)
  insertar(&primero, 10, 25);             // (H) -> (4) -> (10) -> (25) -> (40)

  /* Imprimiendo la lista de 4 elementos */
  recorrer(primero);

  /* Eliminando nodos de la lista */
  eliminar(&primero,4);                   // (H) -> (10) -> (25) -> (40)
  eliminar(&primero,25);                  // (H) -> (10) -> (40)

  /*Imprimiendo la lista de 2 elementos */
  recorrer(primero);

  /* Insertando nodos a la lista */
  insertarFinal(&primero, -4);           // (H) -> (10) -> (40) -> (-4)
  insertarPrimero(&primero , 3);         // (H) -> (3) -> (10) -> (40) -> (-4)

  /* Imprimiendo la lista de 4 elementos */
  recorrer(primero);

  /*
     Buscando Posicion del nodo con valor 40 (posicion 3)

     Nota: para el codigo el indexado de la lista empieza desde 1)
  */

  nodo *n_pos2 = buscarPosicion(primero,3);  // Nodo de la posición 3
  nodo *n_pos6 = buscarPosicion(primero,6);  // Nodo de la posición 6 (no existe)

  // Imprimiendo el valor del nodo de la posicion 3
  if (n_pos2 != NULL) {
    printf("Valor del nodo de la posicion 3: %d\n", n_pos2->dato);
  }
  else {
    printf("Nodo no encontrado\n");
  }

  // Imprimiendo el valor del nodo de la posicion 6
  if (n_pos6 != NULL) {
    printf("Valor del nodo de la posicion 6: %d\n", n_pos2->dato);
  }
  else {
    printf("Nodo no encontrado\n");
  };

  /* Localizando el nodo de la posición 1 */
  nodo *p_n, n;
  p_n = &n;
  p_n = localizar(primero, 3);

  // Imprimiendo el valor del nodo de la posicion 1
  printf("Valor del nodo de la posicion 1: %d\n", p_n->dato);
  // Imprimiendo el valor del nodo de la posicion 2
  printf("Valor del nodo de la posicion 2: %d\n", p_n->siguiente->dato);
  // Imprimiendo el valor del nodo de la posicion 2
  printf("Valor del nodo de la posicion 3: %d\n", p_n->siguiente->siguiente->dato);


  /* Finalizando el programa */

  primero = NULL;
  return 0;
}
