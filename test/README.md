Tienes razón, disculpa por el error. Aquí tienes la versión corregida del README.md con el formato adecuado:

# Push_swap Tester Suite

Este directorio contiene una suite de tests para el proyecto Push_swap. Está diseñado para proporcionar una forma fácil y modular de probar diferentes aspectos del proyecto.

## Estructura

```
test/
├── Makefile
├── testers/
│   ├── tester_parsing.c
│   ├── tester_operations.c
│   ├── tester_sort_small.c
│   ├── tester_sort_large.c
│   └── tester_full_program.c
└── include/
    └── test_utils.h
```

- `Makefile`: Controla la compilación y ejecución de los testers.
- `testers/`: Directorio que contiene los archivos fuente de cada tester.
- `include/`: Directorio para archivos de cabecera compartidos entre testers.

## Cómo usar

### Compilar todos los testers

```bash
make all
```

### Ejecutar todos los testers

```bash
make test
```

### Ejecutar un tester específico

```bash
make run_[nombre_del_tester]
```

Por ejemplo:
```bash
make run_tester_parsing
```

### Limpiar los archivos compilados

```bash
make clean
```

### Limpiar completamente (incluyendo el proyecto principal)

```bash
make fclean
```

### Recompilar todo

```bash
make re
```

## Añadir un nuevo tester

1. Crea un nuevo archivo `.c` en el directorio `testers/`.
2. Añade el nombre del nuevo tester (sin la extensión .c) a la lista `TESTERS` en el Makefile.

Por ejemplo, si creas `testers/tester_new_feature.c`:

```makefile
TESTERS = tester_parsing tester_operations ... tester_new_feature
```

Ahora puedes usar el tester de las siguientes maneras:

Sin argumentos, ejecutará los tests predefinidos y aleatorios:
Copy./tester_parsing

Con argumentos personalizados, ejecutará un test con esos argumentos:
Copy./tester_parsing 1 2 3 4 5
o
Copy./tester_parsing "1 2 3" 4 5


Esta versión te permite probar fácilmente diferentes escenarios y casos de borde simplemente pasando los argumentos que quieres probar directamente al ejecutar el tester.

## Notas

- Cada tester debe tener su propia función `main()`.
- Los testers pueden utilizar las funciones del proyecto principal, pero no deben incluir `main.c`.
- Si necesitas funciones auxiliares compartidas entre testers, considere añadirlas a `test_utils.h` en el directorio `include/`.

## Consejos para escribir testers

1. Cada tester debe enfocarse en probar una funcionalidad específica.
2. Utiliza casos de prueba variados, incluyendo casos límite y entradas inválidas.
3. Imprime mensajes claros para cada prueba, indicando qué se está probando y si pasó o falló.
4. Considera usar colores en la salida para una mejor legibilidad (verde para éxito, rojo para fallo).

## Mantenimiento

Mantén la lista de `TESTERS` en el Makefile actualizada cada vez que añadas o elimines un tester.