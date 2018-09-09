# Ejemplo 2 - Listas enlazadas

Para este caso los archivos fuente (.c) y cabecera (.h) se encuentran los directorios **[ sources ]** y **[ headers ]** respectivamente. La gerarquia de directorios será la siguiente:

```
[ 2 ] --|--> [ sources ] --|-- listas.c        
        |                  |-- main.c
        | 
        |--> [headers] --|-- listas.h
        |
        |--> [bin]
```

En el directorio **[ bin ]** ira el ejecutable. Para el caso se asume que los comandos gcc se ejecutan en el directorio raiz del ejemplo, directorio **[2]** en el caso.

## Comandos de compilacion y enlazado

### Compilando y enlazando por pasos

En este caso se compila cada uno de los archivos fuente generando archivos objeto para luego unir estos ultimos y generar el ejecutable

```
gcc -Wall -I./headers -c ./sources/listas.c
gcc -Wall -I./headers -c ./sources/main.c
gcc listas.o main.o -o ./bin/example_listas.out
```

### Compilando y enlazando por pasos pero usando comodines

```
gcc -I./headers -c -Wall ./sources/*.c
gcc *.o -o ./bin/example_listas.out
```

### Compilando y enlazando por pasos en un solo paso

```
gcc -I./headers -Wall ./sources/*.c -o ./bin/admin_clase.out
```

## Ejecución

```
cd bin
./example_listas.out
```

### Empleando makefiles 

**makefile1**: Caso mas sencillo en el que no se emplean comodines ni variables. (Archivo: [makefile1](makefile1))

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

**Uso basico**:

```
make -f makefile1
```

**Caso 2**: Cado mejorado haciendo uso de variables. (Archivo: [makefile2](makefile2))

```
# gcc for C
# g++ for c++
CC = gcc

#compiler flags
# -Wall
CFLAGS = -Wall -I.

#target
TARGET := example_listas.out
#directory for the object files
HEADERS = listas.h
SOURCES = main.c listas.c
OBJECTS = main.o listas.o

default: $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
```

**Uso basico**:

```
make -f makefile2
```

**Caso 3**: Cado mejorado haciendo uso de variables y comodines. La ventaja es que este makefile puede usarse en otros codigos similares en estructura independiente del nombre de los archivos (Archivo: [makefile3](makefile3))


```
# gcc for C
# g++ for c++
CC = gcc

#compiler flags
# -Wall
CFLAGS = -Wall -I.

#target
TARGET := example_listas.out
#directory for the object files
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:%.c=%.o)

default: all
all: $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
```

**Uso basico**:

```
make -f makefile3
```
