# Laboratorio 5

> **Objetivos**:
> * Comprender el concepto de memoria dinamica en C.
> * Analizar algunas aplicaciones que usan memoria dinamica.

## Manejo dinamico de memoria en C

### Conceptos basicos

Leer, simular y comprender los ejemplos del enlace [Memoria dinamica en C](https://github.com/repos-SO-UdeA/laboratorios/blob/master/lab1/teoria/parte5/memoria_dinamica.ipynb). (**Nota**: Este material aun se encuentra en construcción).

### Aplicaciones de utilidad empleando el manejo dinamico de memoria.

Leer, simular y comprender los ejemplos del enlace [listas enlazadas](https://github.com/tigarto/2018-1/blob/master/listas_enlazadas.ipynb). Las listas enlazadas, son una de las aplicaciones del manejo dinámico de memoria tipicas.

### Ejemplos de repaso de los conceptos basicos

1. ¿Que se hacen siguientes lineas ne codigo?

```C
char *string_ptr;
string_ptr = malloc(80);
free(string_ptr);
pointer = NULL;
```

2. Dada la siguiente estructura:

```C
struct person {
  char name[30];                  /* name of the person */
  char address[30];               /* where he lives */
  char city_state_zip[30];        /* Part 2 of address */
  int age;                        /* his age */
  float height;                   /* his height in inches */
};
```

¿Que hace el siguiente codigo?, ¿Por que sería recomendable el uso del condicional?

```
struct person *new_item_ptr;
new_item_ptr = malloc(sizeof(struct person));
if (new_item_ptr == NULL) {
  fprintf(stderr, "Out of memory\n");
  exit (8);
}
```

¿Como liberaria la memoria asociada new_item_ptr del caso anterior?

```C
// Coloque el codigo aqui



```

3. **Arreglo dinamico**: Codifique, compile y ejecute el programa [ejemplo3.c](./ejemplo3.c)(tomado del libro C primer plus):

```C
/* dyn_arr.c -- dynamically allocated array */
#include <stdio.h>
#include <stdlib.h> /* for malloc(), free() */

int main(void) {
  double * ptd;
  int max = 0;
  int number;
  int i = 0;
  puts("What is the maximum number of type double entries?");
  if (scanf("%d", &max) != 1) {
    puts("Number not correctly entered -- bye.");
    exit(EXIT_FAILURE);
  }
  ptd = (double *) malloc(max * sizeof (double));
  if (ptd == NULL) {
    puts("Memory allocation failed. Goodbye.");
    exit(EXIT_FAILURE);
  }
  /* ptd now points to an array of max elements */
  puts("Enter the values (q to quit):");
  while (i < max && scanf("%lf", &ptd[i]) == 1)
  ++i;
  printf("Here are your %d entries:\n", number = i);
  for (i = 0; i < number; i++) {
    printf("%7.2f ", ptd[i]);
    if (i % 7 == 6)
      putchar('\n');
  }
  if (i % 7 != 0)
    putchar('\n');
  puts("Done.");
  free(ptd);
  return 0;
}
```

4. **Estructuras y reserva dinamica de memoria**: Codifique, compile y ejecute el programa [ejemplo4.c](./ejemplo4.c) (tomado del libro C primer plus):

```C
// names3.c -- use pointers and malloc()
#include <stdio.h>
#include <string.h> // for strcpy(), strlen()
#include <stdlib.h> // for malloc(), free()
#define SLEN 81

struct namect {
  char * fname; // using pointers
  char * lname;
  int letters;
};

void getinfo(struct namect *); // allocates memory
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleanup(struct namect *); // free memory when done
char * s_gets(char * st, int n);

int main(void) {
  struct namect person;
  
  getinfo(&person);
  makeinfo(&person);
  showinfo(&person);
  cleanup(&person);
  
  return 0;
}


void getinfo (struct namect * pst) {
  char temp[SLEN];
  printf("Please enter your first name.\n");
  s_gets(temp, SLEN);
  // allocate memory to hold name
  pst->fname = (char *) malloc(strlen(temp) + 1);
  // copy name to allocated memory
  strcpy(pst->fname, temp);
  printf("Please enter your last name.\n");
  s_gets(temp, SLEN);
  pst->lname = (char *) malloc(strlen(temp) + 1);
  strcpy(pst->lname, temp);
}

void makeinfo (struct namect * pst) {
  pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo (const struct namect * pst) {
  printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect * pst) {
  free(pst->fname);
  free(pst->lname);
}

char * s_gets(char * st, int n) {
  char * ret_val;
  char * find;
  ret_val = fgets(st, n, stdin);
  if (ret_val) {
    find = strchr(st, '\n'); // look for newline
    if (find) // if the address is not NULL,
      *find = '\0'; // place a null character there
    else
      while (getchar() != '\n')
        continue; // dispose of rest of line
  }
  return ret_val;
}
```

5. **Estructura con miembro tipo array flexibles**: Codifique, compile y ejecute el programa [ejemplo5.c](./ejemplo5.c)(tomado del libro C primer plus):

```C
// flexmemb.c -- flexible array member (C99 feature)
#include <stdio.h>
#include <stdlib.h>

struct flex {
  size_t count;
  double average;
  double scores[]; // flexible array member
};

void showFlex(const struct flex * p);

int main(void) {
  struct flex * pf1, *pf2;
  int n = 5;
  int i;
  int tot = 0;
  // allocate space for structure plus array
  pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
  pf1->count = n;
  for (i = 0; i < n; i++) {
    pf1->scores[i] = 20.0 - i;
    tot += pf1->scores[i];
  }
  pf1->average = tot / n;
  showFlex(pf1);
  
  n = 9;
  tot = 0;
  pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
  pf2->count = n;
  for (i = 0; i < n; i++) {
    pf2->scores[i] = 20.0 - i/2.0;
    tot += pf2->scores[i];
  }
  pf2->average = tot / n;
  showFlex(pf2);
  free(pf1);
  free(pf2);
  return 0;
}

void showFlex(const struct flex * p) {
  int i;
  printf("Scores : ");
  for (i = 0; i < p->count; i++)
    printf("%g ", p->scores[i]);
  printf("\nAverage: %g\n", p->average);
}
```

### Ejemplos de repaso de las aplicaciones 

1. Vaya al ejemplo de listas enlazadas del siguiente [enlace](./code/1/)
2. Vaya al ejemplo de listas enlazadas del siguiente [enlace](./code/2/)
3. En el siguiente [enlace](./code/3/) se emplea la libreria [C Algorithms](https://fragglet.github.io/c-algorithms/) para implementar un programa que hace exactamente lo mismo que en el ejemplo 1. Vaya al enlace y analice como funciona.
4. El siguiente [enlace](/code/4) es un intento por reproducir el ejemplo de aplicacion con estudiantes analizado en el [enlace](https://github.com/repos-SO-UdeA/lab4/tree/master/code/2). Analice el codigo. (**Nota**: este codigo aun tien bugs que no han sido corregidos).


## Referencias
* https://www.tutorialspoint.com/data_structures_algorithms/linked_lists_algorithm.htm
* https://www.tutorialspoint.com/data_structures_algorithms/linked_lists_algorithm.htm
* https://www.explainxkcd.com/wiki/index.php/379:_Forgetting
* https://fragglet.github.io/c-algorithms/
* http://www.calcifer.org/documentos/make/ejemplo.html
* https://iie.fing.edu.uy/~vagonbar/gcc-make/make.htm
* https://www.tutorialspoint.com/makefile/
* http://servicio.uca.es/softwarelibre/publicaciones/make.pdf
* http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
* https://hernandis.me/2017/03/20/como-hacer-un-makefile.html
* https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
* http://nuclear.mutantstargoat.com/articles/make/mktut.pdf
* https://www.isical.ac.in/~pdslab/2017/lectures/makefiles.pdf
* http://retis.sssup.it/~luca/makefiles.pdf

<!---

# lab5
Laboratorio 5

https://www.tutorialspoint.com/data_structures_algorithms/linked_lists_algorithm.htm
https://www.tutorialspoint.com/data_structures_algorithms/linked_lists_algorithm.htm
https://www.explainxkcd.com/wiki/index.php/379:_Forgetting
https://www.youtube.com/watch?v=JdQeNxWCguQ
https://fragglet.github.io/c-algorithms/
-->

<!---

By default the libraries and headers will be installed in /usr/local/lib/ and /usr/local/include directories.


Esta fue la libreria que se instalo localmente: https://fragglet.github.io/c-algorithms/ --- https://github.com/fragglet/c-algorithms

Este es el ejemplo base: https://github.com/fragglet/c-algorithms/blob/master/test/test-slist.c





cd c-algorithms-1.2.0/
./configure
make
make check
make install


Installation Names

package's files: /usr/local/bin, /usr/local/man


tigarto@fuck-pc:/usr/local/lib$ ls
crafter-0.2               libof_snmp_cpu.so.0
libcalg.a                 libof_snmp_cpu.so.0.0.0
libcalg.la                libopenflow_action_install.a
libcalg.so                libopenflow_action_install.la
libcalg.so.0              libopenflow_action_install.so
libcalg.so.0.0.0     

 lcalg

/usr/local/include/libcalg-1.0/libcalg

-->

