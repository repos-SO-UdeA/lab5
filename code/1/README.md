# Ejemplo 1 - Listas enlazadas

## Comandos de compilacion y enlazado

### Compilando y enlazando por pasos

En este caso se compila cada uno de los archivos fuente generando archivos objeto para luego unir estos ultimos y generar el ejecutable

```
gcc -Wall -I. -c listas.c
gcc -Wall -I. -c main.c
gcc listas.o main.o -o example_listas.out
```

### Compilando y enlazando por pasos pero usando comodines

```
gcc -I. -c -Wall *.c
gcc *.o -o example_listas.out
```

### Compilando y enlazando por pasos en un solo paso

```
gcc -I. -Wall *.c -o admin_clase.out
```

## Ejecución

```
./example_listas.out
```

### Empleando makefiles

**makefile1**: Caso mas sencillo (No se emplean comodines ni variables).

```
# Regla de construccion general
all: example_listas.out

# Regla que genera el archivo ejecutable
example_multi1.out: main.o listas.o
	gcc main.o listas.o -o example_multi1.out

# Reglas para generar los archivos objeto del programa
listas.o: listas.c listas.h
	gcc -I. -c funciones.c

main.o: main.c funciones.h
	gcc -I. -c main.c

#Regla para borrar todos los archivos obtejo (.o) y copias de seguridad (~) del proyecto
clean:
	rm *.o *~

#Regla para borrar todos los archivos obtejo (.o), copias de seguridad (~) y el ejecutable generado
clean_all:
	rm *.o *~ *.out
```

**Uso**:

```
make -f makefile1
```

