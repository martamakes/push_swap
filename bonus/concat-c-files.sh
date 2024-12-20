#!/bin/bash

# Directorio donde se guardarán los archivos concatenados
OUTPUT_FILE="my-push.c"

# Asegurarse de que estamos en el directorio correcto
if [ ! -d "src" ]; then
    echo "Error: directorio 'src' no encontrado"
    exit 1
fi

# Eliminar el archivo de salida si ya existe
rm -f "$OUTPUT_FILE"

# Crear el archivo de salida
touch "$OUTPUT_FILE"

# Función para procesar los archivos .c
process_directory() {
    local dir=$1
    
    # Añadir un comentario indicando la sección
    echo "/* ************************************************************************** */" >> "$OUTPUT_FILE"
    echo "/*                                                                            */" >> "$OUTPUT_FILE"
    echo "/*                            $dir                                           */" >> "$OUTPUT_FILE"
    echo "/*                                                                            */" >> "$OUTPUT_FILE"
    echo "/* ************************************************************************** */" >> "$OUTPUT_FILE"
    echo "" >> "$OUTPUT_FILE"
    
    # Encontrar y concatenar todos los archivos .c en el directorio actual
    find "$dir" -maxdepth 1 -name "*.c" -type f | sort | while read -r file; do
        echo "Procesando: $file"
        # Añadir una línea en blanco entre archivos
        echo "" >> "$OUTPUT_FILE"
        # Concatenar el contenido del archivo
        cat "$file" >> "$OUTPUT_FILE"
        echo "" >> "$OUTPUT_FILE"
    done
}

# Procesar cada subdirectorio en orden
for dir in src/*/; do
    if [ -d "$dir" ]; then
        process_directory "$dir"
    fi
done

echo "Archivos concatenados en $OUTPUT_FILE"