**Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento**

Aarón Gonzalo Ramírez Tafolla
A01351621

**Análisis de complejidad**

**ordenaSeleccion:**
En el mejor y peor de los casos, el ordenamiento por método de selección tiene complejidad O(n^2), haciéndolo el menos eficiente de los 3. La ventaja que tiene
este método sobre el merge es que la complejidad espacial es constante, lo cual ahorra memoria.

**ordenaBurbuja:**
Ordenar un vector por el método burbuja puede tener complejidad O(n) en el mejor de los casos u O(n^2) en el peor de los casos, dependiendo de cómo se
manejen los índices. Como ordenaSelección, su complejidad espacial es constante.

**ordenaMerge:**
En cualquiera de los casos, ordenamiento por Merge va a tener una complejidad O(nlogn), lo cual es útil para cantidades más grandes de datos porque te garantiza que nunca va a subir a otro grado más lento como O(n^2). Sin embargo, su complejidad espacial es O(n), lo cual significa que gastará más memoria que los dos anteriores.

**busqSecuencial:**
Esta función tiene complejidad lineal, porque maneja sólo un límite y recorre todos los elementos del vector hasta que encuentre la respuesta o
alcance este límite.

**busqBinaria:**
La búsqueda binaria usa una complejidad de O(nlogn) porque existe la posibilidad de que se tenga que recorrer todo un árbol recursivo o se termine en el primer
elemento.
