# Ejemplo 4 - Ejemplo de la administración de un grupo de estudiantes usando una libreria externa

Para este caso se replico una parte del [ejemplo de los estudiantes](https://github.com/repos-SO-UdeA/lab4/tree/master/code/2) empleando la libreria [C-algorithms](https://fragglet.github.io/c-algorithms/) previamente mencionada. 

**Nota**: El programa tiene un bug cuando se trata de hacer interactivo, este aun no hemos sido capaz de solucionarlo. Por dicha razon, solo se muestra la parte asociada a test que combinan el uso de esta libreria con las estructuras asociada al estudiante.

## Comandos de compilacion y enlazado

### Compilando y enlazando por pasos

```
gcc -Wall -I/usr/local/include/libcalg-1.0/libcalg -c tests.c
gcc -Wall -I/usr/local/include/libcalg-1.0/libcalg -c funciones.c
gcc -Wall -I/usr/local/include/libcalg-1.0/libcalg -c main.c
gcc test.o funciones.o main.o -o admin_clase.out -lcalg
```

### Compilando y enlazando por pasos pero usando comodines

```
gcc -I/usr/local/include/libcalg-1.0/libcalg -c -Wall *.c
gcc *.o -o admin_clase.out -lcalg
```

### Compilando y enlazando por pasos en un solo paso

```
gcc -I/usr/local/include/libcalg-1.0/libcalg -Wall *.c -o admin_clase.out -lcalg
```

## Ejecución

```
./admin_clase.out
```

