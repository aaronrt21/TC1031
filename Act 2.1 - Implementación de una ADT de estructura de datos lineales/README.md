**Aarón Gonzalo Ramírez Tafolla - A01351621**
**Act 2.1: Análisis de complejidad**

**add**

Como la función debe recorrer toda la lista un elemento a la vez para verificar que el elemento se está agregando al final, su complejidad es de O(n).

**find**

La función debe de comparar cada valor de cada nodo en la lista. Igual que **add**, esto lo hace un elemento a la vez. Por esto, su complejidad también
es de O(n).

**update**

La función debe comparar el índice introducido por el usuario con la variable posición en aumentos de 1. Si el usuario pide actualizar el primer elemento,
la complejidad de la función es O(1). Si no, será O(n).

**remove**

La función sigue el mismo razonamiento que **update** en términos de complejidad. Puede ser O(1) u O(n).
