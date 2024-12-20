# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    concat-c-files.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 09:15:26 by mvigara-          #+#    #+#              #
#    Updated: 2024/12/20 09:20:19 by mvigara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Función para pedir el nombre del archivo de salida
get_output_filename() {
    local default_name="all.c"
    read -p "Introduce el nombre del archivo de salida [$default_name]: " output_name
    echo "${output_name:-$default_name}"
}

# Función para obtener los directorios a procesar
get_directories() {
    local default_dirs="src"
    local input_dirs
    
    echo "¿Qué directorios quieres procesar? (separados por espacios)"
    echo "Por defecto: $default_dirs"
    read -p "Directorios: " input_dirs
    
    # Si no hay input, usar los directorios por defecto
    if [ -z "$input_dirs" ]; then
        input_dirs=$default_dirs
    fi
    
    # Verificar y devolver solo los directorios que existen
    local valid_dirs=""
    for dir in $input_dirs; do
        if [ -d "$dir" ]; then
            valid_dirs="$valid_dirs $dir"
        else
            echo "Advertencia: El directorio '$dir' no existe y será ignorado"
        fi
    done
    
    if [ -z "$valid_dirs" ]; then
        echo "Error: No se encontraron directorios válidos para procesar"
        exit 1
    fi
    
    echo "Se procesarán los siguientes directorios:$valid_dirs"
    echo "$valid_dirs"
}

# Función para procesar los archivos .c en un directorio y sus subdirectorios
process_directory() {
    local dir=$1
    local output_file=$2
    
    # Procesar cada subdirectorio
    for subdir in "$dir"/*/; do
        if [ -d "$subdir" ]; then
            # Añadir encabezado del subdirectorio
            echo "/* ************************************************************************** */" >> "$output_file"
            echo "/*                                                                            */" >> "$output_file"
            echo "/*                            src/${subdir#$dir}                                           */" >> "$output_file"
            echo "/*                                                                            */" >> "$output_file"
            echo "/* ************************************************************************** */" >> "$output_file"
            echo "" >> "$output_file"
            
            # Encontrar y concatenar todos los archivos .c en el subdirectorio
            find "$subdir" -maxdepth 1 -name "*.c" -type f | sort | while read -r file; do
                echo "Procesando: $file"
                echo "" >> "$output_file"
                cat "$file" >> "$output_file"
                echo "" >> "$output_file"
            done
        fi
    done
}

# Principal
main() {
    # Obtener el nombre del archivo de salida
    OUTPUT_FILE=$(get_output_filename)
    
    # Obtener los directorios a procesar
    DIRS=$(get_directories)
    
    # Eliminar el archivo de salida si ya existe
    rm -f "$OUTPUT_FILE"
    
    # Crear el archivo de salida
    touch "$OUTPUT_FILE"
    
    # Procesar cada directorio
    for dir in $DIRS; do
        if [ -d "$dir" ]; then
            process_directory "$dir" "$OUTPUT_FILE"
        fi
    done
    
    echo "Archivos concatenados en $OUTPUT_FILE"
}

# Ejecutar el script
main