# Práctica: Simulación de Gestión de Memoria en C++

## Descripción
Este repositorio contiene la implementación y el análisis de algoritmos clásicos de asignación dinámica de memoria. El objetivo principal es simular y comprender cómo diferentes estrategias seleccionan bloques de memoria libres para asignar procesos, observando los efectos de la fragmentación.

## Objetivos
*   Implementar los algoritmos de asignación de memoria: First-Fit, Best-Fit y Next-Fit.
*   Comprender las diferencias operativas y de rendimiento entre cada estrategia.
*   Analizar las ventajas y limitaciones en un escenario de particionamiento dinámico simulado en C++.

## Algoritmos Implementados
1.  **First-Fit (`first.cpp`):** Asigna el primer bloque libre con tamaño suficiente, iniciando la búsqueda desde el comienzo de la memoria.
2.  **Best-Fit (`best.cpp`):** Asigna el bloque libre más pequeño que logre satisfacer el tamaño requerido, buscando minimizar el espacio desperdiciado (fragmentación interna).
3.  **Next-Fit (`next.cpp`):** Similar a First-Fit, pero guarda la posición de la última asignación y continúa la búsqueda desde ese punto.

## Compilación y Ejecución

Para compilar y ejecutar cualquiera de los programas, utiliza un compilador de C++ (como `g++`). Desde la terminal:

```bash
# Compilar
g++ src/first.cpp -o first

# Ejecutar
./first