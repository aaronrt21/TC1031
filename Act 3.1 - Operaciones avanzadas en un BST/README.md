**Aarón Gonzalo Ramírez Tafolla - A01351621**

**Act. 3.1 - Operaciones avanzadas en un BST**

**Análisis de complejidad**

**Visit**

La complejidad de visit es lineal (O(n)) porque cada algoritmo tiene que pasar por toda la estructura para poder desplegar el valor de cada nodo.

**Height**

Como visit, height tiene que recorrer toda la estructura, haciendo que su complejidad sea lineal (O(n)).

**Ancestors**

En el mejor de los casos, la función ancestors tiene una complejidad logaritmoca (O(logn)) por la forma en la que se divide la estructura. Si se tuviera un árbol
degenerado (peor de los casos) y se quisieran obtener los ancestros del último nodo, la complejidad cambiaría a O(n) porque tendría que recorrer todos los elementos de
la estructura para poderlos desplegar.

**WhatLevelAmI**

Siguiendo el mismo razonamiento que con la función ancestors, mientras no se maneje una estructura lineal, la complejidad será O(logn) en el mejor de los casos. En el
peor de los casos será O(n).
