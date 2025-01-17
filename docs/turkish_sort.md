# Algoritmo Turkish Sort

El algoritmo Turkish Sort es una variación del algoritmo de ordenación que utiliza dos stacks. Se basa en una estrategia de costes para determinar el movimiento más eficiente en cada paso.

## Pasos principales

1. Indexar el stack A: Asignar a cada número su posición final en el stack ordenado.
2. Inicializar stack B: Mover los primeros elementos según una estrategia inicial.
3. Mover elementos a B: Calcular costes y mover elementos hasta quedar 3 en A.
4. Ordenar los 3 elementos en A.
5. Devolver elementos a A: Calcular posiciones objetivo y costes para cada movimiento.
6. Alineación final: Rotar A para que el mínimo quede arriba.

## Cálculo de costes

- Para cada elemento, se calcula su posición objetivo en el otro stack
- Se calcula el coste de rotación en ambos stacks
- Se elige el elemento con menor coste total de movimiento
- Se realizan las rotaciones y el push

## Optimización actual

El algoritmo incluye varias optimizaciones:
- Detección de stacks casi ordenados (≤3 elementos fuera de lugar)
- Selección de elementos basada en costes ponderados
- Uso de rotaciones dobles cuando es posible

## Posibles optimizaciones:

1. Preagrupación inteligente:
   * En lugar de mover uno a uno, podríamos identificar grupos de números cercanos y moverlos juntos
   * Esto reduciría el número total de operaciones de rotación

2. Mejora en la selección del nodo más barato:
   * Actualmente solo consideramos el coste absoluto
   * Podríamos añadir un factor de "beneficio futuro" al coste
   * Por ejemplo, si mover un número ayuda a posicionar otros números cercanos

3. Optimización de rotaciones:
   * Podríamos buscar oportunidades para hacer más rr y rrr en lugar de rotaciones individuales
   * Esto requeriría modificar la función do_rotations