#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#include "alloc-testing.h"
//#include "framework.h"

#include "slist.h"
#include "compare-int.h"

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
