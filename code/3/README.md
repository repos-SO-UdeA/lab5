# Ejemplo 3 - Listas enlazadas codificadas por otra persona

## Pasos previos ##

### Instalacion y puesta en punto de la libreria ###

1. Instalar la libreria [c-algorithms](https://fragglet.github.io/c/) bajandose el codigo fuente comprimido de: https://github.com/fragglet/c-algorithms/releases
2. Descomprimir:

```
tar -xvzf c-algorithms-1.2.0.tar.gz
```

3. Ingresar al directorio raiz de la libreria:

```
cd c-algorithms-1.2.0/
```

4. Leer y seguir las instrucciones del archivo de texto **INSTALL**, para el caso esta se resumen en los siguientes comandos:

```
./configure
make
make check
make install
```

Tal y como se dice en el archivo **INSTALL**: 

```
...
By default the libraries and headers will be installed in /usr/local/lib/ and /usr/local/include directories.
...

```

Estas rutas deberan ser tenidas en cuenta en el momento de compilar y enlazar. Para nuestro caso, las rutas quedaron asi:
* **Archivos cabecera**: /usr/local/include/libcalg-1.0/libcalg
* **Librerias**: /usr/local/lib. Hay diferentes variantes de la libreria (libcalg.a, libcalg.la, libcalg.so, libcalg.so.0, libcalg.so.0.0.0
).


### Emplear la libreria ###

Aplicando las bases de C adquiridas previamente, cacharreando para dar solución a lo que no se entendió o entiende aun, siguiendo la [documentación](https://fragglet.github.io/c-algorithms/doc/) y los [ejemplos](), se procedió a codificar el archivo fuente [test.c](test.c) que hace exactamente lo mismo que se hace en los ejemplo 1 y 2, pero empleando la libreria previamente instalada. Recuerde que el reuso es buena practica de programación. 

```C
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"
#include "compare-int.h"

/*
Compilacion:
gcc -I/usr/local/include/libcalg-1.0/libcalg  test.c -o test.out -lcalg
Ejecucion:
./test.out
*/


int variable1 = 4, variable2 = 10, variable3 = 25, variable4 = 40;

SListEntry *generate_list(void);

int main() {
  /* Create a list */
  SListEntry *list = generate_list(); // (H) -> (4) -> (10) -> (25) -> (40)
  SListEntry *rover;
  rover = list;

  /* Imprimiendo la lista de 4 elementos */
  while(rover != NULL) {
    printf("%d ",*((int *)slist_data(rover)));
    rover = slist_next(rover);
  }
  printf("\n");

  /* Eliminando nodos de la lista */
  assert(slist_remove_data(&list, int_equal, &variable1) == 1);  // (H) -> (10) -> (25) -> (40)
  assert(slist_remove_data(&list, int_equal, &variable3) == 1);  // (H) -> (10) -> (40)

  /*Imprimiendo la lista de 2 elementos */
  rover = list;
  while(rover != NULL) {
    printf("%d ",*((int *)slist_data(rover)));
    rover = slist_next(rover);
  }
  printf("\n");

  /* Insertando nodos a la lista */

  int variable5 = -4, variable6 = 3;
  assert(slist_append(&list, &variable5) != NULL);  // (H) -> (10) -> (40) -> (-4)
  assert(slist_prepend(&list, &variable6)!= NULL);  // (H) -> (3) -> (10) -> (40) -> (-4)

  /* Imprimiendo la lista de 4 elementos */
  rover = list;
  while(rover != NULL) {
    printf("%d ",*((int *)slist_data(rover)));
    rover = slist_next(rover);
  }
  printf("\n");



  SListValue v_pos2, v_pos6;

  // Imprimiendo el valor del nodo de la posicion 3
  v_pos2 = slist_nth_data(list, 2);
  if (v_pos2 != NULL) {
    printf("Valor del nodo de la posicion 3: %d\n", *((int *)v_pos2));
  }
  else {
    printf("Nodo no encontrado\n");
  }


  // Imprimiendo el valor del nodo de la posicion 6 (no existe)
  v_pos6 = slist_nth_data(list, 5);
  if (v_pos6 != NULL) {
    printf("Valor del nodo de la posicion 6: %d\n", *((int *)v_pos6));
  }
  else {
    printf("Nodo no encontrado\n");
  };

  /* Localizando el nodo de la posición 1 */
  SListEntry *entry;
  SListValue entry_value;
  entry = slist_nth_entry(list, 0);
  entry_value = slist_data(entry);

  // Imprimiendo el valor del nodo de la posicion 1
  printf("Valor del nodo de la posicion 1: %d\n", *((int *)entry_value));

  // Imprimiendo el valor del nodo de la posicion 2
  entry = slist_next(entry);

  printf("Valor del nodo de la posicion 2: %d\n", *((int *)slist_data(entry)));

  // Imprimiendo el valor del nodo de la posicion 3
  entry = slist_next(entry);
  printf("Valor del nodo de la posicion 3 : %d\n", *((int *)slist_data(entry)));

  /* Esperimentando con la funcion para ordenar la lista */

  // Antes de ordenar la lista

  /* Imprimiendo la lista de 4 elementos antes de ordenarla */
  rover = list;
  while(rover != NULL) {
    printf("%d ",*((int *)slist_data(rover)));
    rover = slist_next(rover);
  }
  printf("\n");

  // Despues de ordenar la listas
  slist_sort(&list, int_compare); // Ordenando la lista

  /* Imprimiendo la lista de 4 elementos despues de ordenarla */
  rover = list;
  while(rover != NULL) {
    printf("%d ",*((int *)slist_data(rover)));
    rover = slist_next(rover);
  }
  printf("\n");

  /* Finalizando el programa */

  /* Free a list */
	slist_free(list);

  /* Check the empty list frees correctly */
  slist_free(NULL);
  return 0;

}

SListEntry *generate_list(void)
{
	SListEntry *list = NULL;
	assert(slist_append(&list, &variable1) != NULL); // (H) -> (4)
	assert(slist_append(&list, &variable2) != NULL); // (H) -> (4) -> (10)
	assert(slist_append(&list, &variable3) != NULL); // (H) -> (4) -> (10) -> (25)
	assert(slist_append(&list, &variable4) != NULL); // (H) -> (4) -> (10) -> (25) -> (40)
	return list;
}
```

### Compilando ###

Para este caso, como se va a hacer uso de una libreria ajena se emplean dos parametros adicionales en el gcc. El primero es **-I[ruta_archivos_cabecera]**, el otro es **-l[nombre_libreria]**. Para el caso:
* **ruta_archivos_cabecera**: /usr/local/include/libcalg-1.0/libcalg, así el parametro para el gcc sera: **-I/usr/local/include/libcalg-1.0/libcalg**
* **nombre_libreria**: Para el caso la libreria se llama **libcalg.so** de modo que el parametro a pasar al gcc sera **-lcalg**


#### Compilando y enlazando por pasos ####

```
gcc -Wall -I/usr/local/include/libcalg-1.0/libcalg test.c -c 
gcc test.o -o test.out -lcalg
```


#### Compilando y enlazando por pasos ####

```
gcc -I/usr/local/include/libcalg-1.0/libcalg -Wall test.c -o test.out -lcalg
```

### Ejecutando ###

```
./test.out
```
