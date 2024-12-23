#!/usr/bin/env python3

import os
import shutil

# Define la estructura deseada
structure = {
    'main': ['push_swap.c'],
    'stack': ['stack_init.c', 'stack_utils.c'],
    'parser': ['parse_args.c', 'parse_utils.c'],
    'error': ['error_handler.c'],
    'operations': ['basic_ops.c', 'push_ops.c', 'rotate_ops.c', 'reverse_rotate_ops.c'],
    'sort': ['sort_small.c', 'sort_large.c', 'sort_utils.c']
}

# Directorio base
src_dir = 'src'

def reorganize_src():
    print("🚀 Reorganizando estructura de src/...")
    
    # Crear directorio temporal
    temp_dir = 'src_temp'
    os.makedirs(temp_dir, exist_ok=True)
    
    # Crear la nueva estructura en el directorio temporal
    for folder, files in structure.items():
        folder_path = os.path.join(temp_dir, folder)
        os.makedirs(folder_path, exist_ok=True)
        
        # Mover archivos existentes o crear nuevos vacíos
        for file in files:
            src_file = os.path.join(src_dir, folder, file)
            dst_file = os.path.join(folder_path, file)
            
            if os.path.exists(src_file):
                shutil.copy2(src_file, dst_file)
                print(f"✅ Copiado: {file}")
            else:
                # Crear archivo vacío
                open(dst_file, 'a').close()
                print(f"📝 Creado nuevo: {file}")
    
    # Eliminar el directorio src original y renombrar el temporal
    if os.path.exists(src_dir):
        shutil.rmtree(src_dir)
    shutil.move(temp_dir, src_dir)
    
    print("\n✨ Reorganización completada!")
    print("\nEstructura actual de src/:")
    os.system('tree src')

if __name__ == "__main__":
    reorganize_src()