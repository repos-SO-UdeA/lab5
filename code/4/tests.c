#include "tests.h"


void test1(void) {
  printf("test1");
  int est_matriculados = 0;
  estudiante e1, e2, e3, e4;
  e1 = llenarDatos("Bart Simpson", "0001", 2.3);
  e2 = llenarDatos("Rafa Gorgori", "0002", 2.4);
  e3 = llenarDatos("Lisa Simpson", "0003", 5.0);
  e4 = llenarDatos("Nelson Ruffino", "0004", 2.9);
  /*
  ---- Estas funciones no dieron ----
  agregarEstudiante(e1);
  agregarEstudiante(e2);
  agregarEstudiante(e3);
  */
  slist_append(&grupo, &e1);
  slist_append(&grupo, &e2);
  slist_append(&grupo, &e3);
  est_matriculados = slist_length(grupo);
  printf("Numero de estudiantes: %d\n", est_matriculados);
  printf("\n");
  estudiante *r_e;
  r_e = obtenerEstudiante("0003");
  printf("%s\n", r_e->nom);
  printf("\n");
  imprimirLista();
  removerEstudiante("0001");
  printf("\n");
  imprimirLista();
  //agregarEstudiante(e4);
  //imprimirDatos(e1)
  //printf("\n");
  //imprimirLista();
}
