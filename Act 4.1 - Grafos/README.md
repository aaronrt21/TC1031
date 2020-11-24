**Aarón Gonzalo Ramírez Tafolla - A01351621**

**Funciones y análisis de complejidad**

**loadGraphMat**

La función loadGraphMat lee un archivo y guarda los datos en un grafo en una matriz de adyacencia. Como debe de leer cada línea en el documento, el programa tiene
complejidad O(n).

**loadGraphList**

Al igual que loadGraphMat, la función loadGraphList lee un archivo y genera un grafo con los datos contenidos en él en una lista de adyacencia. Al igual que la función
anterior, tiene una complejidad O(n).

**DFS**

La función DFS realiza una búsqueda usando una estructura stack. Maneja una complejidad O(n^2) debido al manejo de los índices.

**BFS**

A diferencia de DFS, la función BFS utiliza una estructura queue. También usa una complejidad de O(n^2) debido al manejo de los índice en los ciclos y condicionales.
