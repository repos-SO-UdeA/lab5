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

**makefile1**: [makefile1](makefile1)

```
# gcc for C
# g++ for c++
CC = gcc

#compiler flags
# -Wall
CFLAGS = -Wall 

# Search for dependencies and targets from "src" and "include" directories
# The directories are separated by space

INCLUDES = -I$(shell pwd)/headers

VPATH = sources:headers
TARGET = example_listas.out
OBJECTS = main.o listas.o 
BIN = $(shell pwd)/bin

#target
default: all

all:$(TARGET)

$(TARGET): $(OBJECTS)
	echo $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

main.o: main.c funciones.h
	$(CC) $(CFLAGS) $(INCLUDES) $< -c

funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) $(INCLUDES) $< -c

clean:
	-rm -f *.o
	-rm -f $(TARGET)

install: $(TARGET)
	mv $(TARGET) $(BIN)
```

**Uso basico**:

```
make -f makefile1
```

**Caso 2**: [makefile2](makefile2)

```
# gcc for C
# g++ for c++
CC = gcc

#compiler flags
# -Wall
CFLAGS = -Wall 

# Search for dependencies and targets from "src" and "include" directories
# The directories are separated by space
INCLUDES = -I$(shell pwd)/headers

# Directories
BASEDIR = $(shell pwd)
SCR_DIR = $(BASEDIR)/sources
HEADERS_DIR = $(BASEDIR)/headers
BIN_DIR = $(BASEDIR)/bin

# VPATH variable
VPATH = sources:headers


# VPATH variable
SOURCES = $(shell ls $(SCR_DIR))
OBJECTS = $(SOURCES:%.c=%.o)

#target
TARGET = example_multi1.out

# Rules
default: all

all:$(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c funciones.h
	$(CC) $(CFLAGS) $(INCLUDES) $< -c

install: $(TARGET)
  mv $(TARGET) $(BIN_DIR)

clean:
	-rm -f *.o
	-rm -f $(TARGET)
```

**Uso basico**:

```
make -f makefile2
```
