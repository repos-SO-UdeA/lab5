#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "funciones.h"
#include "tests.h"


SListEntry *grupo = NULL;
estudiante e_i_data;

int main() {
  /*
    -- Este es un test de las funciones --
    printf("Ensayo\n");
    test1();
  */
  /*Variables locales */
  int opc;  // Variable asociada al menu
  int banExit = 0; // bandera para salirse del programa
  char nom[TAM_NAME]; // Nombres del estudiante
  char cc[TAM_ID]; // Identificacion del estudiante
  estudiante est; // Variable auxiliar para almacenar datos del estudiante
  //int banEst;  // Bandera con la que se indica si un estudiante fue agregado a la lista
  estudiante *ptr;
  printf("%s\n","SISTEMA PARA ADMINISTRACION DEL CURSO DE SO");
  for(;;) {
    menu();
    scanf("%d", &opc);
    switch (opc) {
      case 1:
        if(slist_length(grupo) == 0) {
          printf("\nNo hay estudiantes matriculados. Presione [Enter] para continuar... ");
          waitForEnter();
          clear();
        }
        else {
          imprimirLista();
          printf("\n\nPresione [Enter] para continuar... ");
          waitForEnter();
          clear();
        }
        break;
      case 2:
        printf("Ingresando los datos del estudiante\n");
        printf("- Nombre: ");
        //gets(nom);
        //fgets(nom, TAM_NAME, stdin);
        //scanf("%[^\n]s", nom);  // Para poder leer espacios en el scanf
        scanf("%s", nom); // Nota: Hay un bug pues no se logran leer nombres completos
        printf("- Cedula: ");
        scanf("%s", cc);
        est = llenarDatos(nom, cc, 0.0);
        if(slist_append(&grupo, &est) != NULL) {
          printf("\nEstudiante agregado...");
        }
        else {
          printf("\nERROR!!! No hay cupos...");
        }
        printf("\n\nPresione [Enter] para continuar... ");
        waitForEnter();
        clear();
        break;
      case 3:
        printf("Ingrese la identificacion del estudiante a eliminar: ");
        scanf("%s",cc);
        if(removerEstudiante(cc) == FALSE) {
          printf("\nERROR!!! Estudiante no disponible...");
        }
        else {
          printf("\nEstudiante eliminado...");
        }
        printf("\n\nPresione [Enter] para continuar... ");
        waitForEnter();
        clear();
        break;
      case 4:
        printf("Ingrese la identificacion del estudiante: ");
        scanf("%s",cc);
        ptr = obtenerEstudiante(cc);
        if(ptr == NULL) {
          printf("\nERROR!!! Estudiante no disponible...");
        }
        else {
          imprimirDatos(*ptr);
        }
        printf("\n\nPresione [Enter] para continuar... ");
        waitForEnter();
        clear();
        break;
      case 5:
        printf("Ingrese la identificacion del estudiante: ");
        scanf("%s",cc);
        ptr = obtenerEstudiante(cc);
        if(ptr == NULL) {
          printf("\nERROR!!! Estudiante no disponible...");
        }
        else {
          float nota;
          printf("Ingrese la calificacion del estudiante: ");
          scanf("%f", &nota);
          modificarNota(cc, nota);
          printf("\nNota actualizada...");
        }
        printf("\n\nPresione [Enter] para continuar... ");
        waitForEnter();
        clear();
        break;
      case 6:
        printf("El promedio del grupo es: %.1f\n", calcularPromedio());
        printf("\n\nPresione [Enter] para continuar... ");
        waitForEnter();
        clear();
        break;
      case 7:
        printf("Suerte es que le digo\n");
        banExit = 1;
        break;
      default:
        printf("ERROR!!! Opcion invalida. Presione enter para continuar\n");
        waitForEnter();
        clear();
    }
    if(banExit == 1) {
      break;
    }
  }
  printf("\nCerrando el programa...\n");
  waitForEnter();
  return 0;
}
