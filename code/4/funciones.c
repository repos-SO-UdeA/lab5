#include "funciones.h"

estudiante llenarDatos(char *nom, char *id, float nota) {
  estudiante e;
  strcpy(e.nom, nom);
  strcpy(e.id, id);
  e.nota = nota;
  return e;
}

/*
int agregarEstudiante(estudiante e) {
  if (slist_append(&grupo, &e) != NULL) {
    return TRUE; // Estudiante matriculado con exito
  }
  else {
    return FALSE; // No se pudo matricular el estudiante
  }
}
*/

void waitForEnter(void) {
  while(getchar()!='\n'); // option TWO to clean stdin
  getchar(); // wait for ENTER
}

void imprimirDatos(estudiante e) {
  printf("** DATOS DEL ESTUDIANTE **\n");
  printf("-> Nombre: %s\n",e.nom);
  printf("-> Identificacion: %s\n",e.id);
  printf("-> Nota: %.1f\n",e.nota);
}

int removerEstudiante(char *id) {
  estudiante *e = obtenerEstudiante(id);
  SListEntry *e_i = grupo;
  while(e_i != NULL) {
    e_i_data = *((estudiante *)slist_data(e_i));
    if ((strcmp(e->nom, e_i_data.nom) == 0) & (strcmp(e->id, e_i_data.id) == 0) & (e->id ==e_i_data.id)) {
      if (slist_remove_entry(&grupo, e_i) != 0) {
        return TRUE;
      }
    }
    e_i = slist_next(e_i);
  }
  return FALSE;
}


estudiante *obtenerEstudiante(char *id) {
  /* Requerimientos: Asume que el estudiante se encuentra en la lista */
  SListEntry *e_i = grupo;
  while(e_i != NULL) {
     e_i_data = *((estudiante *)slist_data(e_i));
     if (strcmp(e_i_data.id,id) == 0) {
       return &e_i_data;
     }
     e_i = slist_next(e_i);
  }
  return NULL;
}

void imprimirLista(void) {
  printf("%-4s %-20s %-50s %5s\n", "#","IDENTIFICACION","NOMBRE","CEDULA");
  int i = 0;
  SListEntry *e_i = grupo;
  estudiante e_i_data;
  while(e_i != NULL) {
     e_i_data = *((estudiante *)slist_data(e_i));
     printf("%-4d %-20s %-50s %-5.1f\n", i, e_i_data.id, e_i_data.nom, e_i_data.nota);
     e_i = slist_next(e_i);
  }
}

float calcularPromedio(void) {
  float avg = 0;
  if(slist_length(grupo) != 0) {
    SListEntry *e_i = grupo;
    estudiante e_i_data;
    while(e_i != NULL) {
       e_i_data = *((estudiante *)slist_data(e_i));
       avg += e_i_data.nota;
       e_i = slist_next(e_i);
    }
    avg /= slist_length(grupo);
    return avg;
  }
  else {
    return 0;
  }
}

void modificarNota(char *id, float nota) {
  estudiante *e = obtenerEstudiante(id);
  SListEntry *e_i = grupo;
  estudiante *e_aux;
  while(e_i != NULL) {
    e_aux = ((estudiante *)slist_data(e_i));
    if (strcmp(e->id, e_aux->id) == 0) {
      e_aux->nota = nota;
    }
    e_i = slist_next(e_i);
  }
}

void menu(void) {
  printf("OPCIONES\n");
  printf("1. Imprimir Lista\n");
  printf("2. Agregar Estudiante\n");
  printf("3. Eliminar estudiante\n");
  printf("4. Obtener datos de un estudiante\n");
  printf("5. Modificar la nota de un estudiante\n");
  printf("6. Obtener el promedio del grupo\n");
  printf("7. Salir\n");
  printf("\nSeleccione una opcion: ");
}
