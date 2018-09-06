#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "slist.h"
//#include "compare-int.h"

/* Declaraciones asociadas al programa */

# define TAM_NAME 51   /* Tamaño de la cadena que almacena el nombre del estudiante */
# define TAM_ID 16     /* Tamaño de la cadena que almacena el ID del estudiante */
# define MAX_EST 10

typedef struct estudiante {
  char nom[TAM_NAME];
  char id[TAM_ID];
  float nota;
} estudiante;

extern SListEntry *grupo; // estudiante grupo[MAX_EST];
extern estudiante e_i_data;
#define TRUE 1
#define FALSE 0



/* Prototipos de las funciones */

// Funcion con implementada como macro con #define
#define clear() printf("\033[H\033[J")

/* Funciones que implementan el despliegue de la interfaz*/

void menu(void);
void waitForEnter(void);

/* Funciones que implementan la logica de la aplicacion */

estudiante llenarDatos(char *nom, char *id, float nota);
// int agregarEstudiante(estudiante e); ---- No nos dio
void imprimirLista(void);
int removerEstudiante(char *id);
estudiante *obtenerEstudiante(char *id);


/*
estudiante llenarDatos(char *nom, char *id, float nota);
int estudianteDisponible(char *id);
estudiante *obtenerEstudiante(char *id);
void imprimirDatos(estudiante e);
float calcularPromedio(void);
int agregarEstudiante(estudiante e);
int removerEstudiante(char *id);
void imprimirLista(void);
void modificarNota(char *id, float nota);
*/

#endif
