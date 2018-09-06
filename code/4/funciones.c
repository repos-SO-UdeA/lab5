#include "funciones.h"

estudiante llenarDatos(char *nom, char *id, float nota) {
  estudiante e;
  strcpy(e.nom, nom);
  strcpy(e.id, id);
  e.nota = nota;
  return e;
}

int agregarEstudiante(estudiante e) {
  if (slist_append(&grupo, &e) == NULL) {
    return TRUE; // Estudiante matriculado con exito
  }
  else {
    return FALSE; // No se pudo matricular el estudiante
  }
}

void imprimirLista(void) {
  printf("%-4s %-20s %-50s %5s\n", "#","IDENTIFICACION","NOMBRE","CEDULA");
  int i = 0;
  SListEntry *e_i = grupo;
  estudiante e_i_data;
  e_i_data = *((estudiante *)slist_data(e_i));
  //printf("%-4d %-20s %-50s %-5.1f\n", i, e_i_data.id, e_i_data.nom, e_i_data.nota);


  /*while(e_i != NULL) {
     e_i_data = *((estudiante *)slist_data(e_i));
     printf("%-4d %-20s %-50s %-5.1f\n", i, e_i_data.id, e_i_data.nom, e_i_data.nota);
     e_i = slist_next(e_i);
  }
  */
}
